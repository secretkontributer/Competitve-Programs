
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
int arr[100010];
int dp[100010];
void solve()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  dp[0]=0;
  dp[1]=abs(arr[1]-arr[0]);
  for(int i=2;i<n;i++)
  {
    int min1=abs(arr[i]-arr[i-2])+dp[i-2];
    int min2=abs(arr[i]-arr[i-1])+dp[i-1];
    dp[i]=min(min1,min2);
  }
  cout<<dp[n-1]<<"\n";
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    solve();


  return 0;
}
// competitive programming syn