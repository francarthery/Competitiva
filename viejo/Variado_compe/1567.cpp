#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    while(cin >> n){
        long long int s2, r2 = 0, s3, r3 = 0, s4, r4 = 0;

        s2 = (n * (n + 1) * (2 * n + 1)) / 6; //Sumatoria de cuadrados de 1 a N
        s3 = pow((n * (n + 1) / 2), 2); //Sumatoria de cubos de 1 a N
        s4 = (n * (n + 1) * (2*n + 1) * (3*pow(n,2) + 3*n - 1)) / 30; //Sumatoria de hypercubos de 1 a N
        
        r2 = s3 - s2; //S3 es gauss al cuadrado asi que no lo vuelvo a calcular
        r3 = pow((n * (n + 1)) / 2, 3) - s3; //Suma de gauss al cubo - cubos
        r4 = pow((n * (n + 1)) / 2, 4) - s4;

        cout << s2 << " " << r2 << " " << s3 << " " << r3 << " " << s4 << " " << r4 << endl;
    }

    return 0;
}

//R2 =  pow(((n*(n+1))/2),i)