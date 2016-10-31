#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

#define NMAX 105
#define MMAX 105

int x,y,dx,dy,count;
char **tab;

void set_direction(char direction)
{	switch(direction)
	{	case 'N':
			dx = 0;
			dy = -1;
			break;
		case 'S':
			dx = 0;
			dy = 1;
			break;
		case 'L':
			dx = 1;
			dy = 0;
			break;
		default:
			dx = -1;
			dy = 0;
			break;
	}
}

void rotate()
{	if(dx == 1)
	{	dx = 0;
		dy = 1;
	}
	else if(dx == -1)
	{	dx = 0;
		dy = -1;
	}
	else if(dy == 1)
	{	dx = -1;
		dy = 0;
	}
	else
	{	dx = 1;
		dy = 0;
	}
}

void do_action(char action)
{	switch(action)
	{	case 'D':
			rotate();
			break;
		case 'E':
			rotate();
			rotate();
			rotate();
			break;
		default:
			if(tab[y+dy][x+dx] != '#')
			{	y += dy;
				x += dx;

				if(tab[y][x] == '*')
				{	count++;
					tab[y][x] = '.';
				}
			}
	}
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	char *sec,direction;

	tab = (char**)malloc(NMAX*sizeof(char*));

	for(int i=0;i<NMAX;i++)
		tab[i] = (char*)malloc(MMAX*sizeof(char));

	sec = (char*)malloc(sizeof(char));
	sec[0] = '\0';

	int n,m,s;

	while(cin >> n >> m >> s)
	{	if(n == 0) break;

		for(int i=0;i<=m+1;i++)
			tab[0][i] = tab[n+1][i] = '#';

		x = strlen(sec);
		count = 0;

		if(x < s)
			sec = (char*)malloc((s+1)*sizeof(char));

		for(int i=1;i<=n;i++)
		{	tab[i][0] = tab[i][m+1] = '#';

			for(int j=1;j<=m;j++)
			{	cin >> tab[i][j];

				if(isalpha(tab[i][j]))
				{	y = i;
					x = j;
					direction = tab[i][j];
					tab[i][j] = '.';
				}
			}
		}

		cin >> sec;

		set_direction(direction);

		for(int i=0;i<s;i++)
			do_action(sec[i]);

		cout << count << '\n';
	}

	return 0;
}
