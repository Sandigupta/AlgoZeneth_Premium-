/*
Question:
Write a C++ program that, for each test case, calculates the total number of subarrays in a given array that contain at most k zeros.
The program should read multiple test cases, each containing an array and a value k, and output the total count of such subarrays for each test case.

Details:

The first line of the input contains the number of test cases t.
For each test case:
The first line contains two integers n (size of the array) and k (maximum number of zeros allowed in a subarray).
The second line contains n integers representing the array.
For each test case, output the total number of subarrays that contain at most k zeros.
Constraints:


1≤t≤100

1≤n≤100,000

0≤k≤n
The array elements can be either 0 or 1.

*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
int arr[100100];
int pref[100100];
int numZero(int l, int r)
{
    return (r - l + 1) - (pref[r] - (l > 0 ? pref[l - 1] : 0));
}

int check(int st, int mid)
{
    return numZero(st, mid) <= k;
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pref[i] = arr[i];
        if (i)
        {
            pref[i] += pref[i - 1];
        }
    }
    int total = 0;
    for (int st = 0; st < n; st++)
    {
        int lo = st;
        int hi = n - 1;
        int ans = st - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(st, mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        total += (ans - st + 1);
        // longest_subarray = max(total, (ans - st + 1));
    }
    cout << total << "\n";
    // cout << longest_subarray << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}