#include <bits/stdc++.h>

using namespace std;

void bfs_result(vector<int>& levels, vector<int>& parents, int s)
{
	for(int i=1; i<levels.size();++i)
	{
		if(i==s) continue;
		if(levels[i] == -1)
		{
			cout << "There is no path from " << s << " to " << i << endl;
		}
		else
		{
			int v = i;
			cout << "The path from " << s << " to " << i << " is : " << v;
			while(parents[v] != -1)
			{
				cout << "<-" << parents[v];
				v = parents[v];
			}
			cout << endl;
		}
	}
}

void digokey_result(vector<int>& levels, vector<int>& parents)
{
	int n = levels.size()-1;
	if(levels[n] == -1)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << levels[n] << endl;
		vector<int> path;
		int v = n;
		while(parents[v] != -1)
		{
			path.push_back(v);
			v = parents[v];
		}
		path.push_back(1);
		for_each(path.rbegin(), path.rend()-1, [](auto& el)
		{
			cout << el << " ";
		});
		cout << endl;
	}
}

void bfs(const vector<vector<int>>& adj_list, vector<int>& levels,
        vector<int>& parents, int s)
{
    auto frontier = make_shared<vector<int>>();
    shared_ptr<vector<int>> next;
    frontier->push_back(s);   
    levels[s] = 0;
    int i = 1;
    while(!frontier->empty())
    {
		next = make_shared<vector<int>>();
		for(auto& u : *frontier)
		{
			for(auto& v : adj_list[u])
			{
				if(levels[v] == -1)
				{
					levels[v] = i;
					parents[v] = u;
					next->push_back(v);
				}
			}
		}
		frontier = next;
		++i;
	}
	digokey_result(levels, parents);
}

template <typename T>
void print_container(vector<T>& x)
{
	for_each(x.begin(), x.end(), [](auto &el)
	{
		cout << el << "\t";
	});
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("treasures.txt", "r", stdin);
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		vector<vector<int>> adj_lists(N+1);
		for(int i=1; i<N; ++i)
		{
			int Mi;
			cin >> Mi;
			for(int j=1;j<=Mi;++j)
			{
				int neighbor;
				cin >> neighbor;
				adj_lists[i].push_back(neighbor);
				sort(adj_lists[i].begin(), adj_lists[i].end());	
			}
		}
		vector<int> levels(adj_lists.size(), -1);
		vector<int> parents(adj_lists.size(), -1); 
		bfs(adj_lists, levels, parents, 1);
		cout << endl;		
	}	
	fclose(stdin);
    return 0; 
}
