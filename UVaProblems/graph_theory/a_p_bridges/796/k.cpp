#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

int n,a,b,m,root,n_child,n_ans,k_visit;
char h;

vvi G;
vi parent,num,low;
priority_queue<ii> ans;

void dfs(int node)
{	num[node] = low[node] = k_visit++;

	for(int i=0;i<G[node].size();i++)
	{	int v = G[node][i];

		if(num[v] == -1)
		{	parent[v] = node;
			dfs(v);

			if(low[v] > num[node])
			{	n_ans++;
				a = v;
				b = node;

				if(b<a) swap(a,b);

				ans.push(make_pair(-a,-b));
			}

			low[node] = min(low[node],low[v]);
		}
		else if(parent[node] != v)
			low[node] = min(low[node],num[v]);
	}
}

int main()
{	while(scanf("%d%*c",&n) != EOF)
	{	G.clear();
		G.resize(n);
		parent.assign(n,-1);
		num.assign(n,-1);
		low.assign(n,-1);
		n_ans = k_visit = 0;

		for(int i=0;i<n;i++)
		{	scanf("%d%*c%*c%d%*c",&a,&m);

			for(int j=0;j<m;j++)
			{	scanf("%d",&b);

				G[a].push_back(b);
				//G[b].push_back(a);
			}
		}

		for(int i=0;i<n;i++)
			if(num[i] == -1)
			{	root = i;
				n_child = 0;

				dfs(i);
			}

		printf("%d critical links\n",n_ans);

		while(!ans.empty())
		{	printf("%d - %d\n",-ans.top().first,-ans.top().second);
			ans.pop();
		}

		printf("\n");
	}

	return 0;
}
