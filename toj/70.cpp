#include<iostream>
#include<queue>
#include<algorithm> 
using namespace std;
int main(){
	int n,temp;
	int num[100000];
	while(cin>>n){
		if(n>0){
			for(int i=0;i<n;i++){
				cin>>num[i];
			}
			temp=0;
			sort(num,num+n);
			for(int i=0;i<n;i++){
				temp+=num[i]*(n-i);
			}
			temp-=num[0];
			cout<<temp<<endl;
		}
	}
}
