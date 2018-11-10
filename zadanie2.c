#include <stdio.h>

float average(float * nums, size_t count);

int main(){
    float liczby[] = {5.0,5.0,5.0,5.5};
    float liczby1[] = {4.0,4.0,4.0,4.0,4.0,4.0};
    float liczby2[] = {3.0};
    float liczby3[] = {-2.0,3.0,2.0};
    float liczby4[] = {1.0,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0};
    float liczby5[] = {1.0};
    float result;
    result = average(liczby,sizeof(liczby)/sizeof(float));
    printf("\n Pierwsza tablica: %f",result);
    result = average(liczby1,sizeof(liczby1)/sizeof(float));
    printf("\n Druga tablica: %f",result);
    result = average(liczby2,sizeof(liczby2)/sizeof(float));
    printf("\n Trzecia tablica: %f",result);
    result = average(liczby3,sizeof(liczby3)/sizeof(float));
    printf("\n Czwarta tablica: %f",result);
    result = average(liczby4,sizeof(liczby4)/sizeof(float));
    printf("\n Piata tablica: %f",result);
    result = average(liczby5,sizeof(liczby5)/sizeof(float));
    printf("\n Szosta tablica: %f",result);
}

float average(float * nums, size_t count){
    int i;
    float sum, avg = 0.0;
    for(i = 0; i < count;i++){
        sum += nums[i];
    }
    avg = (sum/count);
    return avg;
}