#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int>vec(n);
  for (int i = 0; i < n; i++) cin>>vec[i];

  int first=INT32_MIN,second=INT32_MIN;

  for (int i = 0; i < n; i++)
  {
    if(vec[i]>first){
      second=first;
      first=vec[i];
    }
    else if(vec[i]>second&&vec[i]!=first){
      second=vec[i];
    }
  }
  if(second==INT32_MIN) cout<<"NOT";
  else cout<<second;
}