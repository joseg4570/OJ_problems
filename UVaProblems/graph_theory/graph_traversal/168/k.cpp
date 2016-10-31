#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define NMAX 30

int light_on[NMAX];
int la[NMAX][NMAX];
int size[NMAX];
int k;
vector<int> ans;

void dfs(int now,int before,int number)
{	if(k == number)
	{	light_on[now] = 1;
		number = 0;
		ans.push_back(now);
	}

	int trapped = 1;

	for(int i=0;trapped && i<size[now];i++)
		if(la[now][i] != before && !light_on[la[now][i]])
		{	trapped = 0;
			dfs(la[now][i],now,number+1);
		}

	if(trapped)
	{	if(number)
			ans.push_back(now);

		for(int i=0;i<ans.size()-1;i++)
			cout << (char)(ans[i] + 'A') << ' ';

		cout << '/' << (char)(ans[ans.size()-1] + 'A') << '\n';
	}
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	string lect;
	char pos_act,where_go;
	int i,a;

	while(getline(cin,lect,'.'))
	{	if(lect[0] == '#') break;

		cin >> where_go >> pos_act >> k;
		cin.ignore();

		lect += ';';
		where_go -= 'A';
		pos_act -= 'A';
		memset(size,0,sizeof(size));
		memset(light_on,0,sizeof(light_on));
		ans.clear();

		for(i=0;i<lect.length();i++)
		{	a = lect[i] - 'A';

			for(i+=2;lect[i] != ';';i++)
				la[a][size[a]++] = lect[i] - 'A';
		}

		dfs(where_go,pos_act,1);
	}


	return 0;
}
