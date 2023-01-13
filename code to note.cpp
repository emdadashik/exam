#include <bits/stdc++.h>
using namespace std;

int merge_sort_and_count_pairs(int arr[], int temp[], int left, int right, int k) {
    int mid, i, j, z, count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        count = merge_sort_and_count_pairs(arr, temp, left, mid, k);
        count += merge_sort_and_count_pairs(arr, temp, mid+1, right, k);
        i = left;
        j = mid+1;
        z = left;
        while (i <= mid && j <= right) {
            if (arr[i] + arr[j] < k) {
                temp[z++] = arr[i++];
            } else if (arr[i] + arr[j] > k) {
                temp[z++] = arr[j++];
            } else {
                count++;
                temp[z++] = arr[i++];
                temp[z++] = arr[j++];
            }
        }
        while (i <= mid) {
            temp[z++] = arr[i++];
        }
        while (j <= right) {
            temp[z++] = arr[j++];
        }
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    
    int arr[n],temp[n];
    for(int i=0 ; i<n ; i++)
        cin>>arr[i];
        
    int k;
    cin>>k;
    
    int pair_count = merge_sort_and_count_pairs(arr, temp, 0, n-1, k);
    
    cout << pair_count << endl;
    return 0;
}
