#include<iostream>
#include<queue>
#include<string>
using namespace std;
queue<int>x;
queue<int>y;
queue<int>needx;
queue<int>needy;
int step[100][100];
char que[100][100];
void bfs(int nowy, int nowx) {
	int gox[] = { 1,0,0,-1 };
	int goy[] = { 0,1,-1,0 };
	for (int i = 0; i < 4; i++) {
		if ((step[nowy + goy[i]][nowx + gox[i]]==-1) && (que[nowy + goy[i]][nowx + gox[i]] == '.' || que[nowy + goy[i]][nowx + gox[i]] == '@')) {
			step[nowy + goy[i]][nowx + gox[i]] = step[nowy][nowx] + 1;
			x.push(nowx + gox[i]);
			y.push(nowy + goy[i]);
		}
	}
	x.pop();
	y.pop();
	if (!x.empty()) {
		bfs(y.front(), x.front());
	}
}
int main() {
	int n;
	string temp;
	while (cin >> n) {
		if (n > 0) {
			cin.ignore();
			for (int i = 0; i < n; i++) {
				getline(cin, temp);
				for (int h = 0; h < temp.size(); h++) {
					que[i][h] = temp[h];
					step[i][h] = -1;
					if (que[i][h] == 'K') {
						x.push(h);
						y.push(i);
						step[i][h] = 0;
					}
					if (que[i][h] == '.') {
						step[i][h] = -1;
					}
					if (que[i][h] == '@'){
						needx.push(h);
						needy.push(i);
						step[i][h] = -1;
					}
				}
			}
			bfs(y.front(), x.front());
			int small = 10000;
			bool ch = false;
			while(!needx.empty()){
					if (que[needy.front()][needx.front()] == '@'&&step[needy.front()][needx.front()] !=-1&&step[needy.front()][needx.front()] < small) {
						ch = true;
						small = step[needy.front()][needx.front()];
					}
					needx.pop();
					needy.pop();
			}
			if (ch)
				cout << small << endl;
			else
				cout << "= =\"" << endl;
		}
	}
}
