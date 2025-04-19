#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int start[12001], end[12001], money[12001];

    for (int i = 0; i < n; i++) {
        cin >> start[i] >> end[i] >> money[i];
    }

    int maxMoney = 0;

    for (int i = 0; i < n; i++) {
        int currentMoney = money[i];
        int lastEnd = end[i];

        for (int j = i + 1; j < n; j++) {
            if (start[j] >= lastEnd) {
                currentMoney += money[j];
                lastEnd = end[j];
            }
        }

        if (currentMoney > maxMoney) {
            maxMoney = currentMoney;
        }
    }

    cout << maxMoney << endl;

    return 0;
}