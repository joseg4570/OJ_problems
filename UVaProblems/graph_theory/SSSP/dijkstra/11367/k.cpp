#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define GMAX 105
#define x first
#define y second

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef pair<int,ii> iii;

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int n,m,a,b,w,nq,cap,u,v,tank,pay,duv,n_tank;
	vvii G;

	cin >> n >> m;

	int d[n][GMAX];
	vi t(n);
	G.resize(n);

	for(int i=0;i<n;i++)
		cin >> t[i];

	for(int i=0;i<m;i++)
	{	cin >> a >> b >> w;

		G[a].push_back(make_pair(b,w));
		G[b].push_back(make_pair(a,w));
	}

	cin >> nq;

	for(int i=0;i<nq;i++)
	{	memset(d,-1,sizeof(d));
		cin >> cap >> a >> b;

		priority_queue<iii,vector<iii>,greater<iii> > pq;
		d[a][0] = 0;
		pq.push(make_pair(0,make_pair(a,0)));

		while(!pq.empty())
		{	u = pq.top().y.x;
			tank = pq.top().y.y;
			w = pq.top().x;
			pq.pop();

			if(u == b)
				break;

			if(d[u][tank] == w)
			{	for(int i=0;i<G[u].size();i++)
				{	v = G[u][i].x;
					duv = G[u][i].y;

					for(int buy=duv-tank;buy<=cap-tank;buy++)
					{	if(buy < 0) continue;

						n_tank = tank + buy - duv;

						if(d[v][n_tank] == -1 || w + buy * t[u] < d[v][n_tank])
						{	d[v][n_tank] = w + buy * t[u];
							pq.push(make_pair(d[v][n_tank],make_pair(v,n_tank)));
						}
					}
				}
			}
		}

		if(d[b][0] != -1)
			cout << d[b][0] << '\n';
		else
			cout << "impossible\n";
	}

	return 0;
}
