#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int batdau[12001], ketthuc[12001], tien[12001];
    for (int i = 0; i < n; i++) {
        cin >> batdau[i] >> ketthuc[i] >> tien[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ketthuc[i] > ketthuc[j]) {
                int temp = ketthuc[i];
                ketthuc[i] = ketthuc[j];
                ketthuc[j] = temp;
                temp = batdau[i];
                batdau[i] = batdau[j];
                batdau[j] = temp;
                temp = tien[i];
                tien[i] = tien[j];
                tien[j] = temp;
            }
        }
    }
    int maxTien = 0;
    for (int i = 0; i < n; i++) {
        int currentTien = tien[i];
        int lastEnd = ketthuc[i];
        for (int j = i + 1; j < n; j++) {
            if (batdau[j] >= lastEnd) {
                currentTien += tien[j];
                lastEnd = ketthuc[j];
            }
        }
        if (currentTien > maxTien) maxTien = currentTien;
    }
    cout << maxTien;
    return 0;
}