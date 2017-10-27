#include<stdio.h>
#include<stdlib.h>
#define TAM 10

struct posicao{
   
	int *ponteiro;
	int tam;
    	int quant;
    
    
};


typedef struct posicao Posicao;

void iniciarEstrutura(Posicao *vet);
int menu();
int inserir(Posicao *vet);
void listarEstruturas(Posicao *vet);
void listarOrdenar(Posicao *vet);
int OrdenarEstrutura(Posicao *vet);
int remover(Posicao *vet);
int realocar(Posicao *vet);
void liberarEstrutura(Posicao *vet);
int lerPosicao();
int verificaPos(Posicao *vet, int pos);
int alocaEstrutura(Posicao *vet, int pos);
int verificaAloc(Posicao *vet, int pos);
int inserirElem(Posicao *vet, int pos);
void printEstrutura(Posicao *vet);
void copiarEstrutura(Posicao *vetAux, Posicao *vet);
void selection(Posicao *vetAux);
int totalElementos(Posicao *vet);
int copiarElementos(int *totalEstr, Posicao *vet);
void ordenarEstrutura(int *totalEstr, int kcont);
void printEstrTotal(int *totalEstr, int kcont);
int buscaElemento(Posicao *vet, int pos, int *achei);
void deletarElemento(Posicao *vet, int pos, int achei, int prox);
void inserirArquivo(Posicao *vet);
void alocaImportArq(Posicao *vet, int pos, int tam);
void importArquivo(Posicao *vet);
void inserirArquivoBin(Posicao *vet);
void importArquivoBin(Posicao *vet);
int menuArquivo();
int abrirArquivo();
void limparTela();


int main(){
    
	Posicao vet[TAM];

    	iniciarEstrutura(vet);
	int op, opArq;
    	int sair = 0;

    	int sms;

	do{
	
		opArq = abrirArquivo();

		switch(opArq){

			case 1:

				importArquivo(vet);
				break;

			case 2:

				importArquivoBin(vet);
				break;

			case 3:

				break;

			default:

				printf("\nOperacao invalida");

		}
		
		limparTela();

	}while((opArq != 1) && (opArq != 2) && (opArq != 3));

	//importArquivoBin(vet);
    
    	while (!sair){

        	op = menu();
		//limparTela();

        	switch (op){

            		case 0:
				do{

					opArq = menuArquivo();

					switch(opArq){

						case 1:

							inserirArquivo(vet);
							break;

						case 2:

							inserirArquivoBin(vet);
							break;

						default:

							printf("\nOperacao invalida");

					}

				}while((opArq != 1) && (opArq != 2));
			
				liberarEstrutura(vet);
                		sair = 1;
                		printf("\nPrograma Finalizado com sucesso\n\n");
                		break;
            
            		case 1: //Inserir elemento
        
                		sms = inserir(vet);
               
                		if(sms == 0){
                   
                   			printf("\nOperacao realizada com sucesso\n");
                   
                		}else if(sms == 1){
                   
                  			printf("\nTamanho total da estrutura auxiliar invalido\n");
                   
                		}else if(sms == 2){
                  
                   			printf("\nNao foi possivel alocar o espaco indicado\n");
                   
                		}else if(sms == 3){
                   
                   			printf("\nA estrutura auxiliar nao possui mais espaco para inserir valores\n");
                      
                		}else if(sms == 4){
                   
                   			printf("\nPosicao informada e invalido\n");
                      
                		}
                  
                		break;
            

            		case 2: //Listar os numero de todas as estruturas
            
                		listarEstruturas(vet);
                		break;
                
            		case 3: //Listar os elementos ordenados para cada estrutura auxiliar 
            
                		listarOrdenar(vet);
                		break;
            
                
            		case 4: //Cria uma estrutura com todos os elementos das estruturas auxiliares 
            
                		sms = OrdenarEstrutura(vet);
				if(sms == 1){

					printf("\nAinda nao foi alocada nenhuma estrutura auxiliar\n");

				}

                		break;
                
                
            		case 5: //Excluir um elemento 
            
                		sms = remover(vet);
		
				if(sms == 0){

		   			printf("\nValor removido com sucesso\n");

				}else if(sms == 1){

		   			printf("\nEssa posicao do vetor nao aponta para uma estrura auxiliar\n");

				}else if(sms == 2){

		   			printf("\nValor nao encontrado\n");

				}else if(sms == 4){
                   
                   			printf("\nPosicao informada e invalido\n");
                      
                		}
           
                		break;
                
            		case 6: //Aumentar o tamanho de uma estrutura auxiliar 
            
                		sms = realocar(vet);
                
                		if(sms == 0){

                    			printf("\nA sua estrutura foi realocada com sucesso\n");
                         
                		}else if(sms == 1){
                   
                    			printf("\nNao existe uma estrutura auxiliar nessa posicao\n");
                    
                		}else if(sms == 2){
                    
                    			printf("\nNao foi possivel realocar a estrutura auxiliar\n");
                    
                		}else if(sms == 4){
                   
                   			printf("\nPosicao informada e invalido\n");
                      
                		}  

             
                		break;
              
             
		 	default:
            	
                		printf("\nOpcao invalida\n");
            
        	}
         
    	}
    
}


int menu(){

    	int op;
    	printf("\n\n----- Menu de Operacoes -----\n\n");
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

void iniciarEstrutura(Posicao *vet){
    
    	int icont;
    
    	for(icont = 0; icont < TAM; icont++){
     
        	vet[icont].ponteiro = NULL;
        	vet[icont].tam = 0;
        	vet[icont].quant = 0;
        
    	}    
    
}

int inserir(Posicao *vet){
    
    	int pos,quantPos = 0;

   
	pos = lerPosicao();
	
      	if(!pos){

	 	return 4;

      	}

	pos = pos - 1;
  
    	if(verificaPos(vet,pos)){

		quantPos = alocaEstrutura(vet,pos);
            
        	if(!quantPos){

            		return 1;    
        	}  
    	}
	
    
    	if(verificaAloc(vet,pos)){
		
		vet[pos].tam = 0;
       		return 2;
       
     	} 

	if(!inserirElem(vet,pos)){

    		return 0;

	}else{

		return 3;

	}
    
}

void listarEstruturas(Posicao *vet){
   
  	printEstrutura(vet);
   
}


void listarOrdenar(Posicao *vet){

	Posicao vetAux[TAM];

	iniciarEstrutura(vetAux);

	copiarEstrutura(vetAux,vet);

	selection(vetAux);

	printEstrutura(vetAux);

	liberarEstrutura(vetAux);
			

}

int OrdenarEstrutura(Posicao *vet){


	int totalQuant = 0, kcont = 0;

	totalQuant = totalElementos(vet);

	if(!totalQuant){

		return 1;

	}

	int totalEstr[totalQuant];

	kcont = copiarElementos(totalEstr, vet);

	ordenarEstrutura(totalEstr,kcont);
	
	printEstrTotal(totalEstr, kcont);


	return 0;
	
}

int remover(Posicao *vet){

	int achei, pos, prox;

	pos = lerPosicao();

	if(!pos){

	 	return 4;

      	}

	pos = pos - 1;

	if(verificaPos(vet,pos)){

	   	return 1;

	}

	prox = buscaElemento(vet,pos,&achei);

	if(!prox){

		return 2;

	}

	deletarElemento(vet, pos, achei, prox);

	return 0;


}

int realocar(Posicao *vet){
	
	int pos, tamanho, atual;
	
	pos = lerPosicao();
	
	if(!pos){

	 	return 4;

      	}

	pos = pos - 1;
	
	if(verificaPos(vet,pos)){
		
	    return 1;
		
	}else{
		
	  	printf("\nDigite o quanto voce deseja aumentar: ");
	  	scanf("%d", &tamanho);
		
	  	vet[pos].ponteiro = (int *) realloc(vet[pos].ponteiro, (tamanho + vet[pos].tam) * sizeof(int));
	  	vet[pos].tam = tamanho + vet[pos].tam;

        
          	if(!verificaAloc(vet,pos)){
            
             		return 0;
            
          	}else{   
		
            		return 2;
        
          	}
		
	}
			
}

void liberarEstrutura(Posicao *vet){

	int icont;

	for(icont = 0; icont < TAM; icont++){
		
		if(vet[icont].ponteiro != NULL){

			free(vet[icont].ponteiro);

		}

	}

}

int lerPosicao(){

	int pos;

	printf("\nDigite a posicao do vetor de estrutura: ");
      	scanf("%d", &pos);

      	if(((pos > 10) || (pos < 1)) || ((pos >= 'a') && (pos <= 'z')) || ((pos >= 'A') && (pos <= 'Z'))){


	 	return 0;

      	}

	return pos;


}

int verificaPos(Posicao *vet, int pos){

	if(!vet[pos].tam == 0){

		return 0;

	}else{

		return 1;

	}

}

int alocaEstrutura(Posicao *vet, int pos){

	int quantPos;

        printf("\nEssa posicao ainda nao aponta para uma estrutura\n");
        printf("\nDigite o tamanho total da estrutura auxiliar: ");
        scanf("%d", &quantPos);
        
        if((quantPos <= 0) || ((quantPos >= 'a') && (quantPos <= 'z')) || ((quantPos >= 'A') && (quantPos <= 'Z'))){
        
		return 0;
	   
        }else{
        
            	vet[pos].ponteiro = (int *)malloc(quantPos*sizeof(int));
		vet[pos].tam = quantPos;
            	return quantPos;
           
        } 

} 

int verificaAloc(Posicao *vet, int pos){

	if(vet[pos].ponteiro != NULL){

		return 0;

	}else{

		return 1;

	}

}

int inserirElem(Posicao *vet, int pos){

	int elemento;
  
	if (vet[pos].quant < vet[pos].tam){

            	printf("\nDigite elemento a ser inserido na posicao %d da estrutura auxiliar: ", vet[pos].quant + 1);
            	scanf("%d", &elemento);
        
         	vet[pos].ponteiro[vet[pos].quant] = elemento;
            	vet[pos].quant++;
           	return 0;
    
	}else{
        
           	return 1;
        
        }

}

void printEstrutura(Posicao *vet){

	int icont, jcont;

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

void copiarEstrutura(Posicao *vetAux, Posicao *vet){

	int icont, jcont;

	for(icont = 0; icont < TAM; icont++){
		
		if(vet[icont].tam){

			vetAux[icont].tam = vet[icont].tam;
			vetAux[icont].quant = vet[icont].quant;
			vetAux[icont].ponteiro = (int *) malloc(vetAux[icont].tam * sizeof(int));

		}

	}


	for(icont = 0; icont < TAM; icont++){
		if(vetAux[icont].ponteiro != NULL){
			for(jcont = 0; jcont < vetAux[icont].quant; jcont++){
				vetAux[icont].ponteiro[jcont] = vet[icont].ponteiro[jcont];
			}
		}
	}

}
		

void selection(Posicao *vet){

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

}

int totalElementos(Posicao *vet){

	int icont, totalQuant = 0;
	
	for(icont = 0; icont < TAM; icont++){

	       	totalQuant = totalQuant + vet[icont].quant;
	     	
	}

	if(!totalQuant){

		return 0;

	}

	return totalQuant;

}

int copiarElementos(int *totalEstr, Posicao *vet){

	int icont, jcont, aux = 0;

	for(icont = 0; icont < TAM; icont++){

	 	for(jcont = 0; jcont < vet[icont].quant; jcont++){

			totalEstr[aux] = vet[icont].ponteiro[jcont];
			aux++;
	    	}

	}

	return aux;

}

void ordenarEstrutura(int *totalEstr, int kcont){

	int posm, atual, aux, icont, jcont;

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

}

void printEstrTotal(int *totalEstr, int kcont){

	int icont;

	printf("\nEstrutura com todos os elementos inseridos nas etruturas auxiliares:\n");

	for(icont = 0; icont < kcont; icont++){

	     	printf("Posicao[%d] = %d\n", icont + 1, totalEstr[icont]);

	}
}

int buscaElemento(Posicao *vet, int pos, int *achei){

	int valor, icont, fim;

	printf("Digite o valor que voce deseja remover: ");
	scanf("%d", &valor);

	for(icont = 0, fim = 0; icont < vet[pos].quant && !fim; icont++){

	    	if(vet[pos].ponteiro[icont] == valor){

			*achei = icont;
	 		fim = 1;

	    	}

	}

	if(fim){

		return icont;

	}else{

		return 0;

	}

}

void deletarElemento(Posicao *vet, int pos, int achei, int prox){

	int jcont, kcont;

	for(jcont = achei, kcont = prox; kcont < vet[pos].quant; jcont++, kcont++){

	       	vet[pos].ponteiro[jcont] = vet[pos].ponteiro[kcont];

	  }

 	vet[pos].quant--;

}

void inserirArquivo(Posicao *vet){

	FILE *arq;
	int icont, jcont;
	char arquivo[] = "arquivo.txt";

	arq = fopen(arquivo, "w");

	if(arq == NULL){

		printf("Erro, nao foi possivel abrir o arquivo\n");

	}else{

		for(icont = 0; icont < TAM; icont++){
			if(vet[icont].tam){

				fprintf(arq, "%d\n", icont);
				fprintf(arq, "%d\n", vet[icont].tam);
				fprintf(arq, "%d\n", vet[icont].quant);

			}
			
			for(jcont = 0; jcont < vet[icont].quant; jcont++){

				fprintf(arq, "%d\n", vet[icont].ponteiro[jcont]);

				if(jcont == vet[icont].quant - 1){

					fprintf(arq, "\n");
				}
			}
		}

		fclose(arq);
	}

}


void importArquivo(Posicao *vet){

	FILE *arq;
	int icont, jcont, aux;
	char arquivo[] = "arquivo.txt";

	arq = fopen(arquivo, "r");

	if(arq == NULL){
		
		printf("Erro, nao foi possivel abrir o arquivo");

	}else{

		for(icont = 0; icont < TAM; icont++){
			fscanf(arq, "%d", &aux); 
			if(aux == icont){
				fscanf(arq, "\n%d\n", &vet[icont].tam);
				fscanf(arq, "%d\n", &vet[icont].quant);

				alocaImportArq(vet, icont, vet[icont].tam);
				
				for(jcont = 0; jcont < vet[icont].quant; jcont++){
					if(jcont != vet[icont].quant - 1){
						fscanf(arq, "%d\n", &vet[icont].ponteiro[jcont]);
					}else{
						fscanf(arq, "%d\n\n", &vet[icont].ponteiro[jcont]);
					}

				}
			}else{
				fseek(arq, -1 , SEEK_CUR);
			}
		}
	}

}


void alocaImportArq(Posicao *vet, int pos, int tam){
        
            	vet[pos].ponteiro = (int *)malloc(tam*sizeof(int));

} 

int menuArquivo(){

	int op;

	printf("\n\n--- Em que tipo de arquivo voce deseja salvar os seus dados ---");
	printf("\n1 - Arquivo texto");
	printf("\n2 - Arquivo Binario");
	printf("\nDigite o valor correspondente a operacao desejada: ");
	scanf("%d", &op);

	return op;

}

void inserirArquivoBin(Posicao *vet){

	FILE *arq;
	int icont, jcont;
	char arquivo[] = "arquivobin.txt";

	arq = fopen(arquivo, "wb");

	if(arq == NULL){

		printf("Erro, nao foi possivel abrir o arquivo\n");

	}else{

		for(icont = 0; icont < TAM; icont++){
			if(vet[icont].tam){

				fwrite(&icont, sizeof(int), 1, arq);
				fwrite(&vet[icont].tam, sizeof(int), 1, arq);
				fwrite(&vet[icont].quant, sizeof(int), 1, arq);

			}
			
			for(jcont = 0; jcont < vet[icont].quant; jcont++){

				fwrite(&vet[icont].ponteiro[jcont], sizeof(int), 1, arq);

				/*if(jcont == vet[icont].quant - 1){

					fprintf(arq, "\n");
				}*/
			}
		}

		fclose(arq);
	}

}


void importArquivoBin(Posicao *vet){

	FILE *arq;
	int icont, jcont, aux;
	char arquivo[] = "arquivobin.txt";

	arq = fopen(arquivo, "rb");

	if(arq == NULL){
		
		printf("Erro, nao foi possivel abrir o arquivo");

	}else{

		for(icont = 0; icont < TAM; icont++){
			fread(&aux, sizeof(int), 1, arq);
			if(aux == icont){
				fread(&vet[icont].tam, sizeof(int), 1, arq);
				fread(&vet[icont].quant, sizeof(int), 1, arq);

				alocaImportArq(vet, icont, vet[icont].tam);
				
				for(jcont = 0; jcont < vet[icont].quant; jcont++){
					fread(&vet[icont].ponteiro[jcont], sizeof(int), 1, arq);

				}
			}else{
				fseek(arq, -sizeof(int) , SEEK_CUR);
			}
		}
	}

}

int abrirArquivo(){

	int op;

	printf("\n\n--- Em que tipo de arquivo voce salvou os dados do seu programa ---");
	printf("\n1 - Arquivo texto");
	printf("\n2 - Arquivo Binario");
	printf("\n3 - Primeira execucao do programa");
	printf("\nDigite o valor correspondente a operacao desejada: ");
	scanf("%d", &op);

	return op;

}

void limparTela(){

	system("clear");

}








