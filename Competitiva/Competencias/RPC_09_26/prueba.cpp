#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int n; 
    while(cin >> n and n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << setw(3) << setfill(' ') << min({i, j, n-1-i, n-1-j}) + 1;
                if(j != n-1) cout << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    
    return 0;
}