#include <iostream>
#include <algorithm>
#include <vector>
using namespace  std;

int main() {
    vector< pair<int, int> > vect, result;
    short int M; cin >> M;
    int x, y, max_right_copy = 0, max_right = 0, i = 0;

    while (cin >> x >> y) {
        if (x == 0 && y ==0) break;
        vect.emplace_back(x, y);
    }
    sort(vect.begin(), vect.end());

    while (true) {
        if (max_right >= M) break;
        max_right = 0;
        while (i < vect.size() && vect[i].first <= max_right_copy) {
            if (vect[i].second > max_right) max_right = vect[i].second;
            i++;
        }
        if (max_right == 0) { cout << "No solution"; return 0; }
            max_right_copy = max_right;
            result.emplace_back(vect[i - 1]);
        }
        cout << result.size() << "\n";
        for (auto & k : result) cout << k.first << " " << k.second << "\n";
}
