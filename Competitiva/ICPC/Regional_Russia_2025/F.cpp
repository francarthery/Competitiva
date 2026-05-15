#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define ws <<" "<<
#define nl cout<<"\n";
#define vdbg(x) for(auto &e: x) cout<<"[";for(auto e : x) cout<<e<<" "; cout<< "]"<<endl;
#define dbg(x) cout<<#x ws "=" ws x<<endl;



using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran 
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif

    int n; cin >> n;
    
    int filas = 0, level = 18, filasM = 130;
    ll ptos = 0;

    map<string, ll> ptitos, fila;
    ptitos["single"] = 760, fila["single"] = 1;
    ptitos["double"] = 1900, fila["double"] = 2;
    ptitos["triple"] = 5700, fila["triple"] = 3;
    ptitos["tetris"] = 22800, fila["tetris"] = 4;

    forn(i, n){
        if(filas >= filasM){
            filasM+= 10;
            ptitos["single"]+= 40;
            ptitos["double"]+= 100;
            ptitos["triple"]+= 300;
            ptitos["tetris"]+= 1200;
            level++;
        }
        string s; cin >> s;
        filas+= fila[s];
        ptos+= ptitos[s];
    }

    if(filas >= filasM){
            filasM+= 10;
            ptitos["single"]+= 40;
            ptitos["double"]+= 100;
            ptitos["triple"]+= 300;
            ptitos["tetris"]+= 1200;
            filas = 0;
            level++;
        }

    cout << ptos << ' ' << level << '\n';

    return 0;
}