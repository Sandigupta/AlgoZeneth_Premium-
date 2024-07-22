#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<int> nse;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && v[st.top()] >= v[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                nse.push_back(st.top()+1);
            }
            else
            {
                nse.push_back(0);
            }
            st.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            cout << nse[i]<< " ";
         }
        
    }
}