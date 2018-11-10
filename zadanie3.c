#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846



void rectangle_area();
void circle_area();
void triangle_area();

int main(){
    char wybor;

    do{
        system("cls");
        printf("Wybierz opcje:\na).Oblicz pole prostokata\nb).Oblicz pole kola\nc).Oblicz pole trojkata\nK) Wyjdz\n");
        scanf("%c",&wybor);
        system("cls");
        if(wybor == 'a'){
            rectangle_area();
            system("pause");
        } else if(wybor == 'b'){
            circle_area();
            system("pause");
        } else if(wybor == 'c'){
            triangle_area();
            system("pause");
        }
    } while(wybor!='K');

}

void rectangle_area(){
    float a, b;
    printf("\nPodaj pierwszy bok:\t");
    scanf("\n%f",&a);
    printf("Podaj drugi bok:\t");
    scanf("\n %f",&b);
    printf("Pole prostokata o bok %.3f i boku %.3f to %.3f\n",a,b,a*b);
}

void circle_area(){
    float r;
    printf("\nPodaj promien:\t");
    scanf("\n%f",&r);
    printf("Pole kola o promieniu %.3f to %.3f\n",r,M_PI*(pow(r,2)));
}

void triangle_area(){
    float h,a;
    printf("\nPodaj wysokosc trojkata:\t");
    scanf("\n%f",&h);
    printf("Podaj podstawe trojkata:\t");
    scanf("\n%f",&a);
    printf("Pole trojkata o wysokosci %.3f i podstawie %.3f to %.3f\n",h,a,a*h*0.5);
}