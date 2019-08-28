#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])

{	//declaração do tabuleiro
    setlocale(LC_ALL, "portuguese");
    void nomePeca(char peca); //função que retorna o nome das peças
    void imprimeTabuleiro(char peca[8][8]); //função que imprime o tabuleiro
    char retiradas(char pecaRetirada, char *pontPF, char *pontBF); //função que imprime as peças retiradas
    char tabuleiro[8][8], pecaRetirada, pretasFora[16]={'x'}, brancasFora[16]={'x'}, *pontBF, *pontPF, pecaOrigem, pecaDestino;
    int i, j, lpo, cpo,lpd,cpd, jogador=1;
   
    pontPF=pretasFora;
    pontBF=brancasFora; //recebe o endereço das brancas fora
    //maisculas
    tabuleiro[0][0]='T'; //torre
    tabuleiro[0][1]='C';//cavalo
    tabuleiro[0][2]='B';//bispo
    tabuleiro[0][3]='Q';//rainha
    tabuleiro[0][4]='K';//rei
    tabuleiro[0][5]='B';//bispo
    tabuleiro[0][6]='C';
    tabuleiro[0][7]='T';
    tabuleiro[1][0]='P';//peão
    tabuleiro[1][1]='P';
    tabuleiro[1][2]='P';
    tabuleiro[1][3]='P';
    tabuleiro[1][4]='P';
    tabuleiro[1][5]='P';
    tabuleiro[1][6]='P';
    tabuleiro[1][7]='P';
    //minusculas
    tabuleiro[6][0]='p';
    tabuleiro[6][1]='p';
    tabuleiro[6][2]='p';
    tabuleiro[6][3]='p';
    tabuleiro[6][4]='p';
    tabuleiro[6][5]='p';
    tabuleiro[6][6]='p';
    tabuleiro[6][7]='P';
    tabuleiro[7][0]='t';
    tabuleiro[7][1]='c';
    tabuleiro[7][2]='b';
    tabuleiro[7][3]='q';
    tabuleiro[7][4]='k';
    tabuleiro[7][5]='b';
    tabuleiro[7][6]='c';
    tabuleiro[7][7]='t';

    //8 col 4 linhas peças brancas
    for(i=2;i<6;i++){
        for(j=0;j<8;j++){
            tabuleiro[i][j]=' ';
        }
    }
   
/* inicio da rotina principal*/
do{
    imprimeTabuleiro(tabuleiro);
	/*Até aqui foi a declarção da matriz*/
	
    //movimento das peças pretas
    do{
    	if(jogador==1) { //peças maiusculas
        	printf("JOGADOR 01\nEscolha uma peça preta\n");
        		/*origem */
      		 do{
				printf("Linha : ");
	        	scanf("%i",&lpo); //linha da peça de origem
	       		printf("Coluna: ");
	       		scanf("%i",&cpo); //coluna da peça de origem
	       		--lpo; //ajusta a matriz par começar em zero
       			--cpo;
				   if(!isupper(tabuleiro[lpo][cpo])){
	       				printf("Você deve escolher uma peça preta!!\n");
						printf("Digite novamente\n");	
					}
       			}while(!isupper(tabuleiro[lpo][cpo])); //repete emquanto origem não for maiuscula
       			
       		 /* destino*/
        	do{
	        	printf("\nEscolha o destino da peça\n");//minuscula
		        printf("Linha : ");
		        scanf("%i",&lpd); //linha da peça de destino
		        printf("Coluna: ");
		        scanf("%i",&cpd); //coluna da peça de destino
		        --lpd; //ajusta a matriz par começar em zero
		        --cpd;	
		        	if(isupper(tabuleiro[lpd][cpd])){
	       				printf("Você deve escolher uma peça branca!!\n");
						printf("Digite novamente\n");	
					}
			}while(isupper(tabuleiro[lpd][cpd])); //repete emquanto destino for maiscula
        	jogador=2; //armazena o proximo jogador
    	}
		else{ //peças minusculas
        	printf("JOGADOR 02\nEscolha uma peça branca\n");  //minuscula
        	do{
        		printf("Linha : ");
	        	scanf("%i",&lpo); //linha da peça de origem
	       		printf("Coluna: ");
	       		scanf("%i",&cpo); //coluna da peça de origem
	       		--lpo; //ajusta a matriz par começar em zero
       			--cpo;
				   if(isupper(tabuleiro[lpo][cpo])){
	       				printf("Você deve escolher uma peça branca!!\n");
						printf("Digite novamente\n");	
					}
       		}while(isupper(tabuleiro[lpo][cpo])); //repete emquanto origem for maiscula
       		
        	do{
	        	printf("\nEscolha o destino da peça\n");//maiuscula
		        printf("Linha : ");
		        scanf("%i",&lpd); //linha da peça de destino
		        printf("Coluna: ");
		        scanf("%i",&cpd); //coluna da peça de destino
		        --lpd; //ajusta a matriz par começar em zero
		        --cpd;	
		        	if(!isupper(tabuleiro[lpd][cpd])){
	       				printf("Você deve escolher uma peça preta!!\n");
						printf("Digite novamente\n");	
					}
			}while(isupper(tabuleiro[lpo][cpo])); //repete emquanto destino maiscula
        	jogador=1;
        }
	
		if(tabuleiro[lpo][cpo]==' ') //mensagem se existe peça na posição escolhida
	    	printf("\nNão existe peça nesta posição");

    }while(tabuleiro[lpo][cpo]==' '); //se não exitir peça na posição escolhida faz o loop
    
        pecaOrigem=tabuleiro[lpo][cpo]; //"peca" recebe a letra da peca de origem
        printf("Você escolheu: ");
        nomePeca(pecaOrigem);	//imprime o nome da peça (funçao)


        
        pecaDestino=tabuleiro[lpd][cpd];
        printf("Você escolheu: ");
        nomePeca(pecaDestino);	//imprime o nome da peça (funçao)
        printf("peca dest %c peca or %c \n", pecaDestino, pecaOrigem);

        /*verifica o destino para gravar a peça preta e apagar a origem */
        
       	if(!isupper(tabuleiro[lpd][cpd]) && isupper(tabuleiro[lpo][cpo])&&jogador==2){	//se o local de destino for minuscula e a origem for maiscula
       		pecaRetirada=tabuleiro[lpd][cpd]; //salva peça retirada do tabuleiro de adversário
       		if(tabuleiro[lpd][cpd]=='k') //se o for rei minusculo é adversário
        		printf("\n\nXEQUE MATE!!!\n\n");
				    
       		//else if (!isupper(tabuleiro[lpd][cpd])) { //se local de destino é minusculo

		    else if (tabuleiro[lpd][cpd]==' '){ //se a linha da peça de destino e a colunada peça de destino for vazio
		        	tabuleiro[lpd][cpd]=pecaOrigem; //grava a peça no endereço de destino
		            tabuleiro[lpo][cpo]=' ';//apaga a peça da posição de origem
		        }
		    else{
		        
		 	  	    tabuleiro[lpd][cpd]=pecaOrigem; //grava a peça preta no endereço
	                tabuleiro[lpo][cpo]=' '; //apaga a posição de origem
	            }
			}
	       // else{ //se o local de destino for maiusculo e a origem minuscula
	       //         printf("Atenção você esta remontando peça sua!!");
	       //     }
		
	           
	        
		
		 /*verifica o destino para gravar a peça branca e apagar a origem */
        
       	if(isupper(tabuleiro[lpd][cpd]) && !isupper(tabuleiro[lpo][cpo])&&jogador==1){	//se o local de destino for maiscula e a origem for minuscula
       		pecaRetirada=tabuleiro[lpd][cpd]; //salva peça retirada do tabuleiro de adversário
       		if(tabuleiro[lpd][cpd]=='K') //se o for rei minusculo é adversário
        		printf("\n\nXEQUE MATE!!!\n\n");
				    
       	//	else if (isupper(tabuleiro[lpd][cpd])) {

		    else if (tabuleiro[lpd][cpd]==' '){ //se a linha da peça de destino e a colunada peça de destino for vazio
		            tabuleiro[lpd][cpd]=pecaOrigem; //grava a peça no endereço de destino
		            tabuleiro[lpo][cpo]=' ';//apaga a peça da posição de origem
		        }
		        else{
		        
		 	  	    tabuleiro[lpd][cpd]=pecaOrigem; //grava a peça branca no endereço
	                tabuleiro[lpo][cpo]=' '; //apaga a posição de origem
	            }
		//	}
	       // else{
	       //         printf("Atenção você esta remontando peça sua!!");
	       //     }
		
	           
	        
		}
	
		
		//printf("Peça retirada:  %c", pecaRetirada);
		printf("Você removeu: ");
		nomePeca(pecaRetirada); //imprime o nome da peça retirada
		retiradas(pecaRetirada, pontPF, pontBF); //chama a função que imprime as retiradas
        //imprimeTabuleiro(tabuleiro);
        printf("peças retirada foi %c \n", pecaRetirada );
        
        
} while(pecaRetirada != 'k'|| pecaRetirada != 'K'); //A PEÇA É k mas não encerra
/* fim da rotina principal*/
}

/*fução que imprime o tabuleiro*/
void imprimeTabuleiro(char peca[8][8]){ 
int i, j;
//printf("\nVerificando o tabuleiro\n");
printf("\n\nPeças pretas\n");
printf("    1   2   3   4   5   6   7   8\n");
printf("  --------------------------------\n");

for(i=0;i<8;i++){
        printf("%i| ", i+1);
        for(j=0;j<8;j++){
           printf("[%c] ", peca[i][j]);
        }
        printf("\n");
    }
printf("Peças brancas\n\n");
}
/*Função que da nome as peças*/
void nomePeca(char peca){ //exibe o nome das peças
	printf("\n");
	switch(peca){ //maiusculas preta
		case 'T':
			printf("Torre preta");
			break;
		case 'C':
			printf("Cavalo preta");
			break;
		case 'B':
			printf("Bispo preta");
			break;
		case 'Q':
			printf("Rainha preta");
			break;
		case 'K':
			printf("Rei preta");
			break;
		case 'P':
			printf("Peão preta");
			break;
		case 't':	//minusculas branca
			printf("Torre branca");
			break;
		case 'c':
			printf("Cavalo branco");
			break;
		case 'b':
			printf("Bispo branco");
			break;
		case 'q':
			printf("Rainha branca");
			break;
		case 'k':
			printf("Rei branco");
			break;
		case 'p':
			printf("Peão branco");
			break;		
	}
	printf("\n");
}

/*função pedras retiradas passar(nome da peça, ponteiro de preta e ponteiro de branca*/
char retiradas(char peca, char *pontPF, char *pontBF){ //"peca" recebe o valor da peça, e "pontPF"o endereço da peça fora
	int i=0, nBretiradas=0, nPretiradas=0;
	//printf("pecax %c\n", peca);

	
	if(isupper(peca)){ //se for maisucula é preta 
	//printf("Pretas retiradas: ");
		nPretiradas++; //conta as pretas retiradas
		printf("pretas Retiradas: %i: ",nPretiradas);
		for(i=0;i<nPretiradas;i++){
			if (pontPF[i]=='x')
				pontPF[i]=peca;
				printf("[%c]", pontPF[i]);//peças retiradas brancas
		}
	}
	else{ 
	//printf("Brancas retiradas: ");
			nBretiradas++; //conta as brancas retiradas
			printf("Brancas Retiradas: %i: ",nBretiradas);
		for(i=0;i<nBretiradas;i++){ //peças retiradas pretas
			if (pontBF[i]=='x')
				pontBF[i]=peca;
			
		printf("[%c]", pontBF[i]); //imprime esta linha com x
		i++;
		};
	}	
	printf("\n");
}




