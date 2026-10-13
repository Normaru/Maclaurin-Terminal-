#include <stdio.h>

double fatorial(int num); //vai saber que tem um fatorial em baixo

int main(){

double e = 1;
int exp;
double pi = 3.141592653589793; //definindo pi
double graus;
int c;
double x;
double potencia;
int sinal;

printf("Digite o que deseja calcular!!\n");

printf("1 - e^x\n");
printf("2 - sin(x)\n");
printf("3 - cos(x)\n");
printf("Digite aqui:");
scanf("%d", &c);

switch(c){
case 3:{

printf("Digite os graus:\n");
scanf("%lf", &graus);
double x = graus*(pi/180.0);//é necessária essa conversão pois a série de maclaurin para funções trigonometricas precisa que o x seja em radianos, então isso é pra digitar em graus e ser convertido pra radianos

double cosx = 1; //é 1 porque a série começa exatamente em 1

double potencia = x*x; //é porque a série começa com x^2 

int sinal = -1; //faz a série começar negativa, já que o segundo termo da série é negativo

for (int i = 2; i <= 30; i += 2){ //repetição pra repetir tudo até menor ou igual a 30, aí minha precisão é de 30

cosx += sinal*(potencia/fatorial(i));
potencia *= (x*x); //vai garantir que a série só tenha expoentes pares
sinal *= -1; //garante que os sinais alternem entre positivo e negativo
}

printf("%f\n", cosx);
break;
}
case 2:{
printf("Digite os graus:\n");

scanf("%lf", &graus);

double x = graus*(pi/180.0); //é necessária essa conversão pois a série de maclaurin para funções trigonometricas precisa que o x seja em radianos, então isso é pra digitar em graus e ser convertido pra radianos

double sinx = 0; //a série de maclaurin pra sinx começa em zero, já que sin(0) = 0 e (0^0)/0! = 0
double potencia = x; //começa em x porque é o primeiro termo da série
int sinal = 1; 

for (int i = 1; i <= 30; i += 2){ //repetição pra repetir tudo até menor ou igual a 30, aí minha precisão é de 30
//o negócio é += 2 porque tem que virar um numero impar, pois a série de maclaurin pra sinx são com expoentes e fatoriais de números impares, como começa de i = 1 e vai pular de 2 em 2, então vai ficar impar

sinx += sinal*(potencia/fatorial(i)); //calcula os termos da série e vai acumulando os termos
potencia *= (x*x); //vai fazer o expoente ser impar, porque como já começa em x, aí vai pular de 2 em 2, e ficar impar também

sinal *= -1; //faz com que os termos alternem entre positivo e negativo, a série começa positiva, aí com isso o próximo vai ser negativo, depois positivo, e por aí vai
}

printf("%f\n", sinx);
break;
}
case 1:{
printf("Digite o expoente x que será elevado a euler\n");
scanf("%d", &exp);

double potencia = 1; //variavel para potencia, começa em 1 obviamente 

for (int i = 1; i <= 50; i++){ //repetição pra repetir tudo até menor ou igual a 30, aí minha precisão é de 30

potencia *= exp; //potencia = potencia * exp
e += potencia/fatorial(i);

}

printf("%f\n", e);
break;
}
default:
printf("Inválido!!!");
}
return 0;
}
//função que calcula fatorial 
double fatorial(int num){ //tem double porque o int não suporta muita coisa
double fat = 1; //começa em 1 porque qualquer multiplicação com 0 dá 0 né

for (int i = num; i >= 1; i--){ //i = num porque tem que receber o n! numero, e isso é um loop que faz uma regressão
//por causa do i--, que vai diminuindo o numero e multiplica pelo valor acumulado fat, basicamente vai funcionar
//como um fatorial normalmente funciona
fat *= i;
} 
return fat; //devolve pro fatorial
}

