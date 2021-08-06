#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back

const ll int inf = 1e9 + 7;

using namespace std;



 //<---------------------------------Cyclic components using DFS--------------------------------------->//

int ans = 0;
vector<int> v[1000005];
int vis[1000005] = { };
int r[1000005] = { };
bool d = false;
bool a = false;
void dfs(int i,int k)
{

    vis[i] = 1;
    r[i] = 1;
    
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

 //<---------------------------------Code begins--------------------------------------->//

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    

}









 //<---------------------------------Code ends--------------------------------------->//