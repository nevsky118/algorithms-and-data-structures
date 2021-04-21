#include <iostream>
#include <algorithm>
#include <vector>
using namespace  std;
#define X first
#define Y second

int main() {
    vector< pair<int, int> > vect, temp, res;
    int n, x, y, j; cin >> n;
    auto i = 0;
	
    while (i < n) {
        cin >> x >> y;
        vect.emplace_back(min(x, y), max(x, y)); 
        i++;
    } sort(vect.begin(), vect.end()); 

    for (j = 0; j < n; j++) temp.emplace_back(0,0); 

    for (i = 0; i < n; i++) {
        temp[i].X = 1;
        temp[i].Y = -1;
        for (j = i - 1; j >= 0; j--) {
            if ((vect[j].Y <= vect[i].X) && (temp[i].X < temp[j].X + 1)) {
                temp[i].X = temp[j].X + 1;
                temp[i].Y = j;
            }
        }
    }
    i = temp.size() - 1;

    while (temp[i].Y != -1) {
        res.emplace_back(vect[i]);
        i = temp[i].Y;
    } res.emplace_back(vect[i]);
	
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (j = 0; j < res.size(); j++) cout << res[j].X << " " << res[j].Y << "\n";
    return 0;
}
