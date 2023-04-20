#include<stdio.h>

int main()
{
    int n,i,j,a[5];
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i = 0; i < n; i++)    
    {    
      for(j = 0; j < n; j++)    
        {   
            if(a[j]<a[j-1])
            {
                a[j] = a[j] ^ a[j-1];
                a[j-1] = a[j] ^ a[j-1];
                a[j] = a[j] ^ a[j-1];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
