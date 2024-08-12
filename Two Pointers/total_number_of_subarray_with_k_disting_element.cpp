#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >>v[i];
    }
    map<int, int> mp;
    int tail = 0;
    int head = -1;
    int total_sub_array = 0;
    int dist_cnt = 0;
    while (tail<n)
    {
        while (head+1<n && (mp[v[head+1]]>=1 || dist_cnt<k))
        {
            head++;
            if (mp[v[head]]==0)
            {
                dist_cnt++;
            }
            mp[v[head]]++;
        }
        total_sub_array += (head - tail + 1);
        if (tail>head)
        {
            tail++;
            head = tail - 1;
        }else{
            mp[v[tail]]--;
            if (mp[v[tail]]==0)
            {
                dist_cnt--;
            }
            tail++;
        }
        
    }
    cout << total_sub_array << "\n";
}