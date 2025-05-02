#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

void solve()
{
  int n, ct = 0;
  cin >> n;
  FOR(i, 0, n)
  {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c >= 2)
      ct++;
  }
  cout << ct << endl;
}

int main()
{
  FastIO();
  solve();
  return 0;
}
