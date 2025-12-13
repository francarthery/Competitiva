#include <bits/stdc++.h>
using namespace std;

string sacar_0_inicio(string a){
	for(int i = 0; i < a.size(); i++){
		// En cuanto se encuentra un digito != 0 se devuelven todos los digitos siguientes
		if(a[i] != '0')
			return a.substr(i, a.size() - i);
	}
	// Si todos los digitos son 0 devolvemos 0
	return "0";
}
string suma_str(string a, string b){
	if(a.size() > b.size()) swap(a, b);
	
	int n = a.size();
	int diff = b.size() - a.size();
	string ans; //Almacena el resultado
	int acarreo = 0;
	for(int i = n-1; i > -1; i--){
		// Calculo suma digitos y acarreo
		int sum_d = (a[i] - '0') + (b[i + diff] - '0') + acarreo;
		acarreo = sum_d / 10;
		ans.push_back(sum_d % 10 + '0');
	}
	for(int i = diff - 1; i > -1; i--){
		// Calculo suma de digitos extra
		int sum_d = (b[i] - '0') + acarreo;
		acarreo = sum_d / 10;
		ans.push_back(sum_d % 10 + '0');
	}
	// Si existe acarreo se agrega a la respuesta
	if(acarreo) ans.push_back(acarreo + '0');
	//Se invierte ans para que este ordenado correctamente.
	reverse(ans.begin(), ans.end());
	return ans;
}
string resta_str(string b, string a){
	if(a.size() > b.size()) swap(a, b);
	
	int n = a.size();
	int diff = b.size() - a.size();
	string ans;
	int acarreo = 0;
	for(int i = n-1; i > -1; i--){
		// Resto digitos y acarreo
		int diff_d = (b[i + diff] - '0') - (a[i] - '0') - acarreo;
		// Si la resta dio negativa hago 1 el acarreo
		acarreo = (diff_d < 0);
		// Si la diferencia es negativa agrego 10
		diff_d += 10 * acarreo;
		ans.push_back(diff_d + '0');
	}
	for(int i = diff - 1; i > -1; i--){
		// Calculo la resta de los digitos extra y el acarreo
		int diff_d = (b[i] - '0') - acarreo;
		acarreo = (diff_d < 0);
		diff_d += 10 * acarreo;
		ans.push_back(diff_d + '0');
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
	
string mult_1_digito(string b, char a){ //Se realiza invertida para facilitar el proceso
	string ans;
	int d = a - '0', acarreo = 0;
	for(int i = b.size() - 1; i > -1; i--){
		// multiplico todos los digitos por el digito d
		int mul_d = (b[i] - '0') * d + acarreo;
		acarreo = mul_d / 10;
		ans.push_back(mul_d % 10 + '0');
	}
	// Si hay acarreo lo agrego a la respuesta
	if(acarreo) ans.push_back(acarreo + '0');

	reverse(ans.begin(), ans.end());
	return ans;
}

string karatsuba(string a, string b){
	//Nos aseguramos de que a sea menor a b
	if(a.size() > b.size()) swap(a, b);
	
	int A = a.size(), B = b.size();
	if(A == 1) return mult_1_digito(b, a[0]);
	
	string copy_A, copy_B;
	if(B & 1){ 
		copy_B.push_back('0'); //Si B es impar lo hago par agregando un 0 inicial
		B += 1;
	}
	for(int i = 0; i < B - A; i++){
		copy_A.push_back('0'); //Hacemos los dos strings del mismo tam agregando 0s al principio
	}
	// finalmente ingresamos los valores de a y b. Los dos numeros tienen la misma longitud.
	copy_A += a;
	copy_B += b;
	
	// Partimos copy_A y copy_B en dos partes iguales, una izquierda y la otra derecha
	string A_l, A_r, B_l, B_r;
	A_l = copy_A.substr(0, B/2);
	A_r = copy_A.substr(B/2, B/2);
	B_l = copy_B.substr(0, B/2);
	B_r = copy_B.substr(B/2, B/2);
	
	/* Tomamos a m = n/2
	=> A * B
	=> (Al * 10^(n/2) + Ar) * (Bl * 10^(n/2) + Br)
	=> (Al*Bl*10^(n) + (Al*Br + Ar*Bl) * 10^(n/2) + Ar*Br)
	=> (Al*Bl*10^(n) + ((Al+Ar)*(Bl+Br)-Al*Bl-Ar*Br)*10^(n/2) + Ar*Br)
	*/
	
	// Al * Bl
	string I_1 = karatsuba(A_l, B_l);
	// Ar * Br
	string I_2 = karatsuba(A_r, B_r);
	// (Al + Ar) * (Bl + Br)
	string I_3 = karatsuba(suma_str(A_l, A_r), suma_str(B_l, B_r));
	// Al * Bl + Ar * Br
	string sum_I1_I2 = suma_str(I_1, I_2);
	// (Al + Ar) * (Bl + Br) - Al * Bl - Ar * Br
	I_3 = resta_str(I_3, sum_I1_I2);
	// Al * Bl * 10^(n)
	I_1 += string(B, '0');
	// ((Al + Ar) * (Bl + Br) - Al * Bl - Ar * Br) * 10^(n/2)
	I_3 += string(B/2, '0');
	// (Al*Bl*10^(n) + ((Al+Ar)*(Bl+Br)-Al*Bl-Ar*Br)*10^(n/2) + Ar*Br)
	string I_4 = suma_str(I_3, suma_str(I_1, I_2));
	
	// Sacamos 0s del frente y retornamos resultado
	return sacar_0_inicio(I_4);
}

int main(){
	
	#ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

	string a, b;

	while(cin >> a >> b){
        auto inicio = chrono::high_resolution_clock::now(); //Obtener tiempo de inicio
		string ans = karatsuba(a, b);
		cout << ans << endl;

		// Obtener el tiempo de fin
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio; // Calcular la duración
        cout << "El tiempo de ejecucion es: " << fixed << setprecision(10) << duracion.count() << " segundos" << '\n';
	}
	
	return 0;
}
