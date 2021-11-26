#include <api.h>
#include <stdlib.h>

#define N 100   //tamanho da população
#define M 2     //dimensão de x

Message msg;

void ofun(int x[N][M], int of[]); 
void min(int f[], int aux[]);

int main (){
	int t;
	t = GetTick();
	
	int lim_inf[M] = {0, 0};
	int lim_sup[M] = {100, 100};
	int w = 1;
	
	int c1 = 2;         //constante positiva
	int c2 = 2;
	int maxite = 20;   //total de iterações
	int maxrun = 1;     //total de vezes que o programa vai rodar

	int i = 0;
	int j = 0;
	int k = 0;
	int run = 1;
	int iteracao = 0;

	int x[N][M];      //população
	int v[N][M];      //velocidade das partículas

	int pbest[N][M];  //melhor de cada partícula
	int gbest[M];     //melhor global
	int f0[N];        //valores de aptidao (fitness)
	int f[N];         //valores de aptidao (fitness) corrente

	int x_min;    //índice do valor mínimo de fitness
	int fmin0, fmin;   //minimo guardado e minimo corrente
	int ffmin[maxite][maxrun];
	int ffite[maxrun];

	int aux[2];   //aux[0] guarda o valor mínimo e aux[1] guarda o índice do valor mínimo
	
	for(run=1;run<=maxrun;run++){
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				x[i][j] = (rand(GetTick(),0,100));
			}
		}
		
        	for(i=0;i<N;i++){
            		for(j=0;j<M;j++){
                		x[i][j] = x[i][j];
				v[i][j] = 1;
            		}
        	}

		//Calculando a aptidão
		ofun(x,f0);
        	
		min(f0,aux);    //pega o indice do menor valor
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
			//w = wmax - (wmax - wmin)*(iteracao/maxite);  //calculando o coeficiente de inércia
            
			//atualizando as velocidades
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					v[i][j] = w*v[i][j] + (c1*(rand(GetTick(),0,2))*(pbest[i][j]-x[i][j]) + c2*(rand(GetTick(),0,2))*(gbest[j]-x[i][j]))%10;
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
            		ofun(x,f);

            		//atualizando pbest
            		for(i=0;i<N;i++){
                		if(f[i]<f0[i]){
                    			f0[i] = f[i];
                    			for(j=0;j<M;j++) pbest[i][j] = x[i][j];
                		}
            		}

		    	min(f0,aux);
		    	fmin = aux[0];
		    	x_min = aux[1];
		    	ffmin[iteracao][run] = fmin;
		    	ffite[run] = iteracao;

			Echo("iteracao: ");
			Echo(itoa(iteracao));
			Echo("Gbest: ");

            		if(fmin<fmin0){
                		for(j=0;j<M;j++){
                    			gbest[j] = pbest[x_min][j];
                    			Echo(itoa(gbest[j]));
                		}
                	fmin0 = fmin;
            		}
            
            		iteracao++;
		}

	}
	  
    	for(k=0;k<M;k++)
        	msg.msg[k] = gbest[k];
        
	msg.length = M;
	
    	Echo("Melhor particula: ");
	Echo(itoa(msg.msg[0])); Echo(itoa(msg.msg[1]));
    	Echo("Fitness: ");
    	Echo(itoa(fmin));
    	Echo("Tempo total de execucao: ");
    	Echo(itoa(GetTick()));
}

void ofun(int x[N][M], int of[]){
    int i;

    for(i=0;i<N;i++){
        //Função objetivo
        of[i] = 10*(x[i][0]-10)*(x[i][0]-10) + 20*(x[i][1]-20)*(x[i][1]-20);
    }
}

void min(int f[],int aux[]){
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
