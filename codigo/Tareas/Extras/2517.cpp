#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void resolvente(float &x0, float &x1, float A, float B, float C){
	
	x0 = (-B + sqrt(pow(B, 2) - 4 * A * C)) / (2 * A);
	x1 = (-B - sqrt(pow(B, 2) - 4 * A * C)) / (2 * A);
}

int main() {
	
	int A, B, C, xc, yc, D;
	
	while(cin >> A >> B >> C >> xc >> yc >> D){
		
		float m, b, x0, x1, y0, y1, dist;
	
		m = float(D) / C;
		b = yc - m * xc;

		resolvente(x0, x1, -1.0 / A , -1.0 / B - m, C - b);

		y0 = -pow(x0, 2) / 10.0 - x0 / 2.0 + 5;
		y1 = -pow(x1, 2) / 10.0 - x1 / 2.0 + 5;

		dist = min(sqrt(pow(x0 - xc, 2) + pow(y0 - yc, 2)), sqrt(pow(x1 - xc, 2) + pow(y1 - yc, 2)));

		cout << fixed << setprecision(2) << dist << endl;
	}
	
	return 0;
}

