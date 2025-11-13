#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int f(int &ini, string &s){
    int res = 0;

    while(isdigit(s[ini])){
        res *= 10;
        res += (s[ini++] - '0');
    }
    return res;
}

void parseo(string &s, vector<int> &padre){
    int ind = 0;
    vector<int> st{f(ind, s)};

    while(ind < sz(s)){
        if(s[ind] == ' ') {
            ind++;
            continue;
        }
        else if(s[ind] == '('){
            ind++;
            while(s[ind] == ' ') ind++;

            st.pb(f(ind, s));
            padre[st.back()] = st[sz(st) - 2];
        }
        else if(s[ind] == ')') {
            ind++;
            st.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string a, b; 
    getline(cin, a);
    getline(cin, b);
    
    vector<int> padre1(1e6 + 1), padre2(1e6 + 1);
    int ind1 = 0, ind2 = 0;
    
    parseo(a, padre1);
    parseo(b, padre2);
    //vdbg(padre1);vdbg(padre2);
    bool flag = (f(ind1, a) == f(ind2, b));
    forn(i, 1e6 + 1) if(padre1[i] != padre2[i]) flag = false;
    cout << (flag ? "Yes" : "No") << '\n'; 


    return 0;
}