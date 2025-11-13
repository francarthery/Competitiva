#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, negras, cont = 0;
    char c;
    cin >> n;

    for(int i = 0; i < n; i++){
        negras = 0;
        for(int j = 0; j < n; j++){
            cin >> c;
            if(c == 'N'){
                negras++;
                if(j == n - 1 and negras > 1){
                    cont += negras / 2;
                }
            }
            else if(c == 'B' or j == n - 1){
                if(negras > 1){
                    cont += negras / 2;
                }
                negras = 0;
            } 
        }
    }

    cout << cont << '\n';

    return 0;
}