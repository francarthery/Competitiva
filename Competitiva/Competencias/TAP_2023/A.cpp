#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
 
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    vector<int> e(m);
    for(int i = 0; i < m; i++) cin >> e[i];

    int mn = e[0];
    for(int i = 0; i < m; i++){
        e[i] = mn = min(mn, e[i]); //Hago que los empleados sean descendentes (Si x < x+1, vuelo x+1)
    }
    
    vector<int>::iterator elem, fin = unique(e.begin(), e.end());
 
    for(auto x : a){
        while(x > 0 and x >= *(fin - 1)){
            elem = lower_bound(e.begin(), fin, x, [](int a, int b){return a > b;});
            if(elem != fin) x %= *elem;
        }
        cout << x << ' ';
    }
    cout << '\n';
 
    return 0;
}