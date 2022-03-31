#include<stdio.h>
#include<ctype.h>
#include<math.h>

void RM(int arr[20][20], int R, int C);
void PM(int arr[20][20], int R, int C);

void RM(int arr[20][20], int R, int C)
{
    int i, j;
    for (i = 0; i < R; i++)
    {
        printf("\t%d entries for row %d: ", C, i + 1);
        for (j = 0; j < C; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    return;
}

void PM(int arr[20][20], int R, int C)
{
    int i, j;
    for (i = 0; i < R; i++) 
    {
        for (j = 0; j < C; j++)
        {
            printf("\t%d", arr[i][j]);
        }
        printf("\n");
    }
}