#include <iostream>
using namespace std;

int N, M, max_element = 0;

struct temp {
    int first, second;
} vect[100017];

void inputSegment() {
    for (int i = 1; i <= N; i++) {
        cin >> vect[i].first >> vect[i].second;
        if (vect[i].second > max_element) max_element = vect[i].second;
    }
}
void queryProcessing() {
    int input[100017];
    for (int i = 1; i <= M; i++) cin >> input[i];

    int count = 0, k = 1;
    for (int i = 1; i <= M; i++) {
        if (input[i] < vect[1].first || max_element < input[i]) {
            cout << -1 << endl;
            continue;
        }
        while (input[i] >= vect[k].first) {
            count++;
            k++;
            if (k > N) break;
        }
        while (input[i] > vect[k-1].second) {
            count--;
            k--;
        }
        cout << k - 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N;
    inputSegment();

    cin >> M;
    queryProcessing();

    return 0;
}



