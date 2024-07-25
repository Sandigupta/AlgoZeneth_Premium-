#include<bits/stdc++.h>
using namespace std;
int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    int a1 = max(x1, x3);
    int b1 = max(y1, y3);
    int a2 = min(x2, x4);
    int b2 = min(y2, y4);

    int area_intersection = 0;
    if(a1<=a2 && b1<=b2){
       area_intersection=(a2 - a1) * (b2 - b1);
    }
   
    int area_rect1 = (x2 - x1) * (y2 - y1);
    int area_rect2 = (x4 - x3) * (y4 - y3);

    cout<<"Area Intersection: "<<area_intersection<<"\n"<<"Area of rectangle: "<<area_rect1*area_rect2-area_intersection<<"\n";
}