#include <bits/stdc++.h>
using namespace std;

// Merge function
void merge(int A[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i=0;i<n1;i++)
        L[i] = A[left+i];

    for(int j=0;j<n2;j++)
        R[j] = A[mid+1+j];

    int i=0, j=0, k=left;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        A[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        A[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void merge_sort(int A[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;

        merge_sort(A, left, mid);
        merge_sort(A, mid+1, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int m, n;
    cin >> m >> n; // number of valid elements in nums1 and nums2

    int nums1[m+n], nums2[n];

    // Input nums1 valid elements
    for(int i=0;i<m;i++)
        cin >> nums1[i];

    // Input nums2
    for(int i=0;i<n;i++)
        cin >> nums2[i];

    // Copy nums2 into nums1 after valid elements
    for(int i=0;i<n;i++)
        nums1[m+i] = nums2[i];

    // Merge sort on combined array
    merge_sort(nums1,0,m+n-1);

    // Print sorted nums1
    for(int i=0;i<m+n;i++)
        cout << nums1[i] << " ";
}
