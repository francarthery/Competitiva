#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
	int n, lim;

	while(cin >> n and n != 0){
		int m[n][n];
		lim = n / 2 + (n & 1);
		n--;
	
		for(int i = 0; i < lim; i++){
			for(int j = 0; j < lim; j++){
				m[i][j] = m[i][n - j] = m[n - i][j] = m[n - i][n - j] =  lim - max(abs(lim - 1 - i), abs(lim - 1 - j));;
			}
		}
		
        n++;
		for(int i = 0; i < n; i++){
			cout << setfill(' ') << setw(3) << m[i][0];
			for(int j = 1; j < n; j++){
				cout << setw(4) << m[i][j];
			}
			cout << '\n';
		}
		cout << '\n';
	}
	
	return 0;
}