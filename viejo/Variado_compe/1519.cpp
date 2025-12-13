#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string aux, pal;
    while(getline(cin, aux) and aux != "."){
        istringstream stream(aux);
        map<string, int> m;
        vector<string> v;
        vector<pair<string, int>> max_l(26);
        int cont = 0;

        while(stream >> pal){
            v.push_back(pal);
            m[pal]++;
        }

        for(auto i : m){
            if((i.first.size() - 2) * i.second > max_l[i.first[0] - 'a'].second and i.first.size() > 2){
                if(max_l[i.first[0] - 'a'].second == 0) cont++; //Contador cant de abreviaturas
                max_l[i.first[0] - 'a'] = {i.first, (i.first.size() - 2) * i.second};
            }
        }

        for(int i = 0; i < v.size(); i++){
            if(max_l[v[i][0] - 'a'].first == v[i]) //Si la palabra tiene abreviacion
                cout << v[i][0] << ".";
            else
                cout << v[i];

            cout << (i < v.size() - 1 ? ' ' : '\n');
        }
        cout << cont << '\n';

        for(auto i : max_l){
            if(i.second > 0) cout << i.first[0] << ". = " << i.first << endl; 
        }

    }

    return 0;
}