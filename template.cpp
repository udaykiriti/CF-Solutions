//g++ datatypes.cpp -o datatypes.exe
//.\datatypes.exe
//g++ templates.cpp
//./a.out<in.txt >out.txt


// g++ template.cpp -o a.exe
// a.exe < in.txt > out.txt


#include<bits\stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORk(i,a,b,k) for(int i=(a);i<(b);i+=k)
#define RFOR(i,a,b) for(int i=(a);i>=(b);i--)
#define RFORK(i,a,b,k) for(int i=(a);i>=(b);i-=k) 


void solve()
{
  int n;
  cin>>n;
    if(n==1){
      cout<<"no"<<endl;
      return;
    }
    if(n==2){
      cout<<"yes"<<endl;
      return;
    }
    if(n==3){
      cout<<"yes"<<endl;
      return;
    }
   
    FOR(i,sqrt(n),n){
      if(n%i==0){
        cout<<"no"<<endl;
        return;
      }
    }
    cout<<"yes"<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t=1;
  cin>>t;
  while (t--)
  {
    solve();
  }
  return 0;
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

//     int n,i,arr[5001],a,b,c;

//     while (sf ("%d",&n) != EOF)
//     {
//         set <int> mySet;

//         for (i=0; i<n; i++)
//         {
//             sf ("%d",&arr[i]);
//             mySet.in(arr[i]);
//         }

//         if (mySet.size () < 3)
//             pf ("NO\n");
//         else
//         {
//             mySet.clear ();
//             bool k = false;

//             for (i=0; i<n; i++)
//             {
//                 a = arr[i];
//                 b = arr[a-1];
//                 c = arr[b-1];

//                 if ((a != b) && (b != c) && (c != a) && arr[c-1] == a)
//                 {
//                     k = true;
//                     pf ("YES\n");
//                     break;
//                 }
//             }

//             if (!k)
//                 pf ("NO\n");
//         }
//     }

//     return 0;
// }