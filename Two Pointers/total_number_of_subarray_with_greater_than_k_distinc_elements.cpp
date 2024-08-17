#include <bits/stdc++.h>
using namespace std;
int freq[100100];

int total_subarray_with_less_than_k_dist_ele(vector<int> &v,int n, int k)
{
    
    int tail = 0;
    int head = -1;
    int total_sub_array = 0;
    int dist_cnt = 0;
    while (tail < n)
    {
        while (head + 1 < n && (freq[v[head + 1]] >= 1 || dist_cnt < k))
        {
            head++;
            if (freq[v[head]] == 0)
            {
                dist_cnt++;
            }
            freq[v[head]]++;
        }

        total_sub_array += (head - tail + 1);

        if (tail > head)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            freq[v[tail]]--;
            if (freq[v[tail]] == 0)
            {
                dist_cnt--;
            }
            tail++;
        }
    }
   return total_sub_array ;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int lessthn_equal=total_subarray_with_less_than_k_dist_ele(v, n, k);
    cout << n * (n + 1) / 2 - lessthn_equal<<"\n";// subarray with length greater than k.
    int greater_than_equal = total_subarray_with_less_than_k_dist_ele(v, n, k - 1);
    cout<<"for k==1"<<lessthn_equal-greater_than_equal<<"\n";

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