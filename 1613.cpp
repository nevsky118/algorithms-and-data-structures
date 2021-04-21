#include <vector>
#include <iostream>
#define ADD result.push_back
int main() {
    std::vector<int> result;
    unsigned int n = 0, input = 0;
    int l = 0, r = 0, i, j;
    bool isFound;
    scanf_s("%lu", &n);
    int *arr = new int [n];
    for (i = 0; i < n; i++) std::cin >> arr[i];
    scanf_s("%lu", &n);
    for (i = 0; i < n; i++) {
        isFound = false;
        scanf_s("%d%d%lu", &l, &r, &input);
        for (j = l; j <= r; j++) {
            if (input == arr[j-1]) {
                isFound = true;
                ADD(1);
                break;
            }
        }
        if (!isFound) ADD(0);
    }
    for (int k : result) printf("%d", k);
    delete[] arr;
    return 0;
}