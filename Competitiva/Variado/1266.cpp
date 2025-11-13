#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, pos = 0, cont, rta;
    bool flag, x;
    
    while(cin >> n and n != 0){
        vector<bool> palo(n);
        flag = rta = 0;
        pos = n;

        for(int i = 0; i < n; i++){
            cin >> x;
            palo[i] = x;
            if(!flag and x == 1){
                flag = true;
                pos = i; //Marcamos primer aparicion de poste
            }
        }

        if(pos == n){//No hay postes
            rta = n / 2 + (n & 1);
        }
        else{
            flag = false; cont = 1;
            rotate(palo.begin(), palo.begin() + pos, palo.end()); //Me aseguro de empezar con un poste

            for(int elem : palo){
                if(!elem and !flag){
                    flag = true;
                }
                else if(!elem and flag){
                    cont++;
                }
                else if(elem and flag){
                    flag = false;
                    rta += cont / 2;
                    cont = 1;
                }
            }
            rta += cont / 2;
        }

        cout << rta << endl;
    }

    return 0;
}