#include <iostream>
#include <vector>
using namespace std;

int main(){

    //Array de longitud dinámica
    vector <int> cont;

    for(int i=0; i<10; i++){
        cont.push_back(i);
    }

    for (int i : cont)
        cout << i << endl;

    return 0;
}