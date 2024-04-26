// https://education.yandex.ru/ege/task/ad72b4d3-4107-411d-b8e9-024c69852ae0


#include <bits/stdc++.h>


typedef long long ll;
#define int ll


void setmax(int &x, const int &y) { if (x < y) x = y; }

void setmin(int &x, const int &y) { if (x > y) x = y; }

using namespace std;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;


#define endl "\n"
#define S second
#define F first
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define forn(i, n) for(int i = 0; i < ll(n); i++)
#define mp make_pair
#define pb push_back
#define sz(x) ll((x).size())

#define newln cout << endl;
#define yes "YES\n"
#define no "NO\n"

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    for (auto i: a) os << i << ' ';
    os << endl;
    return os;
}


/* ================== actual code =================== */

const int INF = 1e17;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

     freopen("27-B.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    const int MOD = 51;

    vector<vector<int>> a(n, vector<int>(3));

    int cnt = sz(a[0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cnt; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> c(n, vector<int>(MOD, INF));

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            if (i != j) {
                int t = a[0][i] + a[0][j];
                setmin(c[0][t % MOD], t);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int M = 0; M <= MOD - 1; M++) {
            for (int e1 = 0; e1 < cnt; e1++) {
                for (int e2 = 0; e2 < cnt; e2++) {
                    if (e1 == e2) continue;

                    int t = c[i-1][M] + a[i][e1] + a[i][e2];

                    if (c[i-1][M] != INF) {
                        setmin(c[i][t % MOD], t);
                    }
                }
            }
        }
    }


    int max_sum = 1e18;
    for (int i = 0; i <= MOD - 1; i++) {
        if (i != 0 && (i % 3 == 0 || i % 17 == 0) && c[n - 1][i] != INF) {
            setmin(max_sum, c[n - 1][i]);
        }

    }
    cout << max_sum;
}
