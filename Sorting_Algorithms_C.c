#include <stdio.h>
#include <stdlib.h>
// Sorting algorithms

void selection_sort(int arr[], int len);
void bubble_sort(int arr[], int len);
void insertion_sort(int arr[], int len);

void arrprint(int arr[], int len)
{
    printf("\nOutput:\n");
    int k;
    for(k=0; k<len; k++)
    {
        if (k!=len-1)
            printf("%d, ", arr[k]);
        else
            printf("%d", arr[k]);
    }
    printf("\n");
}

int main()
{
    // For given arrays
    int arr[] = {3, 7, 1, 9, 4, 6, 8, 2, 5, 0, 11, 19, 15, 12, 14, 16, 10, 13, 17, 18, 20, 23, 26, 24, 25, 22, 21, 29, 30, 28, 27, 33, 35, 32, 31, 34, 38, 36, 37, 41, 45, 48, 49, 47, 42, 44, 43, 46, 40, 39};
    int len = sizeof(arr)/ sizeof(arr[0]);

    int check;
    while(1)
    {
        printf("Which sorting algorithm do you wanna test?\n");
        printf("1-Selection Sort\n");
        printf("2-Bubble Sort\n");
        printf("3-Insertion Sort\n");
        printf("4-No Sorting\n");
        printf("5-End\n");
        printf("Input: ");
        scanf("%d", &check);

        if (check==1)
        {
            selection_sort(arr, len);
            arrprint(arr, len);
        }
        else if (check==2)
        {
            bubble_sort(arr, len);
            arrprint(arr, len);
        }
        else if (check==3)
        {
            insertion_sort(arr, len);
            arrprint(arr, len);
        }
        else if (check==4)
        {
            arrprint(arr, len);
        }
        else if (check==5)
            break;
        else
            printf("Invalid input");
        system("pause");
        system("cls");
    }
    return 0;
}

// Selection Sort
int swap(int arr[], int i1, int i2)
{
    arr[i1] += arr[i2];
    arr[i2] = arr[i1] - arr[i2];
    arr[i1] -= arr[i2];
    return 0;
}
void selection_sort(int arr[], int len)
{
    int i, j;
    // O(n^2) time complexity
    // Just going through each case and swapping if left element is greater than the right
    for (i=0; i<len; i++)
    {
        for (j=i; j<len; j++)
        {
            if (arr[i] > arr[j])
                swap(arr, i, j);
        }
    }
}

// Optimised implementation of Bubble Sort I think
int swap2(int arr[], int it)
{
    arr[it] += arr[it+1];
    arr[it+1] = arr[it] - arr[it+1];
    arr[it] -= arr[it+1];
    return 0;
}
void bubble_sort(int arr[], int len)
{
    int i, j;
    for (i=0; i<len; i++)
    {
        if (arr[i]>=arr[i+1])
        {
            swap2(arr, i);
            for (j=i; j>0; j--)
            {
                // Added a backtrack checker which reduces the number of comparisons in best case I think
                // Still suffers O(n^2) time complexity
                if (arr[j] >= arr[j-1])
                    break;
                else
                    swap2(arr, j-1);
            }            
        }
    }
}

// Insertion Sort
void insertion_sort(int arr[], int len)
{
    int i, key;
    // Starts from first index [2,3,1]
    for (i=1; i<len; i++)
    {
        // Stores the current value temporarily
        key = arr[i];
        // Loops backwards to swap each number if condition is satisfied, at i=2, [2,3,3] -> [2,2,3]
        while (i>=1 && arr[i-1]>key)
        {
            arr[i] = arr[i-1];
            i--;
        }
        // Finally replaces the current value in it's correct position [1,2,3]
        arr[i] = key;
    }
}
