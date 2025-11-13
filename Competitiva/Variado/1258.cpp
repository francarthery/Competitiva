#include <bits/stdc++.h>

using namespace std;

typedef pair<string, pair<char, string>> pp;

struct compare{
    bool operator()(const pp &a, const pp &b) const {
        if(a.first != b.first) return a.first < b.first;
        else{
            if(a.second.first != b.second.first) return a.second.first > b.second.first;
            else return a.second.second < b.second.second;
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    multiset<pp, compare> s;
    int n;
    string col, nom;
    char c;
    bool prim = true;

    while(cin >> n and n != 0){
        if(!prim) cout << '\n'; prim = false;

        s.clear();
        cin.ignore();
        for(int i = 0; i < n; i++){
            getline(cin, nom);
            cin >> col >> c;
            cin.ignore();
            s.insert({col,{c, nom}});
        }

        for(pp i : s)
            cout << i.first << " " << i.second.first << " " << i.second.second << '\n';
    }

    return 0;
}