#include<bits/stdc++.h>
using namespace std;

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

void merge_sort(int A[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;

        merge_sort(A, left, mid);
        merge_sort(A, mid+1, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int A[] = {5,2,9,1,3};
    int n = sizeof(A)/sizeof(A[0]);

    merge_sort(A,0,n-1);

    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }

    return 0;
}


