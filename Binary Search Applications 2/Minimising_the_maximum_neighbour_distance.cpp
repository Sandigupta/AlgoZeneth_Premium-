/*
In the provided code, the array `arr` is sorted to ensure that the points are in ascending order. This helps in correctly calculating the gaps between consecutive points and is crucial for the binary search logic applied later to find the minimum possible maximum difference.

Here’s a detailed explanation of why sorting the array is necessary and how the code works:

1. **Understanding the Problem**:
   - You have `n` points.
   - You can insert up to `k` additional points to minimize the maximum gap between any two consecutive points.
   - The goal is to find the smallest possible value of the maximum gap after inserting up to `k` points.

2. **Why Sorting?**:
   - Sorting ensures that the points are in ascending order. This makes it easier to compute the gaps between consecutive points accurately.
   - Without sorting, the gaps calculated between consecutive points in an unsorted array would be incorrect, leading to incorrect calculations and results.

3. **How the Code Works**:
   - **Input and Initialization**:
     ```cpp
    sort(arr, arr + n);
     cin >> n >> k;
     int lo = 1;
     int hi = 0;
     int ans = -1;
     for (int i = 1; i < n; i++) {
         cin >> arr[i];
         hi = max(hi, arr[i] - arr[i - 1]);
     }

     ```
     - The code reads the number of points `n` and the number of additional points `k` that can be inserted.
     - It initializes `lo` and `hi` for binary search, where `hi` is set to the maximum initial gap between any two points.
     - It sorts the array to ensure the points are in ascending order.

   - **Binary Search**:
     ```cpp
     while (lo <= hi) {
         int mid = lo + (hi - lo) / 2;
         if (check(mid)) {
             ans = mid;
             hi = mid - 1;
         } else {
             lo = mid + 1;
         }
     }
     cout << ans << "\n";
     ```
     - The binary search tries to find the smallest possible maximum gap.
     - `mid` represents the current guess for the maximum gap.
     - The `check` function is called to see if it's possible to ensure all gaps are less than or equal to `mid` by inserting up to `k` points.

   - **Check Function**:
     ```cpp
     int check(int mid) {
         int needed_points = 0;
         for (int i = 1; i < n; i++) {
             needed_points += (((arr[i] + arr[i - 1])+mid - 1) / mid) - 1;
         }
         if (needed_points > k)
             return 0;
         else
             return 1;
     }
     ```
     - The `check` function calculates how many additional points are needed to ensure no gap exceeds `mid`.
     - If the number of needed points is greater than `k`, it returns 0 (false), indicating `mid` is too small.
     - Otherwise, it returns 1 (true), indicating it’s possible to achieve with the given `k` points.

Sorting the array ensures that the gaps between consecutive points are calculated correctly and allows the binary search to function correctly. Without sorting, the logic for calculating gaps and inserting points would not be valid.



    #include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100100];

// Function to check if we can ensure no gap exceeds 'mid' by inserting up to 'k' points
int check(int mid) {
    int needed_points = 0;
    for (int i = 1; i < n; i++) {
        needed_points += ((arr[i] - arr[i - 1] + mid - 1) / mid) - 1;
    }
    return needed_points <= k;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int lo = 1; // The lowest possible gap can't be 0 to avoid division by zero
    int hi = 0; // Highest difference between the two points in the given inputs.
    for (int i = 1; i < n; i++) {
        hi = max(hi, arr[i] - arr[i - 1]);
    }

    int ans = -1; // Minimum difference among maximum possible differences is the answer

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // The difference possible int between lo to high
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}

*/












#include<bits/stdc++.h>
using namespace std;
int n;
int k; // total number of point you inserting from out side to minimise the gap.
int arr[100100];
int check(int mid){
    int needed_points = 0;
    for (int i = 1; i < n; i++)
    {
        needed_points += (((arr[i] - arr[i - 1])+mid - 1) / mid) - 1;
    }
    if(needed_points>k)
        return 0;
    else
        return 1;
}
int main(){
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> arr[i];
       
    }
    sort(arr, arr + n);
    int lo = 1;// lowest gat between two points
    int hi = 0;// Highest difference between the two points in the given inputs.
    int ans = -1;// minimum difference among maximum possible difference is ans.
    for (int i = 1; i < n;i++){
        hi = max(hi, arr[i] - arr[i - 1]);
    }
    

    while (lo<=hi)
    {
        int mid = lo + (hi - lo) / 2; //the difference possible int between lo to high.
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }else
        {
            lo = mid + 1;
        }

    }
    cout << ans << "\n";
}