#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n;

    while(cin >> n, n){
        char x;
        vector<char> v1(n), v2(n);
        stack<char> st;
        forn(i, n) cin >> v1[i];
        forn(i, n) cin >> v2[i];

        //A la stack le tiro siempre todos los numeros. Si se puede hacer la permutacion, va a quedar vacia.
        
        int i = 0, j = 0; //Con uno controlo v2 y con el otro v1
        while(true){
            if(!st.empty() and st.top() == v2[i]){
                st.pop();
                i++;
                cout << 'R';
            }
            else if(j < n){
                st.push(v1[j]);
                j++;
                cout << 'I';
            }
            else break;
        }
        if(!st.empty()) cout << " Impossible";
        cout << '\n';
    }
    return 0;
}