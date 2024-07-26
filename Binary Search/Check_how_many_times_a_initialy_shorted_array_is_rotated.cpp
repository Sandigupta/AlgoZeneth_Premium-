#include<bits/stdc++.h>
using namespace std;

int check(int mid, int arr[],int n){
    if(arr[mid]<=arr[n-1]){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int lo = 0;
    int hi = n - 1;
    int ans = 0;
    \
    while(lo<=hi){
        int mid = lo + (hi - lo) / 2;
        if(check(mid,arr,n)==0){
            lo = mid + 1;
        }else{
            ans = mid;
            hi = mid - 1;
        }
    }
    cout << ans << "\n";
}