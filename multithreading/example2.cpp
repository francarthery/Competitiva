#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>

//Para poder indicar los milisegundos en el hilo
using namespace std::chrono_literals;

void RefreshForecast(std::map<std::string, int> forecastMap){

    //Creamos un bucle infinito que cada 2 segundos Aumenta en 1 grado la temperatura
    while(true){
        //Al elemento hay que tomarlo por referencia para poder modificarlo
        for(auto &item : forecastMap){
            item.second++;
            std::cout << item.first << " " << item.second << std::endl;
        }

        std::this_thread::sleep_for(2000ms);
    }
}

int main(){

    std::map<std::string, int> forecastMap = {
        {"New York", 2},
        {"Buenos Aires", 34},
        {"London", 8},
        {"Pekin", 5}
    };

    //Creamos un hilo para que se ejecute en segundo plano y actualice los datos
    std::thread bgWorker(RefreshForecast, forecastMap);

    bgWorker.join(); // Espera a que el hilo termine para que no se produzca un runtime error
    
    return 0;
}