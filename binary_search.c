#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x){
while(l<=r){
    int mid = (l+r)/2;
    if(arr[mid] == x){
        return mid;
    }
    else if (arr[mid]<x)
    {
        l=mid+1;
        return binarySearch(arr,l,r,x);
    }
    else {
       r=mid-1;
       return binarySearch(arr,l,r,x);
    }
    
}
return -1;
}


void main(){
  int i, first, last, n, search, array[100], index;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &array[i]);

  printf("Enter value to find\n");
  scanf("%d", &search);

  first = 0;
  last = n - 1;

  index = binarySearch(array, first, last, search);
 
  if (index == -1)
    printf("Not found! %d isn't present in the list.\n", search);
  else
    printf("%d is present at location %d.\n", search, index + 1);
 
  
}