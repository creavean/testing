#include <stdio.h>
#include <ctype.h>
#include <math.h>

float DET(float a[20][20], int G);    //as the inverse can be in intergers we are using float
void CF(float num[20][20], float F);
void TR(float num[20][20], float fac[20][20], float L);

float DET(float a[20][20], int G)
{
  float s = 1, det = 0, b[20][20];
  int i, j, m, n, c;
  if (G == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < G; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < G; i++)
          {
            for (j = 0 ;j < G; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (G - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * DET(b, G - 1));
          s = -1 * s;
          }
    }
 
    return (det);
}
 
void CF(float num[20][20], float F)
{
 float b[20][20], fac[20][20];
 int p, q, m, n, i, j;
 for (q = 0;q < F; q++)
 {
   for (p = 0;p < F; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < F; i++)
     {
       for (j = 0;j < F; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (F - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * DET(b, F - 1);
    }
  }
  TR(num, fac, F);
}

void TR(float num[20][20], float fac[20][20], float L)
{
  int i, j;
  float b[20][20], inverse[20][20], d;
 
  for (i = 0;i < L; i++)
    {
     for (j = 0;j < L; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = DET(num, L);
  for (i = 0;i < L; i++)
    {
     for (j = 0;j < L; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
   printf("\n\n\nThe inverse of matrix is : \n");
 
   for (i = 0;i < L; i++)
    {
     for (j = 0;j < L; j++)
       {
         printf("\t%F", inverse[i][j]);
        }
    printf("\n");
     }
}