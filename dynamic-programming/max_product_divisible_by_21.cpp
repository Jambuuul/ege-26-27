// https://education.yandex.ru/ege/task/b0d4e72e-b754-4eaf-9262-000c8eac0a86


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
    for (int i = 0; i < n; i++ ){
        cin >> a[i];
    }
    int max_21 = -1, max_3 = -1, max_7 = -1;
    int ind_21 = -1;
    int ind_7 = -1, ind_3 = -1;
    sort(all(a));
    for (int i = 0; i < n; i++) {
        if (a[i] % 21 == 0) {
            ind_21 = i;
        }
        if (a[i] % 7 == 0) {
            ind_7 = i;
        }
        if (a[i] % 3 == 0 && (ind_7 == -1 || i != ind_7)) {
            ind_3 = i;
        }
    }
    int res_21 = -1;
    if (ind_21 != -1) {
        int second_max = -1;
        for (int i = 0; i < n; i++) {
            if (i != ind_21) {
                second_max = a[i];
            }
        }
        res_21 = a[ind_21] * second_max;
    }
    int res_37 = -1;
    if (ind_3 != -1 && ind_7 != -1) {
        res_37 = a[ind_3] * a[ind_7];
    }
    cout << max(res_37, res_21);
}
