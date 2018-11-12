
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
#define INF 100000000000000000
#define ull unsigned long long
#define BL 24
using namespace std;
int gmask =0;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef pair<ll,ll> pll;
typedef vector< pll > vll;

typedef pair<int,int> pii;
typedef vector< pii > vii;


vll *G ,*GG;   // Graph
vl Dist;  // for storing the distance of every other node from source.
/*==========================================*/

int edgex[300005];
void Dijkstra(int source, int N)
{
    priority_queue<pll, vector<pll>, greater<pll> > Q;   // min heap
    Dist.assign(N,INF);
    Dist[source] = 0;
    Q.push({0,source});
    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        for(auto &c : G[u]){
            ll v = c.first;
            ll w = c.second;
            // cout<<"v:"<<v<<" "<<Dist[v]<<" u:"<<u<<" "<<Dist[u]<<" w:"<<w<<" condition "<<Dist[u]+w<<endl;
            if(Dist[v] > Dist[u]+w){
              // cout<<"change v:"<<v<<" "<<Dist[v]<<" u:"<<u<<" "<<Dist[u]<<" w:"<<w<<" condition "<<Dist[u]+w<<endl;
                Dist[v] = Dist[u]+w;
                edgex[v]=u;
                // cout<<"changed to "<<Dist[v]<<endl;
                Q.push({Dist[v],v});

            }
        }
    }
}

map<pair<ll,ll> ,ll > edge_map;
int visited[3000005];
int rem;
vector<int> ans;
void dfs(int root)
{
    // cout<<root<<" rem: "<<rem<<endl;
    if(rem==0)
    return;
    visited[root]=1;
    for(auto &c : GG[root])
    {
      int v = c.first;
      if(!visited[v])
      {
        ans.pb(edge_map[make_pair(root,v)]);
          rem--;
        dfs(v);
      }
      if(rem==0)
        return;
    }


}
int main()
{
  int n,e,k,u,v;
  ll w;

  gi(n);
  gi(e);
  gi(k);
  G = new vll[n+1];
  rep(i,e)
  {
    gi(u);gi(v);gl(w);
    G[u].pb({v,w});
    G[v].pb({u,w});
    edge_map[make_pair(u,v)]=i+1;
    edge_map[make_pair(v,u)]=i+1;

  }
  int source = 1;
  Dijkstra(source,n+1);

  GG = new vll[n+1];
  rem = k;
  for(int i=2;i<=n;i++)
  {
    int v = edgex[i];
    GG[v].pb({i,1});
    GG[i].pb({v,1});
    // cout<<i<<" --"<<v<<endl;
  }
  dfs(1);
  pin(ans.size());
  rep(i,ans.size())
    pis(ans[i]);

}
