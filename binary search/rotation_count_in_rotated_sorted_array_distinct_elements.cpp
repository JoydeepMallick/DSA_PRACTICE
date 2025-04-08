int findKRotation(vector<int> &arr){
    //right rotated r times meaning min shifted by r times to right
    //find position of min mean found r
    int n = arr.size(),low = 0, high = n-1;  
    int minind = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        //if entire array was sorted, we know all element are distinct
        if(arr[low] <= arr[high]){
            if(minind == n || arr[low] < arr[minind]){
                minind = low;
            }
            break;
        }

        //check if left is sorted
        else if(arr[low] <= arr[mid]){
            if(minind == n || arr[low] < arr[minind]){
                minind = low;
            }
            //jump to unsorted
            low = mid+1;
        }
        //check if right is sorted
        else if(arr[mid] <= arr[high]){
            if(minind == n || arr[mid] <= arr[minind]){
                minind = mid;
            }
            high = mid-1;
        }
    }
    return minind;
}