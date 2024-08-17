#include<bits/stdc++.h>
using namespace std;
int freq[100100];

int main(){
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >>v[i];
    }

    int tail = 0;
    int head = -1;
    int sum_of_len_of_subarray = 0;
    int dist_cnt = 0;
    while (tail<n)
    {
        while (head+1<n && (freq[v[head+1]]>=1 || dist_cnt<k))
        {
            head++;
            if (freq[v[head]]==0)
            {
                dist_cnt++;
            }
            freq[v[head]]++;
        }
       int len = (head - tail + 1);
       sum_of_len_of_subarray += len * (len + 1) / 2;
       if (tail > head)
       {
           tail++;
           head = tail - 1;
        }else{
            freq[v[tail]]--;
            if (freq[v[tail]]==0)
            {
                dist_cnt--;
            }
            tail++;
        }
        
    }
    cout << sum_of_len_of_subarray << "\n";
}
