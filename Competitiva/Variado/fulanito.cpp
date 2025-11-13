#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define sc second
#define fr first

using namespace std;

typedef pair<pair<int,int>,int> pp;

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);
    //#ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    //#endif

	int n, q, x, cont = 0, ant = 0;
	cin >> q >> n;
	vector<int> s(n);
	vector<pp> v(q);
	
    cin >> s[0];
	for(int i = 1; i < n; i++){
		cin >> x;
		s[i] = s[i - 1] + x; //Vector creciente (con binaria no me anduvo)
	}
    reverse(s.begin(), s.end());
	
	for(int i = 0; i < q; i++){
		cin >> x;
		v[i] = {{x, 0}, i}; // ((cantidad, autos a llenar), indice de entrada)
	}
	sort(v.begin(), v.end(), [](pp a, pp b){return a.fr.fr < b.fr.fr;});
	
	for(int i = 0; i < q; i++){
		while(!s.empty() and v[i].fr.fr >= s.back()){
            ant = s.back();
			s.pop_back();
            cont++;
		}
		v[i].fr = {v[i].fr.fr - ant, cont};
	}
	
	sort(v.begin(), v.end(), [](pp a, pp b){return a.sc < b.sc;});
	for(int i = 0; i < q; i++){
		cout << v[i].fr.sc << ' ' << v[i].fr.fr << '\n';
	}
	
	return 0;
}



