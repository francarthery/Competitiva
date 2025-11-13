#include <cstdio>

using namespace std;
int main(){

    int N, V, L;
    
    while(scanf("%d",&N)!=EOF){
        L=1;
        for(int i=0; i<N; i++){
            scanf("%d",&V);
            if(L<3){
                if(V>=10 and V<20)
                    L=2;
                else if(V>=20)
                    L=3;
            }}
        printf("%d\n", L);
        }

    return 0;
}