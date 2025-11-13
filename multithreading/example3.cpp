/*
Mutex: mutex-exclusion. Es una forma de asegurar que dos hilos de un programa no accedan a la
misma funcion al mismo tiempo.

Para bloquear una zona critica tenemos dos opciones:
    lock_guard<mutex> carLock(carMutex); Desde esa linea hacia abajo se bloquea se bloqueara
el contenido hasta que carLock quede fuera de alcance (termine la funcion). Esta forma es mas
simple y garantiza el desbloqueo. Sin embargo no se puede desbloquear manualmente.
    
    unique_lock<mutex> carLock(carMutex); En este caso necesitamos al final de la seccion que
queremos bloquear usar la senctencia carLock.unlock(); para desbloquear el contenido.  
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex carMutex;

void driveCar(string driverName){
    unique_lock<mutex> carLock(carMutex);

    cout << driverName << " is driving" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << driverName << " is done driving" << endl;

    carLock.unlock();
}

int main(){

    //Dos hilos intentan acceder simultaneamente al mismo recurso
    thread t1(driveCar, "Saldina");
    thread t2(driveCar, "Francisco");

    t1.join();
    t2.join();

    return 0;
}