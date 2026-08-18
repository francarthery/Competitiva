import subprocess
import time
import os

def find_best_k():
    # Nombres de tus archivos
    cpp_source = "Distinct_Values_Queries_2.cpp"  # Cambiá esto si tu archivo se llama distinto
    executable = "mo_prog.exe" if os.name == 'nt' else "./mo_prog"
    
    # Tus 4 casos de prueba (asegurate de crearlos/nombrarlos así)
    test_cases = ["test1.in", "test2.in", "test3.in", "test4.in"]
    
    # Verificar que los tests existan
    for tc in test_cases:
        if not os.path.exists(tc):
            print(f"Error: No se encontró el caso de prueba {tc}.")
            return

    # 1. Compilar el programa (sin -Dfran para poder mandarle el input por consola)
    print("Compilando código C++ (con -O3 para máximo rendimiento)...")
    compile_cmd = ["g++", "-O3", "-std=c++20", cpp_source, "-o", executable]
    
    try:
        subprocess.run(compile_cmd, check=True)
    except subprocess.CalledProcessError:
        print("Error en la compilación. Revisa tu código C++.")
        return

    # 2. Definir el rango de k a probar
    # Un N de 100,000 suele tener un N^(2/3) de aprox 2150.
    # Probaremos desde 500 hasta 4500 con saltos de 100.
    k_values = range(4500, 6501, 100)
    
    best_k = -1
    min_max_time = float('inf')

    print("\nComenzando pruebas...")
    print(f"{'k':<8} | {'Max Time (s)':<15}")
    print("-" * 28)

    # 3. Probar cada valor de k
    for k in k_values:
        max_time_for_k = 0.0
        
        for tc in test_cases:
            with open(tc, 'r') as fin:
                # Usamos perf_counter que es muy preciso para benchmarks
                start = time.perf_counter()
                
                # Ejecutar el programa pasándole k como argumento
                subprocess.run([executable, str(k)], stdin=fin, stdout=subprocess.DEVNULL)
                
                end = time.perf_counter()
                elapsed = end - start
                
                # Nos quedamos con el máximo tiempo de los 4 casos
                if elapsed > max_time_for_k:
                    max_time_for_k = elapsed
        
        print(f"{k:<8} | {max_time_for_k:.4f}")
        
        # 4. Actualizar el mínimo de los máximos (minimax)
        if max_time_for_k < min_max_time:
            min_max_time = max_time_for_k
            best_k = k

    print("-" * 28)
    print(f"¡Búsqueda finalizada!")
    print(f"El k óptimo es: {best_k}")
    print(f"El peor tiempo con este k fue de: {min_max_time:.4f}s")

if __name__ == "__main__":
    find_best_k()