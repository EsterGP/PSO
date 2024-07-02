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
    	int N = 150; //tamanho da população para cada servo
    	
    	int w = 1;
	int c = 2;	   //constante positiva (c1 e c2)
	int gbest[M];     //melhor global
	int fmin;   	  //minimo da função objetivo
	int tfmin, tgbest[M]; //mínimo geral e gbest geral
	int i;
    	
    	//  ########### slave 1 ###########
    	int Xmin1 = -65;
	int Xmax1 = -1;
	int Ymin1 = -65;
	int Ymax1 = -1;
	
	//  ########### slave 2 ###########
    	int Xmin2 = 0;
	int Xmax2 = 65;
	int Ymin2 = -65;
	int Ymax2 = -1;
	
	//  ########### slave 3 ###########
    	int Xmin3 = 0;
	int Xmax3 = 65;
	int Ymin3 = 0;
	int Ymax3 = 65;
	
	//  ########### slave 4 ###########
    	int Xmin4 = -65;
	int Xmax4 = -1;
	int Ymin4 = 0;
	int Ymax4 = 65;
	
	
	// ###### Inicialização da mensagem para o servo 1 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin1;
	msg.msg[3] = Xmax1;
	msg.msg[4] = Ymin1;
	msg.msg[5] = Ymax1;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	Echo(itoa(GetTick()));
	Send (&msg, pso_slave1); // Envia parâmetros ao servo 1
	Echo(itoa(GetTick()));
	
	
	// ###### Inicialização da mensagem para o servo 2 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin2;
	msg.msg[3] = Xmax2;
	msg.msg[4] = Ymin2;
	msg.msg[5] = Ymax2;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	Echo(itoa(GetTick()));
	Send (&msg, pso_slave2); // Envia parâmetros ao servo 2
	Echo(itoa(GetTick()));
	
	// ###### Inicialização da mensagem para o servo 3 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin3;
	msg.msg[3] = Xmax3;
	msg.msg[4] = Ymin3;
	msg.msg[5] = Ymax3;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	Echo(itoa(GetTick()));
	Send (&msg, pso_slave3); // Envia parâmetros ao servo 3
	Echo(itoa(GetTick()));	
	
	// ###### Inicialização da mensagem para o servo 4 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin4;
	msg.msg[3] = Xmax4;
	msg.msg[4] = Ymin4;
	msg.msg[5] = Ymax4;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
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
