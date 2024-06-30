#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >>n>>k;

    priority_queue<int,vector<int>, greater<int>> pq;
    int sum = 0;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        if(pq.size()==k+1){
            int minele = pq.top();
            sum -= minele;
            pq.pop();
        }else{
            pq.push(x);
            sum += x;
        }
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
    cout <<"ans: "<< sum << "\n";
}
