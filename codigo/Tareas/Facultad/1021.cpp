#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	double dinero_todo;
	int b_100, b_50, b_20, b_10, b_5, b_2, m_100, m_50, m_25, m_10, m_5, m_1, dinero_entero, dinero;
	
	cin >> dinero_todo;
	
	dinero_entero = dinero_todo;
	dinero = (dinero_todo - dinero_entero) * 100;
	
	b_100 = dinero_entero / 100;
	b_50 = (dinero_entero - b_100 * 100) / 50;
	b_20 = (dinero_entero - b_100 * 100 - b_50 * 50) / 20;
	b_10 = (dinero_entero - b_100 * 100 - b_50 * 50 - b_20 * 20) / 10;
	b_5 = (dinero_entero - b_100 * 100 - b_50 * 50 - b_20 * 20 - b_10 * 10) / 5;
	b_2 = (dinero_entero - b_100 * 100 - b_50 * 50 - b_20 * 20 - b_10 * 10 - b_5 * 5) / 2;
	
	dinero = (dinero_todo - b_100 * 100 - b_50 * 50 - b_20 * 20 - b_10 * 10 - b_5 * 5) * 100;
	
	m_100 = dinero / 100;
	m_50 = (dinero - m_100 * 100) / 50;
	m_25 = (dinero - m_100 * 100 - m_50 * 50) / 25;
	m_10 = (dinero - m_100 * 100 - m_50 * 50 - m_25 * 25) / 10;
	m_5 = (dinero - m_100 * 100 - m_50 * 50 - m_25 * 25 - m_10 * 10) / 5;
	m_1 = (dinero - m_100 * 100 - m_50 * 50 - m_25 * 25 - m_10 * 10 - m_5 * 5) / 1;
	
	cout << "NOTAS:" << endl;
	cout << b_100 << " nota(s) de R$ 100.00" << endl;
	cout << b_50 << " nota(s) de R$ 50.00" << endl;
	cout << b_20 << " nota(s) de R$ 20.00" << endl;
	cout << b_10 << " nota(s) de R$ 10.00" << endl;
	cout << b_5 << " nota(s) de R$ 5.00" << endl;
	cout << b_2 << " nota(s) de R$ 2.00" << endl;
	cout << "MOEDAS:" << endl;
	cout << m_100 << " moeda(s) de R$ 1.00" << endl;
	cout << m_50 << " moeda(s) de R$ 0.50" << endl;
	cout << m_25 << " moeda(s) de R$ 0.25" << endl;
	cout << m_10 << " moeda(s) de R$ 0.10" << endl;
	cout << m_5 << " moeda(s) de R$ 0.05" << endl;
	cout << m_1 << " moeda(s) de R$ 0.01" << endl;
	
	
	return 0;
}
