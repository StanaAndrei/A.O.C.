#include <bits/stdc++.h>
using namespace std;
//dirs:N-0,E-1,S-2,W-3;
int x, y, x2 = 10, y2 = 1, dir = 1;

void rotate(int r) {
    dir += r + 4;
    dir %= 4;
    if(r < 0){
        while(r) {
            swap(x2, y2);
            x2 = -x2;
            r++;
        }
    }
    else {
        while(r) {
            swap(x2,y2);
            y2 = -y2;
            r--;
        }
    }
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
                y2 += a;
                break;
            }
            case 'E': {
                x2 += a;
                break;
            }
            case 'S': {
                y2 -= a;
                break;
            }
            case 'W': {
                x2 -= a;
                break;
            }
            case 'F': {
                x += x2 * a;
                y += y2 * a;
            }
        }
        //cerr << x << ' ' << y << endl;
    }
    cout << abs(x) + abs(y) << endl;
    return 0;
}
