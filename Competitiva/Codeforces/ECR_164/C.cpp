#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, s;
    cin >> t;

    for(int i = 0; i < t; i++){
        string a, b;
        s = 0;
        cin >> a >> b;

        for(int i = 0; i < a.size(); i++){
            if(!s){
                if(a[i] > b[i])s = 1;
                else if(a[i] < b[i]){
                    swap(a[i], b[i]);
                    s = 1;
                } 
            }
            else{
                if(a[i] > b[i]) swap(a[i], b[i]);
            }
        }

        cout << a << '\n' << b << '\n';
    }

    return 0;
}