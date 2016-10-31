#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef vector<char> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<char,int> c_i;

vs let;
int n,T,selected;
char A,B,h,a,b;
c_i reg;
vi parent;
vi ans;
bool f_case,s_found;

bool ok(int node)
{	if(selected & (1<<node))
		return 0;

	if((selected & parent[node]) == parent[node])
		return 1;

	return 0;
}

void backtracking(int level)
{	if(level == n)
	{	cout << let[ans[0]];

		for(int i=1;i<n;i++)
			cout << ' ' << let[ans[i]];

		cout << '\n';
		s_found = 1;
	}

	for(int i=0;i<n;i++)
		if(ok(i))
		{	ans[level] = i;
			selected += (1<<i);
			backtracking(level + 1);
			selected -= (1<<i);
		}

}

int main()
{	f_case = 1;
	scanf("%d%*c%*c",&T);

	while(T--)
	{	if(!f_case)
			printf("\n"),scanf("%*c");

		f_case = s_found = selected = 0;

		let.clear();

		while(scanf("%c%c",&A,&h) && h != '\n')
			let.push_back(A);

		let.push_back(A);

		sort(let.begin(),let.end());
		n = let.size();
		parent.assign(n,0);
		ans.assign(n,0);

		for(int i=0;i<n;i++)
			reg[let[i]] = i;

		while(scanf("%c%*c%c%c",&A,&B,&h) && h != '\n')
		{	a = reg[A];
			b = reg[B];

			parent[b] |= (1 << a);
		}

		a = reg[A];
		b = reg[B];

		parent[b] |= (1 << a);

		//printf("%d\n",n);

		backtracking(0);

		if(!s_found)
			cout << "NO\n";
	}

	return 0;

}
