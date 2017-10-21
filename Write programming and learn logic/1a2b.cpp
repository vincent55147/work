#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
bool play;
int mode,guess_way[4],guess_know[4],a,b,turn=0,player_num=21425314;
//函式
	int mach_a(int guess[],int password[]) { /*找A,AI行動*/
		int a=0,num;
		bool know_a[4]= {false};
		for(int i=0; i<4; i++)
			guess_way[i]=-1;
		for(int i=0; i<4; i++)
			if(guess[i]==password[i]) {
				a++;
				if(mode==5&&!play)
					guess_way[i]=guess[i];
			}
		if(mode==4&&!play) {
			for(int i=0; i<a; i++) {
				srand(time(NULL));
				do {
					num=rand() % 4;
				} while(know_a[num]!=false);
				know_a[num]=true;
				guess_way[num]=guess[num];
			}
		}
		return a;
	}
	int mach_b(int guess[],int password[]) { /*找b,AI行動*/
		int b=0,num,know;
		bool know_b[4]= {false};
		for(int i=0; i<4; i++)
			guess_know[i]=-1;
		for(int i=0; i<4; i++)
			for(int u=0; u<4; u++)
				if(guess[i]==password[u])
					b++;
		b-=a;
		if(mode==3&&!play) {
			for(int i=0; i<b; i++) {
				srand(time(NULL));
				do {
					know=rand() % 4;
				} while(know_b[know]!=false);
				know_b[know]=true;
				srand(time(NULL));
				do {
					num=rand() % 4;
				} while(guess_know[num]!=-1||num==know);
				guess_know[num]=guess[know];
			}
		} else if((mode==5||mode==4)&&!play) {
			for(int i=0; i<b; i++) {
				srand(time(NULL));
				do {
					know=rand() % 4;
				} while(know_b[know] || guess_way[know]>-1||(b==3&&know==num));
				know_b[know]=true;
				srand(time(NULL));
				do {
					num=rand() % 4;
				} while(guess_know[num]!=-1||num==know||guess_way[num]>-1);
				guess_know[num]=guess[know];
			}
		}
		return b;
	}
	void bore (int guess[],string name,int a,int b) { /*驗證使用所猜得是否有誤，並輸出AB*/
		bool bore=false;
		for(int i=0; i<4; i++)
			for(int u=i+1; u<4; u++)
				if(guess[i]==guess[u])
					bore=true;
		if(bore)
			cout<<"請重新輸入數字不重複的4位數字\n";
		else {
			if(play==0)
				play++;
			else if(play)
				play=0;
			if(a==4)
				cout<<name<<":\t win"<<endl;
			else
				cout<<name<<":\t"<<a<<"A "<<b<<"B"<<endl;
			++turn%=player_num;
		}
	}
//主程式碼 
int main() {
	int password[4],guess[4],num,re,bmode,com[4];
	long long guess_;
	string name1,name2,quit,player[20];
	bool check;
		cout<<"如要玩請按s\n";
		cin>>quit;
	while(quit=="S"||quit=="s") {
//password預備
		{
			a=b=0; 
			for(int i=0; i<4; i++)
				password[i]=-1;
			re=0;
			srand(time(NULL));
			while(re<4) {
				check=false;
				num= rand() % 10;
				for(int i=0; i<4; i++)
					if(num==password[i])check=true;
				if(check==false) {
					password[re]=num;
					cout<<num;
					re++;
				}
			}
		}
		cout<<endl;
//主要 mode 0=雙人玩 1=自己玩 2=與等級1的AI玩(以此類推) 6=多人玩 
		{
			cout<<"請選擇模式\n 1.雙人玩 2.單人玩 3.多人玩"<<endl;
			cin>>bmode;
			while(bmode!=1&&bmode!=2&&bmode!=3) {
				cout<<"請輸入1或2或3"<<endl;
				cin>>bmode;
			}
			if (bmode==1) {
				cout<<"請輸入玩家1的名字:";
				cin>>name1;
				cout<<"請輸入玩家2的名字:";
				cin>>name2;
				mode=0;
			}
			if (bmode==2) {
				cout<<"請選擇模式\n 1.自己玩 2.與AI\n";
				cin>>mode;
				while(mode!=1&&mode!=2) {
					cout<<"請輸入1或2"<<endl;
					cin>>mode;
				}
				if(mode==2) {
					cout<<"請輸入AI等級(1-4)\n";
					cin>>mode;
					while(mode<1||mode>4) {
						cout<<"請入1到4\n";
						cin>>mode;
					}
					mode++;
				}
			}
			if (bmode==3) {
				cout<<"請輸入總人數(20人為限):\t";
				do {
					cin>>player_num;
					if(player_num<0||player_num>20)
						cout<<"0-20"<<endl;
				} while(player_num<0||player_num>20);
				for(int i=0; i<player_num; i++) {
					cout<<"請輸入玩家"<<i+1<<"的名字:";
					cin>>player[i];
				}
				mode=6;
			}
		}
		switch  (mode) {
			case 0: {
				play=0;
				cout<<"請輸入4位數字"<<endl;
				while(a!=4) {
					for(int i=0; i<4; i++)
						guess[i]=-1;
					guess_=10001;
					while(guess_>10000||guess_<1000) {
						if(play)
							cout<<name2<<"\t";
						else
							cout<<name1<<":\t";
						cin>>guess_;
						if(guess_>10000||guess_<1000)
							cout<<"4位數"<<endl;
					}
					guess[0]=guess_/1000;
					guess[1]=guess_/100-guess[0]*10;
					guess[2]=guess_/10-guess[0]*100-guess[1]*10;
					guess[3]=guess_%10;
					a=mach_a(guess,password);
					b=mach_b(guess,password);
					if(play)
						bore(guess,name2,a,b);
					else
						bore(guess,name1,a,b);
				}
				break;
			}
			case 1: {
				cout<<"請輸入玩家名字";
				cin>>name1;
				cout<<"請輸入4位數字"<<endl;
				while(a!=4) {
					for(int i=0; i<4; i++)
						guess[i]=-1;
					guess_=10001;
					while(guess_>10000||guess_<1000) {
						cout<<name1<<":\t";
						cin>>guess_;
						if(guess_>10000||guess_<1000)
							cout<<"4位數"<<endl;
					}
					guess[0]=guess_/1000;
					guess[1]=guess_/100-guess[0]*10;
					guess[2]=guess_/10-guess[0]*100-guess[1]*10;
					guess[3]=guess_%10;
					a=mach_a(guess,password);
					b=mach_b(guess,password);
					bore(guess,name1,a,b);
				}
				break;
			}
			case 2: {
				play=0;
				cout<<"請輸入玩家名字";
				cin>>name2;
				name1="AI";
				cout<<"請輸入4位數字"<<endl;
				while(a!=4) {
					for(int i=0; i<4; i++)
						guess[i]=-1;
					if(play) {
						cout<<name1<<":\t";
						re=0;
						srand(time(NULL));
						while(re<4) {
							check=false;
							num= rand() % 10;
							for(int i=0; i<4; i++)
								if(num==guess[i])check=true;
							if(check==false) {
								guess[re]=num;
								cout<<guess[re];
								re++;
							}
						}
						cout<<endl;
					} else {
						guess_=10001;
						cout<<name2<<":\t";
						while(guess_>10000||guess_<1000) {
							cin>>guess_;
							if(guess_>10000||guess_<1000)
								cout<<"4位數"<<endl;
						}
						guess[0]=guess_/1000;
						guess[1]=guess_/100-guess[0]*10;
						guess[2]=guess_/10-guess[0]*100-guess[1]*10;
						guess[3]=guess_%10;
					}
					a=mach_a(guess,password);
					b=mach_b(guess,password);
					if(play)
						bore(guess,name1,a,b);
					else
						bore(guess,name2,a,b);
				}
				break;
			}
			case 3: {
				play=0;
				cout<<"請輸入玩家名字";
				cin>>name2;
				name1="AI";
				cout<<"請輸入4位數字"<<endl;
				while(a!=4) {
					for(int i=0; i<4; i++)
						guess[i]=-1;
					if(play) {
						cout<<name1<<":\t";
						re=0;
						srand(time(NULL));
						while(re<4) {
							if(guess_know[re]>-1) {
								guess[re]=guess_know[re];
								cout<<guess[re];
								re++;

							} else {
								check=false;
								num= rand() % 10;
								for(int i=0; i<4; i++)
									if(num==guess[i])check=true;
								for(int i=0; i<4; i++)
									if(num==guess_know[i])
										check=true;
								if(check==false) {
									guess[re]=num;
									cout<<guess[re];
									re++;
								}
							}
						}
						cout<<endl;
					} else {
						guess_=10001;
						cout<<name2<<":\t";
						while(guess_>10000||guess_<1000) {
							cin>>guess_;
							if(guess_>10000||guess_<1000)
								cout<<"4位數"<<endl;
						}
						guess[0]=guess_/1000;
						guess[1]=guess_/100-guess[0]*10;
						guess[2]=guess_/10-guess[0]*100-guess[1]*10;
						guess[3]=guess_%10;
					}
					a=mach_a(guess,password);
					b=mach_b(guess,password);
					if(play)
						bore(guess,name1,a,b);
					else
						bore(guess,name2,a,b);
				}
				break;
			}
			case 4: {
				play=0;
				cout<<"請輸入玩家名字";
				cin>>name2;
				name1="AI";
				cout<<"請輸入4位數字"<<endl;
				while(a!=4) {
					for(int i=0; i<4; i++)
						guess[i]=-1;
					if(play) {
						cout<<name1<<":\t";
						re=0;
						srand(time(NULL));
						while(re<4) {
							if(guess_way[re]>-1) {
								guess[re]=guess_way[re];
								cout<<guess[re];
								re++;
							} else if(guess_know[re]>-1) {
								guess[re]=guess_know[re];
								cout<<guess[re];
								re++;
							} else {
								check=false;
								num= rand() % 10;
								for(int i=0; i<4; i++)
									if(num==guess[i])check=true;
								for(int i=0; i<4; i++)
									if(num==guess_know[i]||num==guess_way[i])
										check=true;
								if(check==false) {
									guess[re]=num;
									cout<<guess[re];
									re++;
								}
							}
						}
						cout<<endl;
					} else {
						guess_=10001;
						cout<<name2<<":\t";
						while(guess_>10000||guess_<1000) {
							cin>>guess_;
							if(guess_>10000||guess_<1000)
								cout<<"4位數"<<endl;
						}
						guess[0]=guess_/1000;
						guess[1]=guess_/100-guess[0]*10;
						guess[2]=guess_/10-guess[0]*100-guess[1]*10;
						guess[3]=guess_%10;
					}
					a=mach_a(guess,password);
					b=mach_b(guess,password);
					if(play)
						bore(guess,name1,a,b);
					else
						bore(guess,name2,a,b);
				}
				break;
			}
			case 5: {
				play=0;
				cout<<"請輸入玩家名字";
				cin>>name2;
				name1="AI";
				cout<<"請輸入4位數字"<<endl;
				while(a!=4) {
					for(int i=0; i<4; i++)
						guess[i]=-1;
					if(play) {
						cout<<name1<<":\t";
						re=0;
						srand(time(NULL));
						while(re<4) {
							if(guess_way[re]>-1) {
								guess[re]=guess_way[re];
								cout<<guess[re];
								re++;
							} else if(guess_know[re]>-1) {
								guess[re]=guess_know[re];
								cout<<guess[re];
								re++;
							} else {
								check=false;
								num= rand() % 10;
								for(int i=0; i<4; i++)
									if(num==guess[i])check=true;
								for(int i=0; i<4; i++)
									if(num==guess_know[i]||num==guess_way[i])
										check=true;
								if(check==false) {
									guess[re]=num;
									cout<<guess[re];
									re++;
								}
							}
						}
						cout<<endl;
					} else {
						guess_=10001;
						cout<<name2<<":\t";
						while(guess_>10000||guess_<1000) {
							cin>>guess_;
							if(guess_>10000||guess_<1000)
								cout<<"4位數"<<endl;
						}
						guess[0]=guess_/1000;
						guess[1]=guess_/100-guess[0]*10;
						guess[2]=guess_/10-guess[0]*100-guess[1]*10;
						guess[3]=guess_%10;
					}
					a=mach_a(guess,password);
					b=mach_b(guess,password);
					if(play)
						bore(guess,name1,a,b);
					else
						bore(guess,name2,a,b);
				}
				break;
			}
			case 6: {
				cout<<"請輸入4位數字"<<endl;
				turn=0;
				while(a!=4) {
					for(int i=0; i<4; i++)
						guess[i]=-1;
					guess_=10001;
					while(guess_>10000||guess_<1000) {
						cout<<player[turn]<<":\t";
						cin>>guess_;
						if(guess_>10000||guess_<1000)
							cout<<"4位數"<<endl;
					}
					guess[0]=guess_/1000;
					guess[1]=guess_/100-guess[0]*10;
					guess[2]=guess_/10-guess[0]*100-guess[1]*10;
					guess[3]=guess_%10;
					a=mach_a(guess,password);
					b=mach_b(guess,password);
					bore(guess,player[turn],a,b);
				}
				break;
			}
		}
	}
}


