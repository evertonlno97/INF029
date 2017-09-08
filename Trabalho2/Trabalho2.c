#include<stdio.h>
#include<stdlib.h>
#define TAM 10

struct posicao{
   
    int *ponteiro;
    int tam;
    int quant;
    
    
};

typedef struct posicao Posicao;

void iniciarVet(Posicao *vet);
int menu();
int inserir(Posicao *vet);
void listarEstruturas(Posicao *vet);
void listarOrdenar(Posicao *vet);
void criarEstrutura(Posicao *vet);
int realocar(Posicao *vet);


int main(){
    
    Posicao vet[TAM];
    iniciarVet(vet);

    int op;
    int sair = 0;
    int sms;
    
    while (!sair){
        op = menu();
        switch (op){
            case 0:
                
                sair =1;
                printf("\nPrograma Finalizado com sucesso\n\n");
                
                break;
            
            case 1: //Inserir elemento
        
                sms = inserir(vet);
               
                if(sms == 0){
                   
                   printf("\nOperacao realizada com sucesso\n\n");
                   
                }else if(sms == 1){
                   
                  printf("\nTamanho total invalido\n\n");
                   
                }else if(sms == 2){
                  
                   printf("\nNao foi possivel alocar o espaco indicado\n\n");
                   
                }else if(sms == 3){
                   
                   printf("\nO vetor auxiliar nao possui mais espaço para inserir valores\n\n");
                      
                }else if(sms == 4){
                   
                   printf("\nIndice informado e invalido\n\n");
                      
                }
                
                
                break;
            

            case 2: //Listar os numero de todas as estruturas
            
                listarEstruturas(vet);
                
                break;
                
            case 3: //Listar os elementos ordenados para cada estrutura auxiliar 
            
                listarOrdenar(Posicao *vet);
                break;
            
                
            case 4: //Cria uma estrutura com todos os elementos das estruturas auxiliares 
            
                criarEstrutura(vet);
                break;
                
                
            case 5: //Excluir um elemento 
            
             //TODO
             
                break;
                
            case 6: //Aumentar o tamanho de uma estrutura auxiliar 
            
                sms = realocar(vet);
                
                if(sms == 0){
                    
                    printf("A sua estrutura foi realocada com sucesso");
                         
                }else if(sms == 1){
                    
                    printf("Nao existe uma estrutura auxiliar nessa posicao\n");
                    
                }else if(sms == 2){
                    
                    printf("Nao foi possivel realocar a estrutura auxiliar\n");
                    
                }   
             
                break;
              
             
            default:
            	
                printf("Opcao inválida\n");
            
        }
         
    }
    
}


int menu(){
    int op;
    printf("\n----- Menu de Operacoes -----\n\n");
    printf("0 - Sair\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar todas as estruturas\n");
    printf("3 - Ordenar e listar todas as estruturas\n");
    printf("4 - Listar e ordenar uma estrutura com todos os elementos inseridos\n");
    printf("5 - Excluir elemento\n");
    printf("6 - Expandir o tamanho de uma estrutura auxiliar\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &op);
    return op;
}

void iniciarVet(Posicao *vet){
    
    int icont;
    
    for(icont = 0; icont < TAM; icont++){
     
        vet[icont].ponteiro = NULL;
        vet[icont].tam = 0;
        vet[icont].quant = 0;
        
    }    
    
}

int inserir(Posicao *vet){
    
    int id, elemento;
    int quantPos;
    
    printf("\nDigite o indice do vetor em que voce deseja criar uma estrutura auxiliar: ");
    scanf("%d", &id);

    if(id > 10 || id < 1){

	return 4;

     }

    id = id - 1;
    
    if( vet[id].tam == 0){
        
        printf("\nDigite o tamanho total da estrutura auxiliar: ");
        scanf("%d", &quantPos);
        
        if(quantPos > 0){
        
            vet[id].ponteiro = (int *)malloc(quantPos*sizeof(int));
            vet[id].tam = quantPos;   
            
        }else{
        
            return 1; 
           
        }    
    }
    
    if(vet[id].ponteiro != NULL){
    
        if (vet[id].quant < vet[id].tam){
            printf("\nDigite elemento a ser inserido na posicao %d: ", vet[id].quant + 1);
            scanf("%d", &elemento);
        
            vet[id].ponteiro[vet[id].quant] = elemento;
            vet[id].quant++;
           
            return 0;
    

        }else{
        
        return 3;
        
        }
    
     }else{
       
       return 2;
       
     } 
    
}

void listarEstruturas(Posicao *vet){
   
   int icont;
   int jcont;
   
   for(icont = 0; icont < TAM; icont++){
      
      if(!vet[icont].tam){
         
         printf("\nA posicao %d do vetor nao aponta para nunhuma estrutura auxiliar\n", icont + 1);
      
      }else{
         
         printf("\nEstrutura [%d] possui %d posicoes\n", icont + 1, vet[icont].tam);
         
         for(jcont = 0; jcont < vet[icont].quant; jcont++){
            
            printf("\nPosicao[%d]: %d\n", jcont + 1, vet[icont].ponteiro[jcont]);
              
         }
      }
      
   }    
   
}


void listarOrdenar(Posicao *vet){

	int icont, jcont, kcont, atual, aux, posm;

	for(icont = 0; icont < TAM; icont++){
	     for(jcont = 0; jcont < vet[icont].quant - 1 && vet[icont].quant > 0; jcont++){
		  
		  aux = vet[icont].ponteiro[jcont];
		  atual = vet[icont].ponteiro[jcont];
		  posm = jcont;

		  for(kcont = jcont + 1; kcont < vet[icont].quant && vet[icont].quant > 0; kcont++){

		       if(atual > vet[icont].ponteiro[kcont]){

			   posm = kcont;
			   atual = vet[icont].ponteiro[kcont];

			}

		  }

		  if(posm != jcont){

		      vet[icont].ponteiro[jcont] = vet[icont].ponteiro[posm];
		      vet[icont].ponteiro[posm] = aux;

		  }

	     }

	}

	for(icont = 0; icont < TAM; icont++){
      
      	     if(!vet[icont].tam){
         
                 printf("\nA posicao %d do vetor nao aponta para nunhuma estrutura auxiliar\n", icont + 1);
      
             }else{
         
                 printf("\nEstrutura [%d] possui %d posicoes\n", icont + 1, vet[icont].tam);

         
                 for(jcont = 0; jcont < vet[icont].quant; jcont++){
            
                      printf("\nPosicao[%d]: %d\n", jcont + 1, vet[icont].ponteiro[jcont]);
              
                 }

             }
      
         } 

}

void criarEstrutura(Posicao *vet){

	int totalQuant = 0, icont, jcont, kcont = 0, atual, aux, posm;

	for(icont = 0; icont < TAM; icont++){
	    if(vet[icont].quant > 0){

	       totalQuant = totalQuant + (vet[icont].quant - 1);

	     } 
	}

	int totalEstr[totalQuant];

	for(icont = 0; icont < TAM; icont++){

	    for(jcont = 0; jcont < vet[icont].quant; jcont++){

		totalEstr[kcont] = vet[icont].ponteiro[jcont];
		kcont++;
	    }
	}

	for(icont = 0; icont < kcont - 1; icont++){

	     aux = totalEstr[icont];
	     atual = totalEstr[icont];
	     posm = icont;
	     for(jcont = icont + 1; jcont < kcont; jcont++){

		  if(atual > totalEstr[jcont]){

		      posm = jcont;
		      atual = totalEstr[jcont];

		  }
	     }

		  if(posm!=icont){

		     totalEstr[icont] = totalEstr[posm];
		     totalEstr[posm] = aux;

		  }
        }

	printf("\nEstrutura com todos os elementos inseridos nas etruturas auxiliares:\n");

	for(icont = 0; icont < kcont; icont++){

	     printf("Posicao[%d] = %d\n", icont + 1, totalEstr[icont]);

	}

}


int realocar(Posicao *vet){
	
	int pos, tamanho, atual;
	
	printf("\nDigite a posicao do vetor em que você deseja realocar a estrutura auxiliar: ");
	scanf("%d", &pos);
	
	if(!vet[pos].tam){
		
		return 1;
		
	}else{
		
		printf("\nDigite a quantidade que você deseja aumentar: ");
		scanf("%d", &tamanho);
		
		vet[pos].ponteiro = (int *) realloc(vet[pos].ponteiro, (tamanho + vet[pos].tam) * sizeof(int));
		atual = tamanho + vet[pos].tam;
        
        if(vet[pos].ponteiro != NULL){
            
	    printf("\nTamanho atual da estrutura %d e %d posicoes\n", pos, atual);
            return 0;
            
        } else{   
		
        return 2;
        
        }
		
	}
		
	
}
