#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(NULL);

int main()
{
  FastIO() int n;
  cin >> n;
  vector<int> vec(n);

  FOR(i, 0, n - 1)
  cin >> vec[i];

  int evens = 0, odds = 0;

  FOR(i, 0, 2)
  {
    if (vec[i] % 2 == 0)
      evens++;
    else
      odds++;
  }

  bool isEven = evens > odds;

  FOR(i, 0, n - 1)
  {
    if ((vec[i] % 2 == 0 && !isEven) || (vec[i] % 2 != 0 && isEven))
    {
      cout << i + 1 << endl;
      break;
    }
  }

  return 0;
}
