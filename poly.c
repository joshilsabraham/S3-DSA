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
    
    
 #include<stdio.h>
struct poly{
int coef;
int expo;
}p1[10],p2[10],p3[10];
int main(){
  int i=0,j=0,k=0,term1,term2;
  printf("FIRST POLYNOMIAL\n");
  printf("Enter the NO: OF TERMS:");
  scanf("%d",&term1);
  for (i=0;i<term1;i++){
    printf("Enter the coefficient of %d term in polynomial",i+1);
    scanf("%d",&p1[i].coef);
    printf("Enter the power of %d term in the polynomial",i+1);
    scanf("%d",&p1[i].expo);
    }
    
  printf("SECOND POLYNOMIAL\n");
  printf("Enter the NO: OF TERMS:");
  scanf("%d",&term2);
  for (j=0;j<term2;j++){
    printf("Enter the coefficient of %d term in polynomial",j+1);
    scanf("%d",&p2[j].coef);
    printf("Enter the power of %d term in the polynomial",j+1);
    scanf("%d",&p2[j].expo);
    }
  i=j=0;
    while(i<term1&&j<term2){
      
      if(p1[i].expo==p2[j].expo){
        p3[k].coef=p1[i].coef+p2[j].coef;
        p3[k].expo=p1[i].expo;
        k=k+1,i++,j++;
        }
        
        else if(p1[i].expo>p2[j].expo){
        p3[k].coef=p1[i].coef;
        p3[k].expo=p1[i].expo;
        k++,i++;
        }
        else{
          p3[k].coef=p2[j].coef;
          p3[k].expo=p2[j].expo;
          k++,j++;
          }
      }
    
    
    while(i<term1){
    p3[k].coef=p1[i].coef;
    p3[k].expo=p1[i].expo;
    i++,k++;
    }
    
    while(j<term2){
    p3[k].coef=p2[j].coef;
    p3[k].expo=p2[j].expo;
    j++,k++;
    }
    
    for(int a=0;a<k;a++){
    printf(" %dX^%d ",p3[a].coef,p3[a].expo);
    
    if(a<k-1){
    printf("+"); }
    }
  return 0;
}
