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

void solve()
{
  string str;cin>>str;
  string str1;cin>>str1;
  int dp[str1.size()+1][str.size()+1];
  // base-case
  for (int i = 0; i <= str.size(); i++)
  {
    dp[0][i] = 0;
  }
  for (int i = 0; i <= str1.size(); i++)
  {
    dp[i][0] = 0;
  }
  // transition
  for (int i = 1; i <= str1.size(); i++)
  {
    for (int j = 1; j <= str.size(); j++)
    {
      if (str[j - 1] == str1[i - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  // backtracking the string
  string ans;
  int x = str1.size();
  int y = str.size();
  int temp = dp[x][y];
  int cnt = 0;
  while (cnt != temp)
  {
    if (str1[x - 1] == str[y - 1])
    {
      ans +=str1[x - 1];
      x = x - 1;
      y = y - 1;
      cnt++;
    }
    else
    {
      if (dp[x - 1][y] >= dp[x][y - 1])
      {
        x = x - 1;
      }
      else
      {
        y = y - 1;
      }
    }
  }
  for(int i=ans.size()-1;i>=0;i--)
  {
    cout<<ans[i];
  }

}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();

  return 0;
}
// competitive programming syn