#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> nse(n);
    stack<int> st;
    // nearest smallest element int the left.
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && v[st.top()] >= v[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            nse[i] = st.top() + 1;
        }
        else
        {
            nse[i] = 0;
        }
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }

    // nearest smallest element from right.
    vector<int> pse(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && v[st.top()] >= v[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            pse[i] = st.top() - 1;
        }
        else
        {
            pse[i] = 0;
        }
        st.push(i);
    }

    int max_area_rec = 0;
    for (int i = 0; i < n; i++)
    {
        max_area_rec = max(max_area_rec, (pse[i] - nse[i] + 1) * v[i]);
    }

    cout << max_area_rec << " ";
}