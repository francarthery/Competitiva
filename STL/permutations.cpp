#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> permutation;

    for(int i = 0; i < n; i++) permutation.push_back(i);

    do{
        for(int i = 0; i < n; i++) cout << permutation[i] << " ";
        cout << endl;
    }
    while(next_permutation(permutation.begin(), permutation.end()));

    return 0;
}