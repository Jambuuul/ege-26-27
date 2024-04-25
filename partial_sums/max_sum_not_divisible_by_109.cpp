// https://education.yandex.ru/ege/task/33fee015-674c-4deb-9824-14414a8d9ff9


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

     freopen("27_B.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int> (3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> c(n, vector<int> (109, 0));

    c[0][a[0][0] % 109] = a[0][0];
    c[0][a[0][1] % 109] = a[0][1];
    c[0][a[0][2] % 109] = a[0][2];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k <= 108; k++) {
                int t = c[i-1][k] + a[i][j];
                c[i][t % 109] = max(c[i][t % 109], t);
            }
        }
    }
    cout << *max_element(all(c[n-1]));
}
