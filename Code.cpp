#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define ln "\n"
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)   // Replaced loop with FOR
#define rFOR(i, a, b) for (int i = (a); i >= (b); i--) // Replaced rloop with rFOR
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define print(x) cout << x << ln
#define scan(x) cin >> x
#define multicase \
  int t;          \
  scan(t);        \
  while (t--)     \
    solve();
#define GG return 0;
void solve()
{
  int n;
  scan(n);
  vector<vector<int>> grid(n, vector<int>(n, 0));

  int top = 0, bottom = n - 1;
  int left = 0, right = n - 1;
  int value = 0;

  while (top <= bottom && left <= right)
  {
    FOR(i, left, right + 1)
    grid[top][i] = value++;
    top++;

    FOR(i, top, bottom + 1)
    grid[i][right] = value++;
    right--;

    if (top <= bottom)
    {
      rFOR(i, right, left) grid[bottom][i] = value++;
      bottom--;
    }

    if (left <= right)
    {
      rFOR(i, bottom, top) grid[i][left] = value++;
      left++;
    }
  }

  int maxVal = n * n - 1;
  FOR(i, 0, n)
  FOR(j, 0, n) grid[i][j] = maxVal - grid[i][j];

  FOR(i, 0, n)
  {
    FOR(j, 0, n)
        cout << grid[i][j] << " ";
    cout << ln;
  }
}

int main()
{
  fast_io;
  multicase GG
}