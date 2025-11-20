#include <bits/stdc++.h>

using namespace std;

vector<long long int> ni, pr;

bool valid(int m){
    long long int sum = 0;
    for(int i = 0; i < pr.size() - 1; i++){
        if(pr[i] + sum >= ni[i] * m)
            sum = (pr[i] + sum - ni[i] * m);
        else
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long int n, x, totn = 0, totp = 0, ma = 0;
    cin >> n;

    ni.resize(n);
    pr.resize(n + 1);

    for(int i = 0; i < n; i++){
        cin >> x;
        ni[i] = x;
        totn += x;
    }
    
    for(int i = 0; i < n; i++){
        cin >> x;
        pr[i] = x;
        totp += x;
    }

    ma = totp / totn + 10;
    
    int l = 0, r = ma, m;
    while(l < r){
        m = (l + r) / 2;
        if(!valid(m)) r = m;
        else l = m + 1;
    }

    cout << l - 1 << '\n';
    
    return 0;
}