#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])

{	//declara��o do tabuleiro
    setlocale(LC_ALL, "portuguese");
    void nomePeca(char peca); //fun��o que retorna o nome das pe�as
    void imprimeTabuleiro(char peca[8][8]); //fun��o que imprime o tabuleiro
    char retiradas(char pecaRetirada, char *pontPF, char *pontBF); //fun��o que imprime as pe�as retiradas
    char tabuleiro[8][8], pecaRetirada, pretasFora[16]={'x'}, brancasFora[16]={'x'}, *pontBF, *pontPF, pecaOrigem, pecaDestino;
    int i, j, lpo, cpo,lpd,cpd, jogador=1;
   
    pontPF=pretasFora;
    pontBF=brancasFora; //recebe o endere�o das brancas fora
    //maisculas
    tabuleiro[0][0]='T'; //torre
    tabuleiro[0][1]='C';//cavalo
    tabuleiro[0][2]='B';//bispo
    tabuleiro[0][3]='Q';//rainha
    tabuleiro[0][4]='K';//rei
    tabuleiro[0][5]='B';//bispo
    tabuleiro[0][6]='C';
    tabuleiro[0][7]='T';
    tabuleiro[1][0]='P';//pe�o
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

    //8 col 4 linhas pe�as brancas
    for(i=2;i<6;i++){
        for(j=0;j<8;j++){
            tabuleiro[i][j]=' ';
        }
    }
   
/* inicio da rotina principal*/
do{
    imprimeTabuleiro(tabuleiro);
	/*At� aqui foi a declar��o da matriz*/
	
    //movimento das pe�as pretas
    do{
    	if(jogador==1) { //pe�as maiusculas
        	printf("JOGADOR 01\nEscolha uma pe�a preta\n");
        		/*origem */
      		 do{
				printf("Linha : ");
	        	scanf("%i",&lpo); //linha da pe�a de origem
	       		printf("Coluna: ");
	       		scanf("%i",&cpo); //coluna da pe�a de origem
	       		--lpo; //ajusta a matriz par come�ar em zero
       			--cpo;
				   if(!isupper(tabuleiro[lpo][cpo])){
	       				printf("Voc� deve escolher uma pe�a preta!!\n");
						printf("Digite novamente\n");	
					}
       			}while(!isupper(tabuleiro[lpo][cpo])); //repete emquanto origem n�o for maiuscula
       			
       		 /* destino*/
        	do{
	        	printf("\nEscolha o destino da pe�a\n");//minuscula
		        printf("Linha : ");
		        scanf("%i",&lpd); //linha da pe�a de destino
		        printf("Coluna: ");
		        scanf("%i",&cpd); //coluna da pe�a de destino
		        --lpd; //ajusta a matriz par come�ar em zero
		        --cpd;	
		        	if(isupper(tabuleiro[lpd][cpd])){
	       				printf("Voc� deve escolher uma pe�a branca!!\n");
						printf("Digite novamente\n");	
					}
			}while(isupper(tabuleiro[lpd][cpd])); //repete emquanto destino for maiscula
        	jogador=2; //armazena o proximo jogador
    	}
		else{ //pe�as minusculas
        	printf("JOGADOR 02\nEscolha uma pe�a branca\n");  //minuscula
        	do{
        		printf("Linha : ");
	        	scanf("%i",&lpo); //linha da pe�a de origem
	       		printf("Coluna: ");
	       		scanf("%i",&cpo); //coluna da pe�a de origem
	       		--lpo; //ajusta a matriz par come�ar em zero
       			--cpo;
				   if(isupper(tabuleiro[lpo][cpo])){
	       				printf("Voc� deve escolher uma pe�a branca!!\n");
						printf("Digite novamente\n");	
					}
       		}while(isupper(tabuleiro[lpo][cpo])); //repete emquanto origem for maiscula
       		
        	do{
	        	printf("\nEscolha o destino da pe�a\n");//maiuscula
		        printf("Linha : ");
		        scanf("%i",&lpd); //linha da pe�a de destino
		        printf("Coluna: ");
		        scanf("%i",&cpd); //coluna da pe�a de destino
		        --lpd; //ajusta a matriz par come�ar em zero
		        --cpd;	
		        	if(!isupper(tabuleiro[lpd][cpd])){
	       				printf("Voc� deve escolher uma pe�a preta!!\n");
						printf("Digite novamente\n");	
					}
			}while(isupper(tabuleiro[lpo][cpo])); //repete emquanto destino maiscula
        	jogador=1;
        }
	
		if(tabuleiro[lpo][cpo]==' ') //mensagem se existe pe�a na posi��o escolhida
	    	printf("\nN�o existe pe�a nesta posi��o");

    }while(tabuleiro[lpo][cpo]==' '); //se n�o exitir pe�a na posi��o escolhida faz o loop
    
        pecaOrigem=tabuleiro[lpo][cpo]; //"peca" recebe a letra da peca de origem
        printf("Voc� escolheu: ");
        nomePeca(pecaOrigem);	//imprime o nome da pe�a (fun�ao)


        
        pecaDestino=tabuleiro[lpd][cpd];
        printf("Voc� escolheu: ");
        nomePeca(pecaDestino);	//imprime o nome da pe�a (fun�ao)
        printf("peca dest %c peca or %c \n", pecaDestino, pecaOrigem);

        /*verifica o destino para gravar a pe�a preta e apagar a origem */
        
       	if(!isupper(tabuleiro[lpd][cpd]) && isupper(tabuleiro[lpo][cpo])&&jogador==2){	//se o local de destino for minuscula e a origem for maiscula
       		pecaRetirada=tabuleiro[lpd][cpd]; //salva pe�a retirada do tabuleiro de advers�rio
       		if(tabuleiro[lpd][cpd]=='k') //se o for rei minusculo � advers�rio
        		printf("\n\nXEQUE MATE!!!\n\n");
				    
       		//else if (!isupper(tabuleiro[lpd][cpd])) { //se local de destino � minusculo

		    else if (tabuleiro[lpd][cpd]==' '){ //se a linha da pe�a de destino e a colunada pe�a de destino for vazio
		        	tabuleiro[lpd][cpd]=pecaOrigem; //grava a pe�a no endere�o de destino
		            tabuleiro[lpo][cpo]=' ';//apaga a pe�a da posi��o de origem
		        }
		    else{
		        
		 	  	    tabuleiro[lpd][cpd]=pecaOrigem; //grava a pe�a preta no endere�o
	                tabuleiro[lpo][cpo]=' '; //apaga a posi��o de origem
	            }
			}
	       // else{ //se o local de destino for maiusculo e a origem minuscula
	       //         printf("Aten��o voc� esta remontando pe�a sua!!");
	       //     }
		
	           
	        
		
		 /*verifica o destino para gravar a pe�a branca e apagar a origem */
        
       	if(isupper(tabuleiro[lpd][cpd]) && !isupper(tabuleiro[lpo][cpo])&&jogador==1){	//se o local de destino for maiscula e a origem for minuscula
       		pecaRetirada=tabuleiro[lpd][cpd]; //salva pe�a retirada do tabuleiro de advers�rio
       		if(tabuleiro[lpd][cpd]=='K') //se o for rei minusculo � advers�rio
        		printf("\n\nXEQUE MATE!!!\n\n");
				    
       	//	else if (isupper(tabuleiro[lpd][cpd])) {

		    else if (tabuleiro[lpd][cpd]==' '){ //se a linha da pe�a de destino e a colunada pe�a de destino for vazio
		            tabuleiro[lpd][cpd]=pecaOrigem; //grava a pe�a no endere�o de destino
		            tabuleiro[lpo][cpo]=' ';//apaga a pe�a da posi��o de origem
		        }
		        else{
		        
		 	  	    tabuleiro[lpd][cpd]=pecaOrigem; //grava a pe�a branca no endere�o
	                tabuleiro[lpo][cpo]=' '; //apaga a posi��o de origem
	            }
		//	}
	       // else{
	       //         printf("Aten��o voc� esta remontando pe�a sua!!");
	       //     }
		
	           
	        
		}
	
		
		//printf("Pe�a retirada:  %c", pecaRetirada);
		printf("Voc� removeu: ");
		nomePeca(pecaRetirada); //imprime o nome da pe�a retirada
		retiradas(pecaRetirada, pontPF, pontBF); //chama a fun��o que imprime as retiradas
        //imprimeTabuleiro(tabuleiro);
        printf("pe�as retirada foi %c \n", pecaRetirada );
        
        
} while(pecaRetirada != 'k'|| pecaRetirada != 'K'); //A PE�A � k mas n�o encerra
/* fim da rotina principal*/
}

/*fu��o que imprime o tabuleiro*/
void imprimeTabuleiro(char peca[8][8]){ 
int i, j;
//printf("\nVerificando o tabuleiro\n");
printf("\n\nPe�as pretas\n");
printf("    1   2   3   4   5   6   7   8\n");
printf("  --------------------------------\n");

for(i=0;i<8;i++){
        printf("%i| ", i+1);
        for(j=0;j<8;j++){
           printf("[%c] ", peca[i][j]);
        }
        printf("\n");
    }
printf("Pe�as brancas\n\n");
}
/*Fun��o que da nome as pe�as*/
void nomePeca(char peca){ //exibe o nome das pe�as
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
			printf("Pe�o preta");
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
			printf("Pe�o branco");
			break;		
	}
	printf("\n");
}

/*fun��o pedras retiradas passar(nome da pe�a, ponteiro de preta e ponteiro de branca*/
char retiradas(char peca, char *pontPF, char *pontBF){ //"peca" recebe o valor da pe�a, e "pontPF"o endere�o da pe�a fora
	int i=0, nBretiradas=0, nPretiradas=0;
	//printf("pecax %c\n", peca);

	
	if(isupper(peca)){ //se for maisucula � preta 
	//printf("Pretas retiradas: ");
		nPretiradas++; //conta as pretas retiradas
		printf("pretas Retiradas: %i: ",nPretiradas);
		for(i=0;i<nPretiradas;i++){
			if (pontPF[i]=='x')
				pontPF[i]=peca;
				printf("[%c]", pontPF[i]);//pe�as retiradas brancas
		}
	}
	else{ 
	//printf("Brancas retiradas: ");
			nBretiradas++; //conta as brancas retiradas
			printf("Brancas Retiradas: %i: ",nBretiradas);
		for(i=0;i<nBretiradas;i++){ //pe�as retiradas pretas
			if (pontBF[i]=='x')
				pontBF[i]=peca;
			
		printf("[%c]", pontBF[i]); //imprime esta linha com x
		i++;
		};
	}	
	printf("\n");
}




