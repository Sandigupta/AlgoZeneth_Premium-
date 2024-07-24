#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_element = INT_MIN;
    int max_idx = -1;

    // Finding the maximum element and its index
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
            max_idx = i;
        }
    }

    int smax_element = INT_MIN;
    int smax_idx = -1;

    // Finding the second maximum element and its index
    for (int i = 0; i < n; i++) {
        if (arr[i] > smax_element && arr[i] < max_element) {
            smax_element = arr[i];
            smax_idx = i;
        }
    }

    cout << "Max element: " << max_element << " " << max_idx << "\n"
         << "Second max element: " << smax_element << " " << smax_idx << "\n";

    return 0;
}
