#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1; i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<" "; cout<<endl;}
#define nl cout<<"\n";
#define ws <<" "<<

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    string s, t; cin >> s >> t;
    
    bool automa = false, ar = false, tree = false;

    if(sz(s) > sz(t)) automa = true;
    else if(sz(t) > sz(s)){
        cout << "need tree";
        return 0;
    }

    if(s.find(t) != -1){
        cout << "automaton";
        return 0;
    }

    bool soloauto = 0;
    forn(i, sz(s)){
        int ind = 0;
        forr(j,i,sz(s)){
            if(s[j] == t[ind]) ind++;
            if(ind == sz(t)) {
                soloauto=1;
                break;
            }
        }
        if(soloauto){
            cout<<"automaton";nl;
            return 0;
        }
    }
    

    vector<int> freq1(26), freq2(26);
    for(auto e : s) freq1[e - 'a']++;
    for(auto e : t) freq2[e - 'a']++;

    forn(i, 26){
        if(freq1[i] < freq2[i]){
            cout << "need tree";
            return 0;
        }
    }

    if(automa){
        cout << "both";
    }else{
        cout << "array";
    }
    
    return 0;
}