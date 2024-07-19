#include <bits/stdc++.h>
using namespace std;
#define int long long

struct monotonic_deque
{
    deque<int> dq;

    void insert(int x)
    {
        while ( !dq.empty()&& dq.back() > x)
        {
            dq.pop_back();
        }

        dq.push_back(x);
    }

    void remove(int x)
    {
        if (dq.front() == x)
        {
            dq.pop_front();
        }
    }

    int getMinEle(){
        return dq.front();
    }
};

signed main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    monotonic_deque mt;
    for (int i = 0; i < n; i++)
    {
        mt.insert(arr[i]);

        if(i>=k){
            mt.remove(arr[i - k]);
        }
        if (i>=k-1){
            cout<<mt.getMinEle()<<" ";
        }
        
    }
    
}


// Time complexcity is O(nlog(k))