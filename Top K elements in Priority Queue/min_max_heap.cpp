#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Max-Heap
    priority_queue<int> maxHeap;

    // Min-Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Adding elements
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(5);
    maxHeap.push(2);

    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(5);
    minHeap.push(2);

    // Printing elements of Max-Heap
    cout << "Max-Heap: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    // Printing elements of Min-Heap
    cout << "Min-Heap: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
