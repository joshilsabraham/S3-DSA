#include <stdio.h>
struct term{
    int coeff;
    int exp;
};
int main(){
    int i,j,k;
    printf("Input Degree of First Polynomial: ");
    scanf("%d",&i);
    printf("Input Degree of Second Polynomial: ");
    scanf("%d",&j);
    i > j ? (k = i) : (k = j); 
    struct term poly1[i], poly2[j],result[k];
    
    
    enter the coeffient and exponent in terms
    
    
 
