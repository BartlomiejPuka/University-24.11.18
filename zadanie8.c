#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int func(int arr[],int size);

int main(int argc, char *argv[] ){
    FILE *file;
    int c, d;
    int i = 0;
    int j = 0;
    int decimals = 1;
    int result = 0;
    int arr[20];
    int resultArr[20];
    int resultCounter = 0;
    int n;
    system("cls");
    if(argc > 1)
    {
        file = fopen(argv[1],"r");
        do{
            c = fgetc(file);
            if(c != ' ' && c !='\n' && c != EOF){
                arr[j] = c - '0';
                // printf("arr[%d] = %d\n",j,arr[j]);
                j++;
            } else{
                for(i=0;i<j;i++){
                    result = result + arr[j-i-1]*decimals;
                    decimals = decimals*10;
                    if(i==j-1){
                        resultArr[resultCounter] = result;
                        resultCounter++;
                        result = 0;
                        decimals = 1;
                        j = 0;
                    }
                }
            }
        }while(c != EOF);
        fclose(file);
    }  else{
        printf("failed to load from %s",argv[1]);
        return 1;
    }

    for(i=0;i<sizeof(resultArr)/sizeof(int);i++){
        printf("resultArr[%d] = %d\n",i,resultArr[i]);
    }
    
    result = func(resultArr, sizeof(resultArr)/sizeof(int));
    printf("\nWynik funkcji to iloczyn elementow nieparzystych i dodatnich to: %d.",result);
    return 0;
}


int func(int arr[],int size){
    int i;
    int iloczyn = 1;
    for(i = 0 ; i < size ; i++){
        if(arr[i] % 2 != 0 && arr[i] > 0){
            iloczyn*=arr[i];
        }
    }
    return iloczyn;
}