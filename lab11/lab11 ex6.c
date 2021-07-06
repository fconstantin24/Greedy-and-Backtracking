#include <stdio.h>
#include <stdlib.h>

#define N 9

void scrie(int matrice[N][N])
{
     for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
            printf("%d ",matrice[i][j]);
         printf("\n");
       }
}


int verifica(int grila[N][N], int rand,
                       int col, int nr)
{

    for (int x = 0; x <= 8; x++)
        if (grila[rand][x] == nr)
            return 0;

    for (int x = 0; x <= 8; x++)
        if (grila[x][col] == nr)
            return 0;

    int startRand = rand - rand % 3,
                 startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grila[i + startRand][j +
                          startCol] == nr)
                return 0;

    return 1;
}

int rezolva(int grila[N][N], int rand, int col)
{

    if (rand == N - 1 && col == N)
        return 1;

    if (col == N)
    {
        rand++;
        col = 0;
    }

    if (grila[rand][col] > 0)
        return rezolva(grila, rand, col + 1);

    for (int nr = 1; nr <= N; nr++)
    {

        if (verifica(grila, rand, col, nr)==1)
        {
            grila[rand][col] = nr;

            if (rezolva(grila, rand, col + 1)==1)
                return 1;
        }
        grila[rand][col] = 0;
    }
    return 0;
}

int main()
{
    int grila[N][N] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
                       { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
                       { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
                       { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
                       { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
                       { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
                       { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
                       { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
                       { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

    if (rezolva(grila, 0, 0)==1)
        scrie(grila);
    else
        printf("Nu exista nicio solutie!");

    return 0;

}
