#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_min(int arr[],int size);
int czy_pierwsza(int num);

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
    
    result = find_min(arr,sizeof(arr)/sizeof(int));
    fprintf(file,"\nWynik funkcji to %d",result);
    fclose(file);
    printf("\nWynik funkcji to %d",result);
}

int find_min(int arr[],int size){
    int result;
    int temp;
    int picked = 0;
    int i;
    for(i=0;i<size;i++){
        if(arr[i] > 0 && !picked && czy_pierwsza(arr[i])){
            temp = arr[i];
            result = temp;
            picked = 1;
        } else if(arr[i] > 0 && czy_pierwsza(arr[i])){
            temp=arr[i];
            if(temp < result){
                result = arr[i];
            }      
        }
    }
    return result;
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