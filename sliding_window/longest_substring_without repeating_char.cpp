#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
  int n;
  cin >> n;
  while (n--)
  {
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = 0;
    int mx = 0;
    map<char, int> m;
    while (r < n)
    {
      if (m[s[r]] > 0)
      {
        m[s[l]]--;
        l++;
      }
      else
      {
        mx = max(mx, r - l + 1);

        m[s[r]]++;
        r++;
      }
    }
    cout << mx << endl;
  }
}