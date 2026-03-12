#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) forr(i,0,n)
#define sz(stru) (int(stru.size()))
#define all(stru) stru.begin(), stru.end()
#define dbg(x) cout<<#x<<" "<<x<<" ";
#define ws <<" "<<
#define nl cout<<"\n";
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int N=2e5+10;
int SQR=round(sqrt(N));
vector<deque<int>> vec;

void insert(int i, int x}{
    int num_dq = i/SQR;
    int num_ar = i%SQR;
    vec[num_dq].insert(vec[num_dq].begin()+num_ar, x);
    while(sz(vec[num_dq])>SQR){
        if(num_dq+1>=sz(vec)){
            vec.push_back(deque<int>());
        }
        while(sz(vec[num_dq])>SQR){
            vec[num_dq+1].push_front(vec[num_dq].back());
            vec[num_dq].pop_back();
        }
        num_dq++;
    }
}

void del(int i){
    int num_dq = i/SQR;
    int num_ar = i%SQR;
    vec[num_dq].erase(vec[num_dq].begin()+num_ar);
    while(sz(vec)==SQR-1){
        if(num_dq+1>=sz(vec)){
            break;
        }
        while(sz(vec[num_dq])<SQR){
            vec[num_dq].push_back(vec[num_dq+1].front());
            vec[num_]
        }
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}