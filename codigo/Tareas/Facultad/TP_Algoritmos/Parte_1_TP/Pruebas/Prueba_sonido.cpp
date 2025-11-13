#include <iostream>
#include <windows.h>

using namespace std;

int main(){

    PlaySoundA((LPCSTR) "sonido_inicio.wav", NULL, SND_FILENAME | SND_ASYNC);
	Sleep(10000);
    return 0;
}
