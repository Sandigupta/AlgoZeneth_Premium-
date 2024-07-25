#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    int best_idx[k];
    // for(int j=0;j<k;j++){best_idx[j]=-1;}
    memset(best_idx,-1,sizeof(best_idx));
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if(best_idx[j]==-1||arr[i]>arr[best_idx[j]]){
                for(int x=k-2;x>=j;x--){
                    best_idx[x+1] = best_idx[x];
                }
                best_idx[j] = i;
                break;
            }
        }
    }
    for(int i=0;i<k;i++){
        cout<<best_idx[i]<<" ";
    }
    cout<<endl;
    
    cout<<arr[best_idx[1]]<<" at "<<best_idx[1]<<endl;
    return 0;
}