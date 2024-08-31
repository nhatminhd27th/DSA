#include <stdio.h>

struct maxMin
{
    int max;
    int min;
};
struct maxMin findMaxMin(int *arr, int n)
{
    struct maxMin maxMinValue;
    maxMinValue.max = 0;
    maxMinValue.min = 0;
    int i = 0;
    if(n % 2 != 0)
    {
        if(arr[0] >= arr[1])    maxMinValue.max = arr[0];
        else    maxMinValue.min = arr[0];
        i = 1;
    }

    while(i < n)
    {
        if(arr[i] < arr[i+1])
        {
            if(arr[i] < maxMinValue.min)    maxMinValue.min = arr[i];
            if(arr[i+1] > maxMinValue.max)  maxMinValue.max = arr[i+1];
        }
        else
        {
            if(arr[i+1] < maxMinValue.min)  maxMinValue.min = arr[i+1];
            if(arr[i] > maxMinValue.max)    maxMinValue.max = arr[i];
        }
        i += 2;
    }
    return maxMinValue;
}

int main()
{
    int arr[] = {100, 1, 99, 2, 98, 3, 97, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct maxMin maxMinValue = findMaxMin(arr, n);
    printf("max: %d\n", maxMinValue.max);
    printf("min: %d\n", maxMinValue.min);
}
