#include <bits/stdc++.h>
using namespace std;
#define int long long

struct dynamic_median
{

    multiset<int> lo, hi;
    void insert(int x)
    {
        if (!lo.empty())
        {
            auto it = lo.end();
            it--;
            if (x <= *it)
            {
                lo.insert(x);
            }
        }
        if (!hi.empty())
        {
            auto it = hi.begin();
            if (*it >= x)
            {
                hi.insert(x);
            }
        }
        lo.insert(x);
    }

    void erase(int x)
    {
        auto it = lo.end();
        it--;
        if (*it >= x)
        {
            lo.erase(lo.find(x));
        }
        else
        {
            auto v = hi.begin();
            if (*v <= x)
            {
                hi.erase(hi.find(x));
            }
        }
    }

    void rebalance()
    {
        while (lo.size() >= hi.size() + 2)
        {
            auto it = lo.end();
            it--;
            int val = *it;
            lo.erase(it);
            hi.insert(val);
        }
        while (hi.size() > lo.size())
        {
            auto it = hi.begin();
            int val = *it;
            hi.erase(it);
            lo.insert(val);
        }
    }

    int getMedian(){
        rebalance();
        auto it = lo.end();
        it--;
        return *it;
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dynamic_median med;
    med.insert(1);
    med.insert(2);
    med.insert(3);
    med.insert(4);
    med.insert(5);
    med.insert(6);
    cout << med.getMedian();
}