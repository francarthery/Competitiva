#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> c; //Guardo lo ya visitado

void expansion(int x, int y){
    c[x][y] = 1;

    if(x < v.size() - 1 and !c[x + 1][y] and v[x][y] == v[x + 1][y]) expansion(x + 1, y);
    if(x > 0 and !c[x - 1][y] and v[x][y] == v[x - 1][y]) expansion(x - 1, y);
    if(y < v[x].size() - 1 and !c[x][y + 1] and v[x][y] == v[x][y + 1]) expansion(x, y + 1);
    if(y > 0 and !c[x][y - 1] and v[x][y] == v[x][y - 1]) expansion(x, y - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, cx = 2, cy = 2, cz = 1, cont;
    cin >> n >> m;

    v.assign(n, vector<int>(m));
    c.assign(n, vector<bool>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 1; j++){
            cont = 1;
            if(!c[i][j + 1] and v[i][j] < v[i][j + 1]){
                cy++;
                c[i][j + 1] = 1;
                while(i + cont < n and v[i + cont][j] < v[i + cont][j + 1] and v[i + cont][j] < v[i + cont - 1][j + 1] and v[i + cont][j + 1] > v[i + cont - 1][j]) //inicio sig < fin ant y fin sig > ini ant
                    c[i + cont++][j + 1] = 1; //Guardamos que ya contamos esa cara
            }
            else if(!c[i][j + 1] and v[i][j] > v[i][j + 1]){
                cy++;
                c[i][j + 1] = 1;
                while(i + cont < n and v[i + cont][j] > v[i + cont][j + 1] and v[i + cont][j] > v[i + cont - 1][j + 1] and v[i + cont][j + 1] < v[i + cont - 1][j]) //inicio sig < fin ant y fin sig > ini ant
                    c[i + cont++][j + 1] = 1; //Guardamos que ya contamos esa cara
            }
        }
    }

    c.assign(n, vector<bool>(m)); //Reseteo cache

    for(int j = 0; j < m; j++){
        for(int i = 0; i < n - 1; i++){
            cont = 1;
            if(!c[i + 1][j] and v[i][j] < v[i + 1][j]){
                cx++;
                c[i + 1][j] = 1;
                while(j + cont < m and v[i][j + cont] < v[i + 1][j + cont] and v[i][j + cont] < v[i + 1][j + cont - 1] and v[i + 1][j + cont] > v[i][j + cont - 1]) //inicio sig < fin ant y fin sig > ini ant
                    c[i + 1][j + cont++] = 1; //Guardamos que ya contamos esa cara
            }
            else if(!c[i + 1][j] and v[i][j] > v[i + 1][j]){
                cx++;
                c[i + 1][j] = 1;
                while(j + cont < m and v[i][j + cont] > v[i + 1][j + cont] and v[i][j + cont] > v[i + 1][j + cont - 1] and v[i + 1][j + cont] < v[i][j + cont - 1]) //inicio sig < fin ant y fin sig > ini ant
                    c[i + 1][j + cont++] = 1; //Guardamos que ya contamos esa cara
            }
        }
    }


    c.assign(n, vector<bool>(m)); //Reseteo cache

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!c[i][j]){ //Parecido a dfs con varias componentes
                expansion(i, j);
                cz++;
            }
        }
    }

    cout << cx + cy + cz << '\n';

    return 0;
}