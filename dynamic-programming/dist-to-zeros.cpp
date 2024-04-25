// https://education.yandex.ru/ege/task/3d6293ee-53c2-4c63-ba3e-94a4d126ce26


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

     freopen("27B.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pref(n + 1, -1);
    vector<int> suff(n + 1, -1);
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            pref[i + 1] = 0;
        } else if (pref[i] != -1) {
            pref[i + 1] = pref[i] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            suff[i] = 0;
        } else if (suff[i + 1] != -1){
            suff[i] = suff[i + 1] + 1;
        }
    }

    vector<int> dist(n, 0);
    for (int i = 0; i < n; i++) {
        if (pref[i + 1] != -1) {
            dist[i] = pref[i + 1];
        } else {
            dist[i] = 1e9;
        }

    }
    for (int i = 0; i < n; i++) {
        if (suff[i] != -1) {
            dist[i] = min(dist[i],suff[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (pref[i + 1] == suff[i] == -1) {
            cout << 42 << ' ';
        }
        if (dist[i] == -1) cout << '7' << ' ';
    }

    cout << accumulate(all(dist), 0ll);
}
