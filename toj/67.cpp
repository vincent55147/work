bool hard;
int egg;
long long int x,top=1,end=2147483647;

int main(){	

	initialize();
	while(end-top!=1){
		x=(top+end)/2;

		hard=throw_egg(x);
		if(hard)
			top=x;
		else
			end=x;
	}
		
		if(throw_egg(x))
			answer(x);
		else
			answer(x-1);
	}
