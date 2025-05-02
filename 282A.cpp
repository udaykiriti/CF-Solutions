#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i <= (b); i += (k))
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= (k))

void solve()
{
  int n, x = 0;
  cin >> n;
  FOR(i, 1, n)
  {
    string s;
    cin >> s;
    if (s.find('+') != string::npos)
      x++;
    else
      x--;
  }
  cout << x << endl;
}

int main()
{
  FastIO();
  solve();
  return 0;
}
