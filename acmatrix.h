#include <stdio.h>
#include <ctype.h>
#include <math.h>

void MAS(int arrone[20][20], int arrtwo[20][20], int R, int C, int X);

void MAS(int arrone[20][20], int arrtwo[20][20], int R, int C, int X)
{
    int i, j;
    int sumM[20][20];
    int M[20][20];
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            M[i][j] = X * arrtwo[i][j];
        }
    }

    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            sumM[i][j] = arrone[i][j] + M[i][j];
            printf("\t%d", sumM[i][j]);
        }
        printf("\n");
    }
}