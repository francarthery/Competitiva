#include <bits/stdc++.h>

using namespace std;

int n, m; 

bool compare(int a, int b) {
    if (a % n != b % n) 
        return a % n < b % n;
    else {
        if (abs(a % 2) != abs(b % 2)) return a % 2; // Impar gana sobre par
        else if (a % 2) return a > b; // Ambos son impares, el mayor gana
        else return a < b; // Ambos son pares, el menor gana
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(cin >> m >> n and (m != 0 or n != 0)){
        vector<int> v(m);
        for(int i = 0; i < m; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end(), compare);
        
        cout << m << " " << n << endl;
        for(int i : v)
            cout << i << endl;
    }
    cout << "0 0" << endl;

    return 0;
}