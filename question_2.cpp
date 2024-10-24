#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printNGE(int arr[], int n) {
    // ���|�ӫO�s����
    stack<int> s;

    // �V�q�Ӧs�x NGE ���G
    vector<int> nge(n);

    // �q�k�쥪�M���}�C
    for (int i = n - 1; i >= 0; i--) {
        // ����|�����ťB���|���ݤ����p�󵥩��e�����ɡA�������|���ݤ���
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // �p�G���|���šA�h��e������ NGE �� -1
        if (s.empty()) {
            nge[i] = -1;
        } else {
            // �_�h�A���|���ݤ����Y����e������ NGE
            nge[i] = s.top();
        }

        // �N��e�������J���|
        s.push(arr[i]);
    }

    // ���L�C�Ӥ����Ψ� NGE
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
