
/*-------------------My wrong approch----------*/

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;

//         multiset<int> st;
//         int cnt = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin >> x;
//             if (st.empty())
//             {
//                 st.insert(x);
//             }
//             else
//             {
//                 if (x < *st.begin())
//                 {
//                     st.insert(x);
//                 }
//                 else
//                 {
//                     if (st.size() >= 2 || i==n-1)
//                     {
//                         cnt++;
//                         st.clear();
//                     }
//                     else
//                     {
//                         st.insert(x);
//                     }
//                 }
//             }
//         }

//         if (cnt == 0)
//             cout << n << "\n";
//         else
//             cout << cnt << "\n";
//     }
// }



#include <bits/stdc++.h>
using namespace std;

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define int long long

signed main() {
  IOS int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      auto it = s.upper_bound(x);
      if (it == s.end()) {
        s.insert(x);
      } else {
        s.erase(it);
        s.insert(x);
      }
    }
    cout << s.size() << "\n";
  }
  return 0;
}
      