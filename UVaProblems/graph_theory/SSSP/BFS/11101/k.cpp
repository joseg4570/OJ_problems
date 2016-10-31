#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

#define NMAX 2010
#define x first
#define y second

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef queue<ii> Q;

int t[NMAX][NMAX];
int n1,n2,x,y,ans;
Q q;

int dv[] = {1,-1,0, 0};
int dh[] = {0, 0,1,-1};

bool ok(int x,int y)
{	return x>=0 && x<NMAX && y>=0 && y<NMAX;	}

void bfs()
{	while(!q.empty())
	{	x = q.front().x;
		y = q.front().y;

		q.pop();

		for(int i=0;i<4;i++)
		{	int dx = x + dv[i];
			int dy = y + dh[i];

			if(ok(dx,dy))
			{	if(t[dx][dy] == -2)
				{	ans = t[x][y] + 1;
					return;
				}

				if(t[dx][dy] == -1)
				{	q.push(make_pair(dx,dy));
					t[dx][dy] = t[x][y] + 1;
				}
			}
		}
	}
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	while(cin >> n1 && n1)
	{	while(!q.empty())
			q.pop();

		memset(t,-1,sizeof(t));

		for(int i=0;i<n1;i++)
		{	cin >> x >> y;
			q.push(make_pair(x,y));
			t[x][y] = 0;
		}

		cin >> n2;

		for(int i=0;i<n2;i++)
		{	cin >> x >> y;
			t[x][y] = -2;
		}

		bfs();

		cout << ans << '\n';
	}

	return 0;
}
