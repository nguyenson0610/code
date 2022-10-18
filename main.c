
#include<stdio.h>
#include <stdlib.h>

void mintomax(int a[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        
    }
}

void maxtomin(int a[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if(a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        
    }
    
}

struct typeArr
{
    int *arr;
    int size;
};

struct typeArr *nhapmang()
{
    int size;
    int *ptr;
    static struct typeArr arr;
    printf("nhap so luong mang la ");
    scanf("%d", &size);

    ptr = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        printf("nhap arr[%d] = ", i);
        scanf("%d", &ptr[i]);
    }
    arr.size =size;
    arr.arr = ptr;

    return &arr;
}

void xuatmang(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("ptr[%d] = %d\n",i , a[i]);
    }
}

int main(int argc, char const *argv[])
{
    struct typeArr *test;
    
    test = nhapmang();
    xuatmang(test->arr, test->size);
    printf("xuat mang la \n");

    mintomax(test->arr, test->size);
    printf("xuat mang tu nho den lon la \n");
    xuatmang(test->arr, test->size);

    maxtomin(test->arr, test->size);
    printf("xuat mang tu lon den nho la \n");
    xuatmang(test->arr, test->size);

    return 0;
}