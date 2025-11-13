#include <iostream>

using namespace std;

void Mover(float &posX, float &posY, char direccion, float amplitud);

int main(){

    float posX, posY, amplitud;
    char direccion;

    cout << "Indique la posición del barco" << endl;

    cin >> posX >> posY;

    cout << "Indique la dirección del movimiento" << endl;

    do{
        cin >> direccion;
        if(direccion < 'A' or direccion > 'H')
            cout << "Dirección no válida. Inténtelo de nuevo." << endl;
    }
    while(direccion < 'A' or direccion > 'H');


    Mover(posX, posY, direccion, amplitud);

    cout << "La posición es:" << posX << " " << posY << endl;

    return 0;
}

void Mover(float &posX, float &posY, char direccion, float amplitud){

    switch (direccion)
    {
    case 'A':
        posY += amplitud;        
        break;
    case 'B':
        posX += amplitud;
        posY += amplitud;
        break;
    case 'C':
        posX += amplitud;
        break;
    case 'D':
        posX += amplitud;
        posY -= amplitud;
        break;
    case 'E':
        posY -= amplitud;
        break;
    case 'F':
        posX -= amplitud;
        posY -= amplitud;
        break;
    case 'G':
        posX -= amplitud;
        break;
    case 'H':
        posX -= amplitud;
        posY += amplitud;
        break;
    default:
        break;
    }
}
