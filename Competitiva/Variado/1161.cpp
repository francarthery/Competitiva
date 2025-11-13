#include <bits/stdc++.h>

using namespace std;

long long unsigned fact(int n){
    if(n == 0) return 1;
    else return n * fact(n - 1);
}

int main(){

    long long unsigned n, m, rta;

    while(cin >> n >> m){
        rta = fact(n) + fact(m);
        cout << rta << endl;
    }

    return 0;
}