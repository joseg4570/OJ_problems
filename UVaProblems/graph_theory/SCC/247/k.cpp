#include <iostream>
#include <cstring>
#include <map>
#include <stack>
#include <vector>
using namespace std;

#define NMAX 30

typedef map<int,string> i_s;
typedef map<string,int> s_i;
typedef vector<int> vi;
typedef stack<int> si;

int n,m,a,b,T,k_name,k_visited;
string namea,nameb;
bool G[NMAX][NMAX];
s_i reg;
i_s reg_inv;
vi num,low,visited;
si S;

void dfs(int node)
{	num[node] = low[node] = ++k_visited;

	visited[node] = 1;
	S.push(node);

	for(int i=1;i<=n;i++)
		if(G[node][i] == 1)
		{	if(num[i] == -1)
				dfs(i);
			if(visited[i])
				low[node] = min(low[node],low[i]);
		}

	if(num[node] == low[node])
	{	bool f_print = 1;

		while(1)
		{	int v = S.top();
			S.pop();

			if(!f_print)
				cout << ", ";
			f_print = 0;

			cout << reg_inv[v];

			visited[v] = 0;

			if(v == node)
				break;
		}

		cout << '\n';
	}

}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	bool fs = 1;
	T = 0;

	while(cin >> n >> m && n)
	{	memset(G,0,sizeof(G));
		reg.clear();
		reg_inv.clear();
		num.assign(n+1,-1);
		low.assign(n+1,-1);
		visited.assign(n+1,0);
		k_name = k_visited = 0;

		if(!fs)
			cout << '\n';
		fs = 0;

		for(int i=0;i<m;i++)
		{	cin >> namea >> nameb;

			if(reg[namea] == 0)
			{	reg[namea] = ++k_name;
				reg_inv[k_name] = namea;
			}

			if(reg[nameb] == 0)
			{	reg[nameb] = ++k_name;
				reg_inv[k_name] = nameb;
			}

			a = reg[namea];
			b = reg[nameb];

			G[a][b] = 1;
		}

		cout << "Calling circles for data set " << ++T << ":\n";

		for(int i=1;i<=n;i++)
			if(num[i] == -1)
				dfs(i);
	}

	return 0;
}
