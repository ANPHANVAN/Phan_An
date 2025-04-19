#include <iostream>

using namespace std;

const int MAXN = 12005;

struct Booking {
    int start;
    int end;
    int cost;
};

Booking bookings[MAXN];
int dp[MAXN]; // dp[i] là lợi nhuận tối đa đến đơn thứ i

// Hàm tìm đơn gần nhất trước đó mà kết thúc trước khi đơn thứ i bắt đầu
int binarySearch(int i) {
    int l = 0, r = i - 1, res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (bookings[mid].end < bookings[i].start) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> bookings[i].start >> bookings[i].end >> bookings[i].cost;
    }

    // Khởi tạo dp[0]
    dp[0] = bookings[0].cost;

    for (int i = 1; i < n; i++) {
        int j = binarySearch(i);
        int include = bookings[i].cost;
        if (j != -1) include += dp[j];
        dp[i] = max(dp[i - 1], include);
    }

    cout << dp[n - 1] << endl;
    return 0;
}
