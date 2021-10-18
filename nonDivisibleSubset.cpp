#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    int n,k;
    cin >> n >> k;
    vi a(n);
    vi c(k);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++c[a[i] % k];
    }
    int res = min(1, c[0]);
    for (int i = 1; 2*i < k; ++i) {
        res += max(c[i], c[k-i]);
    }
    if (k % 2 == 0) res += min(1, c[k/2]);
    cout << res << endl;
    return 0;
}
