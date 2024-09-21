#include <bits/stdc++.h>
using namespace std;
//dirs:N-0,E-1,S-2,W-3;
const int dirX[]= {0,1,0,-1};
const int dirY[]= {1,0,-1,0};
int x, y, dir = 1;

void rotate(int r) {
    dir += r + 4;
    dir %= 4;
}

int main() {
    freopen("text.in", "r", stdin);
    char s[10];
    while (cin >> s) {
        char c = s[0];
        int a = atoi(s + 1);
        switch (c) {
            case 'L': {
                rotate(-a / 90);
                break;
            }
            case 'R': {
                rotate(a / 90);
                break;
            }
            case 'N': {
                y += a;
                break;
            }
            case 'E': {
                x += a;
                break;
            }
            case 'S': {
                y -= a;
                break;
            }
            case 'W': {
                x -= a;
                break;
            }
            case 'F': {
                if (dir & 1) {
                    x += dirX[dir] * a;
                } else {
                    y += dirY[dir] * a;
                }
                break;
            }
        }
        //cerr << x << ' ' << y << endl;
    }
    cout << abs(x) + abs(y) << endl;
    return 0;
}
