#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllocationPages) {  // O(n)
    int student = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllocationPages) {
            return false;  // A single book has more pages than allowed
        }

        if (pages + arr[i] <= maxAllocationPages) {
            pages += arr[i];
        } else {
            student++;  // Allocate to next student
            pages = arr[i];
        }
    }

    return student <= m;  // If students required are less than or equal to m
}

int allocationBook(vector<int>& arr, int n, int m) {  // O(logN * n)
    if (m > n) {  // More students than books
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];  // Calculate total sum of pages
    }

    int ans = -1;
    int st = 0, end = sum;  // Range of possible answers

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;  // Try to find a smaller maximum allocation
        } else {
            st = mid + 1;  // Increase the minimum allocation
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2;
    cout << allocationBook(arr, n, m) << endl;  // Output: 5
    return 0;
}
