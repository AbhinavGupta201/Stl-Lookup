#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
struct segtree
{
  // data- structure
  ll size;
  vector<ll> seg;
  // constructor
  segtree(ll n)
  {
    size = 1;
    while (size < n)
    {
      size *= 2;
    }
    // assign is used to assign a single value or to the whole of the array
    // syntax: assign(size, value)
    seg.assign(2 * size, 0);
  }
  // build the segment tree in O(n) time complexity as every node is visited exactly once
  void build(vector<ll> &a, ll x, ll lx, ll rx)
  {
    if (rx - lx == 1)
    {
      // to check if it a valid position of the vector array
      if (lx < a.size())
      {
        seg[x] = a[lx];
      }
      return;
    }
    ll m = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    seg[x] = seg[x + 1] + seg[x + 2];
  }
  void build(vector<ll> &a)
  {
    build(a, 0, 0, size);
  }
  // set the segtree tree
  // set index i with the value time complexity: O(logN)
  void set(ll i, ll v, ll x, ll lx, ll rx)
  {
    if (rx - lx == 1)
    {
      seg[x] = v;
      return;
    }
    ll m = (lx + rx) / 2;
    if (i < m)
      set(i, v,
          2 * x + 1, lx, m);
    else
      set(i, v,
          2 * x + 2, m, rx);
    seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
  }
  void set(ll i, ll val)
  {
    set(i, val,
        0,
        0, size);
  }
  ll sum(ll l, ll r, ll x, ll lx, ll rx)
  {
    if (lx >= r || rx <= l)
      return 0;
    if (lx >= l && rx <= r)
      return seg[x];
    ll s1, s2;
    ll m = (lx + rx) / 2;
    s1 = sum(l, r,
             2 * x + 1, lx, m);
    s2 = sum(l, r,
             2 * x + 2, m, rx);
    return s1 + s2;
  }
  ll sum(ll l, ll r)
  {
    return sum(l, r,
               0,
               0, size);
  }
};
void solve()
{
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}