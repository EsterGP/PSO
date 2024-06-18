#include <api.h>
#include <stdlib.h>

Message msg;

void ofun(int x[][2], int of[], int N); 
void min(int f[], int aux[], int N);

int main (){
	int t;
	t = GetTick();
	
	msg.length = MSG_SIZE;
	
	int N, M, XMin, XMax, YMin, YMax, w, c, i;

	//Recebe parâmetros do mestre
	Receive (&msg, pso_master);
	Echo ("Mensagem recebida pelo escravo 2");
	for (i = 0; i < MSG_SIZE; i++){
		Echo (itoa (msg.msg[i]));
	}

	M = msg.msg[0];
	N = msg.msg[1];
	XMin = msg.msg[2];
	XMax = msg.msg[3];
	YMin = msg.msg[4];
	YMax = msg.msg[5];
	w = msg.msg[6];
	c = msg.msg[7];
	
	int lim_inf[] = {XMin, YMin};
	int lim_sup[] = {XMax, YMax};
	
	int maxite = 500;   //total de iterações
	int maxrun = 1;     //total de vezes que o programa vai rodar

	//int i = 0; linha 15
	int j = 0;
	//int k = 0;
	int run = 1;
	int iteracao = 0;

	int x[N][M];      //população
	int v[N][M];      //velocidade das partículas

	int pbest[N][M];  //melhor de cada partícula
	int gbest[M];     //melhor global
	int f0[N];        //valores de aptidao (fitness)
	int f[N];         //valores de aptidao (fitness) corrente

	int x_min;    //índice do valor mínimo de fitness (Menor)
	int fmin0, fmin;   //minimo guardado e minimo corrente  (MenorFun0, MenorFun)
	int ffmin[maxite][maxrun];
	int ffite[maxrun];

	int aux[2];   //aux[0] guarda o valor mínimo e aux[1] guarda o índice do valor mínimo
	
	for(run=1;run<=maxrun;run++){
		for(i=0;i<N;i++){
			x[i][0] = (rand(GetTick(),XMin,XMax-XMin));
			x[i][1] = (rand(GetTick(),YMin,YMax-YMin));
			v[i][0] = 1;
			v[i][1] = 1;
		}

		//Calculando a aptidão
		ofun(x,f0,N);
        	
		min(f0,aux,N);    //pega o indice do menor valor
		fmin0 = aux[0];
		x_min = aux[1];


		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				pbest[i][j] = x[i][j];
			}
		}
		
		for(j=0;j<M;j++){
			gbest[j] = x[x_min][j];
		}

		iteracao = 1;

		while(iteracao<=maxite){            
			//atualizando as velocidades
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					v[i][j] = w*v[i][j] + (c*(rand(GetTick(),0,2))*(pbest[i][j]-x[i][j]) + c*(rand(GetTick(),0,2))*(gbest[j]-x[i][j]))%10;
				}
			}
            
			//atualizando a posição das partículas
			for(i=0;i<N;i++)
				for(j=0;j<M;j++)
					x[i][j] = x[i][j] + v[i][j];

			//verificando limites
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					if(x[i][j] < lim_inf[j]) x[i][j] = lim_inf[j];
					else if(x[i][j] > lim_sup[j]) x[i][j] = lim_sup[j];
                		}
            		}

            		//Calculando a aptidão
            		ofun(x,f,N);

            		//atualizando pbest
            		for(i=0;i<N;i++){
                		if(f[i]<f0[i]){
                    			f0[i] = f[i];
                    			for(j=0;j<M;j++) pbest[i][j] = x[i][j];
                		}
            		}

		    	min(f0,aux,N);
		    	fmin = aux[0];
		    	x_min = aux[1];
		    	ffmin[iteracao][run] = fmin;
		    	ffite[run] = iteracao;

            		if(fmin<fmin0){
				Echo("iteracao: ");
				Echo(itoa(iteracao));
				Echo("Gbest: ");
                		for(j=0;j<M;j++){
                    			gbest[j] = pbest[x_min][j];
                    			Echo(itoa(gbest[j]));
                		}
				Echo("Fitness: ");
				Echo(itoa(fmin));
                		fmin0 = fmin;
            		}
            
            		iteracao++;
            		
		}

	}
	  
    	Echo("Melhor particula: ");
	Echo(itoa(gbest[0])); Echo(itoa(gbest[1]));
    	Echo("Fitness: ");
    	Echo(itoa(fmin));
    	Echo("Tempo total de execucao: ");
    	Echo(itoa(GetTick()));
    	
    	//Enviando os resultados para o mestre

	msg.msg[0] = fmin;
	msg.msg[1] = gbest[0];
	msg.msg[2] = gbest[1];
	Send (&msg, pso_master);
}

void ofun(int x[][2], int of[], int N){
    int i;

    for(i=0;i<N;i++){
        //Função objetivo (1-x)^2 + 100(y-x^2)^2
        of[i] = (1-x[i][0])*(1-x[i][0]) + 100*((x[i][1]-x[i][0]*x[i][0])*(x[i][1]-x[i][0]*x[i][0]));
    }
}

void min(int f[],int aux[], int N){
    int i;
    aux[0] = f[0];
    aux[1] = 0;

    for(i=1;i<N;i++){
        if(f[i] < aux[0]){
            aux[0] = f[i];
            aux[1] = i;
        }
    }
}
