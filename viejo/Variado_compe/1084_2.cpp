#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, d;
    while(cin >> n >> d and (n or d)){
        string s;
        cin >> s;

        stack<char> st;

        for(char e : s){
            while(d and !st.empty() and st.top() < e){ //Si todavía tengo intentos, cambio el tope por un elem mas grande
                d--;
                st.pop();
            }
            st.push(e);
        }

        while(d){
            d--;
            st.pop();
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }

    return 0;
}