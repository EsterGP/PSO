#include <api.h>
#include <stdlib.h>

#define N 10   //tamanho da população
#define M 3     //dimensão de x

void ofun(int x[N][M], int of[]); 
void min(int f[], int aux[]);
int pow(int x, int y);

int main (){
	int t;
	t = GetTick();
	
	int lim_inf[M] = {0, 0, 0};
	int lim_sup[M] = {10, 10, 10};
	int wmin = 0;   //coeficiente de inércia mínimo
	int wmax = 1;   //coeficiente de inércia máximo
	int w = 0;
	
	int c1 = 2;         //constante positiva
	int c2 = 2;
	int maxite = 10;     //total de iterações
	int maxrun = 1;     //total de vezes que o programa vai rodar

	int i = 0;
	int j = 0;
	int k = 0;
	int run = 1;
	int iteracao = 0;

	int x[N][M];      //população atual
	int x_ini[N][M];  //população inicial
	int v[N][M];      //velocidade das partículas

	int pbest[N][M];  //melhor de cada partícula
	int gbest[M];     //melhor global
	int f0[N];        //valores de aptidao (fitness)
	int f[N];         //valores de aptidao (fitness) corrente

	int x_min0, x_min;    //índice dos valores mínimos de fitness
	int fmin0, fmin;   //minimo guardado e minimo corrente
	int ffmin[maxite][maxrun];
	int ffite[maxrun];

	int aux[2];   //aux[0] guarda o valor mínimo e aux[1] guarda o índice do valor mínimo
	
	for(run=1;run<=maxrun;run++){
		Echo("Comeco da run ");
		for(i=0;i<N;i++){
			Echo("Primeiro for");
			for(j=0;j<M;j++){
				Echo("formando a populacao inicial");
				//o máximo que a função rand retorna é 32767 e (double) pq senao ele daria 0 ou 1
				x_ini[i][j] = lim_inf[j] + (rand(32767,0,1))*(lim_sup[j] - lim_inf[j]);
			}
		}
/*        	Echo("Valores iniciais");
        	for(i=0;i<N;i++){
            		for(j=0;j<M;j++){
                		x[i][j] = x_ini[i][j];
				v[i][j] = (int)(0.1*x_ini[i][j]);
            		}
        	}

		//Calculando a aptidão
		ofun(x_ini,f0);
        
		min(f0,aux);    //pega o indice do menor valor
		fmin0 = aux[0];
		x_min0 = aux[1];

		for(i=0;i<N;i++)
			for(j=0;j<M;j++)
				pbest[i][j] = x_ini[i][j];

		for(j=0;j<M;j++)
			gbest[j] = x_ini[x_min0][j];

		iteracao = 1;

		while(iteracao<=maxite){
			w = wmax - (wmax - wmin)*(iteracao/maxite);  //calculando o coeficiente de inércia
            
			//atualizando as velocidades
			for(i=0;i<N;i++)
				for(j=0;j<M;j++)
					v[i][j] = w*v[i][j] + c1*(rand(t,0,1))*(pbest[i][j]-x[i][j]) + c2*(rand(t,0,1))*(gbest[j]-x[i][j]);
            
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

            		if(fmin<fmin0){
                		for(j=0;j<M;j++){
                    			gbest[j] = pbest[x_min][j];
                    			Echo(itoa(gbest[j]));
                		}
                	fmin0 = fmin;
            		}
            
            		iteracao++;
		}
*/
	}
/*	  
    	for(k=0;k<M;k++)
        	msg.msg[i] = gbest[i];
        
	msg.length = M;
	
    	Echo("Melhor partícula: ");
	Echo(itoa(msg.msg[0])); Echo(itoa(msg.msg[1])); Echo(itoa(msg.msg[2]));
    	Echo("Fitness: ");
    	Echo(itoa(fmin));
    	Echo("Tempo total de execução: ");
    	Echo(GetTick());
*/
}

void ofun(int x[N][M], int of[]){
    int i;

    for(i=0;i<N;i++){
        //Função objetivo
        of[i] = 10*pow(x[i][0]-1,2) + 20*pow(x[i][1]-2,2) + 30*pow(x[i][2]-3,2);
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

int pow(int x, int y){
    int i;
    int pot;
    
    if(y>0){
        pot = x;
        for(i=1;i<y;i++)
            pot = pot*x;
    }
    else if(y<0){
        pot = 1/x;
        y = -1 * y;
        for(i=1;i<y;i++)
            pot = pot*x;
    }
    else return 1;
        
    return pot;
}
