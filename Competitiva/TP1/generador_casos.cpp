#include <bits/stdc++.h>

using namespace std;

int main(){
    
    ofstream archivo("input.in");
    srand(time(NULL));
    for(int j = 1; j < (1 << 11); j *= 2){
        string pal1, pal2;
        for(int i = 0; i < j * 100; i++){
            pal1 += char(rand() % 10 + '0'); //Entrada 1
            pal2 += char(rand() % 10 + '0'); //Entrada 2
        }
        archivo << pal1 << '\n' << pal2 << "\n\n";
    }
    
    return 0;
}
