#include<iostream>
#include<algorithm>
#pragma GCC optimize("Ofast")

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string palabra;
    bool prim = true;

    while(std::getline(std::cin, palabra)){
        if(!prim) std::cout << '\n'; prim = false;

        std::pair<short, short> frecuencia[129];
        for(int i = 32; i < 129; i++) frecuencia[i].second = i;
        for(char &i : palabra) frecuencia[i].first++;

        std::sort(frecuencia + 32, frecuencia + 129, [](std::pair<short,short> &x, std::pair<short,short> &y){
            if(x.first != y.first) return x.first < y.first;
            else return x.second > y.second;
        });

        for(short i = 33; i < 129; i++){
            if(frecuencia[i].first != 0) std::cout << frecuencia[i].second << ' ' << frecuencia[i].first << '\n';
        }
    }
}