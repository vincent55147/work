#include<iostream>
#include<vector>
using namespace std;
int sum[100000];
vector<int> line[100000];
void dfs(int top, int father) {
	sum[top] = 1;
	for (int i = 0; i < line[top].size(); i++) {
		if (line[top][i] == father)continue;
		dfs(line[top][i], top);
		sum[top] += sum[line[top][i]];
	}
}
int main() {
	int t, n, a, b,ti;
	cin >> t;
	while (t--) {
		cin >> n;
		ti = n-1;
		while (ti--) {
			cin >> a >> b;
			line[a].push_back(b);
			line[b].push_back(a);
		}
		dfs(0, 0);
		for (int i = 0; i < n; i++) {
			cout << "node " << i << ": " << sum[i] << endl;
			line[i].clear();
		}
	
		
	}
}