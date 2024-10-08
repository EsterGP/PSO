#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100   //tamanho da população
#define M 2     //dimensão de x
#define PI 3.1415

void ofun(double x[N][M], double of[]); 
void min(double f[], double aux[]);

int main (){
    clock_t tempo;
    tempo = clock();

    double lim_inf[M] = {0, 0};
    double lim_sup[M] = {10, 10};
    double wmin = 0.4;   //coeficiente de inércia mínimo
    double wmax = 0.9;   //coeficiente de inércia máximo
    double w = 0;

    time_t t;

    const int c1 = 2;         //constante positiva
    const int c2 = 2;
    const int maxite = 10000;     //total de iterações
    const int maxrun = 1;     //total de vezes que o programa vai rodar

    int cont = 0;
    int i = 0;
    int j = 0;
    int run = 1;
    int iteracao = 0;
    double tolerancia = 0;

    double x[N][M];      //população atual
    double x_ini[N][M];  //população inicial
    double v[N][M];      //velocidade das partículas

    double pbest[N][M];  //melhor de cada partícula
    double gbest[M];     //melhor global
    double f0[N];        //valores de aptidao (fitness)
    double f[N];         //valores de aptidao (fitness) corrente

    int x_min0, x_min;    //índice dos valores mínimos de fitness
    double fmin0, fmin, ffmin[maxite][maxrun], fvalue, fff[maxrun];
    int ffite[maxrun];

    double aux[2];   //aux[0] guarda o valor mínimo e aux[1] guarda o índice do valor mínimo

    for(cont=0;cont<maxrun;cont++){
        printf("Run = %d \n", run);
        srand((unsigned) time(&t)); //iniciando o gerador de números aleatórios

        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                //o máximo que a função rand retorna é 32767 e (double) pq senao ele daria 0 ou 1
                x_ini[i][j] = lim_inf[j] + (((double)rand()/32767)*(lim_sup[j] - lim_inf[j]));
                //printf("\n%f\t", x_ini[i][j]);
            }
            //printf("\n");
        }
        
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                x[i][j] = x_ini[i][j];
                v[i][j] = 0.1*x_ini[i][j];
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
        tolerancia = 1;

        while( (iteracao<=maxite) && (tolerancia > pow(10,-12)) ){
            w = wmax - (wmax - wmin)*(iteracao/maxite);  //calculando o coeficiente de inércia
            
            //atualizando as velocidades
            for(i=0;i<N;i++)
                for(j=0;j<M;j++)
                    v[i][j] = w*v[i][j] + c1*(rand()%2)*(pbest[i][j]-x[i][j]) + c2*(rand()%2)*(gbest[j]-x[i][j]);
            
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
                    //printf(" %f ", gbest[j]);
                }
                printf("\n");
                fmin0 = fmin;
            }

/*
            if(iteracao > 100)
                tolerancia = sqrt(ffmin[iteracao-100][run]-fmin0);
*/
//            printf("\n%d \t %d \t %f", iteracao, x_min, fmin0);
            
            iteracao++;
        }
    }

    printf("\n\nMelhor particula: %f, %f, %f.\tFitness: %f", gbest[0], gbest[1], fmin);
    printf("\nTempo total de execucao = %f s", (clock() - tempo) / (double)CLOCKS_PER_SEC);
}

void ofun(double x[N][M], double of[]){
    int i;

    for(i=0;i<N;i++){
        //Função objetivo 10M + x^2 - cos(2*pi*x) + y^2 - cos(2*pi*y)
        of[i] = 10*M + pow(x[i][0],2) - cos(2*PI*x[i][0]) + pow(x[i][1],2) - cos(2*PI*x[i][1]);
    }
}

void min(double f[],double aux[]){
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