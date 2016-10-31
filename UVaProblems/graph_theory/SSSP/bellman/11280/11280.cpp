#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define x first
#define y second

int main() 
{	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n,m,w,T,u,v,nq,k;
	string a,b;
	
	cin >> T;
	
	for(int I=1;I<=T;I++)
	{	if(I != 1)
			cout << '\n';
		
		cout <<	"Scenario #" << I << '\n';
		map<string,int> reg;
		vector<vector<pair<int,int> > > G;
		vector<int> ans,d;
		
		cin >> n;
		
		G.resize(n);
		ans.assign(n,-1);
		d.assign(n,-1);
		
		for(int i=0;i<n;i++)
		{	cin >> a;

			reg[a] = i;
		}
		
		cin >> m;
		
		for(int i=0;i<m;i++)
		{	cin >> a >> b >> w;
	
			u = reg[a];
			v = reg[b];
			
			G[u].push_back(make_pair(v,w));
		}
		
		d[0] = 0;
		
		for(int i=1;i<n;i++)
		{	for(int u=n-1;u>=0;u--)
				if(d[u] != -1)
					for(int j=0;j<G[u].size();j++)
					{	v = G[u][j].x;
						w = G[u][j].y;
				
						if(d[v] == -1)
							d[v] = d[u] + w;
						else
							d[v] = min(d[v],d[u] + w);
					}
					
			ans[i-1] = d[n-1];
		}
		
		cin >> nq;
		
		for(int i=0;i<nq;i++)
		{	cin >> k;
			
			if(k >= n - 1) k = n - 2; 
			
			if(ans[k] == -1)
				cout << "No satisfactory flights\n";
			else
				cout << "Total cost of flight(s) is $" << ans[k] << '\n';
		}
		
	}
	
	return 0;
}