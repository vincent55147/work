#include<iostream>
using namespace std;
int tree[1000001],size;
bool empty() {
	return size==1;
}
void change(int &a,int &b) {
	int t=a;
	a=b;
	b=t;
}
void input(int n) {
	tree[size++]=n;
	int temp=size-1;
	while(temp>1&&tree[temp]<tree[temp/2]) {
		change(tree[temp],tree[temp/2]);
		temp/=2;
	}
}
void pop() {
	tree[1]=tree[--size];
	int temp=1,next;
	while(temp*2<size) {
		next=temp*2;
		if(temp*2+1<size&&tree[next+1]<tree[next])
			next++;
		if(tree[next]<tree[temp]) {
			change(tree[temp],tree[next]);
			temp=next;
		} else
			break;
	}
}
int main() {
	int t,mode,num;
	cin>>t;
	size=1;
	while(t--) {
		cin>>mode;
		if(mode==1) {
			cin>>num;
			input(num);
		} else {

			if(empty())cout<<"empty!"<<endl;
			else{
				cout<<tree[1]<<endl;
				pop();
			}
		}
	}
}
