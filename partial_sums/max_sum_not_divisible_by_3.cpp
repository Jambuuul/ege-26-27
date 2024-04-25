// https://education.yandex.ru/ege/task/8df48c29-6e63-4187-a21c-c4079ea2d051


#include <bits/stdc++.h>


typedef long long ll;
#define int ll


void setmax (int &x, const int &y) { if (x < y) x = y; }

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



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//     freopen("27_B.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    const int MOD = 3;

    vector<vector<int>> a(n, vector<int> (2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> c(n, vector<int> (MOD, 0));

    c[0][a[0][0] % MOD] =  a[0][0];
    setmax(c[0][a[0][1] % MOD], a[0][1]);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= MOD - 1; k++) {
                int t = c[i-1][k] + a[i][j];
                c[i][t % MOD] = max(c[i][t % MOD], t);
            }
        }
    }
    int max_sum = 0;
    for (int i = 1; i <= MOD; i++) {
        setmax(max_sum, c[n - 1][i]);
    }
    cout << max_sum;
}










