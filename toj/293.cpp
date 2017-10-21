#include <stdio.h>
#include <tchar.h>
#include<iostream>
#include<vector>
using namespace std;
int sum[100000];
int good[100000],good_point,temp;
vector<int> line[100000];
void dfs(int top, int father,int out) {
	sum[top] = 1;
	for (int i = 0; i < line[top].size(); i++) {
		if (line[top][i] == father)continue;
		dfs(line[top][i], top,out);
		sum[top] += sum[line[top][i]];
		if (sum[top] > good[out]&&top!=out)good[out] = sum[top];
	}
}

int main() {
	int t, n, a, b, ti;
	cin >> t;
	while (t--) {
		cin >> n;
		ti = n - 1;
		while (ti--) {
			cin >> a >> b;
			line[a].push_back(b);
			line[b].push_back(a);
		}
		for (int i = 0; i < n; i++) good[i] = 0;
		good_point= 100001;
		for (int i = 0; i < n; i++) {
			dfs(i,i,i);
		}
		temp = 100001;
		for (int i = n - 1; i >= 0; i--) {
			line[i].clear();
			if (good[i] <= temp) {
				good_point = i;
				temp = good[i];
			}
		}
		cout << good_point << endl;
		
	}
}


