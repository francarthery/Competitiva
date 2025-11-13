#include <iostream>
#include <cmath>
 
using namespace std;

#define PI 3.1415
 
int main() {
 
    int R, L;
    
    cin >> R >> L;
    
    cout << L / (PI * pow(R, 3) * (4.0/3)) << endl;
 
    return 0;
}