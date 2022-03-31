#include <stdio.h>
#include <ctype.h>
#include <math.h>

void MSM(int arr[20][20], int S, int R, int C);

void MSM(int arr[20][20], int S, int R, int C)
{
    int i, j;
    int M[20][20];
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            M[i][j] = S * arr[i][j];
            printf("\t%d", M[i][j]);
        }
        printf("\n");
    }
}