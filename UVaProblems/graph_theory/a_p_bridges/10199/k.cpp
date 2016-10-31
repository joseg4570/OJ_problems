#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef map<string,int> s_i;
typedef map<int,string> i_s;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

s_i reg;
i_s reg_inv;
vvi G;
vs ans;
vi num,low,art,fater;

int n,m,k_visit,root,n_child;

void dfs(int node)
{	num[node] = low[node] = k_visit++;

	for(int i=0;i<G[node].size();i++)
	{	int v = G[node][i];

		if(num[v] == -1)
		{	if(root == node)
				n_child++;

			fater[v] = node;

			dfs(v);

			if(low[v] >= num[node])
				art[node] = 1;

			low[node] = min(low[node],low[v]);
		}
		else if(v != fater[node])
			low[node] = min(low[node],num[v]);

	}
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	string name,na,nb;
	int a,b,T = 1;
	bool first = 1;

	while(cin >> n && n)
	{	reg.clear();
		G.clear();
		G.resize(n);
		ans.clear();
		num.assign(n,-1);
		low.assign(n,-1);
		art.assign(n, 0);
		fater.assign(n,-1);
		k_visit = 0;

		if(!first)
			cout << '\n';

		first = 0;

		for(int i=0;i<n;i++)
		{	cin >> name;

			reg[name] = i;
			reg_inv[i] = name;
		}

		cin >> m;

		for(int i=0;i<m;i++)
		{	cin >> na >> nb;

			a = reg[na], b = reg[nb];

			G[a].push_back(b);
			G[b].push_back(a);
		}

		for(int i=0;i<n;i++)
			if(num[i] == -1)
			{	root = i;
				n_child = 0;

				dfs(i);

				art[root] = n_child > 1;
			}

		for(int i=0;i<n;i++)
			if(art[i] == 1)
				ans.push_back(reg_inv[i]);

		sort(ans.begin(),ans.end());

		cout << "City map #" << T++ << ": " << ans.size() << " camera(s) found\n";

		for(int i=0;i<ans.size();i++)
			cout << ans[i] << '\n';

	}


	return 0;
}

