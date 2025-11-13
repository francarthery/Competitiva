#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, n, v, a, x, y;

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n >> v >> a;
        set< pair<int, int> > arcos;

        for(int j = 0; j < a; j++){
            cin >> x >> y;

            x < y ? arcos.insert(make_pair(x, y)) : arcos.insert(make_pair(y, x));
        }

        cout << arcos.size() * 2 << endl;
    }


    return 0;
}