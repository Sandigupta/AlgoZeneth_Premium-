/*
Problem Statement:
We are given N ranges varies from Li to Ri on number line. Then you are given Q queries in form of ? Y, which means you have to return
how many ranges passes through this points. Constraints N, Q <=1e5 Li, Ri, Y <=1e9
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> li(n);
    vector<int> ri(n);
    for (int i = 0; i < n; i++)
    {
        int lo, up;
        cin >> lo >> up;

        li.push_back(lo);
        ri.push_back(up);
    }
    sort(li.begin(), li.end());
    sort(ri.begin(), ri.end());
    int q;
    cin >> q;
    while (q--)
    {
        int y;
        cin >> y;

        auto less_than_y = lower_bound(ri.begin(), ri.end(), y) - ri.begin();

        auto greater_than_y = upper_bound(li.begin(), li.end(), y) - li.begin();

        int ans =(greater_than_y -less_than_y);
        cout << ans << endl;
    }
}

/*........................................................................................................*/
// #include <bits/stdc++.h>
// using namespace std;

// int count_ranges( vector<int> &starts, vector<int>& ends, int Y) {
//     // Find the number of ranges that start at or before Y
//     int start_count = starts.size() - (upper_bound(starts.begin(), starts.end(), Y) - starts.begin());

//     // Find the number of ranges that ends before Y
//     int end_count = (upper_bound(ends.begin(), ends.end(), Y) - ends.begin());

//     // The number of ranges passing through Y is the overlap
//     return (starts.size() - (start_count + end_count));
// }

// int main() {
//     vector<pair<int, int>> ranges = {{1, 5}, {3, 7}, {6, 9}, {8, 11}};
//     vector<int> queries = {3, 6, 8};

//     vector<int> starts, ends;
//     for (const auto& range : ranges) {
//         starts.push_back(range.first);
//         ends.push_back(range.second);
//     }
//     sort(starts.begin(), starts.end());
//     sort(ends.begin(), ends.end());

//     for (int Y : queries) {
//         cout << count_ranges(starts, ends, Y) << endl;
//     }
// }
