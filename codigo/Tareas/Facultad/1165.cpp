#include <iostream>
#include <cmath>
 
using namespace std;

void primo(int X);
 
int main() {

    int N, X;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> X;
        primo(X);
    }
 
    return 0;
}

void primo(int X){
    bool primo = false;
    for(int i = 2; i < sqrt(X); i++){
        if(X % i == 0){
            i = X;
            primo = true;
        }  
    }
    if(primo == true)
        cout << X << " nao eh primo" << endl;
    else
        cout << X << "eh primo" << endl;
}