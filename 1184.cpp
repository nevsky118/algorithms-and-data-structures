#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int N, K, a, b, min = 1, max = 10000000, length, count, result = 0;
    scanf_s("%d %d", &N, &K);
    int *array = new int[N];
    for (int i = 0; i < N; ++i) {
        scanf_s("%d%*c%d", &a, &b);
        array[i] = 100 * a + b;
    }
    while (min <= max) {
        length = (min + max) / 2;
        count = 0;
        for (int i = 0; i < N; i++) count += (array[i] / length);
        if (count < K) max = length - 1;
        else {
            min = length + 1;
            result = length;
        }
    }
    cout << result / 100 << "." << setw(2) << setfill('0') << result % 100;
    delete[] array;
}