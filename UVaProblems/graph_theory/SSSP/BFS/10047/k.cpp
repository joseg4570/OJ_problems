#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define NMAX 30
#define DMAX 4
#define CMAX 5

#define x first
#define y second

typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;
typedef queue<iiii> Q;

char t[NMAX][NMAX];
int visited[NMAX][NMAX][DMAX][CMAX];
int n,m,x,y,d,c,xd,yd,dc,dx,dy,nd;

int dv[] = {-1,0,1, 0};
int dh[] = {0, 1,0,-1};

iiii u;

void bfs()
{	memset(visited,-1,sizeof(visited));

	Q q;

	q.push(make_pair(make_pair(x,y),make_pair(0,0)));
	visited[x][y][0][0] = 0;

	while(!q.empty())
	{	u = q.front();
		q.pop();

		x = u.x.x;
		y = u.x.y;
		d = u.y.x;
		c = u.y.y;

		if(x == xd && y == yd && c == 0)
			break;

		if(t[x + dv[d]][y + dh[d]] != '#')
		{	dx = x + dv[d];
			dy = y + dh[d];
			dc = (c+1)%CMAX;

			if(visited[dx][dy][d][dc] == -1)
			{	visited[dx][dy][d][dc] = visited[x][y][d][c] + 1;
				q.push(make_pair(make_pair(dx,dy),make_pair(d,dc)));
			}
		}

		nd = (d+1)%DMAX;

		if(visited[x][y][nd][c] == -1)
		{	visited[x][y][nd][c] = visited[x][y][d][c] + 1;
			q.push(make_pair(make_pair(x,y),make_pair(nd,c)));
		}

		nd = (d + DMAX -1)%DMAX;

		if(visited[x][y][nd][c] == -1)
		{	visited[x][y][nd][c] = visited[x][y][d][c] + 1;
			q.push(make_pair(make_pair(x,y),make_pair(nd,c)));
		}
	}

}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int k_case,ans;
	bool f_ans,f_case;

	k_case = 0;
	f_case = 1;

	while(cin >> n >> m && n)
	{	memset(t,'#',sizeof(t));

		if(!f_case)
			cout << '\n';

		f_case = 0;

		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{	cin >> t[i][j];

				if(t[i][j] == 'S')
				{	x = i;
					y = j;
				}
				else if(t[i][j] == 'T')
				{	xd = i;
					yd = j;
				}
			}

		bfs();

		f_ans = 0;

		for(int i=0;i<DMAX;i++)
			if(visited[xd][yd][i][0] != -1)
			{	if(f_ans == 0)
					ans = visited[xd][yd][i][0];

				ans = min(ans,visited[xd][yd][i][0]);

				f_ans = 1;
			}

		cout << "Case #" << ++k_case << '\n';

		if(!f_ans)
			cout << "destination not reachable\n";
		else
			cout << "minimum time = " << ans << " sec\n";
	}

	return 0;
}
