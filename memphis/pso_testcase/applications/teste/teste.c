#include <api.h>
#include <stdlib.h>

int main (){
	int i;
	int x = -1;
	int y = 2;
	for(i=0;i<20;i++){
		
		//v = 1*1 + 2*(rand(GetTick(),1,2))*(pbest[i][j]-x[i][j]) + 2*(rand(GetTick(),1,2))*(gbest[j]-x[i][j]);
		Echo(itoa(rand(GetTick(),1,5)));
	}
	
	Echo(itoa(x+y));
}
