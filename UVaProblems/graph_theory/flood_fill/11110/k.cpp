#include <iostream>
#include <sstream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

#define NMAX 105

int tab[NMAX][NMAX];
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

int bfs(int y,int x,int search)
{	queue<ii> q;
	int count = 0;

	q.push(make_pair(y,x));
	tab[y][x] = 5;

	while(!q.empty())
	{	y = q.front().first;
		x = q.front().second;
		q.pop();
		count++;

		for(int i=0;i<4;i++)
			if(tab[y+dy[i]][x+dx[i]] == search)
			{	q.push(make_pair(y+dy[i],x+dx[i]));
				tab[y+dy[i]][x+dx[i]] = 5;
			}
	}

	return count;
}

int main()
{	//cin.tie(0);
	ios::sync_with_stdio(0);

	int n,a,b,l;
	string h;
	bool ok;

	while(cin >> n && n)
	{	memset(tab,0,sizeof(tab));

		for(int i=0;i<=n+1;i++)
			tab[0][i] = tab[n+1][i] = 5;

		cin.ignore();

		for(int i=1;i<n;i++)
		{	tab[i][0] = tab[i][n+1] = 5;

			getline(cin,h);
			stringstream ss(h);

			while(ss >> a >> b)
				tab[a][b] = i;

		}

		ok = tab[n][0] = tab[n][n+1] = 5;

		for(int i=1;ok && i<=n;i++)
			for(int j=1;ok && j<=n;j++)
				if(tab[i][j] != 5)
				{	l = bfs(i,j,tab[i][j]);

					if(l != n)
						ok = 0;
				}

		if(ok)
			cout << "good\n";
		else
			cout << "wrong\n";
	}

	return 0;
}
