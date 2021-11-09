#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of array ");
    scanf("%d",&n);

    int *ptr1;
    ptr1=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        printf("Enter Values inside array ");
        scanf("%d",&ptr1[i]);
    }

    for(int i=0;i<n;i++)
    {
        printf("Values at %d are:%d\n",i,ptr1[i]);
    }

    int n2;
    printf("Enter new size of array: ");
    scanf("%d",&n2);

    ptr1=(int*)realloc(ptr1,n2);
    for(int i=0;i<n2;i++)
    {
        printf("Enter Values inside array ");
        scanf("%d",&ptr1[i]);
    }

    for(int i=0;i<n2;i++)
    {
        printf("Values at %d are:%d\n",i,ptr1[i]);
    }


    free(ptr1);

}