#include <bits/stdc++.h>
using namespace std;
deque<int> dq;
vector<int64_t> all;

bool isOk(int x) {
    for (int i = 0; i < 25; i++)
        for (int j = i + 1; j < 25; j++)
            if (dq[i] + dq[j] == x)
                return false;
    return true;
}

int main() {
    freopen("text.in", "r", stdin);
    for (int x, i = 1; i <= 25; i++) {
        cin >> x;
        dq.push_back(x);
        all.push_back(x);
    }
    int64_t target, sum = all[0];
    for (int x; cin >> x;) {
        if (isOk(x)) {
            target = x;
            break;
        }
        dq.push_back(x);
        dq.pop_front();
        all.push_back(x);
    }
    cout << target << endl;
    int l = 0, r = 0;
    while (sum != target) {
        if (sum < target) {
            r++;
            sum += all[r];
        } else if (sum > target) {
            sum -= all[l];
            l++;
        }
    }
    int64_t maxi = 0, mini = INT_MAX;
    for (int i = l; i <= r; i++) {
        maxi = max(maxi, all[i]);
        mini = min(mini, all[i]);
    }
    cout << maxi + mini << endl;//*/
    return 0;
}
