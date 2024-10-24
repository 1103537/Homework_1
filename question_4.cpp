#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue length is not even!" << endl;
        return;
    }

    // 創建一個臨時隊列來存儲前半部分元素
    queue<int> firstHalf;

    // 將隊列的前半部分元素移到臨時隊列中
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // 交錯插入第一半部分和第二半部分的元素
    while (!firstHalf.empty()) {
        // 先插入臨時隊列中的元素 (即原來的第一半部分)
        q.push(firstHalf.front());
        firstHalf.pop();

        // 再插入剩餘隊列中的元素 (即原來的第二半部分)
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    // 初始化隊列
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // 進行交錯操作
    interleaveQueue(q);

    // 打印交錯後的隊列
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
