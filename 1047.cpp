#include <iostream>
#include <iomanip>
using namespace  std;
int main()
{
    auto *c = new float[3000];
    int i, k, N;
    float sum = 0, a0, an;
    cin >> N >> a0 >> an;

    for (i = 0; i < N; i++) cin >> c[i];
    for (i = 0, k = N; i < N; i++, k--) sum = sum + float(k) * c[i];

    cout << fixed << setprecision(2) << (float(N) * a0 + an - sum * 2) / float(N + 1) << "\n";
    delete[] c;
}