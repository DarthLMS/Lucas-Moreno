#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char rua[31];
    int numero;
    char complemento[31];
    char bairro[31];
    char cep[9];
    char cidade[21];
    char estado[3];
    char pais[31];
} ENDERECO;

typedef struct 
{
	char ddd[3];
	char numero[10];
	
}TELEFONE;

typedef struct 
{
	char dia[3];
	char mes[3];
	char ano[5];
}ANIVERSARIO;

typedef struct 
{
	char nome[41];
	char eMail[21];
	ENDERECO endereco;
	TELEFONE telefone;
	ANIVERSARIO data;
	char observacao[101];
}PESSOA;

PESSOA agenda[100];//declarar variável agenda (b)

void Primeiro_Nome(char *nome); // So coloquei o prototipo mesmo

void buscaNome (PESSOA agenda[]) { //busca pessoas pelo nome (c)
	char nome[41];
	printf("insira o nome desejado:\n");
	gets(nome);
	
	for (int i = 0; i > 100; i++) {
		Primeiro_Nome(agenda[i].nome);
		if (strcmp(agenda[i].nome, nome) == 0) {  /*deve procurar só pelo primeiro nome, estou com dúvida sobre como fazer*/
			printf("nome: %s\n", agenda[i].nome);
			printf("eMail: %s\n", agenda[i].eMail);	
			printf("rua: %s\n", agenda[i].endereco.rua);	
			printf("numero: %d\n", agenda[i].endereco.numero);	
			printf("complemento: %s\n", agenda[i].endereco.complemento);	
			printf("bairro: %s\n", agenda[i].endereco.bairro);	
			printf("CEP: %s\n", agenda[i].endereco.cep);	
			printf("cidade: %s\n", agenda[i].endereco.cidade);	
			printf("estado: %s\n", agenda[i].endereco.estado);	
			printf("país: %s\n", agenda[i].endereco.pais);	
			printf("telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);	
			printf("aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);	
			printf("Observações: %s\n", agenda[i].observacao);	
		}
	}
}

void buscaMes (PESSOA agenda[]) { //busca pessoas pelo mes de aniversário (d)
	char mes[3];
	printf("insira o mes desejado:\n");
	gets(mes);
	while (atoi(mes) < 1 || atoi(mes) > 12) { // Trata os dados de mes como inteiros e verifica se o valor de entrada e maior que 1 e menor que 12
		printf("insira um mês válido:\n");
		gets(mes);
	}
	for (int i = 0; i > 100; i++) {
		if (strcmp(agenda[i].data.mes,mes) == 0) { // Caso o mes de um dos cadastrados é igual ao mes a procurar
			printf("nome: %s\n", agenda[i].nome);
			printf("eMail: %s\n", agenda[i].eMail);	
			printf("rua: %s\n", agenda[i].endereco.rua);	
			printf("numero: %d\n", agenda[i].endereco.numero);	
			printf("complemento: %s\n", agenda[i].endereco.complemento);	
			printf("bairro: %s\n", agenda[i].endereco.bairro);	
			printf("CEP: %s\n", agenda[i].endereco.cep);	
			printf("cidade: %s\n", agenda[i].endereco.cidade);	
			printf("estado: %s\n", agenda[i].endereco.estado);	
			printf("país: %s\n", agenda[i].endereco.pais);	
			printf("telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);	
			printf("aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);	
			printf("Observações: %s\n", agenda[i].observacao);	
		}
	}
}

void buscaMeseDia (PESSOA agenda[]) { //busca pessoas pelo mes e dia de aniversário (e)
	char mes[3], dia[3];
	printf("Insira o mes desejado: ");
	gets(mes);
	while (atoi(mes) < 1 || atoi(mes) > 12) { // Trata o input de dia como int e verifica se o mes é maior que 1 e menor que 31
		printf("insira um mês válido:\n");
		gets(mes);
	}
	printf("Insira o dia desejado: ");
	gets(dia);
	while (atoi(dia) < 1 || atoi(dia) > 31) { // Trata o input de dia como int e verifica se o dia é maior que 1 e menor que 31
		printf("insira um dia válido:\n");
		gets(dia);
	}
	for (int i = 0; i > 100; i++) {
		if (strcmp(agenda[i].data.mes, mes) == 0 && strcmp(agenda[i].data.dia,dia) == 0) { // Se a data de aniversario a procurar e igual a data de alguns cadastrados
			printf("nome: %s\n", agenda[i].nome);
			printf("eMail: %s\n", agenda[i].eMail);	
			printf("rua: %s\n", agenda[i].endereco.rua);	
			printf("numero: %d\n", agenda[i].endereco.numero);	
			printf("complemento: %s\n", agenda[i].endereco.complemento);	
			printf("bairro: %s\n", agenda[i].endereco.bairro);	
			printf("CEP: %s\n", agenda[i].endereco.cep);	
			printf("cidade: %s\n", agenda[i].endereco.cidade);	
			printf("estado: %s\n", agenda[i].endereco.estado);	
			printf("país: %s\n", agenda[i].endereco.pais);	
			printf("telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);	
			printf("aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);	
			printf("Observações: %s\n", agenda[i].observacao);	
		}
	}
}

void Primeiro_Nome(char *nome){ // Função que encontra o primeiro nome.
 /* Essa função pega um nome de input, vai rodando conforme o tamanho do nome(strlen). A função coloca os caracteres
 dentro de uma outra variavel, portanto que não tenha um espaço. Se tiver, o loop para e o primeiro nome é passado de volta
 por referência */
    char primeiro_nome[41]; /* Tem que ter o mesmo número de caracteres que o campo nome no strict, se não dá merda */
    for(int i = 0;i < strlen(nome);i++ ){ // Vai fazer iteração até o tamanho da string
        if(nome[i] != ' '){ // Se nao tiver espaços
            primeiro_nome[i] = nome[i]; // O caracter na posicao i é passado para primeiro_nome
        }
        else{ // se algum espaço for alcançado
            break; // PARA TUDO!!
        }
    }
    strcpy(nome,primeiro_nome); // Passa o valor da variavel temporaria(primeiro_nome) para a variavel de argumento por referencia
}

