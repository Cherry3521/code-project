#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Merge two halves using single temp array
    void merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int i = left;    // left pointer
        int j = mid + 1; // right pointer
        int k = left;    // temp pointer

        while(i <= mid && j <= right){
            if(arr[i] <= arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }

        while(i <= mid) temp[k++] = arr[i++];
        while(j <= right) temp[k++] = arr[j++];

        for(int t = left; t <= right; t++) arr[t] = temp[t];
    }

    void mergeSort(vector<int>& arr, vector<int>& temp, int left, int right){
        if(left >= right) return;

        int mid = left + (right - left)/2;

        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid+1, right);
        merge(arr, temp, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n); // single temp array
        mergeSort(nums, temp, 0, n-1);
        return nums;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    vector<int> sorted = sol.sortArray(nums);

    for(int x : sorted) cout << x << " ";
    cout << endl;

    return 0;
}
