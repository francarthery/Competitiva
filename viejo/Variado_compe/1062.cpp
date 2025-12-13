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
    
    int n, x;

    while(cin >> n, n){
        while(cin >> x, x){
            int m = 1;
            stack<int> st;
            bool flag = true;
            while(x >= m){
                st.push(m);
                m++;
            }
            st.pop();

            forr(i, 1, n){
                cin >> x;
                if(!flag) continue;
                if(m <= x){
                    while(x >= m){
                        st.push(m);
                        m++;
                    }
                }
                
                if(st.top() == x) st.pop();
                else{
                    flag = false;
                }
            }
            cout << (flag ? "Yes\n" : "No\n");
        }
        cout << '\n';
    }
    return 0;
}