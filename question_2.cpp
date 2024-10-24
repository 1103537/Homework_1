#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printNGE(int arr[], int n) {
    // 堆疊來保存元素
    stack<int> s;

    // 向量來存儲 NGE 結果
    vector<int> nge(n);

    // 從右到左遍歷陣列
    for (int i = n - 1; i >= 0; i--) {
        // 當堆疊不為空且堆疊頂端元素小於等於當前元素時，移除堆疊頂端元素
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // 如果堆疊為空，則當前元素的 NGE 為 -1
        if (s.empty()) {
            nge[i] = -1;
        } else {
            // 否則，堆疊頂端元素即為當前元素的 NGE
            nge[i] = s.top();
        }

        // 將當前元素推入堆疊
        s.push(arr[i]);
    }

    // 打印每個元素及其 NGE
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    printNGE(arr, n);

    return 0;
}
