#include <bits/stdc++.h>
using namespace std;

/* void iniciar_criba(vector<int> &prim){
	
	for(int i = 0; i <= prim.size(); i++)prim[i] = i;
	
	prim[0] = prim[1] = -1;
	
	for(int i = 2; i * i <= prim.size(); i++)
		if(prim[i] == i)
			for(int j = i + i; j <= prim.size(); j += i)
				prim[j] = i;
}
	
void fp(vector<int> &  prim, vector<pair<int, int>> &factores, int N){
	
	if(N <= 1) return;
	if(!factores.empty() and factores.back().first == prim[N])
		factores.back().second++;
	else
		factores.push_back(make_pair(prim[N], 1));
	
	fp(prim, factores, N / prim[N]);
	
} */

void factors(long long n, map<int, int> &f){ //O(sqrt(n))
	f.clear();
	int cont = 0;
	for(int x = 2; x*x <= n; x++){
		while(n % x == 0){
			f[x]++;
			n /= x;
		}
	}
	cout << cont << '\n';
	if(n > 1) f[n]++;
}

int main() {
	
	long long n;
	cin >> n;
	map<int, int> f;
	factors(n, f);

	for(auto i: f) cout << i.first << ' ' << i.second << '\n';
	
	return 0;
}

