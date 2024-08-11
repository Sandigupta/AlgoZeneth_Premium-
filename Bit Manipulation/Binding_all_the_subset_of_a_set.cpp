#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=3;
    int arr[] = {2, 3, 7};

    for (int mask = 0; mask <8; mask++)
    {
        cout<<mask<<"("<<bitset<3>(mask)<<"):{";
        for (int pos = 0; pos < n; pos++)
        {
            if ((mask>>pos)&1)
            {
                cout <<arr[pos] << ",";
            }
        }
        cout << "}\n";
    }
    
}