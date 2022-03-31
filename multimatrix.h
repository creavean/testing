#include <stdio.h>
#include <ctype.h>
#include <math.h>

void MM(int arrone[20][20], int arrtwo[20][20], int RA, int CA, int CB);

void MM(int arrone[20][20], int arrtwo[20][20], int RA, int CA,int CB)
{
    int i, j, k;
    int XM[20][20];

    for (i = 0; i<RA; ++i)
        for (j = 0; j<CB; ++j)
        {
            XM[i][j] = 0;
        }

    for (i = 0; i<RA; ++i)
        for (j = 0; j<CB; ++j)
            for (k = 0; k<CA; ++k)
            {
                XM[i][j] += arrone[i][k] * arrtwo[k][j];
            }
    
    printf("\nOutput Matrix:\n");
    for (i = 0; i<RA; ++i)
        for (j = 0; j<CB; ++j)
        {
            printf("\t%d ", XM[i][j]);
            if (j == CB - 1)
                printf("\n\n");
        }
}