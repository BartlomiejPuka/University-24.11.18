#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int factorialize(int n);
int newton(int n, int k);

int main(int argc, char *argv[] ){
    FILE *file;
    int c;
    int i = 0;
    int arr[20];
    system("cls");
    if(argc > 1){
        file = fopen(argv[1],"r");
        if(file){
            while((c = fgetc(file))!=EOF){
                if(c!=' ' && c !='\n'){
                    arr[i] = c -'0';
                    i++;
                }
            }
            fclose(file);
        }
    } else{
        printf("blad");
        return 1;
    }

    printf("Symbol newtona dla %s :",argv[1]);
    for(i=0;i<20;i++){
        printf("\n n= %d, k= %d, newton(%d,%d)= %d",arr[i],arr[i+1],arr[i],arr[i+1],newton(arr[i],arr[i+1]));
        i++;
    }
    return 0;
}


int factorialize(int n){
    if(n==0){
        return 1;
    } 
    return factorialize(n-1)*n;

}

int newton(int n, int k){
    return (factorialize(n))/(factorialize(k)*factorialize(n-k));
}