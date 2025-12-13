#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, aux, pos;
    string s;

    while(cin >> n and n != 0){
        list<pair<int, string>> l;
        pos = 0;

        for(int i = 0; i < n; i++){
            cin >> s >> aux;
            l.push_back(make_pair(aux, s));
        }

        auto it = l.begin();
        aux = it -> first;

        while(l.size() > 1){
            
            if(aux % 2){ //Si el numero es impar vamos para atras
                pos = (pos + aux) % l.size();
                it = next(l.begin(), pos);
            }
            else{
                pos = (pos - (aux % l.size()) + l.size()) % l.size();
                it = next(l.begin(), pos);
            }

            aux = it -> first;
            l.erase(it);
            if(aux % 2) pos = (pos - 1 + l.size()) % l.size(); //Retrocedemos o avanzamos ya que esa pos no existe mas
        }

        cout << "Vencedor(a): " << l.front().second << endl;

    }

    return 0;
}