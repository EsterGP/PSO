#include <api.h>
#include <stdlib.h>

Message msg;

int main (){
	msg.length = MSG_SIZE;
	
	int t;
	t = GetTick();
	
	//para o paralelismo
	int M = 2; //numero de variaveis na função objetivo
    	int N = 50; //tamanho da população para cada servo
    	
    	int w = 1;
	int c = 2;	   //constante positiva (c1 e c2)
	int gbest[M];     //melhor global
	int fmin;   	  //minimo guardado e minimo corrente
	int i;
    	
    	//  ########### slave 1 ###########
    	int Xmin1 = 0;
	int Xmax1 = 50;
	int Ymin1 = 0;
	int Ymax1 = 100;
	
	//  ########### slave 2 ###########
    	int Xmin2 = 50;
	int Xmax2 = 100;
	int Ymin2 = 0;
	int Ymax2 = 100;
	
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
	
	Echo("Mensagem preparada para envio ao servo 1");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave1); // Envia parâmetros ao servo 1
	
	
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
	
	Echo("Mensagem preparada para envio ao servo 2");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave2); // Envia parâmetros ao servo 1
	
	
	// Recebe resultados do servo 1
	Receive (&msg, pso_slave1); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 1");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        // Recebe resultados do escravo 2
	Receive (&msg, pso_slave2); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 2");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        Echo("Fim do PSO: ");
        Echo(itoa(GetTick()));
}
