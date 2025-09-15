#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Insert node in descending order of degree (power)
void insertNode(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;

    if (*poly == NULL || (*poly)->pow < pow) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    struct Node* temp = *poly;
    while (temp->next != NULL && temp->next->pow >= pow)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

struct Node* addPolynomial(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insertNode(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            insertNode(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0)
                insertNode(&result, sumCoeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
    return result;
}

void printPoly(struct Node* poly) {
    int first = 1;
    while (poly != NULL) {
        if (!first) printf(" + ");
        printf("%dx^%d", poly->coeff, poly->pow);
        first = 0;
        poly = poly->next;
    }
    printf("\n");
}

struct Node* readPolynomial() {
    struct Node* poly = NULL;
    int n, coeff, pow;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter each term as: degree coefficient (highest to lowest degree)\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pow, &coeff);
        insertNode(&poly, coeff, pow);
    }
    return poly;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    printf("Enter first polynomial:\n");
    poly1 = readPolynomial();

    printf("Enter second polynomial:\n");
    poly2 = readPolynomial();

    printf("\nPolynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    sum = addPolynomial(poly1, poly2);
    printf("Sum: ");
    printPoly(sum);

    return 0;
}
