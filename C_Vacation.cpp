
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
int dp[100010][3];
int arr[100010][3];
void solve()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<3;j++)
    {
      cin>>arr[i][j];
    }
  }
  //base-case
  for(int i=0;i<3;i++)
  {
    dp[0][i]=arr[0][i];
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(j==0)
      {
        dp[i][j]=max(dp[i-1][j+1]+arr[i][j],arr[i][j]+dp[i-1][j+2]);
        
      }else if(j==1)
      {
        dp[i][j] = max(dp[i - 1][j -1] + arr[i][j], arr[i][j] + dp[i - 1][j + 1]);
      }else
      {
        dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j], arr[i][j] + dp[i - 1][j - 2]);
      }
    }
  }
  int maxm=0;
  for(int i=0;i<3;i++)
  {
    if(maxm<dp[n-1][i])
    {
      maxm=dp[n-1][i];
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