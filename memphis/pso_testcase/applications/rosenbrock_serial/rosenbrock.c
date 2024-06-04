#include <api.h>
#include <stdlib.h>

void ofun(int x[][2], int of[], int N);
void min(int f[],int aux[], int N);


Message msg;

int main (){
	msg.length = MSG_SIZE;
	
	int t;
	t = GetTick();
	Echo("Iniciando");
	
	//para o paralelismo
	int M = 2; //numero de variaveis na função objetivo
    	int N = 200; //tamanho da população para cada servo
    	
    	int w = 1;
	int c = 2;	   //constante positiva (c1 e c2)
	int gbest[M];     //melhor global
	int i, j;
    	
    	int lim_inf = 0;
	int lim_sup = 100;
	
	int maxite = 200;   //total de iterações
	int maxrun = 1;     //total de vezes que o programa vai rodar
	int run = 1;
	int iteracao = 0;

	int x[N][M];      //população
	int v[N][M];      //velocidade das partículas

	int pbest[N][M];  //melhor de cada partícula
	int f0[N];        //valores de aptidao (fitness)
	int f[N];         //valores de aptidao (fitness) corrente

	int x_min;    //índice do valor mínimo de fitness (Menor)
	int fmin0, fmin;   //minimo guardado e minimo corrente  (MenorFun0, MenorFun)
	int ffmin[maxite][maxrun];
	int ffite[maxrun];

	int aux[2];   //aux[0] guarda o valor mínimo e aux[1] guarda o índice do valor mínimo
	
	for(run=1;run<=maxrun;run++){
	
		//inicializando os valores da posição e da velocidade
		for(i=0;i<N;i++){
			x[i][0] = (rand(GetTick(),lim_inf,lim_sup));
			x[i][1] = (rand(GetTick(),lim_inf,lim_sup));
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
		Echo("Gbest: ");
		for(j=0;j<M;j++){
			gbest[j] = x[x_min][j];
                    	Echo(itoa(gbest[j]));
		}

		iteracao = 1;

		while(iteracao<=maxite){            
			//atualizando as velocidades
			//Echo("Velocidade: ");
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					v[i][j] = w*v[i][j] + (c*(rand(GetTick(),0,2))*(pbest[i][j]-x[i][j]) + c*(rand(GetTick(),0,2))*(gbest[j]-x[i][j]))%100;
					//Echo(itoa(v[i][j]));
				}
			}
            
			//atualizando a posição das partículas
			//Echo("Posicao: ");
			for(i=0;i<N;i++)
				for(j=0;j<M;j++){
					x[i][j] = x[i][j] + v[i][j];
					//Echo(itoa(x[i][j]));
				}

			//verificando limites
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					if(x[i][j] < lim_inf) x[i][j] = lim_inf;
					else if(x[i][j] > lim_sup) x[i][j] = lim_sup;
					//Echo("Nova posicao: "); Echo(itoa(x[i][j]));
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

			Echo("iteracao: ");
			Echo(itoa(iteracao));

            		if(fmin<fmin0){
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
}

void ofun(int x[][2], int of[], int N){
    int i;

    for(i=0;i<N;i++){
	//Função objetivo (1-x)^2 + 100(y-x^2)^2
        of[i] = (1-x[i][0])*(1-x[i][0]) + 100*((x[i][1]-((x[i][0])*(x[i][0])))*(x[i][1]-((x[i][0])*(x[i][0]))));
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
