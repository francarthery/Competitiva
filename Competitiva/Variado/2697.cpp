#include <bits/stdc++.h>

using namespace std;

int main(){

    int k, n, x, cont = 0;
    string rta = "*";
    cin >> k >> n;

    map<int ,int> elem;
    map<int, vector<int>> cants;

    for(int i = 0; i < n; i++){
        cin >> x;
        elem[x]++; //Almaceno elementos con cant de apariciones
    }

    for(int i = 1; i <= k; i++){ //Cargo los elementos con 0 apariciones
        if(elem.find(i) == elem.end())
            elem[i] = 0;
    }

    for(auto i : elem)
        cants[i.second].push_back(i.first); //Numeros con cantidad cant.first de apariciones

    pair<int, vector<int>> c1 = *cants.begin();
    pair<int, vector<int>> c2;
    if(cants.size() > 1) c2 = *next(cants.begin(), 1); 


    if(n % k != 0 and cants.size() == 2){ //Solo hay dos grupos de cantidades de elementos

        if(c1.second.size() == 1 or c2.second.size() == 1){ //Si el de cantidad distinta es 1 solo
            if(abs(c2.first - c1.first) == 1){  //Si la diferencia en cantidades es solo 1
                if(c1.second.size() == 1){
                    rta = (c1.first > c2.first ? "-" : "+");
                    rta += to_string(c1.second.front());
                }
                else{
                    rta = (c2.first > c1.first ? "-" : "+");
                    rta += to_string(c2.second.front());
                }
            } 
        }
    }
    else if(n % k == 0 and cants.size() == 3){
        pair<int, vector<int>> c3 = *next(cants.begin(), 2);

        if(c1.second.size() == 1 and c3.second.size() == 1){ //Si o si los extremos van a estar mal
            if(abs(c1.first - c3.first) == 2){//La diferencia entre los extremos tiene que ser 2
                
                rta = '-';
                rta += to_string(c3.second.front());
                rta += " +";
                rta += to_string(c1.second.front());
            }
        }
    }

    cout << rta << endl;

    return 0;
}

/*
--Si k no es divisor de n hay que sumar o restar 1 o no hay solucion
--La suma o resta solo se puede usar si hay un solo elemento con 1 aparicion mas/menos que el resto
--Si hay 3 cantidades distintas si o si va suma y resta o no hay solucion
*/