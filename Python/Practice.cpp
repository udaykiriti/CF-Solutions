#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout << (x) << endl

int sumof(int n)
{
  int temp = n;
  int total = 0;
  while (temp)
  {
    total += temp % 10;
    temp /= 10;
  }
  return total;
}

int main()
{
  int n;
  // cin >> n;
  n = 371;
  int t = sumof(n);
  while (t > 10)
  {
    t = sumof(t);
    //debug(t);
  }
  cout << t << endl;
}