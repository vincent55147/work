#include<iostream>
#include <string>
using namespace std;
int main() {
	string word;
	int T, mid, all, tep, temp, left, right;
	cin >> T;
	cin.ignore();
	while (T--) {

		getline(cin, word);
		all = 1;
		for (int i = 1; i < word.size() - 1; i++) {
			right = i;
			left = right - 1;
			tep = 0;
			while (left - tep > -1 && right + tep < word.size() && word[left - tep] == word[right + tep])
				tep++;
			temp = tep * 2;
			if (temp > all)
				all = temp;

			tep = 1;
			while (i - tep > -1 && i + tep < word.size() && word[i - tep] == word[i + tep])
				tep++;
			tep--;
			temp = tep * 2 + 1;
			if (temp > all)
				all = temp;
		}
		cout << all << endl;
	}

}