#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    int M, i;
    cin >> M;
    vector<int> vect;
    while (cin >> i and i != -1) vect.emplace_back(i);
    for (i = 0; i <= vect.size() - M; i++) cout << *max_element(vect.begin()+i, vect.begin()+(i+M)) << "\n";
}


