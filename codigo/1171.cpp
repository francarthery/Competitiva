#include <iostream>
#include <array>
 
using namespace std;
 
int main() {
 
    int N, X, cont=1;

    cin >> N;

    int RTA[N][2];

    for(int i = 0; i < N; i++){
        cin >> X;
        for (int j = 0; j < cont; j++){
            if(RTA[j][0] == X)
                RTA[j][1] += 1;

            else{
                RTA[cont-1][0]=X;
                RTA[cont-1][1]=1;
                cont++;
                }
        }  
    }

    for (int i = 0; i < cont; i++){
        cout << RTA[i][0] << " aparece " << RTA[i][1] << " vez(es) " << endl;
    }
    
 
    return 0;
}