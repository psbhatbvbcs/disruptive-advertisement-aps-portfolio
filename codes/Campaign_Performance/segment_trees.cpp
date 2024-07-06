/*
    * built on top of segment trees
    * uses O(log n) time
    * can also be done with lookup table but for small arrays
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void build(ll ind, ll low, ll high, vector<ll> &a, vector<ll> &seg)
{
    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }

    ll mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, a, seg);
    build(2 * ind + 2, mid + 1, high, a, seg);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

ll query(ll ind, ll low, ll high, ll l, ll r, vector<ll> &seg)
{
    if (low >= l && high <= r)
    {
        return seg[ind];
    }

    if (high < l || low > r)
    {
        return INT_MAX;
    }

    ll mid = (low + high) / 2;
    ll left = query(2 * ind + 1, low, mid, l, r, seg);
    ll right = query(2 * ind + 2, mid + 1, high, l, r, seg);

    return min(left, right);
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> seg(4 * n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    build(0, 0, n - 1, a, seg);

    ll l, r;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        ll ans = query(0, 0, n - 1, l-1, r-1, seg);
        cout << ans << endl;
    }
}