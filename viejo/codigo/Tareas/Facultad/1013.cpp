#include <iostream>
 
using namespace std;
 
int main() {
 
    int a, b, c, mayor_ab, mayor;

    cin >> a >> b >> c;

    mayor_ab=(a+b+abs(a-b))/2;

    mayor=(mayor_ab+c+abs(mayor_ab-c))/2;

    cout << mayor << " eh o maior" << endl;
 
    return 0;
}