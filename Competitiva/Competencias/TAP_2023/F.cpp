#include <bits/stdc++.h>

using namespace std;

int tx, ty;

double dist(int x, int y){
    return sqrt(pow(x - tx, 2) + pow(y - ty, 2));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, w, l, x, y, p = 0;
    bool g = false; //true si gano a
    priority_queue<double, vector<double>, greater<double>> a, b;

    cin >> n >> w >> l >> tx >> ty;

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        a.push(dist(x, y));
    }
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        b.push(dist(x, y));
    }

    if(a.top() < b.top()){
        while(!a.empty() and a.top() < b.top()){
            p++;
            a.pop();
        } 
        g = true;
    }
    else{
        while(!b.empty() and a.top() > b.top()){
            p++;
            b.pop();
        }
    }

    if(g){
        cout << "A " << p << '\n';
    }
    else{
        cout << "R " << p << '\n';
    }

    return 0;
}