#include <iostream>
#include <cctype>
#include <cmath>
#include <map>
using namespace std;

map<char,char> C;
string line,d_line;
int index;

char r_char(char &a)
{	if(isalpha(a)) return C[a];
	else return a;
}

void decode(int l,int r)
{	if(l>r) return;

	int p = (((double)l+r)/2);
	d_line[p] = r_char(line[index++]);

	decode(l,p-1);
	decode(p+1,r);
}

int main()
{	cin.tie(0);
	ios::sync_with_stdio(0);

	for(int i='B',j='b';i<='Z';i++,j++)
		C[i] = i-1, C[j] = j-1;

	C['A'] = 'Z', C['a'] = 'z';

	while(getline(cin,line))
	{	index = 0;
		d_line = line;
		decode(0,line.length()-1);
		cout << d_line << '\n';
	}

	return 0;
}
