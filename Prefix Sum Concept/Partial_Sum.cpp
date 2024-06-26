/*Partial Sum
Partial sum is a technique used to efficiently compute the sum of elements in a range of an array.
Instead of repeatedly iterating through the array for each query or range sum computation, partial
sum involves precomputing cumulative sums and then using these precomputed values to quickly calculate
the sum of any range.
*/

/*
Problem Statement:
Given an array A of size N, initially all 0's. There are Q queries of the form: +LRx -> add x to all indices
in the range [L, R]. After all queries, you need to find the final array.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[n];
    memset(arr, 0, sizeof(arr));

    int q;
    cin >> q;

    while (q--)
    {
        int l, r, x;
        cin >> l >> r;

        arr[l] += x;
        if (r + 1 < n)
            arr[r + 1] += -x;
    }

    // prifix sum
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            arr[i] += arr[i - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}





/*.............................................................................................................................*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N, 0); // Initialize the array with zeros

    // Process queries
    while (Q--) {
        int L, R, x;
        cin >> L >> R >> x;

        // Update the partial sum array
        arr[L - 1] += x;
        if (R < N) {
            arr[R] -= x;
        }
    }

    // Compute final array using partial sum
    for (int i = 1; i < N; ++i) {
        arr[i] += arr[i - 1];
    }

    // Print the final array
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
