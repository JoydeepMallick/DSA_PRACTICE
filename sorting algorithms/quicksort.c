//quicksort assuming last element as pivot(many more methods available)

#include<stdio.h>

int partition(int a[],int start,int end){
    int pivot = a[end];//pivot element
    int temp,j,ind = start-1;
    for(j = start; j <= end; j++){
        //if current element smaller than pivot
        if(a[j] < pivot){
            ind++;
            //swap values of current element and element at ind
            temp = a[ind];
            a[ind] = a[j];
            a[j] = temp;
        }
    }
    temp = a[ind+1];
    a[ind+1] = a[end];//placing the pivot at the correct position
    a[end] = temp;
    return (ind+1);
}

void quicksort(int a[],int start, int end){
    int p;
    if(start  < end){
        p = partition(a,start,end);//p is partition index
        quicksort(a,start,p-1);
        quicksort(a,p+1,end);
    }
}

int main(){
    int a[1000];
    int n,i;
    printf("Enter size of array : ");
    scanf("%d",&n);
    printf("Enter elements seperated by space : ");
    for(i = 0; i < n; i++) scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    printf("After sorting new array : ");
    for(i = 0; i < n; i++) printf("%d ",a[i]);
    return 0;
}
