#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int find_max_negative(int arr[],int n);

int main(int argc, char *argv[] ){
    FILE *file;
    int c, d;
    int i = 0;
    int j = 0;
    int decimals = 1;
    int result = 0;
    int arr[30];
    int resultArr[30];
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
    
    printf("\nPodaj liczbe n: ");
    scanf("\n %d",&n);
    result = find_max_negative(resultArr, n);
    printf("\nWynik funkcji to %d.",result);
    return 0;
}


int find_max_negative(int arr[],int n){
    int i;
    int temp;
    int max_neg = 0;
    int result = 0;
    for(i=0; i < n;i++){
        if(!max_neg && arr[i] < 0){
            max_neg = arr[i];
            result = 1;
        } else if(arr[i] < 0){
            temp = arr[i];
            if(temp > max_neg){
                max_neg = temp;
            }
        }
    }
    if(!result){
        printf("\nNie ma najwiekszej ujemnej wartosci przy %d elementach.",n);
        return 1;
    } else{
        return max_neg;
    }
}