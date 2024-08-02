// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;

//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     int max=-1e9;
//     int secmax;
//     // int secmax_idx = -1;
//     for (int i = 0; i < n;i++){
//         if (arr[i]>=max)
//         {   
//             secmax = max;
//             max = arr[i];
            
//         }else if(secmax<arr[i]){
//             secmax = arr[i];
//         } 
//     }

//     cout <<"Max element:"<<max << "\n" <<"Second max element:"<<secmax << "\n";
// }

// // Time complexcity is O(n).



/*------------------------------------------USING INDEX TO GET INDEX AS WELL AS ELE-----------------------------------*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max_idx=-1;
    int smax_idx=-1;
    // int secmax_idx = -1;
    for (int i = 0; i < n;i++){
        if (max_idx==-1 || arr[i]>arr[max_idx])
        {   
            smax_idx = max_idx;
            max_idx = i;
            
        }else if(smax_idx==-1 || arr[smax_idx]<arr[i]){
            smax_idx = i;
        } 
    }

    cout <<"Max element:"<<arr[max_idx]<<" "<<max_idx<< "\n" <<"Second max element:"<<arr[smax_idx]<<" "<<smax_idx<<"\n";
}

// Time complexcity is O(n).

