#include <vector>
#include <iostream>
#include <queue>

using namespace std;

queue<int> inputBilliardBalls(int N) {
    queue<int> queue;
    int ballNum;
    for (int i = 0; i < N; i++) {
        cin >> ballNum;
        queue.push(ballNum);
    }
    return queue;
}

vector<int> queryProcessing(int N, queue<int> &queue) {
    vector<int> vector;
    int iterator = 1;
    vector.emplace_back(0);
    for (int i = 0; i < N; i++) {
        while (vector.back() != queue.front()) {
            vector.emplace_back(iterator);
            if (iterator != N) iterator++;
            else break;
        }

        if (vector.back() == queue.front()) {
            vector.pop_back();
            queue.pop();
        }
    } vector.pop_back();
    return vector;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int N; cin >> N;
    queue<int> queue = inputBilliardBalls(N);

    vector<int> vector = queryProcessing(N, queue);

    puts (vector.empty() ? "Not a proof" : "Cheater");

    return 0;
}

