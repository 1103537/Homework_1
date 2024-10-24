#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue length is not even!" << endl;
        return;
    }

    // �Ыؤ@���{�ɶ��C�Ӧs�x�e�b��������
    queue<int> firstHalf;

    // �N���C���e�b�������������{�ɶ��C��
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // ������J�Ĥ@�b�����M�ĤG�b����������
    while (!firstHalf.empty()) {
        // �����J�{�ɶ��C�������� (�Y��Ӫ��Ĥ@�b����)
        q.push(firstHalf.front());
        firstHalf.pop();

        // �A���J�Ѿl���C�������� (�Y��Ӫ��ĤG�b����)
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    // ��l�ƶ��C
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // �i�����ާ@
    interleaveQueue(q);

    // ���L����᪺���C
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
