#include <api.h>
#include <stdlib.h>

#define N 1000   //tamanho da população
#define M 3     //dimensão de x

Message msg;

int main(){

    Receive(&msg,inicio);
    
    Echo("Melhor partícula: ");
    Echo(itoa(msg.msg[0])); Echo(itoa(msg.msg[1])); Echo(itoa(msg.msg[2]));
}
