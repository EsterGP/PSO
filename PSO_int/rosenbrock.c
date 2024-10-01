#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 25   //tamanho da população
#define M 2     //dimensão de x

void ofun(int x[N][M], int of[]); 
void min(int f[], int aux[]);

int main (){
    clock_t tempo;
    tempo = clock();

    int lim_inf[M] = {-65, -65};
    int lim_sup[M] = {65, 65};
    int w = 1;

    time_t t;

    const int c = 2;         //constante positiva

    int i = 0;
    int j = 0;
    int iteracao = 0;

    int x[N][M];      //população atual
    int x_ini[N][M];  //população inicial
    int v[N][M];      //velocidade das partículas

    int pbest[N][M];  //melhor de cada partícula
    int gbest[M];     //melhor global
    int f0[N];        //valores de aptidao (fitness)
    int f[N];         //valores de aptidao (fitness) corrente

    int x_min0, x_min;    //índice dos valores mínimos de fitness
    int fmin0, fmin;


    int aux[2];   //aux[0] guarda o valor mínimo e aux[1] guarda o índice do valor mínimo

    srand((unsigned) time(&t)); //iniciando o gerador de números aleatórios

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            x_ini[i][j] = lim_inf[j] + (rand()%lim_sup[j]);
        }
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

    while(fmin0 != 0){
        
        //atualizando as velocidades
        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
                v[i][j] = w*v[i][j] + c*(rand()%2)*(pbest[i][j]-x[i][j]) + c*(rand()%2)*(gbest[j]-x[i][j]);
        
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


        if(fmin<fmin0){
            for(j=0;j<M;j++){
                gbest[j] = pbest[x_min][j];
                printf(" %d ", gbest[j]);
            }
            printf("\n");
            fmin0 = fmin;
            printf("%d\n", fmin0);
        }
        
        iteracao++;
    }

    printf("\nIteracao: %d", iteracao);
    printf("\n\nMelhor particula: %d, %d.\tFitness: %d", gbest[0], gbest[1], fmin0);
    printf("\nTempo total de execucao = %f s", (clock() - tempo) / (double)CLOCKS_PER_SEC);
}

void ofun(int x[N][M], int of[]){
    int i;

    for(i=0;i<N;i++){
        //Função objetivo
        of[i] = pow(1- x[i][0],2) + 100*pow(x[i][1]-pow(x[i][0],2),2);
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