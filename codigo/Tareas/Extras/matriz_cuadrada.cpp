#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int N, matriz[50][50], cent_x, cent_y;
	
	cin >> N;
	
	cent_x = cent_y = N / 2 - (N % 2 == 0);

	for(int i = 0; i <= cent_y; i++){
		for(int j = 0; j <= cent_x; j++){
			matriz[i][j] = matriz[i][N - 1 - j] = matriz[N - 1 - i][j] =  matriz[N - 1 - i][N - 1 - j] = cent_x + 1 - max(cent_x - j, cent_y - i);
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}

