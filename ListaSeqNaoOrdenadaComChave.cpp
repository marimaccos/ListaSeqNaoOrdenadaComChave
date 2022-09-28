#include <stdio.h>
#include <string.h>

struct listaSeq {
	int chave;
	char nome[20];
	float preco;
};

// Cria vetor com uma posição a mais 
// que sera usado no modulo Busca
struct listaSeq produtos[11]; 
int tamAtual = 0;	// Lista inicia com zero elementos
int tamMax = 10;	// Tamanho máximo da lista	

// Protótipos das funções
void Inclusao (int cod);
void Exclusao (int cod);
int Busca (int cod);
void Listagem ();
void Alteracao (int cod);

int main () {
	
	int opcao;
	int cod;
	
	do {	
		
		printf ("\n1 - Inclusao");
		printf ("\n2 - Exclusao");
		printf ("\n3 - Busca");
		printf ("\n4 - Listagem");
		printf ("\n5 - Alteracao");
		printf ("\n6 - Sair");		
		printf ("\nDigite a opcao: ");
		scanf ("%d", &opcao);
		
		switch (opcao) {
			
			case 1 : {
				
				if ( tamAtual == tamMax ) {
					printf ("\nInclusao falhou! Lista cheia.\n");
								
				} else {			
					printf ("\nDigite a chave para inclusao: ");
					scanf("%d", &cod);
					
					Inclusao(cod);
				}
				break;
			}
			
			case 2 : {
				
				if ( tamAtual == 0 ){
					printf ("\nExclusao falhou! Lista vazia.\n");
					
				} else {
					printf ("\nDigite a chave para exclusao: ");
					scanf("%d", &cod);
					
					Exclusao(cod);
				}
				break;
			}
			
			case 3 : {
				
				if ( tamAtual == 0 ){
					printf ("\nBusca falhou! Lista vazia.\n");
					
				} else {
					
					printf ("\nDigite a chave para busca: ");
					scanf("%d", &cod);
				
					int achou = Busca(cod);
				
					if ( achou < 0 ) {
						printf ("\nBusca falhou! Chave nao encontrada.\n");	
					
					} else {
						
						printf("\n%-8s %-6s %-21s %-4s", "Posicao", "Chave", "Nome", "Preco");
						printf("\n%-8s %-6s %-21s %-4s\n", "-------", "-----", "--------------------", "-----");
						
						printf ("%-9d", achou);
						printf ("%-7d", produtos[achou].chave);
						printf ("%-22s", produtos[achou].nome);
						printf ("%-4.2f\n", produtos[achou].preco);	
					}	
				}				
				break;
			}
			
			case 4 : {
			
				if ( tamAtual == 0 ) {
					printf ("\nListagem falhou! Lista vazia.\n");
			
				} else {
					Listagem();		
				}								
				break;
			}
			
			case 5 : {
				
				if ( tamAtual == 0 ) {
					printf ("\nAlteracao falhou! Lista vazia.\n");
				
				} else {
					
					printf ("\nDigite a chave para alteracao: ");
					scanf("%d", &cod);
					
					Alteracao(cod);		
				} 							
				break;
			}
			
			case 6 : {
				printf ("\nFim programa!\n");
				break;
			}
			
			default : {
				printf ("\nOpcao invalida!\n");
				break;
			}
		}		
							
	} while ( opcao != 6 );
}

void Inclusao (int cod) {
	
	if ( Busca(cod) >= 0 ) {
		printf ("\nInclusao falhou! Chave ja cadastrada.\n");
	
	} else {
		
		produtos[tamAtual].chave = cod;
		printf ("Digite o nome: ");
		// Captura input até que o enter seja pressionado
		// o espaço antes do %[^\n]s faz com que não seja pulado o scanf 
		scanf (" %[^\n]s", produtos[tamAtual].nome); 
		printf ("Digite o preco: ");
		scanf ("%f", &produtos[tamAtual].preco);
		
		tamAtual+=1;
	}	
}

void Exclusao (int cod) {
	
	if ( Busca(cod) < 0 ) {
		printf ("\nExclusao falhou! Chave nao encontrada.\n");
	
	} else {
		
		int i = Busca(cod);
		
		// Desloca os elementos para a esquerda para
		// preeencher o elemento excluído
		for (; i < tamAtual; i++) {
			
			produtos[i].chave = produtos[i+1].chave;
			strcpy( produtos[i].nome, produtos[i+1].nome );
			produtos[i].preco = produtos[i+1].preco;
		}
		tamAtual-=1;
	}	
}

int Busca (int cod) {	
	
	// Atribui o valor buscado ao primeiro nó vazio
	produtos[tamAtual].chave = cod; 
	
	int achou = -1;
	int i = 0;
	
	// Percorre a lista até achar a chave ou
	// até chegar no último nó
	while ( produtos[i].chave != cod ) {
		i++;
	}
	
	// É verdadeiro quando a lista está vazia ou 
	// quando o valor não está na lista
	if ( i == tamAtual ) {
		return achou;
	
	} else {	
		achou = i;
		return achou;
	}
}

void Listagem () {

	int i = 0;
	
	printf("\n%-8s %-6s %-21s %-4s", "Posicao", "Chave", "Nome", "Preco");
	printf("\n%-8s %-6s %-21s %-4s\n", "-------", "-----", "--------------------", "-----");
	
	// Imprime os elementos da lista
	for (; i < tamAtual; i++) {
		
		printf ("%-9d", i);
		printf ("%-7d", produtos[i].chave);
		printf ("%-22s", produtos[i].nome);
		printf ("%-4.2f\n", produtos[i].preco);			
	}	
}

void Alteracao (int cod) {
	
	if ( Busca(cod) < 0 ) {
		printf ("\nAlteracao falhou! Chave nao encontrada.\n");
	
	} else {
		
		int i = Busca(cod);
		
		printf ("Digite o novo nome: ");
		// Captura input até que o enter seja pressionado
		// o espaço antes do %[^\n]s faz com que não seja pulado o scanf 
		scanf (" %[^\n]s", &produtos[i].nome);
		printf ("Digite o novo preco: ");
		scanf ("%f", &produtos[i].preco);
	}	
}
