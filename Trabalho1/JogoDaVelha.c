
#include <stdio.h>
#include<stdlib.h>
#define SPACE 32
#define TAM 3

char matriz[TAM][TAM];

char verficaVercedor(void);
void iniciaMatriz(void);
int obtJogada(int jogada);
void printMatriz(void);

int main(void) {
	// your code goes here
	system("color 70");
	
	char velha;
	int jogada = 0;
	
	velha = SPACE;
	
	iniciaMatriz();
	
	do{
	    
	    printMatriz();
	    
	    jogada++;
	    
	    obtJogada(jogada);
	    
	    velha = verficaVercedor();
	    
	    if(velha != SPACE){
	       break;
	    }
	    
	}while(velha == SPACE);
	
	printMatriz();
	
	if(velha == 'X'){
	    
	    printf("\n\nO vencedor foi o Jogador 1!\n\n");
	    
	} else{
	    
	   printf("\n\nO vencedor foi o Jogador 2!\n\n"); 
	    
	}
	
	return 0;
}

void iniciaMatriz(void){
    
    int icont, jcont;
    
    for(icont = 0; icont < TAM; icont++)
        for(jcont = 0; jcont < TAM; jcont++)
            matriz[icont][jcont] = SPACE;
    
}

int obtJogada(int jogada){
    
    int x,y;
    
     if(jogada % 2 != 0){
        
        	printf("\n\nJogador 1 -> X\n");
        
    	} else{
        
        	printf("\n\nJogador 2 -> 0\n");
        
    	}
    	
    printf("Digite as coordenadas da sua jogada:\n");
    printf("Linha: ");
    scanf("%d", &x);
    printf("Coluna: ");
    scanf("%d", &y);
    printf("\n");
    
    
    if(matriz[x][y] != SPACE || (x > 2) || (y > 2)){
        
        printf("Posicao invalida, digite novamente. \n\n");
        printMatriz();
        obtJogada(jogada);
        
    }
    
    else{
        
        if(jogada % 2 != 0){
        
        	matriz[x][y] = 'X';
        
    	} else{
        
        	matriz[x][y] = '0';
        
    	}
        
        
    }
    
}

void printMatriz(void){
    
    int icont;
    
    	printf("  0   1   2\n");
    
    for(icont = 0; icont < TAM; icont++){
    	
    	
        if(icont == 0){
            
            printf("0 %c | %c | %c ", matriz[icont][0], matriz[icont][1], matriz[icont][2]);
            
        }
        
        if(icont == 1){
            
            printf("1 %c | %c | %c ", matriz[icont][0], matriz[icont][1], matriz[icont][2]);
            
        }
        
        if(icont == 2){
            
            printf("2 %c | %c | %c ", matriz[icont][0], matriz[icont][1], matriz[icont][2]);
            
        }
        
        if(icont != 2){
            
            printf("\n ---|---|---\n");
            
        }
        
        //printf("\n");
        
    }
    
}

char verficaVercedor(void){
    
    int i, j, t;
    
    for(i = 0; i < TAM; i++){
        
        if(matriz[i][0] == matriz[i][1] && (matriz[i][0] == matriz[i][2])){
            
            return matriz[i][0];
            
        }
        
    }
    
     for(i = 0; i < TAM; i++){
        
        if(matriz[0][i] == matriz[1][i] && (matriz[0][i] == matriz[2][i])){
            
            return matriz[0][i];
            
        }
        
    }
    
    if(matriz[0][0] == matriz[1][1] && (matriz[1][1] == matriz[2][2])){
        
        return matriz[0][0];
        
    }
    
     if(matriz[0][2] == matriz[1][1] && (matriz[1][1] == matriz[2][0])){
        
        return matriz[0][2];
        
    }
    
    for(j = 0; j < TAM; j++){
        for(t = 0; t < TAM; t++){
            
            if(matriz[j][t] == SPACE){
                
                return SPACE;
            }
            
            
        }
        
    }
    
    if(j * t == 9){
    	
    	 printMatriz();
        
        printf("\n\nO jogo terminou empatado!\n\n");
        
        exit(0);
        
    }
    
    return SPACE;
    
}

