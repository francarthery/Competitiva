#include <iostream>
using namespace std;

int main() {
  
    int C, P, H, pancho;

    cin >> C >> P >> H;

    pancho = P + (C % (H+1));

    cout << pancho << endl;
    
    return 0;
}