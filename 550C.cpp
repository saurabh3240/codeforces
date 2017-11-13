
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0

#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) printf("%lld ",x)
#define pln(x) printf("%lld\n",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second
#define ll long long
#define pb push_back
#define MOD 1000000007
#define limit 10000005
#define INF 1000000000
#define ull unsigned long long
using namespace std;

int dp[8][102];
int bt[8][102];
int main()
{
  string s;
  cin>>s;
  int n = s.size();
  rep(i,n)
  { int x = s[i]-'0';
    dp[x%8][i]=1;
    bt[x%8][i]=-1;  //1 means no backpointer
  }
  forup(i,1,n)
  {
    rep(j,8)
    {
      int x = s[i]-'0';
      if(dp[j][i-1]==1)
      {
        int z = 10*j+x;
        if(dp[z][i]!=1)
        {
          dp[z%8][i]=1;
          bt[z%8][i]=j;
        }

        if(dp[j][i]!=1)
        {
            dp[j][i]=1;
            bt[j][i]=-2;   // -2 skip
        }
      }
    }
  }

// backtrack
  std::vector<char> v;
  rep(i,n)
  {
    if(dp[0][i]==1)
    {
      int a =0;
      for(int b = i; b>=0;b--)
      {
         if(bt[a][b]==-2)
         {
           //do not include
         }
         else if(bt[a][b]==-1)
         {
           v.pb(s[b]);
           break;
         }
         else
         {
           v.pb(s[b]);
           a = bt[a][b];
         }
      }
      break;
    }
  }//1231
  // rep(i,8)
  //   {
  //     rep(j,n)
  //     {
  //        pis(dp[i][j]);
  //     }
  //     pnl();
  //   }
  //   pnl();
  //   rep(i,8)
  //     {
  //       rep(j,n)
  //       {
  //          pis(bt[i][j]);
  //       }
  //       pnl();
  //     }

  int z = v.size();
  if(v.size()==0)
    cout<<"NO"<<endl;
  else
  {
    cout<<"YES"<<endl;
    rep(i,v.size())
    {
      cout<<v[z-i-1];
    }

  }


}
