#include <iostream>
#include <math.h>

using namespace std;
 
int main() {
 
    int L, C, R1, R2;

    for(;;){
        cin >> L >> C >> R1 >> R2;

        if(L==0 and C==0 and R1==0 and R2==0)break;

        if(R1*2>C and R2*2>C)
            cout << "N" << endl;
        else
            if(L + C - sqrt(2*(L*C)) <= sqrt(pow(L-(R1+R2),2) + pow(C-(R1+R2),2)))
                cout << "S" << endl;
            else
                cout << "N" << endl;
    
    }
 
    return 0;
}

/*
Saber distancia entre centros círculos: a + b - sqrt(2(a*b))

Ecuación de una circunferencia: (x-h)^2 + (y-k)^2 = r^2   (h, k)=centro r=radio 
== (x-R1)^2 + (y-(C-R1))^2 = r^2

Ecuación bisectriz: y=-x+L    Al ser L el lado mayor y la pendiente=1 la OO=L


*/