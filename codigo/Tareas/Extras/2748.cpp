#include <array>
#include <cstdio>
 
using namespace std;
 
int main() {

    char NOMBRE[7] = {'R', 'o', 'b', 'e', 'r', 't', 'o'};
    int NUM[4] = {'5', '7', '8', '6'};
    char UNIFEI[6] = {'U', 'N', 'I', 'F', 'E', 'I'};

    for(int f=0; f<=6; f++){
            
        for (int c = 0; c<39; c++){
            if(f==0 or f==6)
                printf("-");
            else if(c==0 or c==38)
                printf("|");
            else if(f==1 and c>=9 and c<=15)
				printf("%c", NOMBRE[c-9]);
            else if(f==3 and c>=9 and c<=12)
				printf("%c", NUM[c-9]);
            else if(f==5 and c>=9 and c<=14)
				printf("%c", UNIFEI[c-9]);
            else
                printf(" ");
 
        }if(f<7) printf("\n");
        }
    return 0;
}
