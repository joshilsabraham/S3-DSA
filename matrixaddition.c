#include<stdio.h>
void main()
{
    int i,j,n,c1=1,c2=1,count=1,a[10][10],b[10][10],s[20][20],t[20][20],sum[50][50],last[10][10];
    printf("\nEnter dimension:");
    scanf("%d",&n);
    printf("\nEnter elements of 1st matrix:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("\nEnter elements of 2nd matrix:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&b[i][j]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            {
                if (a[i][j]==0)
                    continue;
                else
                {
                    s[c1][1]=i;
                    s[c1][2]=j;
                    s[c1][3]=a[i][j];
                    c1++;

                }
            }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            {
                if (b[i][j]==0)
                    continue;
                else
                {
                    t[c2][1]=i;
                    t[c2][2]=j;
                    t[c2][3]=b[i][j];
                    c2++;
                }
            }
    }
    printf("\nThe sparse matrix form of A is:\n");
    for(i=1;i<c1;i++)
    {
        for(j=1;j<=3;j++)
            printf("%d\t",s[i][j]);
        printf("\n");
    }
    printf("\nThe sparse matrix form of B is:\n");
    for(i=1;i<c2;i++)
    {
        for(j=1;j<=3;j++)
            printf("%d\t",t[i][j]);
        printf("\n");
    }

for(i=1;i<c1;i++)
{
    for(j=1;j<c2;j++) 
        {
        if ((s[i][1]==t[j][1])&&(s[i][2]==t[j][2])) 
        {
        sum[count][1]=s[i][1]; 
        sum[count][2]=s[i][2];
        sum[count][3]=s[i][3]+t[j][3];
        s[i][3]=0; 
        t[j][3]=0;
        count++;
        }
        }
}
for(i=1;i<c1;i++)
{
    if(s[i][3]!=0) 
        {
        sum[count][1]=s[i][1]; 
        sum[count][2]=s[i][2];
        sum[count][3]=s[i][3];
        count++;
        } 
for(i=1;i<c2;i++) 
{
    if(t[i][3]!=0)
        {
        sum[count][1]=t[i][1];
        sum[count][2]=t[i][2];
        sum[count][3]=t[i][3];
        count++;
        }
}
printf("\nThe sparse matrix form of sum is:\n"); 
    for(i=1;i<count;i++)
    {
        for(j=1;j<=3;j++)
            printf("%d\t",sum[i][j]);
        printf("\n");
    }

for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            last[i][j]=0;
    }
    for(i=1;i<count;i++)
    {
        last[sum[i][1]][sum[i][2]]=sum[i][3]; 
    }
    printf("\nSum is:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d\t",last[i][j]);
        printf("\n");
    }
}

