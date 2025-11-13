#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long double n, t, x, tamp = 0, tamn = 0;
    long double clock = 0, wp, wn, tp, tn;
    char c;
    cin >> n >> t;

    vector<double> pri, nop;

    for(int i = 0; i < n; i++){
        cin >> c >> x;
        if(c == 'P'){
            pri.push_back(x);
            tamp++;
        }
        else{
            nop.push_back(x);
            tamn++;
        }
    }

    sort(pri.begin(), pri.end(), greater<double>());
    sort(nop.begin(), nop.end(), greater<double>());

    while(!nop.empty() and !pri.empty()){
        tp = (t * 0.75) / tamp;
        tn = (t * 0.25) / tamn;
        wp = pri.back() / tp;
        wn = nop.back() / tn;

        if(wp < wn){
            clock += wp;
            pri.pop_back();
            tamp--;
        }
        else if(wp > wn){
            clock += wn;
            nop.pop_back();
            tamn--;
        }
        else{
            clock += wn;
            pri.pop_back();
            tamn--;
            nop.pop_back();
            tamp--;
        }

        wp = min(wp, wn);

        for(double &i : pri){
            i -= wp * tp;
        }
        for(double &i : nop){
            i -= wp * tn;
        }
    }

    while(!pri.empty()){
        tp = t / tamp;
        wp = pri.back() / tp;
        clock += wp;
        pri.pop_back();
        tamp--;
        for(double &i : pri){
            i -= wp * tp;
        }
    }

    while(!nop.empty()){
        tn = t / tamn;
        wn = nop.back() / tn;
        clock += wn;
        nop.pop_back();
        tamn--;
        for(double &i : nop){
            i -= wn * tn;
        }
    }

    cout << clock << '\n';

    return 0;
}