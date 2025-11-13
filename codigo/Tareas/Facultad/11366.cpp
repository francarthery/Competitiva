#include <iostream>

using namespace std;

int main() {
 
    int N, A, B;

    cin >> N >> A >> B;

    if (N < 1000){
        while(N < 1000){
            if(N % 2 == 0){
                for(int i = 1; i <= A; i++){
                    N += i;
                }
            }
            else{
                for(int i = 1; i <= B; i++){
                    N += i;
                }
            }
        }
    }

    cout << N << endl;
    
    return 0;
}