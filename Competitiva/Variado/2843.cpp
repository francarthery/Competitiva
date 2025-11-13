#include <bits/stdc++.h>

using namespace std;

#define sc second
#define fr first

typedef pair<int, pair<int, int>> pp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    list<pp> l; //(indice, (reaccion, velocidad))
    int n, timer = 1, x, y, l_pal, vel1, vel2;
    string pal;

    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        l.push_back({i,{x,y}});
    }

    cin.ignore();
    getline(cin, pal);
    l_pal = pal.size();

    list<pp>::iterator ant, act, elim;

    while(n > 1){
        int cont = 0;
        ant = l.begin();
        act = ++l.begin();

        while(cont < n/2){
            vel1 = ant->sc.fr + ant->sc.sc * l_pal;
            vel2 = act->sc.fr + act->sc.sc * l_pal;

            if(vel2 < vel1) //Si el tiempo del primero fue mayor al del segundo
                elim = ant;
            else
                elim = act;

            ant = ++act; //Avanzo a los proximos dos jugadores
            act++;

            v[elim->fr] = timer; //Guardo la ronda en que perdio ese jugador;
            l.erase(elim); //Lo saco de la lista
            cont++;
        }

        n /= 2;
        l_pal *= 2;
        timer++;
    }
    v[l.front().fr] = timer; //Quedo un elemento que es el ganador

    cout << v[0];
    for(int i = 1; i < v.size(); i++){
        cout << " " << v[i];
    }
    cout << '\n';

    return 0;
}