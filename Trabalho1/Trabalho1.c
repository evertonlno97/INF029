
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BARRA 47


/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){
    
    //printf("%s\n", data);
    
    char data_dia[3], data_mes[3], data_ano[5];
	int dia, mes, ano, valida, icont, jcont, econt, j, e;
	
	for(icont=0; *(data + icont)!=BARRA; icont++){
    
	    //strcpy(data_dia[icont], data[icont]);
	    data_dia[icont] = *(data + icont);
	 
	}

	data_dia[icont] = '\0';
	
	for(jcont=icont+1, j=0; *(data + jcont)!=BARRA; jcont++, j++){
	    
	    data_mes[j] = *(data + jcont); 
	    
	}

	data_mes[j] = '\0';
	
	for(econt=jcont+1, e=0; *(data + econt)!='\0'; econt++, e++){
	    
	    data_ano[e] = *(data + econt);
	    
	}

	data_ano[e] = '\0';
	
	dia = atoi(data_dia);
	mes = atoi(data_mes);
	ano = atoi(data_ano);
	
	if((mes >= 1 && mes <= 12) && (dia >= 1 && dia <= 31)){
	
        switch(mes){
        
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
        
                if(dia>=1 && dia<=31){
            
                    valida = 1;
            
                } else{
            
                    valida = 0;
            
                }

		break;
        
            case 2:
        
                 if((ano % 4 == 0) && (ano % 400 == 0 || ano % 100 != 0)){
                    if(dia >= 1 && dia <= 29){
                    
                         valida = 1;
                    
                    }
                
                } else if(dia >= 1 && dia <= 28){
                
                        valida = 1;
                
                } else{
                
                    valida = 0;   
                
                }

		break;
                
            default:
                if(dia >= 1 && dia <= 30){
                    
                    valida = 1;
                    
                    
                }else{
                    
                    valida = 0;
                    
                }

		break;
        
        }
        
	} else {
	    
	    valida = 0;
	    
	}


       if (valida)
           return 1;
       else
           return 0;
    
}

int valida_data (char *data, int *diap, int *mesp, int *anop){

	char data_dia[3], data_mes[3], data_ano[5];
	int dia, mes, ano, valida, icont, jcont, econt, j, e;
	
	for(icont=0; *(data + icont)!=BARRA; icont++){
    
	    //strcpy(data_dia[icont], data[icont]);
	    data_dia[icont] = *(data + icont);
	 
	}

	data_dia[icont] = '\0';
	
	for(jcont=icont+1, j=0; *(data + jcont)!=BARRA; jcont++, j++){
	    
	    data_mes[j] = *(data + jcont); 
	    
	}

	data_mes[j] = '\0';
	
	for(econt=jcont+1, e=0; *(data + econt)!='\0'; econt++, e++){
	    
	    data_ano[e] = *(data + econt);
	    
	}

	data_ano[e] = '\0';
	
	dia = atoi(data_dia);
	mes = atoi(data_mes);
	ano = atoi(data_ano);
    
    	*diap = atoi(data_dia);
	*mesp = atoi(data_mes);
	*anop = atoi(data_ano);
	
	if((mes >= 1 && mes <= 12) && (dia >= 1 && dia <= 31)){
	
        switch(mes){
        
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
        
                if(dia>=1 && dia<=31){
            
                    valida = 1;
            
                } else{
            
                    valida = 0;
            
                }

		break;
        
            case 2:
        
                 if((ano % 4 == 0) && (ano % 400 == 0 || ano % 100 != 0)){
                    if(dia >= 1 && dia <= 29){
                    
                         valida = 1;
                    
                    }
                
                } else if(dia >= 1 && dia <= 28){
                
                        valida = 1;
                
                } else{
                
                    valida = 0;   
                
                }

		break;
                
            default:
                if(dia >= 1 && dia <= 30){
                    
                    valida = 1;
                    
                    
                }else{
                    
                    valida = 0;
                    
                }

		break;
        
        }
        
	} else {
	    
	    valida = 0;
	    
	}

	
       if (valida)
           return 1;
       else
           return 0;

}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial < datafinal
 */

int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){

	int validaInicial, validaFinal, diainicial, diafinal, mesinicial, mesfinal, anoinicial, anofinal;

	validaInicial = valida_data(datainicial, &diainicial, &mesinicial, &anoinicial);
	
	if(validaInicial == 0){

	   return 2;

	}

	validaFinal = valida_data(datafinal, &diafinal, &mesfinal, &anofinal);

	
	if(validaFinal == 0){

	   return 3;

	}

	if(anoinicial > anofinal){

	   return 4;

	}else if(anoinicial == anofinal && (mesinicial > mesfinal) && (diainicial > diafinal)){

	         return 4;

	}else if(anoinicial == anofinal && (mesinicial == mesfinal) && (diainicial > diafinal)){

	         return 4;

	}else if(anoinicial == anofinal && (mesinicial > mesfinal) && (diainicial == diafinal)){

	         return 4;

	}

	if(anoinicial < anofinal && (mesinicial < mesfinal) && (diainicial < diafinal)){

	       *qtdDias = diafinal - diainicial;
    	       *qtdAnos = anofinal - anoinicial;
    	       *qtdMeses = mesfinal - mesinicial;

	}else if(anoinicial < anofinal && (mesinicial < mesfinal) && (diainicial == diafinal)){

           *qtdDias = diafinal - diainicial;
    	   *qtdAnos = anofinal - anoinicial;
    	   *qtdMeses = mesfinal - mesinicial;

	}else if(anoinicial < anofinal && (mesinicial == mesfinal) && (diainicial < diafinal)){

		   *qtdDias = diafinal - diainicial;
    	   	   *qtdAnos = anofinal - anoinicial;
    	   	   *qtdMeses = mesfinal - mesinicial;

	}else if(anoinicial == anofinal && (mesinicial < mesfinal) && (diainicial < diafinal)){

           	*qtdDias = diafinal - diainicial;
    	   	*qtdAnos = anofinal - anoinicial;
    	   	*qtdMeses = mesfinal - mesinicial;

	}else if(anoinicial < anofinal && (mesinicial == mesfinal) && (diainicial == diafinal)){

		*qtdDias = diafinal - diainicial;
    	   	*qtdAnos = anofinal - anoinicial;
    	   	*qtdMeses = mesfinal - mesinicial; 
        
	}else if(anoinicial == anofinal && (mesinicial < mesfinal) && (diainicial == diafinal)){

		*qtdDias = diafinal - diainicial;
    	   	*qtdAnos = anofinal - anoinicial;
    	   	*qtdMeses = mesfinal - mesinicial;

	}else if(anoinicial == anofinal && (mesinicial == mesfinal) && (diainicial < diafinal)){

		*qtdDias = diafinal - diainicial;
    	   	*qtdAnos = anofinal - anoinicial;
    	   	*qtdMeses = mesfinal - mesinicial;

	}else if(anoinicial < anofinal && (mesinicial > mesfinal) && (diainicial == diafinal)){

		*qtdMeses = (12 - mesinicial) + mesfinal;
         	*qtdAnos = 0;
         	*qtdDias = anofinal - anoinicial - 1;

	}else if(anoinicial < anofinal && (mesinicial == mesfinal) && (diainicial > diafinal)){
        
            *qtdMeses = 11;
	    *qtdAnos = anofinal - anoinicial - 1;
        
           switch(mesinicial){
               
                 case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
        
                *qtdDias = (31 - diainicial) + diafinal;
            
            break;
        
            case 2:
        
                if((anoinicial % 4 == 0) && (anoinicial % 400 == 0 || anoinicial % 100 != 0)){
                    
                    *qtdDias = (29 - diainicial) + diafinal;
                
                } else{
                
                        *qtdDias = (28 - diainicial) + diafinal;
                
                }
                
            break;
                
            default:
                
                *qtdDias = (30 - diainicial) + diafinal;
               

            break;
        
        }
        
	   
        
    }else if(anoinicial < anofinal && (mesinicial > mesfinal) && (diainicial > diafinal)){
        
            *qtdMeses = (12 - mesinicial) + mesfinal - 1;
            *qtdDias = anofinal - anoinicial - 1;
        
            switch(mesinicial){
               
                 case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
        
                *qtdDias = (31 - diainicial) + diafinal;
            
            break;
        
            case 2:
        
                if((anoinicial % 4 == 0) && (anoinicial % 400 == 0 || anoinicial % 100 != 0)){
                    
                    *qtdDias = (29 - diainicial) + diafinal;
                
                } else{
                
                        *qtdDias = (28 - diainicial) + diafinal;
                
                }
                
            break;
                
            default:
                
                *qtdDias = (30 - diainicial) + diafinal;
               

            break;
        
        }
        
        
    }

    
    return 1;
    
}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferências entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferências entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0. 
 */
int q3(char *texto, char caracter, int caseSensitive){

	int icont, rep = 0;
        char str[250];

        strcpy(str, texto);
	
	if(caseSensitive == 1){
	   for(icont=0; str[icont] != '\0'; icont++){
	       
	       if(str[icont] == caracter){

	        rep++; 
	        
	       }
	  }
	  
	}else{
	    if(caracter>='a' && caracter<='z'){
	        
	        for(icont=0; str[icont]!='\0'; icont++){
	            
	            if(str[icont]>='A' && str[icont]<='Z'){
	                
	               str[icont] = str[icont] - 'A' + 'a'; 
	               
	            }
	            
	            if(str[icont]==caracter){
	                
	                rep++;
	                
	            }
	        }
	    }
	    
	    if(caracter>='A' && caracter<='Z'){
	        
	         for(icont=0; str[icont]!='\0'; icont++){
	             if(str[icont]>='a' && str[icont]<='z'){
	            
	                str[icont] = str[icont] - 'a' + 'A'; 
	
	             }	
	             
	            if(str[icont]==caracter){
	                
	                rep++;
	                
	            }
	        }
	        
	    }
	    
	}

	
	
    return rep;
    
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){

	int icont, jcont, kcont, tamBusca, tamTexto, volta, achou, bcont = 0, qtdOcorrencias = 0;

	tamTexto = strlen(strTexto);
	tamBusca = strlen(strBusca);
	
	for(icont = 0; icont < tamTexto; icont++){
	    
	    if(strTexto[icont] == strBusca[0]){

	        achou = icont + 1;
	        
	        for(jcont = 1, kcont = icont + 1, volta = 1; (jcont < tamBusca && volta); kcont++, jcont++){
	            
	            if(strTexto[kcont] == strBusca[jcont]) {
	                
	               if(jcont == tamBusca - 1){
	                 
	                 posicoes[bcont] = achou;
	                 bcont++;
	                 posicoes[bcont] = kcont + 1;
	                 bcont++;
	                 
	                 qtdOcorrencias++;
	                 
	             }
	                
	            }else{
	                
	                 volta = 0;
	            }
	            
	        }
	        
	    }
	    
	}
	
    
    return qtdOcorrencias;
    
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){

	int centmilhar, decmilhar,milhar, centena, dezena, unidade, inverte;
	
	
	if(num >= 100000 && num <= 999999){

	    centmilhar = (num / 100000);
	    decmilhar = ((num % 100000) / 10000) * 10;
	    milhar = (((num % 100000) % 10000) / 1000) * 100;
	    centena = ((((num % 100000) % 10000) % 1000) / 100) * 1000;
	    dezena = (((((num % 100000) % 10000) % 1000) % 100) / 10) * 10000;
	    unidade = (((((num % 100000) % 10000) % 1000) % 100) % 10) * 100000;
	    
	    inverte = centmilhar + decmilhar + milhar + centena + dezena + unidade;

	}

	if(num >= 10000 && num <= 99999){

	    decmilhar = (num / 10000);
	    milhar = ((num % 10000) / 1000) * 10;
	    centena = (((num % 10000) % 1000) / 100) * 100;
	    dezena = ((((num % 10000) % 1000) % 100) / 10) * 1000;
	    unidade = ((((num % 10000) % 1000) % 100) % 10) * 10000;
	    
	    inverte = decmilhar + milhar + centena + dezena + unidade;

	}
	
	if(num >= 1000 && num <= 9999){
	
	    milhar = (num / 1000);
	    centena = ((num % 1000) / 100) * 10;
	    dezena = (((num % 1000) % 100) / 10) * 100;
	    unidade = (((num % 1000) % 100) % 10) * 1000;

	    inverte = milhar + centena + dezena + unidade;
	
	}else if(num >= 100 && num <= 999){
	    
	    	centena = (num / 100);
	    	dezena = ((num % 100) / 10) * 10;
	    	unidade = ((num % 100) % 10) * 100;

	    	inverte = centena + dezena + unidade;
	    
	}else if(num >= 10 && num <= 99){
	    
	    	dezena = (num / 10);
	    	unidade = (num % 10) * 10;

	    	inverte = dezena + unidade;
	    
	} else if(num >= 0 && num <= 9){

		inverte = num;

	}


    return inverte;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){

	int qtdOcorrencias=0, aux, aux1, div=1, kcont=0, busca=0, base=0, numbase[10], numbusca[10], icont, jcont, volta;


	aux = numerobase;

	while(aux>0){
    	     aux = aux/10;
             base++;
	}

	aux = numerobusca;
	aux1 = numerobusca;

	while(aux>0){
    	     aux = aux/10;
    	     busca++;
	}

	aux = base;

	while(aux>1){
    	     div = div*10;
    	     aux--;

	}

	for(aux=0; aux < base; aux++){
     	   kcont = numerobase/div;
    	   numbase[aux] = kcont;
    	   numerobase = numerobase-(kcont*div);
    	   div = div/10;
	}

	aux = busca;
	div = 1;

	while(aux>1){
    	     div = div*10;
    	     aux--;

	}

	for(aux=0; aux < busca; aux++){
    	   kcont = numerobusca/div;
    	   numbusca[aux]=kcont;
    	   numerobusca = numerobusca - (kcont*div);
    	   div = div/10;
	}

	if(aux1 == 0){

	   numbusca[0] = 0;
	   busca = 1;

	}


	for(icont = 0; icont < base; icont++){
	    
	    if(numbase[icont] == numbusca[0] && busca > 1){
	        
	        for(jcont = 1, kcont = icont + 1, volta = 1; (jcont < busca && (volta)); kcont++, jcont++){
	            
	            if(numbase[kcont] == numbusca[jcont]) {
	                
	               if(jcont == busca - 1){
	                 
	                 qtdOcorrencias++;
	                 
	             }
	                
	            }else{
	                
	                 volta = 0;
	            }
	            
	        }
	        
	    } else if(numbase[icont] == numbusca[0] && (busca == 1)){
	    	
	    	qtdOcorrencias++;
	    	
		}
	    
	}


    return qtdOcorrencias;
}
