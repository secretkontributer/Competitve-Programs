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
int n;
int w;
ll dp[101][1000];
pair<int, int> arr[101];
void solve()
{
  cin >> n;
  cin >> w;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].first >> arr[i].second;
  }
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=1000;j++)
    {
      dp[i][j]=INT_MAX;
    }
  }
  dp[0][0]=0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= 1000; j++)
    {
      if ((j - arr[i - 1].second) >= 0)
      {
        dp[i][j] = min(arr[i - 1].first + dp[i - 1][j - arr[i - 1].second], dp[i - 1][j]);
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  int maxm=0;
  for(int i=0;i<=1000;i++)
  {
    if(dp[n][i]<=w)
    {
      maxm=max(maxm,i);
    }
  }
  cout<<maxm<<"\n";
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
// competitive programming syn