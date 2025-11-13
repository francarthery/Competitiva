#include<bits/stdc++.h>

using namespace std;

int main(){
    
    string cad;

    while(cin >> cad){
        deque<pair<int, int>> scads;
        int ini = -1;
        bool ult = true;

        for(int i = 0; i < cad.size(); i++){
            if(cad[i] == '[' or cad[i] == ']'){
                if(i > ini + 1){
                    if(!ult)scads.push_front({ini + 1, i - 1});
                    else scads.push_back({ini + 1, i - 1});
                }
                ini = i;
                ult = (cad[i] == '[' ? false : true);
            }
        }

        if(cad.size() > ini + 1){
            if(!ult)scads.push_front({ini + 1, cad.size() - 1});
            else scads.push_back({ini + 1, cad.size() - 1});
        }

        if(!scads.empty()){
            for(auto i : scads){
                cout << cad.substr(i.first, i.second - i.first + 1);
            }
            cout << endl;
        }
    }

    return 0;
}