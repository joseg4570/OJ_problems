#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

#define NMAX 105

char tab[NMAX][NMAX];

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

bool bfs(int y,int x)
{	queue<ii> q;
	bool alive = 0;

	q.push(make_pair(y,x));
	alive = tab[y][x] == 'x';
	tab[y][x] = '.';

	while(!q.empty())
	{	y = q.front().first;
		x = q.front().second;
		q.pop();

		for(int i=0;i<4;i++)
			if(tab[y+dy[i]][x+dx[i]] != '.')
			{	q.push(make_pair(y+dy[i],x+dx[i]));

				if(tab[y+dy[i]][x+dx[i]] == 'x')
					alive = 1;

				tab[y+dy[i]][x+dx[i]] = '.';
			}

	}

	return alive;
}


int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int n,T,count;

	cin >> T;

	for(int t = 1;t<=T;t++)
	{	cin >> n;

		count = 0;

		for(int i=0;i<=n+1;i++)
			tab[0][i] = tab[n+1][i] = '.';

		for(int i=1;i<=n;i++)
		{	for(int j=1;j<=n;j++)
				cin >> tab[i][j];

			tab[i][0] = tab[i][n+1] = '.';
		}

		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(tab[i][j] != '.')
					count += bfs(i,j);

		cout << "Case " << t << ": " << count << '\n';
	}

	return 0;
}
