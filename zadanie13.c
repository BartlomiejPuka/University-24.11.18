#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int licz_iloczyn(int arr[], int size);

int main(int argc, char*argv[]){
    FILE *file;
    int i, result;
    int arr[50];
    srand(time(0));
    file = fopen(argv[1],"w");
    for(i = 0; i < 50;i++){
        arr[i] = rand() % 300;
        printf("\narr[%d] = %d",i,arr[i]);
        fprintf(file,"%d ",arr[i]);
        if(i%5==0 && i!=0){
            fputs("\n",file);
        }
    }
    
    result = licz_iloczyn(arr,sizeof(arr)/sizeof(int));
    fprintf(file,"\nWynik funkcji to %d",result);
    fclose(file);
    printf("\nWynik funkcji to %d",result);
}

int licz_iloczyn(int arr[], int size){
    int iloczyn = 1;
    int i = 0;
    for(i=0;i<size;i++){
        if(arr[i] > 0 && arr[i] % 2 != 0){
            iloczyn *= arr[i];
        }
    }
    return iloczyn;
}