#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define i2 array<int,2>
#define PB push_back
using namespace std;
typedef long long ll;
const int md = int(1e7) + 7;
const int N = 55;
const int oo = 2e9;
int a[N][N], n, m, step[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int mrk[N][N], tt, ans;
bool bad;
bool used[N][N];

void dfs(int x, int y, int vl) {
    if (mrk[x][y] == tt) return;
    if (bad) return;

    mrk[x][y] = tt;

    if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
        bad = 1;
        return;
    }

    for (int it = 0; it < 4; it++) {
        int cx = x + step[it][0];
        int cy = y + step[it][1];

        if (a[cx][cy] >= vl) continue;

        dfs(cx, cy, vl);
    }
}

bool ok(int x, int y, int md) {
    bad = 0;
    tt++;

    dfs(x, y, a[x][y] + md);

    return (!bad);
}

void color(int x, int y, int vl) {
    if (used[x][y]) return;

    used[x][y] = 1;

    if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
        exit(-1);
    }

    ans += vl - a[x][y];

    for (int it = 0; it < 4; it++) {
        int cx = x + step[it][0];
        int cy = y + step[it][1];

        if (a[cx][cy] >= vl) continue;

        color(cx, cy, vl);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

#ifdef _LOCAL
    freopen("in.txt", "r", stdin);
#endif // _LOCAL

    int qq; cin >> qq;

    for (; qq; qq--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                used[i][j] = 0;
            }

        ans = 0;

        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < m - 1; j++) {
                if (used[i][j]) continue;

                if (!ok(i, j, 0)) {
                    used[i][j] = 1;
                    continue;
                }

                int l = 0, r = int(1e4);

                while (l < r) {
                    int md = (l + r + 1) >> 1;

                    if (ok(i, j, md))
                        l = md;
                    else r = md - 1;
                }

                color(i, j, a[i][j] + l);
            }

        cout << ans << '\n';
    }

    return 0;
}