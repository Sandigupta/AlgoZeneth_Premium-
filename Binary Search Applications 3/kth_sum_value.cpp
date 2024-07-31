#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
vector<int> arr, brr;

int check(int mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += upper_bound(brr.begin(), brr.end(), mid - arr[i]) - brr.begin();
    }

    return cnt >= k;
}

void solve()
{
    cin >> n >> m >> k;
    arr.resize(n);
    brr.resize(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }
    if (n > m)
    {
        swap(n, m);
        swap(arr, brr);
    }

    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    int lo = arr[0] + brr[0];
    int hi = arr.back() + brr.back();
    int ans = hi;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
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