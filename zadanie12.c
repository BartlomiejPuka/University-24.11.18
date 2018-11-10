#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_max_negative(int arr[],int n);
int czy_pierwsza(int num);

int main(int argc, char*argv[]){
    FILE *file;
    int i, result;
    int arr[50];
    srand(time(0));
    file = fopen(argv[1],"w");
    for(i = 0; i < 50;i++){
        arr[i] = rand()%300 - 200;
        printf("\narr[%d] = %d",i,arr[i]);
        fprintf(file,"%d ",arr[i]);
        if(i%5==0 && i!=0){
            fputs("\n",file);
        }
    }
    
    result = find_max_negative(arr,sizeof(arr)/sizeof(int));
    fprintf(file,"\nWynik funkcji to %d",result);
    fclose(file);
    printf("\nWynik funkcji to %d",result);
}

int find_max_negative(int arr[],int n){
    int i;
    int temp;
    int max_neg = 0;
    int result = 0;
    for(i=0; i < n;i++){
        if(!max_neg && arr[i] < 0 && czy_pierwsza(abs(arr[i])) ){
            max_neg = arr[i];
            result = 1;
        } else if(arr[i] < 0 && czy_pierwsza(abs(arr[i]))){
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