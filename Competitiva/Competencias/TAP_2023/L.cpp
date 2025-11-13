#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a1, p1, a2, p2;

    cin >> a1 >> p1 >> a2 >> p2;

    if(a1 + a2 > p1 + p2) cout << "A\n";
    else if(a1 + a2 < p1 + p2) cout << "P\n";
    else cout << "D\n";

    return 0;
}