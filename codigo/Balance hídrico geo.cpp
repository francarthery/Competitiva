#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){

    float x, PP[12], T[12], DRS[12], ETPSAJUST[12], SUM_IC=0;
    char h;
    int LAT, cont, FILA, LAT_TABLA[14] = {27, 28, 29, 30, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44};
    string MESES[12] = {"Enero: ", "Febrero: ", "Marzo: ", "Abril: ", "Mayo: ", "Junio: ", "Julio: ", "Agosto: ", "Septiembre: ", "Octubre: ", "Noviembre: ", "Diciembre: "};
    float DRS_TABLA[14][12] = {0.92,0.88,1.03,1.07,1.16,1.15,1.18,1.13,1.02,0.99,0.90,0.90,0.91,0.88,1.03,1.07,1.16,
    1.16,1.18,1.13,1.02,0.98,0.90,0.90,0.91,0.87,1.03,1.07,1.17,1.16,1.19,1.13,1.03,0.98,0.90,0.89,0.90,0.87,1.03,
    1.08,1.18,1.17,1.20,1.14,1.03,0.98,0.89,0.88,0.87,0.85,1.03,1.09,1.21,1.21,1.23,1.16,1.03,0.97,0.86,0.85,0.87,
    0.85,1.03,1.10,1.21,1.22,1.24,1.16,1.03,0.97,0.86,0.84,0.86,0.84,1.03,1.10,1.22,1.23,1.25,1.17,1.03,0.97,0.85,0.83,
    0.85,0.84,1.03,1.10,1.23,1.24,1.25,1.17,1.04,0.96,0.84,0.83,0.85,0.84,1.03,1.11,1.23,1.24,1.26,1.18,1.04,0.96,0.84,
    0.82,0.84,0.83,1.03,1.11,1.24,1.25,1.27,1.18,1.04,0.96,0.83,0.81,0.83,0.83,1.03,1.11,1.25,1.26,1.27,1.19,1.04,0.96,
    0.82,0.80,0.82,0.83,1.03,1.12,1.26,1.27,1.28,1.19,1.04,0.95,0.82,0.79,0.81,0.82,1.02,1.12,1.26,1.28,1.29,1.20,1.04,
    0.95,0.81,0.77,0.81,0.82,1.02,1.13,1.27,1.29,1.30,1.20,1.04,0.95,0.80,0.76};


    cout << "Ingrese Precipitaciones:" << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << MESES[i];
        cin >> x;
        PP[i]=x;
    }
    

    cout << endl << "Ingrese Temperatura:" << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << MESES[i];
        cin >> x;
        T[i]=x;
        SUM_IC+=pow(x/5, 1.514);
    }


    for (int i = 0; i < 12; i++)
    {
        ETPSAJUST[i]=16*pow((10*T[i]/SUM_IC), 0.000000675*pow(SUM_IC, 3) - 0.0000771*pow(SUM_IC, 2) + 0.01792*SUM_IC + 0.49239);
    }

    cout << endl << "Escriba 'N' si el lugar está en el hemisferio norte o 'S' para sur" << endl;
    cin >> h;
    cout << "Escriba Latitud (N más cecano a {27, 28, 29, 30, 35, 36, 37...}" << endl;
    cin >> LAT;

    //Bucle que asigna fila de tabla DRS
     for (int i = 0; i < 14; i++)
    {
        if(LAT==LAT_TABLA[i])
            FILA=i;
    }


    for (int i = 0; i < 12; i++)
    {
        //Se tienen en cuenta los hemisferios para la DRS
        if(h=='N')
            DRS[i]=DRS_TABLA[FILA][i];
        else{
            while(cont<6){
                DRS[i]=DRS_TABLA[FILA+1][i+6];
                cont++;}
            DRS[i]=DRS_TABLA[FILA+1][i-6];
        }
    }

    cout << "IC           ETP s/ajust         DRS           ETP" << endl;
    for (int i = 0; i < 12; i++)
    {
     
        cout << fixed << setprecision(3) << pow(T[i]/5, 1.514) << "    |    " << ETPSAJUST[i] << "     |      " << DRS[i] << "     |     " << DRS[i]*ETPSAJUST[i] << endl;
        
    }

    return 0;
}