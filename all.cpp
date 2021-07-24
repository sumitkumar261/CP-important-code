
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;
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

#define ordered_set1 tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set2 tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>


///// ------------------Segment Tree Query--------------------------------

ll query(ll node,ll query_low,ll query_high,ll node_low, ll node_high)
{
    if(query_low <= node_low && query_high >= node_high)
    {
        return arr[node];
    }
    if(query_low > node_high || query_high < node_low)
    {
        return 0;
    }
    ll x = (node_low + node_high)/2;
    return query(2*node,query_low,query_high,node_low,x) + query(2*node + 1,query_low,query_high,x+1,node_high);
}
 
 
void update(ll c, ll a,ll ans)
{
    arr[c+a] = ans;
    for(ll i = (a+c)/2;i>=1;i = i/2)
    {
        arr[i] = arr[2*i] + arr[2*i+1];
    }
}


///// ------------------bipartite checking dfs--------------------------------

vector<ll> d[200005];
ll color[200005];
ll vis[200005];
int no = 1;
void bipartite_dfs(int i,int p)
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


///// ------------------bipartite checking bfs--------------------------------
vector<ll> d[N];
ll color[N];
 
 
bool check(ll n){
    bool is_bipartite = true;
    queue<int> q;
    for(int i=0; i<n; i++){
        if(color[i]==-1){
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(auto j : d[u]){
                    if(color[j]==-1){
                        color[j] = color[u]^1;
                        q.push(j);
                    }
                    else{
                        is_bipartite &= color[j] != color[u];
                    }
                }
            }
        }
    }
    return is_bipartite;
}

///// ------------------cyclic components check--------------------------------

void cyclic_components(int i,int k)
{
 
    vis[i] = 1;
    r[i] = 1;
    if(v[i].size()!=2)
    {
        a = true;
    }
    for(auto j: v[i])
    {
        if(vis[j]==0)
        {
            dfs(j,i);
        }
        else if(j!=k && r[j]==1 && a==false)
        {
            d = true;
            return;
        }
    }
    r[i] = 0;
 
 
}
///////////------------Mo's Algorithm-------------/////

struct query{
    int l;
    int r;
    int i;
};
query Q[200005];
ll ans[200005] = { };
int x = 600;
bool comp(query a , query b)
{
    if(a.l / x != b.l/x)
    return a.l/x < b.l/x;
 
    return a.r < b.r;
}

///////////------------Disjoint Set and Union-------------/////
int find(int u)
{
    if(p[u]!=u)
    {
        p[u] = find(p[u]);
    }
    return p[u];
}
 
void uni(int u,int v)
{
    
    if(find(u)!=find(v))
    {
        p[find(v)] = find(u);
    }
}

///////////------------GCD-------------/////
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

///////////------------LCM-------------/////
ll lcm(ll a, ll b){
    return (a*b)/(gcd(a,b));
}


///////////------------Binary Exponentiation-------------/////

ll mpow(ll base, ll exp){
    ll res = 1;
    while(exp > 0){
        if(exp&1) res = (res*base)%mod;
        base = (base*base) % mod;
        exp >>= 1;
    }
    return res;
}


///////////------------factorial-------------/////
const int mxn = 1e6 + 7;

vl fact(mxn,0), in (mxn, 0);
void calc_fact(){
    fact[0] = 1;
    fact[1] = 1;
    in[1] = 1;
    for(ll i=2; i<mxn; i++){
        fact[i] = (fact[i-1] * i)%mod;
        in[i] = (in[i-1] * mpow(i, mod - 2)) %mod;
        // in[i] = (in[i-1] * inv(i) %mod
    }
}


///////////------------NcR-------------/////

void ncr(ll n, ll r){
    ll ans = fact[n];
    ans = (ans * in[r])%mod;
    ans = (ans * in[n-r])%mod;
    return ans;
}


///////////------------Calculate Primes-------------/////


vector<ll> calc_primes(ll n){
    vector<ll> p;
    while(n%2 == 0){
        p.push_back(2ll);
        n/=2;
    }
    for(int i=3; i*i <= n; i+=2){
        while(n%i == 0){
            p.push_back(i);
            n/=i;
        }
    }
    if(n > 1) p.push_back(n);

    return p;
}

///////////------------Sieve of Eratosthenes-------------/////

void SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}



int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    ll T=1;
    cin>>T;
    while(T--)
    {

        ///////////------------Range Min Query ( Sparse Table )-------------////
        ll arr[n+1][18] = { };
       for(int i = 0;i<n;i++)
       {
            arr[i][0] = v[i];
       }
       for(int i = 1;i<17;i++)
       {
            for(int j = 0;j + (1<<i) -1<n;j++)
            {
                arr[j][i] = min(arr[j][i-1], arr[j + (1<<(i-1))][i-1]);
            }
       }
       for(int i = 0;i<q;i++)
       {
            ll l,r;
            cin>>l>>r;
            ll x = log2(r-l+1);
            cout<<min(arr[l][x],arr[r-(1<<x)+1][x]);
            cout<<endl;
       }



       ///////////------------Dynamic Range Sum Query ( Segment Tree )-------------////


        ll n,q;
        cin>>n>>q;
        ll a = 1;
        while(a<n)
        {
            a = a*2;
        }
 
        arr.resize(2*a + 1);
        for(int i = 0;i<2*a;i++)
        {
            arr[i] = 0;
        }
        for(ll i = 0;i<n;i++)
        {
            ll c;
            cin>>c;
            arr[a+i] = c;
        }
        for(ll i = a-1;i>=0;i--)
        {
            arr[i] = arr[2*i] + arr[2*i+1];
        }
        for(ll i = 0;i<q;i++)
        {
            ll k,l,r;
            cin>>k;
            if(k==1)
            {
                cin>>l>>r;
                l--;
                update(l,a,r);
               
            }
            else
            {
                cin>>l>>r;
                l--;
                r--;
                ll ans = query(1,a+l,a+r,a,2*a-1);
                cout<<ans<<endl;
            }
            //cout<<endl;
            ///////////------------Mo's Algorithm-------------/////

            int n;
            cin>>n;
            vector<ll> v;
            for(int i = 0;i<n;i++)
            {
                ll c;
                cin>>c;
                v.pb(c);
            }
            int q;
            cin>>q;
            vector<pair<ll,ll>> v1;
            vector<pair<ll,ll>> v2;
            for(int i = 0;i<q;i++)
            {
                ll l,r;
                cin>>l>>r;
                l--;
                r--;
                v1.pb({l,r});
                Q[i].l = l;
                Q[i].r = r;
                Q[i].i = i;

            }
            sort(Q,Q+q,comp);
            //map<pair<ll,ll>,ll> m;
            int freq[1000051] = { };
            sort(abe(v1));
            int x1 = 0;
            int x2 = -1;
            ll cnt = 0;
            for(int i = 0;i<q;i++)
            {
                ll l,r;
                l = Q[i].l;
                r = Q[i].r;
                
                while(x1 > l)
                {
                    x1--;
                    freq[v[x1]]++;
                    if(freq[v[x1]]==1)
                    {
                        cnt++;
                    }
                    

                }
                while(x2 < r)
                {
                    x2++;
                    freq[v[x2]]++;
                    if(freq[v[x2]]==1)
                    {
                        cnt++;
                    }
                    

                }
                while(x1 < l)
                {
                    freq[v[x1]]--;
                    if(freq[v[x1]]==0)
                    {
                        cnt--;
                    }
                    x1++;

                }
                while(x2 > r)
                {
                    freq[v[x2]]--;
                    if(freq[v[x2]]==0)
                    {
                        cnt--;
                    }
                    x2--;

                }
                ans[Q[i].i] = cnt;
            }
            for(int i = 0;i<q;i++)
            {
                cout<<ans[i]<<endl;
            }


            





 
        }




        
    
    }



}





