#include <bits/stdc++.h>

using namespace std;

tuple<int,int,int> ex_gcd(int a, int b){
    if(b == 0) return {1, 0, a};
    else{
        auto [x, y, g] = ex_gcd(b, a%b);
        return {y, x - (a/b) * y, g};
    }
}

int main(){

    auto [a, b, c] = ex_gcd(30, 12);
    cout << a << ' ' << b << ' ' << c << '\n';

    return 0;
}