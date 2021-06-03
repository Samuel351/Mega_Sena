#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
void main()
{
	int val[6], sort[6], prim, seg, x, aux, count=0, count1=0, mega=0, z=0;
	int matriz[5][6], aux[0][0];
	srand(time(NULL));//sorteia aleatoriamente sem repetir
	//baseado no tempo
	setlocale(LC_ALL,"");//inclui caracteres especial na impressão
	printf("Esse programa faz jogo da MegaSena.\n");
	//sorteia numeros de 1 a 60
	for(x=0;x<6;x++)
	{
		sort[x]=rand() % 60+1;
	//	printf(" %d ",sort[x]);
	}
	
	//coloca os valores em ordem crescente - bubble sort
	for(prim=0;prim<5;prim++)
	{
		for(seg=prim+1;seg<6;seg++)
		{
			if(sort[prim]>sort[seg])//verifica se anterior é maior 
			//que posterior
			{
				aux = sort[prim];//movimenta primeiro valor para aux
				sort[prim]=sort[seg];//movimento seg para prim valor
				sort[seg]=aux;//movimenta aux para segundo valor
				//trocando as posições para colocar em ordem 
				//crescente
			}
		}
	}
/*	printf("\nOrdenado.\n");
	for(x=0;x<6;x++)
	{
		printf(" %d ",sort[x]);
	}*/
	novo://label - etiqueta de goto
	
	//bubble sort apra verificar se sorteio foi repetido
	for(prim=0;prim<5;prim++)
	{
		for(seg=prim+1;seg<6;seg++)
		{
			if(sort[prim]==sort[seg])//compara sorteio repetido
			{
				sort[prim]=rand() % 60+1;//sorteia novamente 
				//no lugar do repetido
			}
			else
			{
				count++;//contar quantas vezes foi repetido
				//tem que ser 15 - para garantir todos diferentes
			}
		}
	}
	if(count < 15)//se for menor que 15 tem nuemro repetido
	{
		count=0;//reinicia variavel que conta repetidos
		goto novo;//faz retorno para nova verificação
	}
//	printf("\nSem repetição\n");

//coloca em ordem crescente
	for(prim=0;prim<5;prim++)
	{
		for(seg=prim+1;seg<6;seg++)
		{
			if(sort[prim]>sort[seg])
			{
				aux = sort[prim];
				sort[prim]=sort[seg];
				sort[seg]=aux;
			}
		}
	}
/*	for(x=0;x<6;x++)
	{
		printf(" %d ",sort[x]);
	}*/
	printf("\nSeu jogo:");
	for
	for(x=0;x<6;x++)
	{
		printf("\nO seu %dº valor do jogo:",x+1);
		scanf("%d", &val[x]);
	}
	novojogo://label de retorno de verificação de repetidos
	for(prim=0;prim<5;prim++)
	{
		for(seg=prim+1;seg<6;seg++)
		{
			if(val[prim]==val[seg])
			{
				printf("\nVocê jogou número repetido!");
				printf("\nJogue novamente a posição %d:",seg);
				scanf("%d", &val[seg]);
			}
			else
			{
				count1++;
			}
		}
	}
	if(count1 < 15)
	{
		count1=0;
		goto novojogo;
	}
	//coloca em ordem
	for(prim=0;prim<5;prim++)
	{
		for(seg=prim+1;seg<6;seg++)
		{
			if(val[prim]>val[seg])
			{
				aux = val[prim];
				val[prim]=val[seg];
				val[seg]=aux;
			}
		}
	}
/*	printf("\nJogado  Verificado.\n");
	for(x=0;x<6;x++)
	{
		printf(" %d ",val[x]);
	}*/
	
	//verifica quantos numeros vocÊ acertou na mega - bubble sort
	for(z = 0; z < 5; z++)
	{
	
		for(prim=0;prim<6;prim++)
		{
			for(seg=0;seg<6;seg++)
			{
				if(val[prim]==sort[seg])
				{
					mega++;
				}
			}
		}	
	}
	
	if(mega==6)
	{
		printf("\nParabéns você é um novo milionario!!!");
	}
	if(mega==5)
	{
		printf("\nParabéns você acertou na quina!!!");
	}
	if(mega==4)
	{
		printf("\nParabéns você acertou na quadra!!!");
	}
	if(mega<4)
	{
		printf("\nVocê não ganhou, acertou %d numero(s)!!!",mega);
	}
	getch();
}
