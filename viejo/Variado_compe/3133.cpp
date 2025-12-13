#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define sc second
#define fr first 

typedef pair<int, int> pp;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n, x, y, rta = 0;
    priority_queue<pp> pq1;
    priority_queue<pp, vector<pp>, greater<pp>> pq2;

    cin >> n;
    forn(i, n){
        cin >> x >> y;
        pq1.push({x, -y});
        pq2.push(y);
    }

    forn(i, n){
        if(pq1.top() > pq2.top()){
            rta += pq1.top() - pq2.top();
        }
        else if(pq1.top() < pq2.top()){
            rta += pq2.top() - pq1.top();
        }
        else{

        }
        pq1.pop();
        pq2.pop();
    }




    return 0;
}