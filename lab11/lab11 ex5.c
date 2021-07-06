#include<stdio.h>

//combinari de n luate cate k
int a[20],b[20];

void back(int k,int x,int y)
{
     if(k-1 == y)
     {
         for(int i = 1; i <= y;i++)
           printf("%d ",a[i]);
         printf("\n");
     }
     else
     {
         for(int  i = 1; i <= x; i++)
            if(!b[i] && a[k-1] < i)
           {
                 a[k] = i;
                 b[i] = 1;
                 back(k+1,x,y);
                 b[i] = 0;
           }
     }
}

int main()
{
    int n,k;
    printf("n=");
    scanf("%d",&n);
    printf("k=");
    scanf("%d",&k);
    printf("Combinari de %d luate cate %d:\n", n, k);
    back(1,n,k);
    return 0;
}

//aranjamente de n luate cate k

/*int a[20],b[20];

void back(int k,int x,int y)
{
     if(k-1 == y)
     {
         for(int i = 1; i <= y;i++)
           printf("%d ",a[i]);
         printf("\n");
     }
     else
     {
         for(int  i = 1; i <= x; i++)
            if(!b[i])
           {
                 a[k] = i;
                 b[i] = 1;
                 back(k+1,x,y);
                 b[i] = 0;
           }
     }
}

int main()
{
    int n,k;
    printf("n=");
    scanf("%d",&n);
    printf("k=");
    scanf("%d",&k);
    printf("Aranjamente de %d luate cate %d:\n", n, k);
    back(1,n,k);
    return 0;
}
