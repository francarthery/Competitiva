#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define prq priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define fr first
#define sc second

using namespace std;

template<class x> void vdbg(vector<x> &v){
    cout << '['; for(auto c : v) cout << c << ','; cout << "]\n";
}

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string s; cin >> s;
    string aux; 

    int cont = 1;
    aux += s[0];
    forr(i, 1, sz(s)){
        aux += s[i];
        if(s[i] == ')') cont--;
        else cont++;
        if(!cont) break;
    }

    string aux2 = "(";
    cont = 1;
    bool flag = true;
    forr(i, sz(aux) + 1, sz(s)){
        aux2 += s[i];
        if(s[i] == ')') cont--;
        else cont++;
        if(!cont and aux2 != aux){
            flag = false;
            break;
        }
        else if(!cont and aux2 == aux){
            aux2 = "";
        }
    }

    if(flag){
        cout << "no";
    }else{
        cout << s.substr(sz(aux)) << aux << '\n';
    }

    return 0;
}