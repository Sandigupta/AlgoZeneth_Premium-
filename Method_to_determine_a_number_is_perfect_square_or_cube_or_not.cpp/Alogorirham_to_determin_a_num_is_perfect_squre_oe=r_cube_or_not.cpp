#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    bool flag1 = false;
    bool flag2 = false;
    for (int i = 1; i * i <= n;i++){
        if(i*i==n){
            flag1 = true;
            break;
        }
        if(i*i*i==n){
            flag2 = true;
            break;
        }
    }

    if(flag1)
        cout << "Yes_perfect_squre" << endl;
    else
        cout << "NO_not_a_perfect_squre" << endl;

    if(flag2)
        cout << "Yes_perfect_cube" << endl;
    else
        cout << "NO_not_a_perfect_cube" << endl;

}