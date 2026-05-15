#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define forall(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string s1, s2, t1, t2;
    cin >> s1 >> t1 >> s2 >> t2;
    map<string, int> dias{{"Mon", 1}, {"Tue", 2}, {"Wed", 3}, {"Thu", 4}, {"Fri", 5}, {"Sat", 6}, {"Sun", 7}};

    int d1 = dias[s1];
    int d2 = dias[s2];
    int h1 = stoi(t1.substr(0, 2));
    int h2 = stoi(t2.substr(0, 2));
    int m1 = stoi(t1.substr(3, 2));
    int m2 = stoi(t2.substr(3, 2));

    int d3 = d2 - d1;
    int h3 = h2 - h1;
    int m3 = m2 - m1;

    if(m3 < 0) m3 += 60, h3--;
    if(h3 < 0) h3 += 24, d3--;
    if(d3 < 0) d3 += 7;
    if(!m3 and !h3 and !d3) d3 += 7;

    if(d3) {
        cout << d3 << (d3 > 1 ? " days" : " day");
        if((h3 or m3) and !(h3 and m3)) cout << " and ";
        else if(h3 and m3) cout << ", ";
    }

    if(h3) {
        cout << h3 << (h3 > 1 ? " hours" : " hour");
        if(!d3 and m3) cout << " and ";
        else if(d3 and m3) cout << ", ";
    }
    if(m3) cout << m3 << (m3 > 1 ? " minutes" : " minute");
    cout << '\n';


    return 0;
}