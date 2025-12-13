#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, a, b;
    while(cin >> n >> m and (n != 0 or m != 0)){
        vector< vector<char> > dibu(n, vector<char>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> dibu[i][j];
            }
        }

        cin >> a >> b;
        vector< vector<char> > ndibu(a, vector<char>(b));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){ //Cada posicion del dibujo original
                for(int k = i*(a / n); k < (i + 1)*(a / n); k++){
                    for(int l = j*(b / m); l < (j + 1)*(b / m); l++){
                        ndibu[k][l] = dibu[i][j];
                    }
                }
            }
        }

        for(auto i : ndibu){
            for(char j : i){
                cout << j;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}