#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 冒泡排序：每轮把当前未排序部分的最大值"冒"到末尾
void bubbleSort(vector<int>& arr) {
    const size_t n = arr.size();
    for (size_t i = 0; i + 1 < n; ++i) {
        bool swapped = false;                  // 本轮是否发生交换
        for (size_t j = 0; j + 1 < n - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;                   // 已经有序，提前结束
    }
}

void print(const vector<int>& arr) {
    for (int x : arr) cout << x << ' ';
    cout << '\n';
}

int main() {
    vector<int> arr = {5, 3, 8, 1, 9, 2, 7, 4, 6, 0};

    cout << "排序前: ";
    print(arr);

    bubbleSort(arr);

    cout << "排序后: ";
    print(arr);

    // 用标准库结果校验一遍
    vector<int> expected = arr;
    sort(expected.begin(), expected.end());
    cout << (arr == expected ? "校验通过 ✓" : "校验失败 ✗") << '\n';

    return 0;
}
