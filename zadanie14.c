#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_max_negative(int arr[],int n);
int czy_pierwsza(int num);

int main(int argc, char*argv[]){
    FILE *file;
    int i, result;
    int j = 0;
    int arr[50];
    srand(time(0));
    if(czy_pierwsza(atoi(argv[1]))){
        printf("\n1");
    } else{
        printf("\n0");
    }
    file = fopen(argv[2],"w");
    for(i = 0; i < 50;i++){
        arr[i] = rand()%300 - 200;
        if(czy_pierwsza(arr[i])){
            fprintf(file,"%d ",arr[i]);
            j++;
        }
        if(j%5==0 && j!=0){
            fputs("\n",file);
        }
    }
    fclose(file);
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