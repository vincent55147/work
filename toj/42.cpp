#include<iostream>
#include<queue>
using namespace std;
char que[1000][1000];
bool found[1000][1000] = { false };
queue<int>x;
queue<int>y;
void dfs(int nowy, int nowx) {
	int gox[] = { 1,0,0,-1 };
	int goy[] = { 0,1,-1,0 };
	for (int i = 0; i < 4; i++) {
		if (!found[nowy + goy[i]][nowx + gox[i]] && que[nowy + goy[i]][nowx + gox[i]] == '.') {
			found[nowy + goy[i]][nowx + gox[i]] = true;
			dfs(nowy + goy[i], nowx + gox[i]);
		}
	}
}
void bfs(int nowy, int nowx) {
	int gox[] = { 1,0,0,-1 };
	int goy[] = { 0,1,-1,0 };
	for (int i = 0; i < 4; i++) {
		if (!found[nowy + goy[i]][nowx + gox[i]] && que[nowy + goy[i]][nowx + gox[i]] == '.') {
			x.push(nowx + gox[i]);
			y.push(nowy + goy[i]);
			found[nowy + goy[i]][nowx + gox[i]] = true;
		}
	}
	x.pop();
	y.pop();
	if (!x.empty()) {
		bfs(y.front(), x.front());
	}
}
int main() {
	int t, w, h,all;
	while (cin >> t) {
		while (t--) {
			all = 0;
			cin >> h >> w;
			for (int i = 1; i <= h; i++) {
				for (int a = 1; a <= w; a++) {
					cin >> que[i][a];
					found[i][a] = false;
				}
			}
			for (int i = 0; i <= w + 1; i++) {
				que[0][i] = '#';
				que[h + 1][i] = '#';
			}
			for (int i = 1; i <= h + 1; i++) {
				que[i][0] = '#';
				que[i][w + 1] = '#';
			}
			for (int i = 1; i <= h; i++) {
				for (int a = 1; a <= w; a++) {
					if (!found[i][a] && que[i][a] == '.') {
						found[i][a] = true;
						x.push(a);
						y.push(i);
						all++;
						dfs(i, a);
					}
				}
			}
			cout << all << endl;
		}
	}
}
