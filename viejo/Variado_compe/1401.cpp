#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    string aux;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> aux;
        char pal[11];
        strcpy(pal, aux.c_str()); //Paso el string a una cadena de caracteres

        sort(pal, pal + aux.size()); //Ordeno las letras de menor a mayor

        do{
            for(int i = 0; i < aux.size(); i++) cout << pal[i];
            cout << '\n';
        }
        while(next_permutation(pal, pal + aux.size()));

        cout << '\n';
    }


  return 0;
}