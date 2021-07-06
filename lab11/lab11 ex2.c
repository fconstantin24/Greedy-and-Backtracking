#include<stdio.h>

//Un caz in care tehnica Greedy nu  mai e optima este, de exemplu, atunci cand se introduce suma 210, deoarece selecteaza ca rest bancnota cea mai mare, neglijand suma ramasa.
//Pentru suma de 210 rezultatul va fi 1*150, 1*50, 2*5, un total de 4 bancnote, in timp ce minimul de bancnote primite ca rest este 3 (1*150, 2*30)

int main (void){
    int suma;
    printf("Introduceti suma\n");
    scanf("%d", &suma);
    printf("Restul este: \n");
    greedy(suma);
}

void greedy (int suma){
    int i = 0;
    int bancnote[7] = {150, 50, 30, 15, 5, 3, 1};
    int nr;

    while(i < 7){
        if(bancnote[i]<= suma){
            nr = suma/bancnote[i];
            printf("%d de %d RON \n", nr, bancnote[i]);
            suma = suma - nr*bancnote[i];
        }
        i++;
    }

}
