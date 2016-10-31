#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int,int> ii;

#define NMAX 25
#define MMAX 25

char tab[NMAX][MMAX],land;
int n,m;

int bfs(int y,int x)
{	queue<ii> q;
	int dy[] = {1,-1,0,0};
	int dx[] = {0,0,1,-1};

	int count = 0;
	q.push(make_pair(y,x));
	tab[y][x] = '\n';

	while(!q.empty())
	{	y = q.front().first;
		x = q.front().second;
		q.pop();
		count++;

		for(int i=0;i<4;i++)
			if(tab[y+dy[i]][x+dx[i]] == land)
			{	q.push(make_pair(y+dy[i],x+dx[i]));
				tab[y+dy[i]][x+dx[i]] = '\n';

			}

		if(x == 1)
		{	if(tab[y][m] == land)
			{	q.push(make_pair(y,m));
				tab[y][m] = '\n';
			}
		}
		else if(x == m)
		{	if(tab[y][0] == land)
			{	q.push(make_pair(y,0));
				tab[y][0] = '\n';
			}
		}

	}

	return count;
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int y,x,ans;

	while(cin >> n >> m)
	{	for(int i=0;i<=m+1;i++)
			tab[0][i] = tab[n+1][i] = '\n';

		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{	cin >> tab[i][j];
				tab[i][0] = tab[i][m+1] = '\n';
			}

		cin >> y >> x;
		land = tab[++y][++x];
		ans = bfs(y,x);
		ans = 0;

		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(tab[i][j] == land)
				{	y = bfs(i,j);
					ans = max(y,ans);
				}

		cout << ans << '\n';
	}

	return 0;
}
