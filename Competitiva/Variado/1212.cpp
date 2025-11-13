#include <bits/stdc++.h>

using namespace std;

int main(){

    unsigned n, m, rta;
    bool acarreo = false;
    
    while(cin >> n >> m and (n != 0 or m != 0)){
        rta = 0;
        acarreo = false;

        while(n > 0 or m > 0){
            if(n % 10 + m % 10 + acarreo > 9){
                rta++;
                acarreo = true;
            }
            else
                acarreo = false;

            n /= 10;
            m /= 10;
        }

        if(!rta)
            cout << "No carry operation." << endl;
        else
            cout << rta << " carry operation" << (rta > 1 ? "s." : ".") << endl;
    }

    return 0;
}