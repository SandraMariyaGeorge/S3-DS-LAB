#include <stdio.h>
#include <math.h>
#define MAX 50

struct poly {
    int exp;
    int coeff;
};

void main() 
{
    struct poly poly1[MAX], poly2[MAX], poly3[MAX];
    int t1, t2, i, j, k;

    printf("Enter the highest power of polynomial 1:\n");
    scanf("%d", &t1);
    printf("Enter the details of first polynomial:\n");
    for (i = t1; i >= 0; i--) 
    {
        printf("The coefficient of x^%d : ", i);
        scanf("%d", &poly1[i].coeff);
        poly1[i].exp = i;
    }

    printf("Enter the highest power of polynomial 2:\n");
    scanf("%d", &t2);
    printf("Enter the details of second polynomial:\n");
    for (i = t2; i >= 0; i--) 
    {
        printf("The coefficient of x^%d : ", i);
        scanf("%d", &poly2[i].coeff);
        poly2[i].exp = i;
    }

    // Initialize poly3 coefficients to 0.
    for (i = 0; i < MAX; i++) 
    {
        poly3[i].coeff = 0;
        poly3[i].exp = 0;
    }

    // Perform polynomial multiplication
    for (i = 0; i <= t1; i++) 
    {
        for (j = 0; j <= t2; j++) 
        {
            k = poly1[i].exp + poly2[j].exp;
            poly3[k].coeff += poly1[i].coeff * poly2[j].coeff;
            poly3[k].exp = k;
        }
    }

    // Determine the highest power of the resulting polynomial
    int max_power = 0;
    for (i = 0; i < MAX; i++) 
    {
        if (poly3[i].coeff != 0) 
        {
            max_power = poly3[i].exp;
        }
    }

    printf("Resultant polynomial is :\n");
    for (i = max_power; i >= 0; i--) 
    {
        if (poly3[i].coeff != 0) 
        {
            if (i == 0) 
            {
                printf("%d", poly3[i].coeff);
            } 
            else 
            {
                printf("%dx^%d ", poly3[i].coeff, poly3[i].exp);
            }
            if (i > 0) 
            {
                printf("+ ");
            }
        }
    }

    printf("\n");
}