#include <bits/stdc++.h>
using namespace std;

bool isSubset(int arr1[], int arr2[], int n, int m) {
    sort(arr2, arr2+m); 
    for (int i = 0; i < n; i++) {
        int key = arr1[i];
        int left = 0;
        int right = m - 1;
        bool found = false;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr2[mid] == key) {
                found = true;
                break;
            } else if (arr2[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (!found) { 
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    int arr1[n];
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr1[i];
    }
    
    int m;
    cin>>m;
    int arr2[m];
    for(int i=0 ; i<m ; i++)
    {
        cin>>arr2[i];
    }
    
    if (isSubset(arr1, arr2, n, m)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
