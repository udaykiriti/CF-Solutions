#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);

void solve()
{
  long long n, m, a;
  cin >> n >> m >> a;

  long long Tiles = (n + a - 1) / a;
  long long TTles = (m + a - 1) / a;

  cout << Tiles * TTles << endl;
}

int main()
{
  FastIO();
  solve();
  return 0;
}
