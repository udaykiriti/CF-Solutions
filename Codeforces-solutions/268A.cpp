#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define op()                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int count(int n, const vector<pair<int, int>> &teams)
{
  int c = 0;
  FOR(i, 0, n)
  {
    FOR(j, 0, n)
    {
      if (i != j)
      {
        if (teams[i].first == teams[j].second)
        {
          c++;
        }
      }
    }
  }
  return c;
}

int main(void)
{
  op();
  int n;
  cin >> n;
  vector<pair<int, int>> teams(n);
  FOR(i, 0, n)
  cin >> teams[i].first >> teams[i].second;
  int result = count(n, teams);
  cout << result << endl;
}
