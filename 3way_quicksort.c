#include <stdio.h>
void swap(int a, int b){
    int temp;
    temp = a;
    a = b;  
    b = temp;
}

void quicksort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }

    if (arr[high] < arr[low]) {
        swap(arr[high], arr[low]);
    }

    int pivot1 = arr[low];
    int pivot2 = arr[high];

    int i = low + 1;
    int lt = low + 1;
    int gt = high - 1;

    while (i <= gt) {
        if (arr[i] < pivot1) {
            swap(arr[i], arr[lt]);
            lt++;
            i++;
        } else if (arr[i] > pivot2) {
            swap(arr[i], arr[gt]);
            gt--;
        } else {
            i++;
        }
    }

    swap(arr[low], arr[lt - 1]);
    swap(arr[high], &arr[gt + 1]);

    quicksort(arr, low, lt - 2);
    quicksort(arr, gt + 2, high);

    if (gt - lt > 0) {
        quicksort(arr, lt, gt);
    }
}



int main(){
    int i,arr[10],n;
    printf("Number of elements:");
    scanf("%d",&n);
    printf("Array is:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("Array is:");
    for ( i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
    
}