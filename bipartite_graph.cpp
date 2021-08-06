#include<bits/stdc++.h>

using namespace std;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define abe(x) x.begin(), x.end()
#define dbe(x) x.rbegin(), x.rend()
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

//----------------------------bipartite checking using DFS ( 2 coloring )------------------//
vector<ll> d[200005];
ll color[200005];
ll vis[200005];
int no = 1;
void dfs(int i,int p)
{
    vis[i] = 1;
    for(auto j : d[i])
    {
        if(j!=p && vis[j]==0)
        {
            if(color[j]==color[i] && color[i]!=-1)
            {
                no = 0;
                return;
            }
            if(color[i]==0)
            {
                color[j] = 1;
            }
            else if(color[i]==1)
            {
                color[j] = 0;
            }
        }
    }
    for(auto j : d[i])
    {
        if(j!=p && vis[j]==0)
        {
            dfs(j,i);
        }
    }
}


//----------------------------bipartite checking using BFS ( 2 coloring )------------------//

 const int N = 2e5 + 10;
 vector<long long> adj[N];
 long long s[N], n, m;
 bool bipartite()
 {
     bool bip = true;
 
     for(long long i = 0;i < n;i++)
         s[i] = -1;
 
     queue<long long> q;
 
     for(long long i = 0;i < n;i++){
         if(s[i] != -1)continue;
 
         q.push(i);
         s[i] = 0;
 
         while(!q.empty()){
             long long v = q.front();
             q.pop();
 
             for(long long u: adj[v]){
                 if(s[u] == -1){
                     s[u] = s[v] ^ 1;
                     q.push(u);
                 }else bip &= s[u] != s[v];
             }
         }
     }
     return bip;
 }



 
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    ll t=1;
    cin>>t;
    while(t--)
    {
        
        


    
    }



}