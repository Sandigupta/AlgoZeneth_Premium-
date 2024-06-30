#include <iostream>
#include <set>
using namespace std;

struct MyDataStructure {
    int k;
    multiset<int> mt1, mt2;
    int sumk;

    void initi(int k_) {
        k = k_;
        sumk = 0;
        mt1.clear();
        mt2.clear();
    }

    void insert(int x) {
        mt1.insert(x);
        sumk += x;
        if (mt1.size() == k + 1) {
            auto it = mt1.begin();
            sumk -= *it;
            mt2.insert(*it);
            mt1.erase(it);
        }
    }

    void remove(int x) {
        if (mt1.find(x) != mt1.end()) {
            mt1.erase(mt1.find(x));
            sumk -= x;
        } else if (mt2.find(x) != mt2.end()) {
            mt2.erase(mt2.find(x));
        }
        if (mt1.size() < k && !mt2.empty()) {
            auto it = mt2.end();
            it--;
            int val = *it;
            mt2.erase(it);
            mt1.insert(val);
            sumk += val;
        }
    }

    int getSum() {
        return sumk;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    MyDataStructure ds;
    ds.initi(3);  // Example initialization with k=3
    ds.insert(5);
    ds.insert(1);
    ds.insert(3);
    ds.insert(8);
    ds.insert(7);
    cout << "Sum of largest 3 elements: " << ds.getSum() << endl;  // Should output the sum of the largest 3 elements

    ds.remove(8);
    cout << "Sum of largest 3 elements after removing 8: " << ds.getSum() << endl;  // Should update the sum

    return 0;
}
