#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
map<char, string> m;
map<string, char> mb;
stack<int> S;
void start();
int main()
{
	char in[1010];
	start();
	while(scanf("%s", in) != EOF)
	{
		vector<char> cod;
		for(int i = 0; in[i]; i++)
		{
			S.push(m[in[i]].length());
			for(int j = 0; m[in[i]][j]; j++){
				cod.push_back(m[in[i]][j]);
			}
		}
		int curr = 0;
		while(!S.empty()){
			int popitems = S.top(); S.pop();
			string letter(popitems, '\0');
			for(int i = curr; i < curr +popitems; i++)
			{
				letter[i-curr] = cod[i];
			}
			curr += popitems;
			cout << mb[letter];
		}
		cout << '\n';
	}
}

void start()
{
		m['A'] = (".-\0");
		m['B'] = ("-...\0");
		m['C'] = ("-.-.\0");
		m['D'] = ("-..\0");
		m['E'] = (".\0");
		m['F'] = ("..-.\0");
		m['G'] = ("--.\0");
		m['H'] = ("....\0");
		m['I'] = ("..\0");
		m['J'] = (".---\0");
		m['K'] = ("-.-\0");
		m['L'] = (".-..\0");
		m['M'] = ("--\0");
		m['N'] = ("-.\0");
		m['O'] = ("---\0");
		m['P'] = (".--.\0");
		m['Q'] = ("--.-\0");
		m['R'] = (".-.\0");
		m['S'] = ("...\0");
		m['T'] = ("-\0");
		m['U'] = ("..-\0");
		m['V'] = ("...-\0");
		m['W'] = (".--\0");
		m['X'] = ("-..-\0");
		m['Y'] = ("-.--\0");
		m['Z'] = ("--..\0");
		for(char x = 'A'; x <= 'Z'; x++){
			mb[m[x]] = x;
		}
		m['_'] = ("..--\0");
		m[','] = (".-.-\0");
		m['.'] = ("---.\0");
		m['?'] = ("----\0");
		
		mb[("..--\0")] = '_';
		mb[(".-.-\0")] = ',';
		mb[("---.\0")] = '.';
		mb[("----\0")] = '?';
		
}
