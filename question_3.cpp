#include <iostream>
#include <deque>
using namespace std;

void printFirstNegativeInteger(int arr[], int n, int k) {
    deque<int> dq;

   for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    for (int i = k; i <= n; i++) {
        // 如果佇列不為空，則佇列前端的元素是第一個負數
        if (!dq.empty()) {
            cout << arr[dq.front()] << " ";
        } else {
            // 如果佇列為空，則輸出 0
            cout << "0 ";
        }

        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        if (i < n && arr[i] < 0) {
            dq.push_back(i);
        }
    }
}

int main() {
    int arr[] = {-8, 2, 3, -6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printFirstNegativeInteger(arr, n, k);

    return 0;
}
