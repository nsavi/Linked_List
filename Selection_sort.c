#include<stdio.h>
int main()
{
    int i,j,t,n,a[5];
    int min;
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for (i = 0; i < n-1; i++)
    {  
        min = i;
          
        for (j = i+1; j < n; j++)  
        if (a[j] < a[min])  
            min = j; 
    int t = a[min];  
    a[min] = a[i];  
    a[i] = t;  
    }  
    
    
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
