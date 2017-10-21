#include<bits\stdc++.h> 
using namespace std;
int main(){
	int a,b,c,d,m,s,t,su_go,go,sum;
	while (scanf("%d %d %d %d %d %d %d", &a,&b, &c, &d, &m, &s, &t)) {
		go = 0;
		sum = 0;
		su_go = m / c;
		if (su_go > t) {
			su_go = t;
		}
		m = m - su_go*c;
		go=su_go*b;
		sum= su_go;
		if (go >= s)cout << "Yes" << endl << sum << endl;
		else if (t == sum)cout << "No" << endl<<go<<endl;
		else {
			if (t - sum == 1) {

			}
		}
	}
}