#include <bits/stdc++.h>

using namespace std;

int main(){

    int max, min, n, suma;

    while(cin >> n){
        min = 0;
        max = sqrt(n);

        while(min <= max and suma != n){
            suma = pow(max, 2) + pow(min, 2);
            
            if(suma > n)
                max--;
            else if(suma < n)
                min++;
        }

        cout << (suma == n ? "YES" : "NO") << endl;
    }

    return 0;
}