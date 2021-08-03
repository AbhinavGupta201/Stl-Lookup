/* Problem Statement;
Given a n*n board. and n queens you have to place the queens.
Rules:
    1. No queen attack each other
    2. Each row and column must have exactly one queen.
    
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool isSafe(ll row, ll col, ll n, vector<vector<ll>> &vec)
{
    // row check is safe
    for (ll i = col - 1; i >= 0; i--)
    {
        if (vec[row][i] == 1)
            return false;
    }

    // check it upper diagonal
    for (ll i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (vec[i][j] == 1)
            return false;
    }

    // check in the lower diagonal
    for (ll i = row +1, j = col - 1; i<n && j >= 0; i++, j--)
    {
        if (vec[i][j] == 1)
            return false;
    }
    return true;
}
void NQueen(ll col, ll n, vector<vector<ll>> &vec)
{
    // base case:
    if (col == n)
    {
        for (auto it : vec)
        {
            for (auto e : it)
            {
                cout << e << " ";
            }
            cout << endl;
        }
        cout<<endl;
        return;
    }
    for (ll i = 0; i < n; i++)
    {
        if (isSafe(i, col, n,vec))
        {
            vec[i][col] = 1;
            NQueen(col + 1, n, vec);
            vec[i][col] = 0;
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> vec(n, vector<ll>(n,0));
    NQueen(0, n, vec);
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