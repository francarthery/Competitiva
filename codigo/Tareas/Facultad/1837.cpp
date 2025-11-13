#include <iostream>
 
using namespace std;
 
int main() {
 
    int a, b, q, r;

    cin >> a >> b;

    q = a / b;
    r = a % b;

    if(a < 0 and b >= 0 and r != 0){
        q--;
        r += b;
    }
    else if(a < 0 and b < 0 and r != 0){
        q++;
        r += abs(b);
    }

    cout << q << " " << r << endl;
 
    return 0;
}

/*
50 / 6  q = 8 r = 2

-50 / 6   q = -9  r = 4

50 / -6   q = -8   r = 2

-50 / -6    q = 9   r = 4

*/