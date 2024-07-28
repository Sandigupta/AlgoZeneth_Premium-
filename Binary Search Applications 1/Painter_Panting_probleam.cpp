#include<bits/stdc++.h>
using namespace std;

int arr[100100];
int n, k;

int check(int mid){
    int lastLeft = 0;
    int needed = 0;
    for (int i = 0; i < n; i++)
    {
        if(lastLeft>=arr[i]){
            lastLeft -= arr[i];
        }else{
            needed++;
            lastLeft = mid - arr[i];
        }
        if (needed>k)
        {
            return 0;
        }
        
    }
    if (needed>k)
    {
        return 0;
    }else
    {
        return 1;
    }
}

int main(){
    cin >> n >> k;
    int lo = 0;// min max time taken to paint the wall. 
    int hi = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        lo = max(lo, arr[i]);
        hi += arr[i];
    }
    int ans = 0;
    while (lo<=hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    cout << ans;
}