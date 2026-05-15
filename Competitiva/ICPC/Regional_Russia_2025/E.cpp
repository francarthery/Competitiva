#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define dfor(i,n) for(int i=n-1;i>=0;i--)
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
#define ws <<" "<<
#define nl cout<<"\n";
#define vdbg(x) for(auto &e: x) cout<<"[";for(auto e : x) cout<<e<<" "; cout<< "]"<<endl;
#define dbg(x) cout<<#x ws "=" ws x<<endl;



using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran 
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif

    string s; cin >> s;
    int cont = 0,ind = 0;
    while(s[ind++] == '(') cont++;
    int aux = cont;
    while(ind < sz(s) and cont){
        if(s[ind] == '-' and cont > aux) s[ind] = '+';
        else if(s[ind] == '+' and cont == aux) s[ind] = '-';
        else if(s[ind] == '(') cont++;
        else if(s[ind] == ')') cont--;
        if(cont < aux) aux--;
        ind++;
    }

    forr(i, ind, sz(s)){
        if(s[i] == '('){
            cont++;
        }else if(s[i] == ')'){
            cont--;
        }else{
            if(s[i] == '-' and cont) s[i] = '+';
            else if(s[i] == '+' and !cont) s[i] = '-';
        }

    }
    
    cout << s << '\n';

    return 0;
}