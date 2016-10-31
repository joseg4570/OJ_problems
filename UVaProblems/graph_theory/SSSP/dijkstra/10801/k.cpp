#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

#define x first
#define y second

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;

int n,k,a,b,w;
vvii G;
vvi E;
vi t;
vi label;
char h;

int main()
{
	while(scanf("%d %d",&n,&k) != EOF)
	{
		E.clear();
		E.resize(n);

		G.clear();
		G.resize(100);
		label.assign(100,-1);

		if(t.size() < n)
			t.resize(n);

		for(int i=0;i<n;i++)
			scanf("%d",&t[i]);

		scanf("%*c");

		for(int i=0;i<n;i++)
		{	while(scanf("%d%c",&a,&h))
			{	E[i].push_back(a);
				if(h == '\n') break;
			}

			for(int j=0;j<E[i].size();j++)
				for(int k=j+1;k<E[i].size();k++)
				{	a = E[i][j];
					b = E[i][k];

					if(a>b) swap(a,b);

					w = (b-a)*t[i];

					G[a].push_back(make_pair(b,w));
					G[b].push_back(make_pair(a,w));
				}
		}

		//Dijkstra

		priority_queue<ii,vector<ii>,greater<ii> > pq;
		pq.push(make_pair(0,0));
		label[0] = 0;

		while(!pq.empty())
		{	w = pq.top().x;
			a = pq.top().y;
			pq.pop();

			if(label[a] == w)
			{	for(int i=0;i<G[a].size();i++)
				{	b = G[a][i].x;
					w = G[a][i].y;

					if(label[b] == -1 || label[a] + w + 60 < label[b])
					{	label[b] = label[a] + w + 60;
						pq.push(make_pair(label[b],b));
					}
				}
			}
		}

		if(label[k] == -1)
			printf("IMPOSSIBLE\n");
		else
		{	if(k == 0) label[0] = 60;
			printf("%d\n",label[k] - 60);
		}

	}

	return 0;
}
