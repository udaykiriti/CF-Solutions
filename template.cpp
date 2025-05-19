// g++ datatypes.cpp -o datatypes.exe
//.\datatypes.exe
// g++ templates.cpp
//./a.out<in.txt >out.txt

// g++ template.cpp -o a.exe
// a.exe < in.txt > out.txt

#include <bits\stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i < (b); i += k)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= k)

#define multicases \
  int t;           \
  cin >> t;        \
  while (t--)      \
    solve();

#define EXIT return 0;

#define scan(x) cin >> x;
#define print(x) cout << x << endl;

#define int long long
#define U unsigned int

const int MOD = 1000000007;
const int MAX = 1000005;

void solve()
{
}

void FastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main(void)
{
  FastIO();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  multicases EXIT
}

// #include <bits/stdc++.h>
// using namespace std;

// #define sf scanf
// #define pf printf
// #define ssf sscanf
// #define spf sprintf
// #define fsf fscanf
// #define fpf fprintf
// #define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
// #define scase sf ("%d",&tc)
// #define sn sf ("%d",&n)
// #define whilecase while (tc--)
// #define eof while (cin >> n)
// #define forloop for (pos=1; pos<=tc; pos++)
// #define arrayloop (i=0; i<n; i++)
// #define cinstr cin >> str
// #define getstr getline (cin,str)
// #define pcase pf ("Case %d: ",pos)
// #define pii pair <int,int>
// #define pb push_back
// #define in insert
// #define llu unsigned long long
// #define lld long long
// #define U unsigned int
// #define endl "\n"

// const int MOD = 1000000007;
// const int MAX = 1000005;

// int main (void)
// {
//     /*
//     freopen ("input.txt","r",stdin);
//     freopen ("output.txt","w",stdout);
//     */

//     return 0;
// }