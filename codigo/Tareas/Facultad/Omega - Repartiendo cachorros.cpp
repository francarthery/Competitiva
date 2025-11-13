#include <iostream>
#include <math.h>

using namespace std;

int main(){
	
	float x1, x2, x3, x4, y1, y2, y3, y4, lado_1, lado_2, lado_3, lado_4;
	
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	
	//Usando pitágoras calculamos la longitud de cada lado
	lado_1 = sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
	
	lado_2 = sqrt(pow((y2 - y3), 2) + pow((x2 - x3), 2));
	
	lado_3 = sqrt(pow((y4 - y1), 2) + pow((x4 - x1), 2));
	
	lado_4 = sqrt(pow((y3 - y4), 2) + pow((x3 - x4), 2));
	
	
	if(lado_1 < lado_2 and lado_1 < lado_3 and lado_1 < lado_4)
		cout << lado_1 << endl;
	else if(lado_2 < lado_3 and lado_2 < lado_4)
		cout << lado_2 << endl;
	else if(lado_3 < lado_4)
		cout << lado_3 << endl;
	else
		cout << lado_4 << endl;
	
	
	return 0;
}
