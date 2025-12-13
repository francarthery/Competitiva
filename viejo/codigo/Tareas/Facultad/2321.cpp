#include <iostream>
 
using namespace std;
 
int main() {
 
    int xa0, xa1, ya0, ya1, xb0, xb1, yb0, yb1;

    bool rta = false;
    
    cin >> xa0 >> ya0 >> xa1 >> ya1 >> xb0 >> yb0 >> xb1 >> yb1;

    if(xa0 <= xb0 and xa1 >= xb0 and ya0 <= yb0 and ya1 >= yb0)
        rta = true;
    else if(xa0 <= xb1 and xa1 >= xb1 and ya0 <= yb1 and ya1 >= yb1)
        rta = true;

    cout << rta;
 
    return 0;
}