#include <bits/stdc++.h>
using namespace std;
using Point4d = pair<pair<int, int>, pair<int, int>>;
#define makeP4D(i, j, k, l) make_pair(make_pair(i, j), make_pair(k, l))
set<Point4d> s;
int n;

void read() {
    string line;
    while (cin >> line) {
        for (int i = 0; i < (int)line.size(); i++) {
            if (line[i] == '#')
                s.insert(makeP4D(n, i, 0, 0));
        }
        ++n;
    }
}

int cnt(int i, int j, int k, int l) {
    int nr = 0;
    for (int ii = i - 1; ii <= i + 1; ii++)
        for (int jj = j - 1; jj <= j + 1; jj++)
            for (int kk = k - 1; kk <= k + 1; kk++)
                for (int ll = l - 1; ll <= l + 1; ll++) {
                    if (i == ii && j == jj && k == kk && l == ll)
                        continue;
                    if (s.count(makeP4D(ii, jj, kk, ll)))
                        nr++;
                }
    return nr;
}

int main()
{
    freopen("text.in", "r", stdin);
    read();
    int left = 0, right = n, cycle = 6;
    while (cycle--) {
        left--;
        right++;
        set<Point4d> aux;
        for (int i = left; i <= right; i++)
            for (int j = left; j <= right; j++)
                for (int k = left; k <= right; k++)
                    for (int l = left; l <= right; l++) {
                        int nr = cnt(i, j, k, l);
                        if (s.count(makeP4D(i, j, k, l))) {
                            if (nr == 2 || nr == 3)
                                aux.insert(makeP4D(i, j, k, l));
                        } else {
                            if (nr == 3)
                                aux.insert(makeP4D(i, j, k, l));
                        }
                    }
        s = aux;
    }
    cout << s.size() << endl;
    return 0;
}
