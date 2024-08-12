#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int head = -1;
    int tail = 0;
    // answer maintain
    int max_len = 0;
    // datastructure for window
    int cnt_zero = 0;

    // for every start
    while (tail < n)
    {   
        // eat as many element as possible till its valid
        while (head+1 < n && (v[head + 1] == 1 || cnt_zero < k))
        {
            head++;
            if(v[head]==0)
            cnt_zero++;
        }
        // update the max length fro current start 
        max_len = max(max_len, head - tail + 1);
        // move start one step forward
        if (tail > head)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            if (v[tail] == 0)
            {
                cnt_zero--;
            }
            tail++;
        }
    }
    cout << max_len << '\n';
}

// while(num_zero==k && v[ptr2+1]!=0)
//          {
//              ptr2++;
//              max_len = (ptr2 - ptr1 + 1);
//          }
//          if(num_zero==k && v[ptr2+1]==0){

//              ptr1++;
//          }
//          else{
//              ptr2++;
//          }