#include<iostream>
#include<vector>
using namespace std;
int sum[100001];
bool head[100001];
vector<int> line[100001];
void dfs(int top, int father) {
	sum[top] = 1;
	for (int i = 0; i < line[top].size(); i++) {
		if (line[top][i] == father)continue;
		dfs(line[top][i], top);
		sum[top] += sum[line[top][i]];
	}
}
int main() {
	int t, n, a, b,m,sc;
	cin >> t;
	while (t--) {
		cin >> n>>m;
		for (int i = 1; i <= n; i++)
			head[i] = true;
		while (m--) {
			cin >> a >> b;
			line[a].push_back(b);
			line[b].push_back(a);
			head[b] = false;
		}
		for (int i = 1; i <= n; i++)
			if (head[i]) {
				line[i].push_back(0);
				line[0].push_back(i);
			}
		dfs(0, 0);
		cin >> m;
		while(m--){
			cin >> sc;
			cout << sum[sc] << endl;
		}
		for (int i = 0; i <= n;i++)
		line[i].clear();
	}
}