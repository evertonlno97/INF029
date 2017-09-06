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
                      
                }
                
                
                break;
            

            case 2: //Listar os numero de todas as estruturas
            
                listarEstruturas(vet);
                
                break;
                
            case 3: //Listar os elementos ordenados para cada estrutura auxiliar 
            
             //TODO
             
                break;
            
                
            case 4: //Cria uma estrutura com todos os elementos das estruturas auxiliares 
            
             //TODO
             
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
    printf("----- Menu de Operacoes -----\n\n");
    printf("0 - Sair\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar todas as estruturas\n");
    printf("3 - Ordenar e listar todas as estruturas\n");
    printf("3 - Criar uma estrutura com todos os elementos inseridos\n");
    printf("5 - Excluir elemento\n");
    printf("6 - Expandir o tamanho\n");
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

int realocar(Posicao *vet){
	
	int pos, tamanho;
	
	printf("\nDigite a posicao do vetor em que você deseja realocar a estrutura auxiliar: ");
	scanf("%d", &pos);
	
	if(!vet[pos].tam){
		
		return 1;
		
	}else{
		
		printf("\nDigite a quantidade que você deseja aumentar: ");
		scanf("%d", &tamanho);
		
		vet[pos].ponteiro = (int *) realloc(vet[pos].ponteiro, (tamanho + vet[pos].tam) * sizeof(int));
        
        if(vet[pos].ponteiro != NULL){
            
            return 0;
            
        } else{   
		
        return 2;
        
        }
		
	}
		
	
}
