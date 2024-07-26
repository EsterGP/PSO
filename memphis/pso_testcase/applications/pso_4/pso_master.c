#include <api.h>
#include <stdlib.h>

Message msg;

int main (){
	msg.length = MSG_SIZE;
	
	int t;
	t = GetTick();
	Echo("Iniciando");
	
	//para o paralelismo
	int M = 2; //numero de variaveis na função objetivo
    	int N = 100; //tamanho da população total que será dividido para cada servo
	int sec = 4; //total de EP secundários

	int maxite = 20;   //total de iterações para cada EP secundário
	int maxrun = 1;     //total de vezes que o programa vai rodar em cada EP secundário
    	
    	int w = 1;
	int c = 2;	   //constante positiva (c1 e c2)
	int gbest[M];     //melhor global
	int fmin;   	  //minimo guardado e minimo corrente
	int tfmin, tgbest[M]; //mínimo geral e gbest geral
	int i;
    	
    	//  ########### slave 1 ###########
    	int Xmin1 = 0;
	int Xmax1 = 50;
	int Ymin1 = 0;
	int Ymax1 = 50;
	
	//  ########### slave 2 ###########
    	int Xmin2 = 50;
	int Xmax2 = 100;
	int Ymin2 = 0;
	int Ymax2 = 50;
	
	//  ########### slave 3 ###########
    	int Xmin3 = 50;
	int Xmax3 = 100;
	int Ymin3 = 0;
	int Ymax3 = 50;
	
	//  ########### slave 4 ###########
    	int Xmin4 = 50;
	int Xmax4 = 100;
	int Ymin4 = 50;
	int Ymax4 = 100;
	
	// ###### Inicialização da mensagem para o servo 1 ######
	msg.msg[0] = M;
	msg.msg[1] = N/sec;
	msg.msg[2] = Xmin1;
	msg.msg[3] = Xmax1;
	msg.msg[4] = Ymin1;
	msg.msg[5] = Ymax1;
	msg.msg[6] = w;
	msg.msg[7] = c;
	msg.msg[8] = maxite;
	msg.msg[9] = maxrun;

	for (i = 10; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 1");
	for (i = 0; i < 10; i++){
		Echo(itoa(msg.msg[i]));
	}
	Echo(itoa(GetTick()));
	Send (&msg, pso_slave1); // Envia parâmetros ao servo 1
	Echo(itoa(GetTick()));
	
	
	// ###### Inicialização da mensagem para o servo 2 ######
	msg.msg[0] = M;
	msg.msg[1] = N/sec;
	msg.msg[2] = Xmin2;
	msg.msg[3] = Xmax2;
	msg.msg[4] = Ymin2;
	msg.msg[5] = Ymax2;
	msg.msg[6] = w;
	msg.msg[7] = c;
	msg.msg[8] = maxite;
	msg.msg[9] = maxrun;

	for (i = 10; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 2");
	for (i = 0; i < 10; i++){
		Echo(itoa(msg.msg[i]));
	}
	Echo(itoa(GetTick()));
	Send (&msg, pso_slave2); // Envia parâmetros ao servo 2
	Echo(itoa(GetTick()));
	
	// ###### Inicialização da mensagem para o servo 3 ######
	msg.msg[0] = M;
	msg.msg[1] = N/sec;
	msg.msg[2] = Xmin3;
	msg.msg[3] = Xmax3;
	msg.msg[4] = Ymin3;
	msg.msg[5] = Ymax3;
	msg.msg[6] = w;
	msg.msg[7] = c;
	msg.msg[8] = maxite;
	msg.msg[9] = maxrun;

	for (i = 10; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 3");
	for (i = 0; i < 10; i++){
		Echo(itoa(msg.msg[i]));
	}
	Echo(itoa(GetTick()));
	Send (&msg, pso_slave3); // Envia parâmetros ao servo 3
	Echo(itoa(GetTick()));
	
	
	// ###### Inicialização da mensagem para o servo 4 ######
	msg.msg[0] = M;
	msg.msg[1] = N/sec;
	msg.msg[2] = Xmin4;
	msg.msg[3] = Xmax4;
	msg.msg[4] = Ymin4;
	msg.msg[5] = Ymax4;
	msg.msg[6] = w;
	msg.msg[7] = c;
	msg.msg[8] = maxite;
	msg.msg[9] = maxrun;

	for (i = 10; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 4");
	for (i = 0; i < 10; i++){
		Echo(itoa(msg.msg[i]));
	}
	Echo(itoa(GetTick()));
	Send (&msg, pso_slave4); // Envia parâmetros ao servo 4
	Echo(itoa(GetTick()));

	// Recebe resultados do servo 1
	Receive (&msg, pso_slave1); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];

	tfmin = fmin;
	tgbest[0] = gbest[0];
	tgbest[1] = gbest[1];
        
        // Recebe resultados do escravo 2
	Receive (&msg, pso_slave2); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];

	if(fmin < tfmin){
		tfmin = fmin;
		tgbest[0] = gbest[0];
		tgbest[1] = gbest[1];
        }
        
        // Recebe resultados do servo 3
	Receive (&msg, pso_slave3); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
	if(fmin < tfmin){
		tfmin = fmin;
		tgbest[0] = gbest[0];
		tgbest[1] = gbest[1];
        }
        
        // Recebe resultados do escravo 4
	Receive (&msg, pso_slave4); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];

	if(fmin < tfmin){
		tfmin = fmin;
		tgbest[0] = gbest[0];
		tgbest[1] = gbest[1];
        }
        
        //imprimindo resultados
        Echo("############################");
	Echo("Melhor resultado da funcao: ");
        Echo(itoa(tfmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(tgbest[0]));
        Echo("X2 = ");
        Echo(itoa(tgbest[1])); 
        
        Echo("Fim do PSO: ");
        Echo(itoa(GetTick()));
        
}
