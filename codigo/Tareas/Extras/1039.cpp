#include <iostream>
#include <cmath>
#define pi 3.14159265

using namespace std;
 
int main() {
 
    double r1, x1, y1, r2, x2, y2, co, ca, tan;
    double sinrad, ang, hipo;

    for(;;){
        cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2;

        if(r1 == EOF) break;

    ca = abs(x1 - x2);
    co = abs(y1 - y2);
    if (y2 < y1) swap(ca,co);
    tan= co/ca;
    sinrad= atan(tan);
    ang= sinrad*180/pi;

    hipo=sqrt(pow(ca,2) + pow(co,2));

    if(hipo+r2>r1)
        cout << "MORTO" << endl;
    else
        cout << "RICO" << endl;
 
    }
    
    return 0;
}