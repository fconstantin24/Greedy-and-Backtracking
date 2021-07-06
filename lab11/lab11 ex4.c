#include<stdio.h>
#include<string.h>

void schimba(char *x, char *y)
{
    char aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void permuta(char *a, int inc, int fin)
{
    if (inc == fin)
    printf("%s\n", a);
        else{
            for (int i = inc; i <= fin; i++){
                schimba((a+inc), (a+i));
                permuta(a, inc+1, fin);
                schimba((a+inc), (a+i)); //backtracking
                }
            }
}

int main()
{   char str[10];
    printf("Introduceti numarul\n");
    scanf("%s", str);
    printf("Permutarile sunt:\n");
    int n = strlen(str);
    permuta(str, 0, n-1);

    return 0;
}
