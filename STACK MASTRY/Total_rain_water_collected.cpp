#include <bits/stdc++.H>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    stack<int> st;
    vector<int> nge(n);
    // Next greatest element from left to right
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && v[st.top()] <= v[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            nge[i] = st.top();
        }
        else
        {
            nge[i] = 0;
        }
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    // net gretest eleemnt from right to left
    vector<int> pge;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && v[st.top()] <= v[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            pge[i] = st.top();
        }
        else
        {
            pge[i] = 0;
        }
        st.push(i);

    }

    int total_water_trap = 0;
    for (int i = 0; i < n; i++)
    {
        int min_ = min(nge[i], pge[i]);
        total_water_trap += (v[min_] - v[i]) * (min_ - i);
    }
    cout << total_water_trap;
}

