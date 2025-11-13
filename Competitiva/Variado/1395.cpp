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
    cout << '['; for(auto c : v) cout << c << ','; cout << "\b]\n";
}

typedef long long ll;
typedef tuple<int, int, int, char> iic; //(operador1, operador2, resultado, operando)

vector<iic> res;
vector<char> simbolos{'+', '-', 'x', '/'};
int t, cont, cont2;

void f(vector<int> &op, vector<iic> &term, int res_par){
    cont++;
    if(!res.empty() and res.size() < term.size()) return;
    if(res_par == t and !term.empty()){ //Tengo que tener minimo dos operandos
        if(res.empty()) res = term;
        else{
            forn(i, term.size()){
                
            }
            res = term; //Cambiar
        }
        return;
    }
    if(op.empty()) return; //Si me quede sin operandos termino

    int ope = op.back();
    double temp = 0;
    op.pop_back(); //Saco el ultimo operador
    
    cont2++;
    forn(i, 4){ //4 llamadas recursivas con los 4 operadores.
        if(i == 0) temp = res_par + ope;
        else if(i == 1) temp = res_par - ope;
        else if(i == 2) temp = res_par * ope;
        else temp = (float)res_par / ope;

        if(temp == int(temp) and temp >= 0){ //Si el resultado parcial da con coma o negativo hasta ahi llegue
            term.pb({res_par, ope, temp, simbolos[i]}); //Cargo nueva operacion
            f(op, term, temp); //envio nuevo resultado parcial
            term.pop_back();
        }
    }
    
    op.pb(ope);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
        auto inicio = chrono::high_resolution_clock::now(); //Obtener tiempo de inicio
    #endif

    int n, prim;

    while(cin >> t, t != 0){
        cont = cont2 = 0; //Borrar
        cin >> n;
        res.clear();
        vector<int> op(n);
        vector<iic> term;
        forn(i, n) cin >> op[i];
        sort(all(op));

        do{ //Todas las posibles ordenaciones de numeros
            prim = op.back();
            op.pop_back();
            f(op, term, prim); //Le mando el primer operando como resultado parcial
            op.pb(prim);
        }
        while(next_permutation(all(op)));

        dbg(cont);
        dbg(cont2);
        if(res.empty()) cout << "No solution\n";
        else{
            forn(i, res.size()) {
                auto [x, y, z, op] = res[i];
                cout << x << ' ' << op << ' ' << y << " = " << z;
                cout << (i == res.size() - 1 ? " <-" : "") << '\n';
            }
        }
    }

    #ifdef fran
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio; // Calcular la duración
        cout << "El tiempo de ejecucion es: " << fixed << setprecision(10) << duracion.count() << " segundos" << '\n';
    #endif
    
    return 0;
}