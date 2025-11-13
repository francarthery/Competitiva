#include<bits/stdc++.h>

#define forr(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define sz(a) ((int)(a.size()))
#define all(a) a.begin(), a.end()
#define dbg(x) cout << #x <<" "<< x << endl;
#define ws <<" "<<
#define nl cout << "\n";
typedef long long ll;

using namespace std;

int main(){

    #ifdef fran
        freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int min; cin >> min;

    if(min <= 360){
        cout << 0;nl;
        return 0;
    }
    else if(min <= 390){
        cout << min - 360;nl;
        return 0;
    }
    if(min<=570){
        cout << 30;nl;
        return 0;
    }
    if(min <= 585){
        cout << 30 + min - 570;nl;
        return 0;
    }
    if(min<=645){
        cout << 45;nl;
        return 0;
    }
    else {
        cout << 45 + min - 645;nl;
        return 0;
    }

    return 0;
}