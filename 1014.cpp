#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<long long int> vector;
    long long int N, k = 0;
    cin >> N;

    if (N > 0 && N <= 9) cout << N;
    else if (N == 0) cout << 10;
    else {
        for (int i = 9; i > 1; i--) {
            while (N % i == 0) {
                vector.push_back(i);
                N /= i;
            }
        }
        if (N != 1) cout << -1;
        else {
            reverse(vector.begin(),vector.end());
            for (long long i : vector) cout << k*10 + i;
        }
    }
    return 0;
}