
#include <bits/stdc++.h>
typedef double dl;
typedef unsigned un;
typedef long long int ll;
using namespace std;
// use global variables
// try to define space before;
// bool prime[1000010];
// void SieveOfEratosthenes(int n)
// {
//     memset(prime, true, sizeof(prime));
//     for (int p = 2; p * p <= n; p++) {
//         if (prime[p] == true) {
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }
ll calc(int p)
{
  return (p * (p - 1)) / 2;
}
int binarySearch(pair<ll, int> temp[], int n, int k)
{
  int i = 0;
  int j = n - 1;
  int ans = 0;
  while (i <= j)
  {
    int m = i + (j - i) / 2;
    if (k>= temp[m].first)
    {
      i = m+1;
      ans = m;
    }
    else
    {
      j = m - 1;
    }
  }
  return ans;
}
void solve()
{
  int n;
  cin >> n;
  int q;
  cin >> q;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n);
  pair<ll, int> temp[n];
  temp[0].first = calc(n - 1);
  temp[0].second = arr[0];
  unordered_map<int, ll> mapes;
  mapes[arr[0]] = temp[0].first;
  for (int i = 1; i < n; i++)
  {
    if (arr[i] == arr[i - 1])
    {
      temp[i].first = temp[i - 1].first + mapes[arr[i]];
      temp[i].second=temp[i-1].second;
    }
    else
    {
      ll a = calc(n - i - 1);
      temp[i].first = temp[i - 1].first + a;
     
      if(a==0)
      {
        temp[i].second=temp[i-1].second;
      }else
      {
        temp[i].second=arr[i];
      }
      mapes[arr[i]]=temp[i].first;
    }
    
  }
  // for(int i=0;i<n;i++)
  // {
  //   cout<<temp[i].first<<" "<<temp[i].second<<"\n";
  // }
  while (q--)
  {
    int o;
    cin >> o;
    int y = binarySearch(temp,n,o);
    cout << temp[y].second << "\n";
    // cout<<binarySearch(temp,n,o)<<"\n";
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}
// competitive programming syn