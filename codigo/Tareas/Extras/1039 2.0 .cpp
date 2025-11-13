#include <iostream>
#include <cmath>
#define pi 3.14159265

using namespace std;
 
int main() {
 
    int r1, x1, y1, r2, x2, y2;
    double hipo;
    bool prueba[5625];

    for(int i=0; i<5626; i++){
        cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2;

        if(r1 == EOF or x1 == EOF or y1 == EOF or r2 == EOF or x2 == EOF or y2 == EOF) break;

        hipo=sqrt(pow(x1-x2,2) + pow(y1-y2,2));

        if(hipo+r2>r1)
            prueba[i]=false;
        else
            prueba[i]=true;
 
    }

    for(int i=0; i<5626; i++){
        if(prueba[i]==0)
            cout << "MORTO" << endl;
        else
            cout << "RICO" << endl;

    }
    
    return 0;
}