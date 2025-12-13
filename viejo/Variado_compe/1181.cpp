#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<float> v(144);
    int n;
    char c;

    cin >> n >> c;

    for(int i = 0; i < 144; i++)cin >> v[i];
    
    cout << fixed << setprecision(1) << accumulate(v.begin() + 12*n, v.begin() + 12*(n + 1), 0) / (c == 'S' ? 1.0 : 12.0) << endl;

    return 0;
}