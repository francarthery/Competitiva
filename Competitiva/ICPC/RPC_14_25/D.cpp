#include <bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) forr(i,0,n)
#define dfor(i, n) for(int i = n - 1; i >= 0; i--)
#define sz(a) ((int)a.size())
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x << " = " << (x) << endl
#define vdbg(x) {cout << '['; for(auto i : x) cout << i << ", "; cout << "]\n";}
#define ws <<' '<<
#define nl cout << '\n';

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
	
	vector<int> v(3);
	forn(i,3) cin>>v[i];
	auto ori=v;
	sort(all(v));

    auto valor = [&](string a, string b){
        if(a > b) swap(a, b);
        if(a == string(sz(a), 'a') and b == string(sz(b), 'b')) return v[0];
        else if(a == string(sz(a), 'a') and b != string(sz(b), 'b')) return v[1];
        else return v[2];
    };
	
	auto rta = [&](string a, string b, string c){
		cout<<"Yes";nl;
		string s[3];
        vector<int> pos{1, 2, 3};
        do{
            forn(i, 3){
                if(pos[i] == 1) s[i] = a;
                if(pos[i] == 2) s[i] = b;
                if(pos[i] == 3) s[i] = c;
            }

            if(valor(s[0], s[1]) == ori[0] and valor(s[0], s[2]) == ori[1] and valor(s[1], s[2]) == ori[2]) break;
            
        }while(next_permutation(all(pos)));
        
        forn(i,3)cout<<s[i]<<' ';
        nl;
	};
	
	if(v[0]+v[1]<v[2]){
		cout<<"No";nl; 
		return 0;
	}
	
	if(v==vector<int>{0,0,0}){
        cout << "Yes\n"; //Perdon
		cout<< "a a a";nl;
		return 0;
	} 

    string a,b,c;
	if(v[0]==0){
        cout << "Yes\n"; //Perdon
		string a="a",b="a";
		string c;
		forn(i,v[2])c+="b";
		if(ori[0]==v[0]){
			cout<< a ws b ws c;nl;
		} else if(ori[1]==v[0]){
			cout<< a ws c ws b;nl;
		} else cout<< c ws a ws b<<endl;
		return 0;
	}
    
	forn(i,v[0]){
		a+='a';
		b+='b';
	}
	
	forn(i,v[2]-v[1]){
		c+='a';
	}
	
	forn(i,v[1]){
		c+='c';
	}
	
	rta(a,b,c);
	
	return 0;
}