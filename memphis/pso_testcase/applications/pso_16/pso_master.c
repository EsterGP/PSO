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
    	int N = 100; //tamanho da população para cada servo
    	
    	int w = 1;
	int c = 2;	   //constante positiva (c1 e c2)
	int gbest[M];     //melhor global
	int fmin;   	  //minimo guardado e minimo corrente
	int i;
    	
    	//  ########### slave 1 ###########
    	int Xmin1 = 0;
	int Xmax1 = 25;
	int Ymin1 = 0;
	int Ymax1 = 25;
	
	//  ########### slave 2 ###########
    	int Xmin2 = 25;
	int Xmax2 = 50;
	int Ymin2 = 0;
	int Ymax2 = 25;
	
	//  ########### slave 3 ###########
    	int Xmin3 = 50;
	int Xmax3 = 75;
	int Ymin3 = 0;
	int Ymax3 = 25;
	
	//  ########### slave 4 ###########
    	int Xmin4 = 75;
	int Xmax4 = 100;
	int Ymin4 = 0;
	int Ymax4 = 25;
	
	//  ########### slave 5 ###########
    	int Xmin5 = 0;
	int Xmax5 = 25;
	int Ymin5 = 25;
	int Ymax5 = 50;
	
	//  ########### slave 6 ###########
    	int Xmin6 = 25;
	int Xmax6 = 50;
	int Ymin6 = 25;
	int Ymax6 = 50;
	
	//  ########### slave 7 ###########
    	int Xmin7 = 50;
	int Xmax7 = 75;
	int Ymin7 = 25;
	int Ymax7 = 50;
	
	//  ########### slave 8 ###########
    	int Xmin8 = 75;
	int Xmax8 = 100;
	int Ymin8 = 25;
	int Ymax8 = 50;
	
	//  ########### slave 9 ###########
    	int Xmin9 = 0;
	int Xmax9 = 25;
	int Ymin9 = 50;
	int Ymax9 = 75;
	
	//  ########### slave 10 ###########
    	int Xmin10 = 25;
	int Xmax10 = 50;
	int Ymin10 = 50;
	int Ymax10 = 75;
	
	//  ########### slave 11 ###########
    	int Xmin11 = 50;
	int Xmax11 = 75;
	int Ymin11 = 50;
	int Ymax11 = 75;
	
	//  ########### slave 12 ###########
    	int Xmin12 = 75;
	int Xmax12 = 100;
	int Ymin12 = 50;
	int Ymax12 = 75;
	
	//  ########### slave 13 ###########
    	int Xmin13 = 0;
	int Xmax13 = 25;
	int Ymin13 = 75;
	int Ymax13 = 100;
	
	//  ########### slave 14 ###########
    	int Xmin14 = 25;
	int Xmax14 = 50;
	int Ymin14 = 75;
	int Ymax14 = 100;
	
	//  ########### slave 15 ###########
    	int Xmin15 = 50;
	int Xmax15 = 75;
	int Ymin15 = 75;
	int Ymax15 = 100;
	
	//  ########### slave 16 ###########
    	int Xmin16 = 75;
	int Xmax16 = 100;
	int Ymin16 = 75;
	int Ymax16 = 100;
	
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
	Send (&msg, pso_slave2); // Envia parâmetros ao servo 2
	
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
	
	Echo("Mensagem preparada para envio ao servo 3");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave3); // Envia parâmetros ao servo 3
	
	
	// ###### Inicialização da mensagem para o servo 4 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin4;
	msg.msg[3] = Xmax4;
	msg.msg[4] = Ymin4;
	msg.msg[5] = Ymax5;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 4");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave4); // Envia parâmetros ao servo 4
	
	// ###### Inicialização da mensagem para o servo 5 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin5;
	msg.msg[3] = Xmax5;
	msg.msg[4] = Ymin5;
	msg.msg[5] = Ymax5;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 5");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave5); // Envia parâmetros ao servo 5
	
	
	// ###### Inicialização da mensagem para o servo 6 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin6;
	msg.msg[3] = Xmax6;
	msg.msg[4] = Ymin6;
	msg.msg[5] = Ymax6;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 6");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave6); // Envia parâmetros ao servo 6
	
	// ###### Inicialização da mensagem para o servo 7 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin7;
	msg.msg[3] = Xmax7;
	msg.msg[4] = Ymin7;
	msg.msg[5] = Ymax7;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 7");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave7); // Envia parâmetros ao servo 7
	
	
	// ###### Inicialização da mensagem para o servo 8 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin8;
	msg.msg[3] = Xmax8;
	msg.msg[4] = Ymin8;
	msg.msg[5] = Ymax8;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 8");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave8); // Envia parâmetros ao servo 8
	
	// ###### Inicialização da mensagem para o servo 9 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin9;
	msg.msg[3] = Xmax9;
	msg.msg[4] = Ymin9;
	msg.msg[5] = Ymax9;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 9");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave9); // Envia parâmetros ao servo 9
	
	
	// ###### Inicialização da mensagem para o servo 10 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin10;
	msg.msg[3] = Xmax10;
	msg.msg[4] = Ymin10;
	msg.msg[5] = Ymax10;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 10");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave10); // Envia parâmetros ao servo 10
	
	// ###### Inicialização da mensagem para o servo 11 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin11;
	msg.msg[3] = Xmax11;
	msg.msg[4] = Ymin11;
	msg.msg[5] = Ymax11;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 11");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave11); // Envia parâmetros ao servo 11
	
	
	// ###### Inicialização da mensagem para o servo 12 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin12;
	msg.msg[3] = Xmax12;
	msg.msg[4] = Ymin12;
	msg.msg[5] = Ymax12;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 12");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave12); // Envia parâmetros ao servo 12
	
	// ###### Inicialização da mensagem para o servo 13 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin13;
	msg.msg[3] = Xmax13;
	msg.msg[4] = Ymin13;
	msg.msg[5] = Ymax13;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 13");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave13); // Envia parâmetros ao servo 13
	
	
	// ###### Inicialização da mensagem para o servo 14 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin14;
	msg.msg[3] = Xmax14;
	msg.msg[4] = Ymin14;
	msg.msg[5] = Ymax14;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 14");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave14); // Envia parâmetros ao servo 14
	
	// ###### Inicialização da mensagem para o servo 15 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin15;
	msg.msg[3] = Xmax15;
	msg.msg[4] = Ymin15;
	msg.msg[5] = Ymax15;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 15");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave15); // Envia parâmetros ao servo 15
	
	
	// ###### Inicialização da mensagem para o servo 2 ######
	msg.msg[0] = M;
	msg.msg[1] = N;
	msg.msg[2] = Xmin16;
	msg.msg[3] = Xmax16;
	msg.msg[4] = Ymin16;
	msg.msg[5] = Ymax16;
	msg.msg[6] = w;
	msg.msg[7] = c;

	for (i = 8; i < MSG_SIZE; i++){
		msg.msg[i] = 0;
	}
	
	Echo("Mensagem preparada para envio ao servo 16");
	for (i = 0; i < 8; i++){
		Echo(itoa(msg.msg[i]));
	}
	Send (&msg, pso_slave16); // Envia parâmetros ao servo 16
	
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
        
        // Recebe resultados do servo 3
	Receive (&msg, pso_slave3); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 3");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        // Recebe resultados do escravo 4
	Receive (&msg, pso_slave4); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 4");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        // Recebe resultados do servo 5
	Receive (&msg, pso_slave5); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 5");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        // Recebe resultados do escravo 6
	Receive (&msg, pso_slave6); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 6");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        // Recebe resultados do servo 7
	Receive (&msg, pso_slave7); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 7");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        // Recebe resultados do escravo 8
	Receive (&msg, pso_slave8); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 8");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        	// Recebe resultados do servo 9
	Receive (&msg, pso_slave9); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 9");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        // Recebe resultados do escravo 10
	Receive (&msg, pso_slave10); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 10");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        Echo("Fim do PSO: ");
        Echo(itoa(GetTick()));
        
        // Recebe resultados do servo 11
	Receive (&msg, pso_slave11); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 11");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        // Recebe resultados do escravo 12
	Receive (&msg, pso_slave12); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 12");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        // Recebe resultados do servo 13
	Receive (&msg, pso_slave13); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 13");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        // Recebe resultados do escravo 14
	Receive (&msg, pso_slave14); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 14");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        // Recebe resultados do servo 15
	Receive (&msg, pso_slave15); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 15");
        Echo("Melhor resultado da funcao: ");
        Echo(itoa(fmin));
        Echo("Melhor solucao: ");
        Echo("X1 = ");
        Echo(itoa(gbest[0]));
        Echo("X2 = ");
        Echo(itoa(gbest[1])); 
        
        // Recebe resultados do escravo 16
	Receive (&msg, pso_slave16); 
	fmin = msg.msg[0];
	gbest[0] = msg.msg[1];
	gbest[1] = msg.msg[2];
        
        //imprimindo resultados
        Echo("Resultados do servo 16");
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
