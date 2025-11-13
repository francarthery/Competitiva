#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())

using namespace std;

vector<pair<int,int>> sol, pares;
vector<int> v;
int n, rta = 0, maxm;

void op(int l, int r){
    pares.clear();
    pares.pb({l, l}); //Caso base
    int cont = 1;
    
	forn(i, r - l + 1){ //Genero todas las operaciones
        forn(j, cont - 1){
            pares.pb(pares[j]);
        }
        pares.pb({l, (pares[cont - 1].second) + 1}); //El ultimo elemento aumenta en 1
        cont *= 2;
	}
    pares.back().second--;

    cont = 0;
    forr(i, l - 1, r){ //Solo uso las operaciones que se necesitan
        if(v[i] == i - l + 1) cont += (1LL << i - l + 1); //Si tengo el digito en la posicion i (de 0 a n - 1) me salto 2^i digitos
        else{
            while(cont < (1LL << i - l + 2) - 1){
                sol.pb(pares[cont]);
                cont++;
            }
        }
    }
    sol.pb(pares.back());
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	#ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
  
	int ini, sum;
    cin >> n;
    v.resize(n);
    forn(i, n) cin >> v[i];

    forn(m, 1LL << n){ //Bitmask
        bool ant = false;
        sum = 0;

        forn(i, n){
            if(m & (1 << i)){ //Cuento los intervalos donde tengo que aplicar mex
                if(!ant){
                    ini = i;
                    ant = true;
                }
            }
            else{
                sum += v[n - i - 1]; //Elemento al que no le aplico mex
                if(ant){
                    sum += pow(i - ini, 2); //sumo la longitud del intervalo donde aplico mex al cuadrado
                    ant = false;
                }
            }
        }
        if(ant)sum += pow(n - ini, 2);
        
        if(sum > rta){
            rta = sum;
            maxm = m; //Combinacion con mayor suma total
        }
    }
	
	bool ant = false;
	for(int i = n - 1; i >= 0; i--){
		if(maxm & (1 << i)){ //Cuento los intervalos donde tengo que aplicar mex
			if(!ant){
				ini = n - 1 - i;
				ant = true;
			}
		}
		else{
			if(ant){
				op(ini + 1, n - 1 - i); 
				ant = false;
			}
		}
	}
	if(ant) op(ini + 1, n); 

    cout << rta << ' ' << sz(sol) << '\n';
    forall(it, sol) cout << it -> first << ' ' << it -> second << '\n';

    return 0;
}