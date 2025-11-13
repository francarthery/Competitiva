/*
No es lo mismo multitasking que multithreading. El primero es ir alternando entre tareas pero
sobre un mismo hilo. Multithreading es ejecutar dos tareas en simultaneo
*/

#include <iostream>
#include <thread>

void function1(char symbol){
    for(int i = 0; i < 200; i++){
        std::cout << symbol;
    }
}

void function2(){
    for(int i = 0; i < 200; i++){
        std::cout << "-";
    }
}

int main(){
    //Los parametros a la funcion se pasan separados por comas
    std::thread worker1(function1, 'o');
    std::thread worker2(function2);

    system("pause>nul");
}