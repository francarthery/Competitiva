#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, x, cont1, cont2;

    while(cin >> n >> m and (n != 0 or m != 0)){
        cont1 = cont2 = 0;
        unordered_set<int> al;
        unordered_set<int> be;

        for(int i = 0; i < n; i++){
            cin >> x;
            al.insert(x);
        }

        for(int i = 0; i < m; i++){
            cin >> x;
            be.insert(x);
        }

        for(int i : al){
            if(be.find(i) == be.end()) cont1++;
        }

        for(int i : be){
            if(al.find(i) == al.end()) cont2++;
        }

        cout << min(cont1, cont2) << '\n';
    }

    return 0;
}