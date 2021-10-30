#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <random>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

std::vector<vector<ll>> edges;
vector<bool> visited;
vector<ll> numbers;
ll numberOfMOne;
ll totalSum;

void dfs(ll v, ll depth)
{
    ll total=0;
    visited[v]=true;
    for (auto u: edges[v])
    {
        if (!visited[u])
        {
            total++;
            dfs(u,depth+1);
        }
    }
    if (depth%2==0)
    {
        if (total-1!=0)
        {
            numbers.push_back(abs(total-1));
            totalSum+=abs(total-1);
        }
        /*else if (total-1==-1)
        {
            numberOfMOne++;
        }*/
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    long long T,a,b,c,d,n,m,q;
    std::cin>>T;
    for (int i=0;i<T;i++){
        edges.clear();
        visited.clear();
        numbers.clear();
        numberOfMOne=0;
        totalSum=0;
        std::cin>>n>>q;
        edges.resize(n);
        visited.resize(n,false);
        for (int j=0;j<n-1;j++)
        {
            cin>>a>>b;
            a--;
            b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        dfs(0,0);
        ll calc=0;
        if (q==1)
        {
            for (auto num: numbers)
            {
                calc+=abs(num);
            }
            calc+=numberOfMOne;
            std::cout<<calc<<std::endl;
        }
        else
        {
            vector<bool> dp(totalSum+1,false);
            dp[0]=true;
            ll bestVal=2*totalSum;
            for (auto num: numbers)
            {
                for (int j=totalSum;j>=0;j--)
                {
                    if (j-num>=0 && dp[j-num])
                    {
                        dp[j]=true;
                        bestVal=min(abs(2*j-totalSum),bestVal);
                    }
                }
            }
            /*if (bestVal>=numberOfMOne)
            {
                bestVal-=numberOfMOne;
            }
            else
            {
                if ((bestVal+numberOfMOne)%2==0)
                {
                    bestVal=0;
                }
                else
                {
                    bestVal=1;
                }
            }*/
            cout<<bestVal<<endl;
        }
    }
}