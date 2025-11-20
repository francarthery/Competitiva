#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int t, n, p, dist, m, x;
    cin >> t;
 
    for(int i = 0; i < t; i++){
        cin >> n;
        dist = 1; m = n;
        bool b = false;
        
        cin >> p;
 
        for(int i = 1; i < n; i++){
            cin >> x;
            if(x == p){
                dist++;
            }
            else{
                m = min(m, dist);
                dist = 0;
                b = true;
            }
        }
        m = min(m, dist);
        cout << (b ? m : -1) << '\n';
    }

    return 0;
}