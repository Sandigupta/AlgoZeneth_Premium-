#include <bits/stdc++.h>
using namespace std;
#define int long long
int cbrt_floor(int b)
{
    int ans = 0;
    int lo = 0;
    int hi = b;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        // here mid*mid*mid does not work beacuse it exceed the limmikt of (long long) if mid =1e12 or 1e8.
        //    even the mid>b/mid*mid does not work. mid*mid exceed long long limmit for mid =1e12.
        if (mid > (b / mid) / mid)
        {
            hi = mid - 1;
        }
        else
        {
            ans = mid;
            lo = mid + 1;
        }
    }
    return ans;
}

void solve()
{
    int x;
    cin >> x;

    for (int a = 1; a * a * a < x; a++)
    {
        int b = cbrt_floor(x - a * a * a);
        if (b>0 && b * b * b + a * a * a == x)
        {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
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