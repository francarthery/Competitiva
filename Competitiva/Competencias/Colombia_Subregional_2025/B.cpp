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

    int n, m; cin >> n >> m;
    vector<string> tab(n, string(m, '.'));
    set<ii> posi, posf;

    char c;
    forn(i, n) forn(j, m){
        cin >> c;
        if(c == 'X') posi.insert({i, j});
        else tab[i][j] = c;
    }

    forn(i, n) forn(j, m){
        cin >> c;
        if(c == 'X') posf.insert({i, j});
    }

    function<ii(int, ii, set<ii>&)> f = [&](int dir, ii pos, set<ii>& ball) -> ii {
        int mi = 0, mj = 0, cont = 0;
        while(tab[pos.fr + mi][pos.sc + mj] != '#') { //0 der, 1 izq, 2 arriba, 3 abajo
            if(dir == 0) mj++;
            else if(dir == 1) mj--;
            else if(dir == 2) mi--;
            else if(dir == 3) mi++;

            if(pos.fr + mi >= n or pos.fr + mi < 0 or pos.sc + mj >= m or pos.sc + mj < 0 or tab[pos.fr + mi][pos.sc + mj] == '#') break;
            if(ball.count({pos.fr + mi, pos.sc + mj})) cont++;
        }

        if(dir == 0) mj--;
        else if(dir == 1) mj++;
        else if(dir == 2) mi++;
        else if(dir == 3) mi--;

        if(dir == 0) pos.sc = pos.sc + mj - cont;
        else if(dir == 1) pos.sc = pos.sc + mj + cont;
        else if(dir == 2) pos.fr = pos.fr + mi + cont;
        else pos.fr = pos.fr + mi - cont; 
        return pos;
    };

    queue<set<ii>> q;
    set<set<ii>> vis;
    q.push(posi);
    vis.insert(posi);

    while(sz(q)){
        set<ii> ball = q.front();
        q.pop();

        forn(i, 4){
            set<ii> ballmov; //bolas movidas
            for(ii j : ball) ballmov.insert(f(i, j, ball));
            if(vis.count(ballmov)) continue;
            vis.insert(ballmov);
            q.push(ballmov);
        }
    }

    cout << (vis.count(posf) ? "YES" : "NO") << '\n';




    return 0;
}