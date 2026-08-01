#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0; i--)
#define sz(x) (int(x.size))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x <<" = "<<x<<endl;
#define vdbg(x) cout<<#x<<" = "; for(auto e : x) cout<<e<<' '; cout<<endl;
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int prg(int x){
    cout<<x<<endl;
    string s;cin>>s;
    return s == "yes";
}

void rta(int x){
    
    if(x >= 2 || x == 1000){
        cout<<"composite";
    } else {
        cout<<"prime";
    }
    cout<<endl;
}

int main(){

    vector<int> p = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};


    // cout<<p.size()<<endl;
    int cnt = 0;
    for(auto &e : p){
        cnt += prg(e);
    }

    if(prg(4) || prg(9) || prg(16) || prg(25) || prg(49)) cnt = 1000;

    rta(cnt);
    
    return 0;
}