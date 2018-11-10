#include <stdio.h>

int factorialize(int n);

int main(){
    int dane[10];
    int i;
    int num;
    for(i=0;i<10;i++){
        printf("Podaj %d dane:",i+1);
        scanf("\n %d",&num);
        if(num >= 0){
            dane[i] = num;
        } else{
            i--;
        }
    }
    for(i=0;i<10;i++){
        printf("\n %d! = %d",dane[i],factorialize(dane[i]));
    }

}

int factorialize(int n){
    if(n==0){
        return 1;
    } 
    return factorialize(n-1)*n;

}