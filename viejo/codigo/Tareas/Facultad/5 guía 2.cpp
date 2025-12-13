#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    int pos_inicial, pos_final, tiempo;
    double vel_kmh, vel_ms;


    cin >> pos_inicial >> pos_final >> tiempo;

    vel_kmh = (pos_final - pos_inicial) / (double)tiempo;
    vel_ms = vel_kmh / 3.6;

    cout << "La velocidad fue de " << fixed << setprecision(5) << vel_kmh << " km/h." << endl;
    cout << "Esto es igual a " << fixed << setprecision(5) << vel_ms << " m/s." << endl;

    return 0;
}