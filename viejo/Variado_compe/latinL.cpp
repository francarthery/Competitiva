#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int r, c, k;

    cin >> r >> c >> k;

    vector<string> v1(r), v2(r);
    vector<bool> f1(r), f2(r); 

    for(int i = 0; i < r; i++){
        cin >> v1[i] >> v2[i];
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(v1[i][j] == '-'){
                f1[i] = true;
                break;
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < k; j++){
            if(v2[i][j] == '*'){
                f2[i] = true;
                break;
            }
        }
    }

    for(int i = 0; i < r; i++){
        if(f1[i] and f2[i]){
            cout << "N\n";
            return 0;
        }
    }

    cout << "Y\n";

    return 0;
}