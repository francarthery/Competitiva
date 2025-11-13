#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::string palabra;
    std::unordered_map<short, short> m;
    std::vector<std::pair<short,short>> v;
    bool prim = true;

    while(std::getline(std::cin, palabra)){
        if(!prim) std::cout << '\n'; prim = false;

        m.clear();
        for(char c : palabra) m[c]++;

        v.assign(m.begin(), m.end());
        std::sort(v.begin(), v.end(), [](std::pair<short,short> &x, std::pair<short,short> &y){
            if(x.second != y.second) return x.second < y.second;
            else return x.first > y.first;
        });

        for(std::pair<short,short> i : v){
            std::cout << i.first << ' ' << i.second << '\n';
        }

    }

    return 0;
}