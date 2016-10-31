#include <iostream>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

typedef map<string,int> s_i;
typedef map<int,string> i_s;
typedef pair<int,int> ii;
typedef queue<ii> qii;

#define NMAX 1000
#define x first
#define y second

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int n,nc,u,v,k,ans,k_case,in_q;
	int ma[NMAX][NMAX];
	int p_ans[NMAX][NMAX];
	string a,b;

	k_case = 0;

	while(cin >> nc && nc)
	{	memset(ma,0,sizeof(ma));
		memset(p_ans,0,sizeof(p_ans));
		s_i reg;
		i_s reg_inv;
		n = ans = in_q = 0;
		qii print;

		while(nc--)
		{	cin >> k;

			cin >> a;

			if(!reg[a])
			{	reg[a] = ++n;
				reg_inv[n] = a;
			}

			for(int i=1;i<k;i++)
			{	cin >> b;

				if(!reg[a])
				{	reg[a] = ++n;
					reg_inv[n] = a;
				}

				if(!reg[b])
				{	reg[b] = ++n;
					reg_inv[n] = b;
				}

				u = reg[a];
				v = reg[b];

				ma[u][v] = 1;

				a = b;
			}

		}

		cin >> nc;

		while(nc--)
		{	cin >> a >> b;

			if(!reg[a])
			{	reg[a] = ++n;
				reg_inv[n] = a;
			}
			if(!reg[b])
			{	reg[b] = ++n;
				reg_inv[n] = b;
			}

			u = reg[a];
			v = reg[b];

			ma[u][v] = 1;

		}

		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					ma[i][j] |= ma[i][k] & ma[k][j];


		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if((ma[i][j] == 0) & (ma[j][i] == 0))
				{	ans++;

					if(in_q != 2 && p_ans[i][j] == 0)
					{	print.push(make_pair(i,j));
						in_q++;
						p_ans[i][j] = p_ans[j][i] = 1;
					}
				}

		if(ans)
		{	cout << "Case " << ++k_case << ", " << ans << " concurrent events:\n";

			ii p = print.front();
			print.pop();

			cout << '(' << reg_inv[p.x] << ',' << reg_inv[p.y] << ") ";

			if(in_q == 2)
			{	p = print.front();
				cout << "(" << reg_inv[p.x] << ',' << reg_inv[p.y] << ") ";
			}

			cout << '\n';
		}
		else
			cout << "Case " << ++k_case << ", no concurrent events.\n";


	}

	return 0;
}
