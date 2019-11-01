#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
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

} TELEFONE;

typedef struct
{
        char dia[3];
        char mes[3];
        char ano[5];
} ANIVERSARIO;

typedef struct
{
        char nome[41];
        char eMail[41];
        ENDERECO endereco;
        TELEFONE telefone;
        ANIVERSARIO data;
        char observacao[101];
} PESSOA;

int pessoasInseridas = 0;
void arrumaAgenda (PESSOA agenda[]){
    int arrumado = 0, x = 0;
    PESSOA aux;
    while (arrumado == 0){
        arrumado = 1;
        for (int i = 1; i < pessoasInseridas - x; ++i){
            if (strcmp(agenda[i-1].nome, agenda[i].nome) > 0){
                aux = agenda[i-1];
                agenda[i-1] = agenda[i];
                agenda[i] = aux;
                arrumado = 0;
            }
        }
        x++;
    }
}

void inserePessoa (PESSOA agenda[]){ //insere pessoas em ordem alfabética 
    char c[20];
    printf("\nNome: ");
    gets(c);
    gets(agenda[pessoasInseridas].nome);
    printf("E-mail: ");
    gets(agenda[pessoasInseridas].eMail);
    printf("Rua: ");
    gets(agenda[pessoasInseridas].endereco.rua);
    printf("Número: ");
    scanf("%d", &agenda[pessoasInseridas].endereco.numero);
    printf("Complemento: ");
    gets(c);
    gets(agenda[pessoasInseridas].endereco.complemento);
    printf("Bairro: ");
    gets(agenda[pessoasInseridas].endereco.bairro);
    printf("CEP: ");
    gets(agenda[pessoasInseridas].endereco.cep);
    printf("Cidade: ");
    gets(agenda[pessoasInseridas].endereco.cidade);
    printf("Estado: ");
    gets(agenda[pessoasInseridas].endereco.estado);
    printf("País: ");
    gets(agenda[pessoasInseridas].endereco.pais);
    printf("DDD: ");
    gets(agenda[pessoasInseridas].telefone.ddd);
    printf("Telefone: ");
    gets(agenda[pessoasInseridas].telefone.numero);
    printf("Aniversário\n");
    printf("Dia: ");
    gets(agenda[pessoasInseridas].data.dia);
    printf("Mês: ");
    gets(agenda[pessoasInseridas].data.mes);
    printf("Ano: ");
    gets(agenda[pessoasInseridas].data.ano);
    printf("Observações: ");
    gets(agenda[pessoasInseridas].observacao);
    printf("\nPessoa Inserida com sucesso!\n\n");
    pessoasInseridas++;
}

void retiraPessoa (PESSOA agenda[]){ //retira pessoa: apaga os dados dessa pessoa
    char nome[41];
    printf("\nQual pessoa gostaria de retirar de sua agenda? Todos os dados dela serão apagados!");
    printf("Pessoa a ser removida: ");
    scanf("%s", nome);
    int i = 0;
    while (strncmp(agenda[i].nome, nome, strlen(nome)) != 0 && i < pessoasInseridas){
        i++;
    }
    if (i == pessoasInseridas){
        printf("\nNenhuma pessoa encontrada!\n\n");
        return;
    }
    for (; i < pessoasInseridas - 1; i++){
        agenda[i] = agenda[i+1];
    }
    printf("\nPessoa excluída com sucesso!\n\n");
    pessoasInseridas--;
}


void buscaNome (PESSOA agenda[]){ //busca pessoas através do nome 
    char nome[41];
    printf("\nInsira o nome desejado: ");
    char c[40];
    gets(c);
    gets(nome);
    for (int i = 0; i < pessoasInseridas; i++){
        if (strncmp(agenda[i].nome, nome, strlen(nome)) == 0){
            printf("\nNome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Número: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.complemento);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %s\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("País: %s\n", agenda[i].endereco.pais);
            printf("Telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("Observações: %s\n", agenda[i].observacao);
        }
    }
}

void buscaMes (PESSOA agenda[]){ //busca pessoas pelo mês de aniversário (d)
    char mes[3];
    printf("\nInsira o mês desejado: ");
    gets(mes);
	while (atoi(mes) < 1 || atoi(mes) > 12) { // Trata os dados de mes como inteiros e verifica se o valor de entrada e maior que 1 e menor que 12
		printf("insira um mês válido:\n");
		gets(mes);
    }
    for (int i = 0; i < pessoasInseridas; i++){
        if (strcmp(agenda[i].data.mes, mes) == 0){
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Numero: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.complemento);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %s\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("Pais: %s\n", agenda[i].endereco.pais);
            printf("Telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Aniversario: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("Observacoes: %s\n", agenda[i].observacao);
        }
    }
}

void buscaMeseDia (PESSOA agenda[]){ //busca pessoas pelo mês e dia de aniversário (e)
    char mes[3], dia[3];
    printf("\nInsira o mês desejado: ");
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
    for (int i = 0; i < 100; i++){
        if (strcmp(agenda[i].data.mes, mes) == 0 && strcmp(agenda[i].data.dia, dia) == 0){
            printf("\n\nNome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Número: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.complemento);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %s\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("País: %s\n", agenda[i].endereco.pais);
            printf("Telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("Observações: %s\n", agenda[i].observacao);
        }
        
    }
}

void imprimeAgenda (PESSOA agenda[]){ //Realiza o output dos dados de forma reduzida(nome ,e-mail e telefone) ou completa
    int modo;
    printf("\nDeseja a ver os dados de cada pessoa de modo resumido(nome ,e-mail e telefone) ou completo?\nOpções:\n1 - Resumido\n2 - Completo");
    printf("\n\nEscolho a opção: ");
    scanf("%d", &modo);
    while (modo != 1 && modo != 2){
        printf("\nOpção inválida! Digite um número de opção válido:\n");
        printf("Deseja a ver os dados de cada pessoa de modo resumido(nome ,e-mail e telefone) ou completo?\nOpções:\n1 - Resumido\n2 - Completo");
        printf("\n\nEscolho a opção: ");
        scanf("%d", &modo);
    }
    if (modo == 1){
        for (int i = 0; i < pessoasInseridas; i++){
            printf("\nNome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Telefone: (%s) %s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
        }
    }
    if (modo == 2){
        for (int i = 0; i < pessoasInseridas; i++){
            printf("\nNome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Número: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.complemento);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %s\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("País: %s\n", agenda[i].endereco.pais);
            printf("Telefone: (%s) %s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("Observações: %s\n", agenda[i].observacao);
        }
    }
}

int main (){
    int opc = 0;
    PESSOA agenda[100]; //declarar variável agenda 
    //menu principal oferecendo as várias opções possíveis
    while (opc != 7){
        printf("\n\nEscolha uma dentre as opções a seguir:\n");
        printf("1 - Inserir pessoa\n2 - Retirar pessoa\n3 - Buscar por nome\n4 - Buscar por mês do Aniversário\n5 - Buscar por mês e dia do Aniversário\n6 - Mostrar agenda\n7 - Sair\n");
        printf("\nEscolho a opção: ");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                inserePessoa(agenda);
                arrumaAgenda(agenda);
                break;
            case 2:
                retiraPessoa(agenda);
                break;
            case 3:
                buscaNome(agenda);
                break;
            case 4:
                buscaMes(agenda);
                break;
            case 5:
                buscaMeseDia(agenda);
                break;
            case 6:
                imprimeAgenda(agenda);
                break;
            case 7:
                return 0;
            default:
                printf("\nComando inválido!\n");
                break;
        }
        do{
            printf("\nDeseja continuar?\n1 - Sim\n2 - Não\n");
            printf("\nEscolho: ");
            scanf("%d", &opc);
            if (opc != 1 && opc != 2){
                printf("Comando inválido!\n");
            }else if (opc == 2){
                return 0;
            }
        }while (opc != 1 && opc != 2);
    }
    return 0;
}

