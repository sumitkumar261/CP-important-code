#include<bits/stdc++.h>
#include <stdlib.h>

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
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " : ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
ll fact[1006] = { };
ll in[10006] = { };


//-----------------------modulo----------------------------//

ll modulo(ll a)
{
    return (a%mod + mod) % mod;
}

//-----------------------GCD----------------------------//

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

//-----------------------LCM----------------------------//

ll lcm(ll a, ll b){
    return (a*b)/(gcd(a,b));
}

//-----------------------Binary Exponentiation----------------------------//

ll mpow(ll base, ll exp){
    ll res = 1;
    while(exp > 0){
        if(exp&1) res = (res*base)%mod;
        base = (base*base) % mod;
        exp >>= 1;
    }
    return res;
}

//-----------------------Factorial----------------------------//
const ll mxn = 1004;
void calc_fact(){
    fact[0] = 1;
    fact[1] = 1;
    //in[1] = 1;
    //in[0] = 1;
    for(ll i=2; i<mxn; i++){
        fact[i] = (fact[i-1] * i)%mod;
        //in[i] = (mpow(i, mod - 2)) %mod;
        // in[i] = (in[i*-1] * inv(i) %mod
    }
}

//-----------------------Ncr with division modulo----------------------------//

ll ncr(ll n, ll r){
    ll ans = fact[n];
    ans = (ans * mpow(fact[r],mod-2))%mod;
    ans = (ans * mpow(fact[n-r],mod-2))%mod;
    return ans;
}

//-----------------------Smallest prime factor----------------------------//

ll spf[mxn];

void calc_spf(){
    for(ll i=1; i<mxn; i+=2) spf[i] = i;
    for(ll i=2; i<mxn; i+=2) spf[i] = 2;

    for(ll i = 3; i*i < mxn ; i+=2){
        if(spf[i]==i){
            for(ll j = i*i; j<mxn; j+=i){
                spf[j] = min(spf[j], i);
            }
        }
    }
}


//-----------------------Prime Factors----------------------------//

vector<ll> calc_primes(ll n){
    vector<ll> p;
    while(n%2 == 0){
        p.push_back(2ll);
        n/=2;
    }
    for(ll i=3; i*i <= n; i+=2){
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
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
       
        if (prime[p] == true)
        {
           
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


    }
}
 
 
 