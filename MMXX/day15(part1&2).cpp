#include <bits/stdc++.h>
using namespace std;

int solve(deque<int> dq, int n) {
    unordered_map<int, int> memory;
    int curr = 0, last = -1;
    for (int i = 1; i <= n; i++) {
        if (dq.size()) {
            curr = dq.front();
            dq.pop_front();
        } else {
            if (!memory.count(last)) {
                curr = 0;
            } else {
                curr = i - memory[last];
            }
        }
        memory[last] = i;
        last = curr;
    }
    return curr;
}

int main() {
	const deque<int> dq = {
        	#include "text.in"
	};
	cout << solve(dq, 2020) << endl;//1
	cout << solve(dq, 3e7) << endl;//2
	return 0;
}
