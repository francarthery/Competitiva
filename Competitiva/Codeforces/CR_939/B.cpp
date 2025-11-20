#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, t, c;

    cin >> t;
    
    while(t--){
        cin >> n;
        unordered_set<int> cartas;
        for(int i=0; i < n; i++){
            cin >> c;
            cartas.insert(c);
        }
        cout << n - cartas.size() << '\n';
    }



    return 0;
}