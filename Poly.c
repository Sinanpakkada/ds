
#include<stdio.h>
void main()
{
    int n1,n2,p1[10][2],p2[10][2],i,j;
    printf("Enter the number of terms in the first polynomial\n");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("Enter the coefficient and exponential of the term\n");
        for(j=0;j<2;j++)
        {
        scanf("%d",&p1[i][j]);
        }

    } 
    printf("Enter the number of terms in the second polynomial\n");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("Enter the coefficient and exponential of the term\n");
        for(j=0;j<2;j++)
        {
        scanf("%d",&p2[i][j]);
        }
    }
    int p3[10][2];
    int k=0;
    i=0,j=0;
    while(i<n1||j<n2)
    {
        if(p1[i][1]>p2[j][1])
        {
            p3[k][0]=p1[i][0];
            p3[k][1]=p1[i][1];
            i++;
        }
        else if(p1[i][1]<p2[j][1])
        {
             p3[k][0]=p2[j][0];
             p3[k][1]=p2[j][1];
             j++;
        }
        else
        {
            p3[k][0]=p1[i][0]+p2[j][0];
            p3[k][1]=p1[k][1];
            i++;j++;
        }
        k++;
    }
     printf("The first polynomial is\n");
    for(i=0;i<n1;i++)
    {
        printf("%d x^%d   ",p1[i][0],p1[i][1]);
    }
    printf("\n");
    printf("The second polynomial is\n");
    for(i=0;i<n2;i++)
    {
        printf("%d x^%d   ",p2[i][0],p2[i][1]);
    }
    printf("\n");
    printf("The resultant polynomial is\n");
    for(i=0;i<k;i++)
    {
        printf("%d x^%d   ",p3[i][0],p3[i][1]);
    }

}
