#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, qt, s, x, min_d, gana;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> qt >> s;
        min_d = 1000;
        for(int j = 1; j <= qt; j++){
            cin >> x;
            if(abs(x - s) < min_d){
                min_d = abs(x - s);
                gana = j;
            }
        }
        cout << gana << '\n';
    } 

    return 0;
}