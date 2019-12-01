#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct _Pessoa{
	char nome[25]; //Fazer isso com alocacao dinamica
	short int pontuacao;
}user;

void limpa_tabuleiro(char wTabuleiro[][7]);
int mostrar_menu(void);
void nova_partida();
void pega_nome_dos_users(user wUser[]);
void mostrar_tabuleiro(char wwTabuleiro[][7]);
void aloca_primeiras_pecas(char wwTabuleiro[][7]);
void desenvolve_jogo(char wwTabuleiro[][7]);
int valida_entrada(char jogadores[]);
void busca_trio(char wTab[][7]);
void regras();
void sobre_jogo();



//____________________________________________________________________________________________________________________________
int main(int argc, char const *argv[]){
	int escolha_menu;
	char tabuleiro[7][7];

	limpa_tabuleiro(tabuleiro);
	while(1){
		escolha_menu = mostrar_menu();
		switch(escolha_menu){
			case 1: nova_partida(tabuleiro); break;
			case 2: regras(); break;
			/*case 3: exibe_recordes(); break;*/
			case 4: sobre_jogo(); break;
			case 5: exit(1); break;
			default: system("clear");
                        printf("\n\tERRO: OPCAO INVÁLIDA!\n");
		}
              do{
            printf("\n\t[1] - VOLTAR\n\t[2] - SAIR\n");
            printf("\n\tO QUE DESEJA FAZER?  ");
            scanf("%d", &escolha_menu);
            if (escolha_menu != 1 && escolha_menu != 2){
                printf("\n\tERRO: OPCÃO INVÁLIDA!\n");
            }else if (escolha_menu == 2){
                return 0;
            }
        }while (escolha_menu != 1 && escolha_menu != 2);
    }
    return 0;
}

//___________________________________________________________________________________________________________________________

void regras(){

  system("clear"); 
  FILE *file;
  char regras[100];

  file = fopen("regras.txt","r");

  while(fgets(regras,100,file) != NULL)
       printf("%s",regras);

  fclose(file);
}

void sobre_jogo(){

  system("clear");  
  FILE *file;
  char jogo[100];

  file = fopen("jogo.txt","r");

  while(fgets(jogo,100,file) != NULL)
       printf("%s",jogo);

  fclose(file);
}
    


void limpa_tabuleiro(char wTabuleiro[][7]){
	short int i, j;

	for(i = 0; i < 7; i++){
		for(j = 0; j < 7; j++){
			wTabuleiro[i][j] = ' ';
		}
	}
	return;
}
int mostrar_menu(void){
	int opcao;

	system("clear");
	printf("\n--------------------- TRILHANDO O JOGO ---------------------\n\n\n");
	printf("\t[1] - NOVO JOGO\n");
	printf("\t[2] - INSTRUCOES\n");
	printf("\t[3] - RECORDES\n");
	printf("\t[4] - SOBRE O JOGO\n");
	printf("\t[5] - SAIR\n\n");
	printf("\tO QUE DESEJA FAZER?  ");
	scanf("%d", &opcao);

	return opcao;
}

//====================== NOVA PARTIDA =====================================================================
void nova_partida(char wTabuleiro[][7]){
	//user jogadores[2];
	
	//pega_nome_dos_users(jogadores);
	aloca_primeiras_pecas(wTabuleiro);
	desenvolve_jogo(wTabuleiro);
	return;
}
void pega_nome_dos_users(user wUser[]){
	system("clear");
	printf("\n_____________________ JOGADORES _____________________\n\n");
	printf("Nome do JOGADOR 1: ");
	gets(wUser[0].nome);
	getchar();
	printf("\nNome do JOGADOR 2: ");
	gets(wUser[1].nome);
	getchar();
	return;
}
void mostrar_tabuleiro(char wwTabuleiro[][7]){
	system("clear");
	printf("\n\n\n");
	printf("   \t   1          2          3             4             5          6          7\n\n\n\n");
	printf("   \t _____                               _____                               _____\n");
	printf("   \t|     |_____________________________|     |_____________________________|     |\n");
	printf(" 1 \t|  %c  |                             |  %c  |                             |  %c  |\n", wwTabuleiro[0][0], wwTabuleiro[0][3], wwTabuleiro[0][6]);
	printf("   \t|_____|                             |_____|                             |_____|\n");
	printf("   \t   |                                   |                                   |\n");
	printf("   \t   |        _____                    __|__                    _____        |\n");
	printf("   \t   |       |     |__________________|     |__________________|     |       |\n");
	printf(" 2 \t   |       |  %c  |                  |  %c  |                  |  %c  |       |\n", wwTabuleiro[1][1], wwTabuleiro[1][3], wwTabuleiro[1][5]);
	printf("   \t   |       |_____|                  |_____|                  |_____|       |\n");
	printf("   \t   |          |                        |                        |          |\n");
	printf("   \t   |          |        _____         __|__         _____        |          |\n");
	printf("   \t   |          |       |     |_______|     |_______|     |       |          |\n");
	printf(" 3 \t   |          |       |  %c  |       |  %c  |       |  %c  |       |          |\n", wwTabuleiro[2][2], wwTabuleiro[2][3], wwTabuleiro[2][4]);
	printf("   \t   |          |       |_____|       |_____|       |_____|       |          |\n");
	printf("   \t   |          |          |                           |          |          |\n");
	printf("   \t   |          |          |                           |          |          |\n");
	printf("   \t   |          |          |                           |          |          |\n");
	printf("   \t __|__      __|__      __|__                       __|__      __|__      __|__\n");
	printf("   \t|     |    |     |    |     |                     |     |    |     |    |     |\n");
	printf(" 4 \t|  %c  |----|  %c  |----|  %c  |                     |  %c  |----|  %c  |----|  %c  |\n", wwTabuleiro[3][0], wwTabuleiro[3][1], wwTabuleiro[3][2], wwTabuleiro[3][4], wwTabuleiro[3][5], wwTabuleiro[3][6]);
	printf("   \t|_____|    |_____|    |_____|                     |_____|    |_____|    |_____|\n");
	printf("   \t   |          |          |                           |          |          |\n");
	printf("   \t   |          |          |                           |          |          |\n");
	printf("   \t   |          |          |                           |          |          |\n");
	printf("   \t   |          |        __|__         _____         __|__        |          |\n");
	printf("   \t   |          |       |     |       |     |       |     |       |          |\n");
	printf(" 5 \t   |          |       |  %c  |_______|  %c  |_______|  %c  |       |          |\n", wwTabuleiro[4][2], wwTabuleiro[4][3], wwTabuleiro[4][4]);
	printf("   \t   |          |       |_____|       |_____|       |_____|       |          |\n");
	printf("   \t   |          |                        |                        |          |\n");
	printf("   \t   |        __|__                    __|__                    __|__        |\n");
	printf("   \t   |       |     |                  |     |                  |     |       |\n");
	printf(" 6 \t   |       |  %c  |__________________|  %c  |__________________|  %c  |       |\n", wwTabuleiro[5][1], wwTabuleiro[5][3], wwTabuleiro[5][5]);
	printf("   \t   |       |_____|                  |_____|                  |_____|       |\n");
	printf("   \t   |                                   |                                   |\n");
	printf("   \t __|__                               __|__                               __|__\n");
	printf("   \t|     |                             |     |                             |     |\n");
	printf(" 7 \t|  %c  |_____________________________|  %c  |_____________________________|  %c  |\n", wwTabuleiro[6][0], wwTabuleiro[6][3], wwTabuleiro[6][6]);
	printf("   \t|_____|                             |_____|                             |_____|\n");
	return;
}



void aloca_primeiras_pecas(char wwTabuleiro[][7]){
	short int i, posicao_ocupada = 0;
	char jog_users[3];

	for(i = 0; i < 18; i++){
		mostrar_tabuleiro(wwTabuleiro);


		busca_trio(wwTabuleiro);


		
		if(posicao_ocupada == 1){
			printf("\nPOSICAO OCUPADA! ESCOLHA OUTRA!\n");
			posicao_ocupada = 0;
		}
		while(1){
			printf("\n\nJOGADOR %d\n\nEscolha a posicao: ", ((i%2)+1));
			scanf("%s", jog_users);
			getchar();
			if(valida_entrada(jog_users) != 3)
				printf("ERRO: DIGITE DOIS NUMEROS!");
			else
				break;
		}
		if(wwTabuleiro[((int)jog_users[0])-49][((int)jog_users[1]) - 49] == ' '){
			if(i % 2 == 0)
				wwTabuleiro[((int)jog_users[0])-49][((int)jog_users[1])-49] = 'X';
			else
				wwTabuleiro[((int)jog_users[0])-49][((int)jog_users[1])-49] = 'O';
		}
		else{
			posicao_ocupada = 1;
			i = i - 1;
		}
	}
	return;
}



void desenvolve_jogo(char wwTabuleiro[][7]){
	//short int final = 0;
	short int i = 0, posicao_ocupada = 0;
	char jog_origem[3], jog_destino[3];

	while(i > -1){
		mostrar_tabuleiro(wwTabuleiro);


		if(posicao_ocupada == 1){
			printf("\nPOSICAO DE DESTINO OCUPADA! ESCOLHA NOVAMENTE!\n");
			posicao_ocupada = 0;
		}
		else{
			if(posicao_ocupada == 2){
				printf("\nPOSICAO DE ORIGEM VAZIA! ESCOLHA NOVAMENTE!\n");
				posicao_ocupada = 0;
			}
		}




		while(1){
			printf("\n\nJOGADOR %d\n\nEscolha a Origem: ", ((i%2)+1));
			scanf("%s", jog_origem);
			getchar();
			if(valida_entrada(jog_origem) != 3)
				printf("ERRO: DIGITE DOIS NUMEROS!");
			else
				break;
		}
		while(1){
			printf("\n\nJOGADOR %d\n\nEscolha o Destino: ", ((i%2)+1));
			scanf("%s", jog_destino);
			getchar();
			if(valida_entrada(jog_destino) != 3)
				printf("ERRO: DIGITE DOIS NUMEROS!");
			else
				break;
		}





		if(wwTabuleiro[((int)jog_destino[0])-49][((int)jog_destino[1]) - 49] == ' '){
			if(wwTabuleiro[((int)jog_origem[0])-49][((int)jog_origem[1]) - 49] != ' '){
				wwTabuleiro[((int)jog_origem[0])-49][((int)jog_origem[1])-49] = ' ';
				if(i % 2 == 0)
					wwTabuleiro[((int)jog_destino[0])-49][((int)jog_destino[1])-49] = 'X';
				else
					wwTabuleiro[((int)jog_destino[0])-49][((int)jog_destino[1])-49] = 'O';
				i = i + 1;
			}
			else
				posicao_ocupada = 2;
		}
		else
			posicao_ocupada = 1;





		
	}
	return;
}
//====================== END NOVA PARTIDA =================================================================

int valida_entrada(char jogadores[]){
	int i, cont_valid = 0;

	if(strlen(jogadores) == 2)
		cont_valid = cont_valid + 1;
	for(i = 0; i < 2; i++)
		if(isdigit((int)jogadores[i]) != 0)
			cont_valid = cont_valid + 1;
	return cont_valid;
}










//Ta muito ruin. tem erro na diagonal.



void busca_trio(char wTab[][7]){
	int i, n = 3;	
	int linha_trilha;
	
	//ESSA FUNCIONA PARA A PRIMEIRA LINHA
	for(i = 0; i < 7; i++){ 
		if((wTab[i][i] == wTab[i][i+n]) && (wTab[i][i+n] == wTab[i][i+n+n]) && (wTab[i][i] != ' ')){
			linha_trilha = i;
			printf("\nA linha %d eh uma trilha de %c !\n", linha_trilha+1, wTab[i][i]);
                        
		}
		else{
			n = n - 1;
		}
	}

	//ESSA FUNCIONA PARA A PRIMEIRA COLUNA
	n = 3;
	for(i = 0; i < 7; i++){ 
		if((wTab[i][i] == wTab[i+n][i]) && (wTab[i+n][i] == wTab[i+n+n][i]) && (wTab[i][i] != ' ')){
			linha_trilha = i;
			printf("\nA coluna %d eh uma trilha de %c !\n", linha_trilha+1, wTab[i][i]);
                        
		}
		else{
			n = n - 1;
		}
	}

	if(wTab[0][3] != ' '){
		if(((wTab[0][3]) == (wTab[1][3])) && ((wTab[0][3]) == (wTab[2][3]))){
			printf("\nA coluna 4 tem uma trilha de %c !\n", wTab[0][3]);
                        
		}
	}
	if(wTab[4][3] != ' '){
		if(((wTab[4][3]) == (wTab[5][3])) && ((wTab[4][3]) == (wTab[6][3]))){
			printf("\nA coluna 4 tem uma trilha de %c !\n", wTab[4][3]);
                        
		}
	}

	if(wTab[3][0] != ' '){
		if(((wTab[3][0]) == (wTab[3][1])) && ((wTab[3][0]) == (wTab[3][2]))){
			printf("\nA linha 4 tem uma trilha de %c !\n", wTab[3][0]);
                       
		}
	}
	if(wTab[3][4] != ' '){
		if(((wTab[3][4]) == (wTab[3][5])) && ((wTab[3][4]) == (wTab[3][6]))){
			printf("\nA linha 4 tem uma trilha de %c !\n", wTab[3][4]);
                       
		}
	}
	return;
}





		else{
			posicao_ocupada = 1;
			i = i - 1;
		}
	}
	return;
}
