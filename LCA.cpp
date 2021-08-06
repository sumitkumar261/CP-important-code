#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
const ll int inf = 1e9 + 7;

using namespace std;
vector<int> v[10005];
int depth[10005];
const int l = 18;
int up[10005][l+1];

void dfs(int i)
{
   // cout<<i<<endl;

    for(auto j: v[i])
    {
        up[j][0] = i;
        depth[j] = depth[i] + 1;
        for(int k = 1;k<=l;k++)
        {
            up[j][k] = up[up[j][k-1]][k-1];
        }
        dfs(j);
    }


}
 


//<---------------------------------Code begins--------------------------------------->//


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int c;
        cin>>c;
        for(int j = 0;j<c;j++)
        {
            int c1;
            cin>>c1;
            v[i].pb(c1);
        }
    }
    depth[0] = 0;
    dfs(0);
    int q;
    cin>>q;
    for(int i = 0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(depth[b]>depth[a])
        {
            swap(a,b);
        }
        int k = depth[a] - depth[b];
      //  cout<<depth[a]<<" "<<depth[b]<<endl;
        
        for(int i = l;i>=0;i--)
        {
            if(k&(1<<i))
            {
                a = up[a][i];
            }
        }
        if(a==b)
        {
            cout<<a<<endl;
            continue;
        }
        for(int x = l;x>=0;x--)
        {
            if(up[a][x]!=up[b][x])
            {
                a = up[a][x];
                b = up[b][x];
            }
        }
        
          cout<<up[a][0]<<endl;
        

        


      //  cout<<LCA(c1,c2)<<endl;
    }
    

    
}









 //<---------------------------------Code ends--------------------------------------->//
