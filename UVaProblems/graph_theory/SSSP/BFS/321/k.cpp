#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#define x first
#define y second

#define N_MAX 11
#define S_MAX 3000

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef queue<ii> Q;

int n,m,ms,a,b,mask,u,v,lights;
int state[N_MAX][1<<N_MAX],action[N_MAX][1<<N_MAX];
ii father[N_MAX][1<<N_MAX];
vvi G,S;

ii uxy;

void bfs()
{	memset(state,-1,sizeof(state));
	Q q;

	q.push(make_pair(1,1<<1));
	state[1][1<<1] = 0;

	while(!q.empty() && state[n][1<<n] == -1)
	{	uxy = q.front();
		int u = uxy.x;
		int lights = uxy.y;
		q.pop();

		for(int i=0;i<G[u].size();i++)
		{	int v = G[u][i];

			if(state[v][lights] == -1 && (lights & (1<<v)))
			{	state[v][lights] = state[u][lights] + 1;
				father[v][lights] = uxy;
				action[v][lights] = v + n;
				q.push(make_pair(v,lights));
			}

		}

		for(int i=0;i<S[u].size();i++)
		{	int v = S[u][i];
			mask = lights;

			if(lights & (1<<v))
			{	a = -1;
				mask -= (1<<v);
			}
			else
			{	a = 1;
				mask += (1<<v);
			}

			if(state[u][mask] == -1)
			{	q.push(make_pair(u,mask));
				state[u][mask] = state[u][lights] + 1;
				father[u][mask] = uxy;
				action[u][mask] = a*v;
			}

		}
	}

}

void print()
{	vi ans;

	ii u = make_pair(n,1<<n);

	while(u.x != 1 || u.y != (1<<1))
	{	ans.push_back(action[u.x][u.y]);
		u = father[u.x][u.y];
	}

	for(int i=ans.size()-1;i>=0;i--)
		if(ans[i] > n)
			cout << "- Move to room " << ans[i]-n << ".\n";
		else if(ans[i] < 0)
			cout << "- Switch off light in room " << -ans[i] << ".\n";
		else
			cout << "- Switch on light in room " << ans[i] << ".\n";
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int k_case = 0;

	while(cin >> n >> m >> ms && n)
	{	G.clear();
		S.clear();

		G.resize(n+1);
		S.resize(n+1);

		for(int i=0;i<m;i++)
		{	cin >> a >> b;

			G[a].push_back(b);
			G[b].push_back(a);
		}

		for(int i=0;i<ms;i++)
		{	cin >> a >> b;

			if(a != b)
				S[a].push_back(b);
		}

		bfs();

		cout << "Villa #" << ++k_case << '\n';

		if(state[n][1<<n] == -1)
			cout << "The problem cannot be solved.\n";
		else
		{	//cout << n <<  "\n\n";
			cout << "The problem can be solved in " << state[n][1<<n]
			     << " steps:\n";

			print();
		}

		cout << '\n';
	}

	return 0;
}
