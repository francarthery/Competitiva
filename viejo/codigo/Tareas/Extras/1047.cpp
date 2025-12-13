#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int HI, MI, HF, MF, RTA_HS, RTA_MINS;
	
	cin >> HI >> MI >> HF >> MF;
	
	if(HF > HI){
		if(MF > MI){
			RTA_HS = HF - HI;
			RTA_MINS = MF - MI;}
        else if(MF == MI){
            RTA_HS = 24;
            RTA_MINS = 0;}
		else{
			RTA_HS = (HF - 1) - HI;
			RTA_MINS = 60 - (MI-MF);}
    }
    else if(HI == HF){
        if(MF > MI){
			RTA_HS = 0;
			RTA_MINS = MF - MI;}
        else if(MF == MI){
            RTA_HS = 24;
            RTA_MINS = 0;}
		else{
			RTA_HS = 23;
			RTA_MINS = 60 - (MI-MF);}
    }
	else{
		if(MF >= MI){
			RTA_HS = 24 - (HI - HF);
			RTA_MINS = MF - MI;}
		else{
			RTA_HS = 24 - (HI - (HF - 1));
			RTA_MINS = 60 - (MI-MF);}
    }

	cout << "O JOGO DUROU " << RTA_HS << " HORA(S) E " << RTA_MINS << " MINUTO(S)" << endl;
	
	
	return 0;
}