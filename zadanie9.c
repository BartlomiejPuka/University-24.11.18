#include <stdio.h>
#include <stdlib.h>

int czy_pierwsza(int num);

int main(int argc, char*argv[]){
    int result;
    int primes[10];
    int n = atoi(argv[1]);
    int i,j;
    int licznik = 0;
    if(argc > 1){
        result = czy_pierwsza(n);
        printf("%d",result);
    } else{
        printf("Nie podales argumentu!");
    }
    if(result){
        for(i=0;i<10;i++){
            for(j=0;licznik<10000;j++){
                if(j>n && czy_pierwsza(j) && licznik < j){
                    primes[i] = j;
                    licznik = j;
                    break;
                }
            }
        }
        for(i=0;i<10;i++){
        printf("\n primes[%d] = %d",i,primes[i]);
        }
    } else{
        printf("\nPodana liczba %d nie jest pierwsza",n);
    }

}

int czy_pierwsza(int num){
    int i;
    // printf("\n w programie%d",num);
    if(num<=1){
        return 0;
    } else if(num==2){
        return 1;
    } else{
        for(i=2;i<num;i++){
            if(num%i==0){
                // printf("A %d",i);
                return 0;
            }
        }
    }
    return 1;
}