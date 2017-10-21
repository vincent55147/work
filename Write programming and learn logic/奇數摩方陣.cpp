#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int n, x, y;
	int sq[200][200] = { 0 };
	while (cin >> n){
		if (n>200)
			cout << "200以內" << endl;
		else if (n % 2 == 0)
			cout << "再輸入" << endl;
		else{
			x = n / 2;
			y = 0;
			for (int q = 0; q<n; q++)
				for (int w = 0; w<n; w++)
					sq[w][q] = 0;
			for (int i = 1; i <= n*n; i++){
				sq[x][y] = i;
				x++;
				y--;
				if (x == n&&y == -1){
					y += 2;
					x--;
				}
				else if (y == -1)
					y = n - 1;
				else if (x == n)
					x = 0;
				else if (sq[x][y]>0){
					y += 2;
					x--;
				}
			}
			for (int q = 0; q<n; q++){
				for (int w = 0; w<n; w++)
					cout << setw(6) << sq[w][q];
				cout << endl;

			}
		}
	}
}
