#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum(int arr[],int size);

int main(int argc, char*argv[]){
    FILE *file;
    int i, result;
    int arr[30];
    srand(time(0));
    file = fopen(argv[1],"w");
    for(i = 0; i < 30;i++){
        arr[i] = rand() % 300;
        printf("\narr[%d] = %d",i,arr[i]);
        fprintf(file,"%d ",arr[i]);
        if(i%5==0 && i!=0){
            fputs("\n",file);
        }
    }
    
    result = sum(arr,sizeof(arr)/sizeof(int));
    fprintf(file,"\nWynik funkcji to %d",result);
    fclose(file);
    printf("\nWynik funkcji to %d",result);
}

int sum(int arr[],int size){
    int sum;
    int i;
    for(i=0;i<size;i++){
        if(arr[i]%11==0){
            sum+=arr[i];      
        }
    }
    return sum;
}