#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "rwmatrix.h"
#include "acmatrix.h"
#include "multimatrix.h"
#include "scalarmatrix.h"
#include "invmatrix.h"

//declaration of functions
//RM - read matrix
//PM - print matrix
//MAS - matrix add sub
//MM - martix multiply
//MSM - matrix scalar multiply
//DET - determinant
//CF - cofactor
//TR - transpose
//R - rows
//C - columns
//S - scalar



int main(void)
{
    int choice;
    char repeat = 'Y';
    int matrixA[20][20];
    int matrixB[20][20];
    float matrixC[20][20];
    int rowA, colA;
    int rowB, colB;
    int add = 1;
    int sub = -1;
    int S = 0;
    int i, j, k;
    float a[20][20], d;
    int G;

    while (repeat == 'Y')
    {
        //Main menu to select the type of calculation (type 1/2/3/4/5)
        printf("\nMain Menu\n");
        printf("\t1. Addition\n");
        printf("\t2. Subtract\n");
        printf("\t3. Multiply Two Matrices\n");
        printf("\t4. Scalar Multiply\n");
        printf("\t5. Inverse Of Matrix\n");
        printf("Enter your choice (1/2/3/4/5): ");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the number of rows and number of columns for matrix A: ");
            scanf("%d%d", &rowA, &colA);

            printf("Enter the number of rows and number of columns for matrix B: ");
            scanf("%d%d", &rowB, &colB);

            while ((rowA != rowB) && (colA != colB))    // In case the user enters wrong input
            {
                printf("\nError!!! Both matrices should have same number of rows and columns\n");
                printf("\nEnter the number of rows and number of columns for matrix A: ");
                scanf("%d%d", &rowA, &colA);

                printf("Enter the number of rows and number of columns for matrix B: ");
                scanf("%d%d", &rowB, &colB);
            }

            printf("\n\tEnter the elements of Matrix A (%d x %d matrix)\n", rowA, colA); 
            RM(matrixA, rowA, colA);
            printf("\n\t\tMatrix A\n\n");
            PM(matrixA, rowA, colA);

            printf("\n\tEnter the elements of Matrix B (%d x %d matrix)\n", rowB, colB);
            RM(matrixB, rowB, colB);
            printf("\n\t\tMatrix B\n\n");
            PM(matrixB, rowB, colB);

            printf("\nThe Sum of matrixA and matrixB is : \n");
            MAS(matrixA, matrixB, rowA, colA, add);

            break;

        case 2:

            printf("\nEnter the number of rows and number of columns for matrix A: ");
            scanf("%d%d", &rowA, &colA);

            printf("Enter the number of rows and number of columns for matrix B: ");
            scanf("%d%d", &rowB, &colB);

            while ((rowA != rowB) && (colA != colB))    // In case the user enters wrong input
            {
                printf("\nError!!! Both matrices should have same number of rows and columns\n");
                printf("\nEnter the number of rows and number of columns for matrix A: ");
                scanf("%d%d", &rowA, &colA);

                printf("Enter the number of rows and number of columns for matrix B: ");
                scanf("%d%d", &rowB, &colB);
            }

            printf("\n\tEnter the elements of Matrix A (%d x %d matrix)\n", rowA, colA);
            RM(matrixA, rowA, colA);
            printf("\n\t\tMatrix A\n\n");
            PM(matrixA, rowA, colA);

            printf("\n\tEnter the elements of Matrix B (%d x %d matrix)\n", rowB, colB);
            RM(matrixB, rowB, colB);
            printf("\n\t\tMatrix B\n\n");
            PM(matrixB, rowB, colB);

            printf("\nThe subtraction between matrixA and matrixB is : \n");
            MAS(matrixA, matrixB, rowA, colA, sub);
            break;

        case 3:

            printf("\nEnter the number of rows and number of columns for matrix A: ");
            scanf("%d%d", &rowA, &colA);

            printf("Enter the number of rows and number of columns for matrix B: ");
            scanf("%d%d", &rowB, &colB);

            while (colA != rowB)    // In case the user enters wrong input
            {
                printf("\n\nError! Column of first matrix should equal to row of second matrix.\n\n");
                printf("\nEnter the number of rows and number of columns for matrix A: ");
                scanf("%d%d", &rowA, &colA);

                printf("Enter the number of rows and number of columns for matrix B: ");
                scanf("%d%d", &rowB, &colB);
            }

            printf("\n\tEnter the elements of Matrix A (%d x %d matrix)\n", rowA, colA);
            RM(matrixA, rowA, colA);
            printf("\n\t\tMatrix A\n\n");
            PM(matrixA, rowA, colA);

            printf("\n\tEnter the elements of Matrix B (%d x %d matrix)\n", rowB, colB);
            RM(matrixB, rowB, colB);
            printf("\n\t\tMatrix A\n\n");
            PM(matrixB, rowB, colB);

            MM(matrixA, matrixB, rowA, colA, colB);
            break;

        case 4:

            printf("\nEnter the scalar number: ");
            scanf("%d", &S);
            printf("\nThe scalar is: %d ", S);
            printf("\nEnter the number of rows and number of columns for matrix: ");
            scanf("%d%d", &rowA, &colA);
            printf("\n\tEnter the elements of Matrix (%d x %d matrix)\n", rowA, colA);
            RM(matrixA, rowA, colA);
            printf("\n\t\tMatrix\n\n");
            PM(matrixA, rowA, colA);
            printf("\nThe scalar multiplication between matrix * %d is: \n", S);
            MSM(matrixA, S, rowA, colA);
            break;

        case 5:

            printf("\nEnter the order of matrix: ");    //the inverse matrix can only be calculated of a square matrix
            scanf("%d", &G);
            printf("Enter the elements of Matrix (%d x %d matrix)\n", G, G);
            
            for(i = 0;i < G; i++)
            {
                printf("\t%d entries for row %d: ", G, i + 1);
                for(j = 0;j < G; j++)
                {
                    scanf("%f", &a[i][j]);
                }
            }
            d = DET(a, G);
            if (d == 0)
                printf("\nInverse of this matrix is not possible as the determinant is zero.\n");
            else
                CF(a, G);
            break;

        default:
            printf("\nInvalid selection!!! (enter option 1/2/3/4)");
            break;
        }

        printf("\n\nRestart? Y/N\n");
        scanf(" %c", &repeat);
        repeat = toupper(repeat);
    }
    printf("\n\nThank you\n\n");

    return 0;
}