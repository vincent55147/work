#include<iostream>
using namespace std;
struct Node {
	Node* _dad;
	Node* _left;
	Node* _right;
	int _data;
};
Node* Add(Node* pare,int id,bool turn) {
	Node* item = new Node;
	item->_data = id;
	item->_dad = pare;
	if (turn)
		pare->_left = item;
	else
		pare->_right = item;
	return item;
}
int main() {
	bool a;
	int all=0,num;
	Node* head=new Node;
	Node* down=new Node;
	Node* temp;
	head->_data = 100000;
	a = 1;
	while (scanf("%d", &num )!=EOF ) {
		if (all == 0 && num > head->_data)
			temp = Add(head, num, 0);
		else if (all == 0)
			temp = Add(head, num, 1);
		else if (num < temp->_data)
			temp = Add(temp, num, 1);
		else {
			while (a) {
				down = temp;
				a = 0;
			}
			while(num>temp->_data){
				temp = temp->_dad;
			}
			temp = temp->_left;
			temp = Add(temp, num, 0);
		}
		all++;
	}
	down = down->_dad;
	head = head->_left;
	while (all) {
		while (down != head) {
			if (down->_left != NULL)
				cout << down->_left->_data << endl;
			else if (down->_right != NULL)
				cout << down->_right->_data << endl;
			else {
				down = down->_dad;
			}
			cout << head->_left->_data << endl;
			while (temp != head) {
				if (temp->_left != NULL)
					cout << temp->_left->_data << endl;
				else if (temp->_right != NULL)
					cout << temp->_right->_data << endl;
				else 
					down = temp->_dad;
			}
			cout << head->_data;
		}
		
	}

}
