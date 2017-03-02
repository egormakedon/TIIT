#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<int> *g;
vector<char> cl;
vector<int> p;
vector<int> *cycle;

int n, m;
int MaxCycle = -1;
int ncycle = 0;

int add_cycle(int cycle_end, int cycle_st)
{
	cycle[ncycle].clear();
	cycle[ncycle].push_back(cycle_st);
	for (int v = cycle_end; v != cycle_st; v = p[v])
		cycle[ncycle].push_back(v);
	cycle[ncycle].push_back(cycle_st);

	return cycle[ncycle].size();
}

void dfs(int v)
{
	cl[v] = 1;

	for (int j = 0; j<g[v].size(); j++)
	{
		int w = g[v][j];
		if (cl[w] == 0)
		{
			p[w] = v;
			dfs(w);
		}
		else if (cl[w] == 1)
		{
			if (MaxCycle<(add_cycle(v, w) - 1)) MaxCycle = add_cycle(v, w) - 1;
		}
	}

	cl[v] = 0;
}

int main()
{
	int v1, v2;

	string test[5];
	test[0] = "1.txt";
	test[1] = "2.txt";
	test[2] = "3.txt";
	test[3] = "4.txt";
	test[4] = "5.txt";

	for (int index = 0; index < 5; index++)
	{
		ifstream f1(test[index]);

		f1 >> n >> m;

		g = new vector<int>[n];

		for (int i = 0; i < m; i++)
		{
			f1 >> v1 >> v2;
			v1--;
			v2--;
			g[v1].push_back(v2);
		}

		cl.assign(n, 0);
		p.assign(n, -1);

		cycle = new vector<int>[n];

		for (int i = 0; i<n; i++)
			if (cl[i] == 0) dfs(i);

		cout << MaxCycle << endl;

		f1.close();
	}

	return 0;
}
