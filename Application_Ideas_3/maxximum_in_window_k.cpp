#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    multiset<int> mt;
    
    for (int i = 0; i < n; i++)
    {
        mt.insert(arr[i]);
        if(i>=k){
            mt.erase(mt.find(arr[i - k]));
        }

        if (i>=k-1)
        {
            cout << *mt.begin() << " ";
        }
        
    }
    
}