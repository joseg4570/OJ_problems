#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

#define x first
#define y second
#define NMAX (2000*2)
#define LMAX 30

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<viii> vviii;
typedef map<string,int> si;
typedef map<int,string> is;

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	int m,w,n,u,v,let,dest,ans,n_let,pay;
	int d[NMAX+1][LMAX+1];
	string a,b,word;

	while(cin >> m && m)
	{	si reg;
		is reg_inv;
		n = 0;
		vviii G(2*m+5);

		cin >> a >> b;

		reg[a] = ++n;
		reg_inv[n] = a;

		if(!reg[b])
		{	reg[b] = ++n;
			reg_inv[n] = b;
		}

		dest = reg[b];

		for(int i=0;i<m;i++)
		{	cin >> a >> b >> word;

			if(!reg[a])
			{	reg[a] = ++n;
				reg_inv[n] = a;
			}

			if(!reg[b])
			{	reg[b] = ++n;
				reg_inv[n] = b;
			}

			w = word.length();

			u = reg[a];
			v = reg[b];

			G[u].push_back(make_pair(word[0]-'a'+1,make_pair(v,w)));
			G[v].push_back(make_pair(word[0]-'a'+1,make_pair(u,w)));
		}

		//Dijkstra

		memset(d,-1,sizeof(d));
		priority_queue<iii,vector<iii>,greater<iii> > pq;

		ans = -1;
		d[1][0] = 0;
		pq.push(make_pair(0,make_pair(1,0)));

		while(!pq.empty())
		{	u = pq.top().y.x;
			let = pq.top().y.y;
			w = pq.top().x;

			pq.pop();

			if(u == dest)
			{	ans = w;
				break;
			}

			if(w == d[u][let])
			{	for(int i=0;i<G[u].size();i++)
				{	v = G[u][i].y.x;
					n_let = G[u][i].x;
					pay = G[u][i].y.y;

					if(let == n_let) continue;

					if(d[v][n_let] == -1 || w + pay < d[v][n_let])
					{	d[v][n_let] = w + pay;
						pq.push(make_pair(d[v][n_let],make_pair(v,n_let)));
					}
				}
			}
		}

		if(ans == -1 || ans == 0)
			cout << "impossivel\n";
		else
			cout << ans << '\n';
	}

	return 0;
}
