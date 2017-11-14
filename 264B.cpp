
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

ull mod_pow(ull num, ull pow, ull mod)
{
    ull test,n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}
//while((getchar())!='\n'); //buffer clear

ll gcd(ll a,ll b)
{
    ll r;
    while(b)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

vector<int> divsior[100005];
int dp[100005];
int main()
{   int x=0;
    forup(i,2,100005)
    {
        if(divsior[i].size()==0)
        {
            for(int j=i+i;j<100005;j+=i)
            {    divsior[j].pb(i);
                x++;
            }
            
        }
    }
    //pin(x);

    int n;
    gi(n);
    std::vector<int> v;
    rep(i,n)
    {   int x;
        gi(x);
        v.pb(x);
        dp[x]=1;
    }
    forup(i,0,n)
    {
    //    pin(v[i]);
        rep(j,divsior[v[i]].size())
        {
            int d = divsior[v[i]][j];

            dp[v[i]]=max(dp[v[i]],1+dp[d]);
        }
        rep(j,divsior[v[i]].size())
        {
            int d = divsior[v[i]][j];
            dp[d]= max(dp[d],dp[v[i]]);
            //pis(d);pin(dp[d]);
        }

    }
    int ans =-1;
    rep(i,100005)
    {
        ans=  max(ans,dp[i]);
    }
    pin(ans);

}
