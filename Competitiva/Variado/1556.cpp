#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
	cout << '[';
	for(auto c : v) cout << c << ',';
	cout << "]\n";
}

vector<string> v;

void f(string pal, string c, vector<int> cache){
    if(pal.empty()) return v.push_back(c);

    int tope = cache.back();
    char car = pal.back();
    forn(i, tope){ //Elimino los tope elementos de la palabra porque son iguales
        cache.pop_back();
        pal.pop_back();
    }

    f(pal, c, cache); //No uso la letra repetida
    forn(i, tope){ //La uso i veces
        c.push_back(car);
        f(pal, c, cache);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string pal, c;
    while(cin >> pal){
        v.clear();
        vector<int> cache(pal.size(), 1);
        for(int i = pal.size() - 1; i > 0; i--) if(pal[i] == pal[i - 1]) cache[i - 1] = cache[i] + 1;
        //vdbg(cache);

        reverse(all(cache));
        reverse(all(pal));
        f(pal, c, cache);

        sort(all(v));
        auto it = unique(all(v));
        for(auto i = ++v.begin(); i != it; i++) cout << *i << '\n';
        cout << '\n';
    }
    
    return 0;
}