#include <stdio.h>
#define MAX 100


struct term {
    int coeff;
    int degree;
};


struct term poly1[MAX], poly2[MAX], poly3[MAX];

int main() {
    int n1, n2, i, j, k;

    
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);

    
    printf("Enter degree and coefficient for the first polynomial (highest to lowest degree):\n");
    for (i = 0; i < n1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly1[i].degree, &poly1[i].coeff);
    }

    
    printf("Enter degree and coefficient for the second polynomial (highest to lowest degree):\n");
    for (i = 0; i < n2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly2[i].degree, &poly2[i].coeff);
    }

    
    i = j = k = 0;
    while (i < n1 && j < n2) {
        if (poly1[i].degree == poly2[j].degree) {
            poly3[k].degree = poly1[i].degree;
            poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
            i++; j++; k++;
        } else if (poly1[i].degree > poly2[j].degree) {
            poly3[k] = poly1[i];
            i++; k++;
        } else {
            poly3[k] = poly2[j];
            j++; k++;
        }
    }

    
    while (i < n1) poly3[k++] = poly1[i++];
    while (j < n2) poly3[k++] = poly2[j++];

    
    printf("\nResulting Polynomial:\n");
    for (i = 0; i < k; i++) {
        if (poly3[i].coeff != 0) {
            printf("%dx^%d", poly3[i].coeff, poly3[i].degree);
            if (i < k - 1)
                printf(" + ");
        }
    }
    printf("\n");

    return 0;
}
