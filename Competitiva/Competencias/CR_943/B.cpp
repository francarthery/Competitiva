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
    
    int t, n, m; cin >> t;
    while(t--){
        cin >> n >> m;
        string p1, p2;
        stack<char> st;
        int rta = 0;

        cin >> p1 >> p2;
        reverse(p2.begin(), p2.end());
        for(char c : p2) st.push(c);
        
        forn(i, n){
            while(!st.empty() and st.top() != p1[i]){
                st.pop();
            }

            if(!st.empty() and st.top() == p1[i]){
                rta++;
                st.pop();
            }
            else{
                break;
            }
        }
        cout << rta << '\n';
    }

    return 0;
}