#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i <= (b); i += (k))
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= (k))

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<char> removed;
vector<int> seen_id, distA, parentA, distB, distU, parentU;
int bfs_id;

int BFS_findFarthest(int start)
{
  bfs_id++;
  int id = bfs_id;
  queue<int> q;
  q.push(start);
  seen_id[start] = id;
  distA[start] = 0;
  int far = start, maxd = 0;

  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (int y : adj[x])
    {
      if (!removed[y] && seen_id[y] != id)
      {
        seen_id[y] = id;
        distA[y] = distA[x] + 1;
        q.push(y);
        if (distA[y] > maxd)
        {
          maxd = distA[y];
          far = y;
        }
      }
    }
  }
  return far;
}

int BFS_distParentCompNodes(int start, vector<int> &comp_nodes)
{
  bfs_id++;
  int id = bfs_id;
  queue<int> q;
  q.push(start);
  seen_id[start] = id;
  distA[start] = 0;
  parentA[start] = -1;
  int far = start, maxd = 0;
  comp_nodes.clear();
  comp_nodes.pb(start);

  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (int y : adj[x])
    {
      if (!removed[y] && seen_id[y] != id)
      {
        seen_id[y] = id;
        distA[y] = distA[x] + 1;
        parentA[y] = x;
        q.push(y);
        comp_nodes.pb(y);
        if (distA[y] > maxd)
        {
          maxd = distA[y];
          far = y;
        }
      }
    }
  }
  return far;
}

void BFS_distOnly(int start)
{
  bfs_id++;
  int id = bfs_id;
  queue<int> q;
  q.push(start);
  seen_id[start] = id;
  distB[start] = 0;

  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (int y : adj[x])
    {
      if (!removed[y] && seen_id[y] != id)
      {
        seen_id[y] = id;
        distB[y] = distB[x] + 1;
        q.push(y);
      }
    }
  }
}

int BFS_distParentLexFarthest(int start)
{
  bfs_id++;
  int id = bfs_id;
  queue<int> q;
  q.push(start);
  seen_id[start] = id;
  distU[start] = 0;
  parentU[start] = -1;
  int far = start, maxd = 0;

  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (int y : adj[x])
    {
      if (!removed[y] && seen_id[y] != id)
      {
        seen_id[y] = id;
        distU[y] = distU[x] + 1;
        parentU[y] = x;
        q.push(y);
        if (distU[y] > maxd || (distU[y] == maxd && y > far))
        {
          maxd = distU[y];
          far = y;
        }
      }
    }
  }
  return far;
}

struct Comp
{
  int d, u, v;
  vector<int> path;
};

struct CompareComp
{
  bool operator()(const Comp &a, const Comp &b) const
  {
    if (a.d != b.d)
      return a.d < b.d;
    if (a.u != b.u)
      return a.u < b.u;
    return a.v < b.v;
  }
};

vector<int> comp_nodes;

Comp get_comp(int start)
{
  int A1 = BFS_findFarthest(start);
  int B1 = BFS_distParentCompNodes(A1, comp_nodes);
  BFS_distOnly(B1);
  int D = distA[B1];
  int u_max = 0;
  for (int u : comp_nodes)
  {
    if (distA[u] == D || distB[u] == D)
    {
      if (u > u_max)
        u_max = u;
    }
  }
  int v_max = BFS_distParentLexFarthest(u_max);
  vector<int> P;
  int x = v_max;
  while (x != -1)
  {
    P.pb(x);
    x = parentU[x];
  }

  return {(int)P.size(), u_max, v_max, move(P)};
}

void solve()
{
  int n;
  cin >> n;
  adj.assign(n + 1, vector<int>());
  FOR(i, 1, n - 1)
  {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  removed.assign(n + 1, 0);
  seen_id.assign(n + 1, 0);
  distA.assign(n + 1, 0);
  parentA.assign(n + 1, 0);
  distB.assign(n + 1, 0);
  distU.assign(n + 1, 0);
  parentU.assign(n + 1, 0);
  bfs_id = 0;

  vector<int> res;
  res.reserve(3 * n);

  Comp c0 = get_comp(1);
  res.pb(c0.d);
  res.pb(c0.u);
  res.pb(c0.v);
  for (int x : c0.path)
    removed[x] = 1;

  priority_queue<Comp, vector<Comp>, CompareComp> pq;
  for (int x : c0.path)
  {
    for (int y : adj[x])
    {
      if (!removed[y])
        pq.push(get_comp(y));
    }
  }

  while (!pq.empty())
  {
    Comp c = pq.top();
    pq.pop();
    res.pb(c.d);
    res.pb(c.u);
    res.pb(c.v);
    for (int x : c.path)
      removed[x] = 1;
    for (int x : c.path)
    {
      for (int y : adj[x])
      {
        if (!removed[y])
          pq.push(get_comp(y));
      }
    }
  }

  for (int x : res)
    cout << x << " ";
  cout << endl;
}

int32_t main()
{
  FastIO();
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
