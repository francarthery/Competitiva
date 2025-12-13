#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;
 
int main(){
 
    int A, B, C, R;

    for(;;){
    scanf("%d",&A);
    if(A==0)
        break;
    
    scanf("%d%d",&B,&C);
    R=sqrt((A*B)/(C/100.00));
    
    printf("%d\n",R);
    
    }
    return 0;
}

/*
#include<math.h>
#include<stdio.h>
int main()
{
    int x,y,z,m;
    while(true){
    
    scanf("%d",&x);
        if(x==0)break;
    scanf("%d%d",&y,&m);    
    z=sqrt(x*y*100/m);
    printf("%dn",z);
}}*/