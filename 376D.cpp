
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
int n,m;
int  dp[5002][5002];
void preprocess(int i,string s)
{
    char prev='0';
    int run=0;
    rep(j,s.size())
    {
        if(s[j]=='1'&& prev=='1')
        {
            dp[i][j]=++run;
        }
        else if(s[j]=='1')
        {
            dp[i][j]=1;
            run = 1;
            prev = '1';
        }
        else if(s[j]=='0')
        {
            run=0;
        }

    }
}
int main()
{
    gi(n);
    gi(m);
    string s;
    rep(i,n)
    {
        cin>>s;
        preprocess(i,s);
    }
    int ans =0;
    // for each column


    rep(i,m)
    {
        vector<int> v;
        rep(j,n)
        {
            if(dp[j][i]!=0)
                v.pb(dp[j][i]);
            //    pls(dp[j][i]);
        }
    //    cout<<endl;
        sort(v.begin(),v.end());
        int x=0;
        int sz = v.size();
        for(int k = sz-1;k>=0;k--)
        {
            x++;
            ans =max(ans,v[k]*x);
        }
    ///    pis(i);
    //    pin(ans);

    }
    pin(ans);
}
