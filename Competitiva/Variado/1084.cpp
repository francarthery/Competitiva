#include <bits/stdc++.h>

using namespace std;

int n, d;
string pal, rta;
vector<priority_queue<int, vector<int>, greater<int>>> m;

void f(int liminf, int limsup){
    int pos;

    if(rta.length() == n - d) return; //Si ya tengo el numero completo
    else{
        for (int i = 9; i >= 0; i--){
            if(m[i].empty()) continue;
            while(m[i].top() < liminf and m[i].top() < limsup) //Sacamos lo que no sirve mas
                m[i].pop();
            if(!m[i].empty() and m[i].top() <= limsup){ //Si encontre un digito
                rta += (i + '0');
                pos = m[i].top();
                m[i].pop();
                break;
            }
        }
        
        f(pos + 1, limsup + 1);
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(cin >> n >> d and (n or d)){
        cin >> pal;
        m.assign(10, priority_queue<int, vector<int>, greater<int>>());
        
        for(int i = 0; i < pal.length(); i++){
            m[pal[i] - '0'].push(i);
        }

        rta = "";
        f(0, d);

        cout << rta << endl;
    }
    
    return 0;
}