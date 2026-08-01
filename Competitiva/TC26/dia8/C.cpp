#include <bits/stdc++.h>

#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ws <<" "<<
#define nl cout<<"\n";
#define dbg(x) cout<<#x ws "=" ws x<<endl;
#define vdbg(x) {cout<<#x<<" = "; for(auto e : x) cout<<e<<' ';cout<<endl;}

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef fran
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif

    vector<string> s(3);
    forn(i,3) cin>>s[i];

    auto redu = [&] (string &a, string &bb) -> int{
        string s = bb+'$'+a;
        // dbg(s);
        vector<int> b(sz(s)+1);
        b[0] = -1;
        int j = -1;
        forn(i,sz(s)){
            while(j >= 0 && s[i] != s[j]) j = b[j];
            b[i+1] = ++j;
        }
        // vdbg(b);
        return b.back();
    };

    vector<int> ind = {0,1,2};

    auto check = [&] () -> int {
        string a, b, c;
        a=s[ind[0]];
        b=s[ind[1]];
        c=s[ind[2]];

        int cnt1=redu(a,b);
        int cnt2=redu(b,c);
        // cout<<a ws b;nl;
        // dbg(cnt1);

        if(cnt1 + cnt2 >= sz(b)){  
            if(cnt1 < sz(b)) a = a+b.substr(cnt1);
            int cnt3 = redu(a,c);
            return sz(a) + sz(c) - cnt3;
        }
        return sz(a) + sz(b)+sz(c) - cnt2 - cnt1;
    };

    int rta = 0;


    forn(i,3) rta += sz(s[i]);
    do{
        rta = min(rta, check());
    }while(next_permutation(all(ind)));

    int n = 3;
    sort(all(s), [&] (string &a, string &b) -> bool {
        return sz(a) > sz(b);
    });

    if(s[1].find(s[2]) != s[1].npos){
        n--;
        s.pop_back();
    }
    if(n >= 3 && s[0].find(s[2]) != s[0].npos){
        n--;
        s.pop_back();
    }
    if(n >= 2 && s[0].find(s[1]) != s[0].npos){
        n--;
        s.erase(s.begin()+1);
    }
    if(n == 1)rta = min(rta,sz(s[0]));
    else if(n == 2){
        int cnt = redu(s[0], s[1]);
        // cout<<s[0] ws s[1]<<endl;
        // dbg(cnt);
        rta = min(rta, sz(s[0])+sz(s[1])-cnt);
        cnt = redu(s[1],s[0]);
        // dbg(cnt);
        rta = min(rta, sz(s[0])+sz(s[1])-cnt);
    }
    // vdbg(s);


    cout<<rta<<endl;
    return 0;
}