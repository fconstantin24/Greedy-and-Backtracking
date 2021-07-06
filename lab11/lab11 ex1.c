#include<stdio.h>

int main (void){
    int suma;
    printf("Introduceti suma\n");
    scanf("%d", &suma);
    printf("Restul este: \n");
    greedy(suma);
}

void greedy (int suma){
    int i = 0;
    int bancnote[5] = {100, 50, 10, 5, 1};
    int nr;

    while(i < 5){
        if(bancnote[i]<= suma){
            nr = suma/bancnote[i];
            printf("%d de %d RON \n", nr, bancnote[i]);
            suma = suma - nr*bancnote[i];
        }
        i++;
    }

}
