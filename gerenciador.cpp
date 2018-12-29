/*/  ##menu##
(entra lido sai lido)
	1- ok Cadastro de Produtos (sem repetir) **strcmp**  (criar variavel a parte e depois de validar add a string)
	2- ok Cadastro de Clientes
	3- Relatório de Produtos
	4- Relatório de clientes
	5  ok exclusão de produtos
	6- ok Exclusão de clientes
	0- Sair/*/
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#define TFC 30
#define TFP 40
#define TFV 500
int main()
 {
	 int estoque[TFP], i, j, contpro=0,cont=0,cod, qtdd, contcli=0, v=0, venda[TFV][3], TL=0, t, p;
	 float preco[TFP];
	 char produto[TFP][50], cliente[TFC][TFC], cliente_at[TFC], resp[TFC];
	 /*/ cadastro de produtos/*/
  	
  	char valor;
  	do{
  		system("cls");
  		printf("-------Menu-------");
  		printf("\n1-Cadastrar Produto: \n");
  		printf("\n2-Relatorio de Produtos: \n");
  		printf("\n3-Relatório de Clientes: \n");
  		printf("\n4-Cadastrar cliente: \n");
  		printf("\n5-Venda: \n");
  		printf("\n6-Exclusao de clientes: \n");
  		printf("\n7-Exclusao de produto: \n");
  		printf("\n0-Sair");
  		scanf("%c",&valor);
  		
  		switch(valor)
  		{
  			case '1':
		 		system("cls");
	 			printf("digite o nome do produto %d ou digite (enter) para sair\n",contpro); // fora do DO...WHILE caso contrario ele vai perguntar 2 vezes
		 		fflush(stdin);
			 	gets(resp);
  				while(contpro<TFP && strcmp(resp,"\0")!=0)
  				{
  						if(contpro!=0)
						  {
											cont=0;
											for(i=0;i<=contpro;i++)//coloquei um <= pq ele verifica até o ultimo elemento do TL, assim nao precisa verificar dps no if de baixo
											{
												if(strcmp(produto[i],resp)==0)
												{
													printf("produto ja cadastrado\n");
													cont++;
												}
						    	}
									if(cont==0)//nao precisava das outras condiçoes pq coloquei um <= no for de cima
								 	{
										strcpy(produto[contpro],resp);
									 	printf("\nDigite seu preco\n");
									 	scanf("%f",&preco[contpro]);
									 	printf("\nDigite a quantidade em estoque\n");
									 	scanf("%d",&estoque[contpro]);
										contpro++;	
									 }	
									 printf("Digite o nome do produto %d ou digite (enter) para sair\n",contpro);// entra lido sai lido, 
									 //deixa fora do if pq se existir um produto cadastrado ele pergunta se quer adicionar outro
						 			 fflush(stdin);
						 			 gets(resp);
									cont=0; // precisa disso pq se um produto estiver cadastrado ele nunca vai entrar nesse if de cima,
									// ja que ele deu cont++ no for, entao na segunda vez ele vai estar valendo X
							 }
							else// troquei pra else, mas nao faz diferença, faz o que você achar melhor
						    {
						 		
	  					 		strcpy(produto[contpro],resp);
			  			 		printf("\nDigite seu preco\n");
					  	 		scanf("%f",&preco[contpro]);
						   		printf("\nDigite a quantidade em estoque\n");
						 		  scanf("%d",&estoque[contpro]);
						 	  	contpro++;// estava no começo, entao na hora de adicionar ele adicionaria na posição 1 e nao 0, assim 
						 		// a posição 0 ficaria com lixo e ferraria com o relatorio
		  				 		printf("digite o nome do produto %d ou digite (enter) para sair\n",contpro);// entra lido sai lido
				  		 		fflush(stdin);
						   		gets(resp);
						   	}
  		  }
		  		getch();
		  		break;
		  	
		  	case '2':
		  		/*
		  		. Observações: O relatório está certo, você só precisa fazer uma verificação se existe algum produto cadastrado, se nao
		  		.existir exibe uma msg tipo: nao possui produtos
		  		*/
		  		system("cls");//apaga tela pra deixar mais bonitinho ;) 
		  		for(i=0;i<contpro;i++)
		  		{
		  			if(contpro!=0)
							printf("Produto %d-%s    Preco:%f    Estoque:%d\n",i,produto[i],preco[i],estoque[i]);
				   if(contpro==0)
				   printf("Nao existem produtos cadastrados");
				  }
				 	getch();
		  		break;
	  		case '3':
	  			system("cls");
	  			
	  			for(i=0;i<contcli;i++)
	  			{
	  				if(contcli!=0)
	  				printf("%d- %s\n",i,cliente[i]);
	  				if(contcli==0)
	  				printf("Não existe cliente cadastrado\n");
						}
						getch();
	  			break;
	  		
			  case '4':
			  	{
			  	 printf("\nDigite o nome do cliente %d ou enter para sair\n",contcli);
							fflush(stdin);
							gets(resp);
						 while(contcli<TFC && strcmp(resp,"\0")!=0)
						 {
								strcpy(cliente[contcli],resp);
						 	contcli++;
						  printf("\nDigite o nome do cliente %d ou enter para sair\n",contcli);
							 fflush(stdin);
								gets(resp);
					  }
					  getch();
					 }
	  		 break;
	  		 
	  		 case '5':
	  		 {
	  		 	  printf("\nDigite o nome do cliente\n");
						 		fflush(stdin);
						  	gets(resp);
						  	while(strcmp(resp,"\0")!=0   &&  TL<TFV  && contcli!=0 && contpro!=0)//tinha um N no \0
						  	{
						  		i=0;
						 		 while(i<contcli && strcmp(resp,cliente[i])!=0)
						 		 {
						 		 	i++;
						 		 }
							 		 
								if(i==contcli)
							 		 	printf("\nCliente não existe!\n");
						 		 if(i!=contcli)
						 		 {
						 		 	v=i;
						 		 	printf("PRODUTO                   CODIGO DO PRODUTO");
						 		 	for(i=0;i<contpro;i++)
						 		 	printf("\n%s\t%d\n",produto[i],i);
						 		 	printf("digite o codigo do numero desejado:  ");
						 		 	scanf("%d",&cod);
						 		  do
						 		 	{
							 		 	if(cod>contpro || cod<0)
							 		 	{
							 		 		printf("Codigo invalido\n");
							 		 		printf("digite o codigo do numero desejado:  \n");
						 		 	  scanf("%d",&cod);
											 }
						 		  }while(cod>contpro || cod<0);
						 		  printf("digite a quantidade que deseja (VALIDA)");
						 		  scanf("%d",&qtdd);
						 		  do
						 		 	{
							 		 	if(qtdd>estoque[cod] || qtdd<0)
							 		 	{
							 		 		printf("Quantidade invalida\n");
							 		 		printf("digite a quantidade que deseja (VALIDA)");
						 		    scanf("%d",&qtdd);
												}
											}while(qtdd>estoque[cod] || qtdd<0);
											venda[TL][0]=v;
											venda[TL][1]=cod;
											venda[TL][2]=qtdd;
											estoque[cod]=estoque[cod]-qtdd;
											
								}
								printf("\nDigite o nome do cliente ou enter para sair\n");
									 		  fflush(stdin);
									  	  gets(resp);
								 }
								 if( TL<=TFV  && contcli!=0 && contpro!=0)
								 {
								 	for(p=0;p<contcli;p++)
									{
									 printf("Cliente: %d – %s",p, cliente[p]);
										for(i=0;i<TL;i++)
										{
												if(venda[i][0]==p)
												{
													printf("Produto: %d – %s   	Preco:%f       Quantidade: %d  	Total: %f",venda[i][1],produto[venda[i][1]],preco[venda[i][1]],venda[i][3],preco[venda[i][1]]*venda[i][3]);
													printf("\n");
												}
										}
										printf("\n");
									}
								 }
								 else{
									printf("Cadastre um produto e um cliente");
								 }
								 
						}
						getch();
				  break;
				  case '6':
				  		for(i=0;i<contcli;i++)
						printf("Cliente %d-  %s\n",i,cliente[i]);
					 do 
						{
							printf("Qual cliente deseja excluir(DIGITE O NUMERO) ou  00 para sair:\n ");
						 scanf("%d",&v);
						 if(v!=00)
						 {
							 for(i=v;i<contcli-1;i++)
							 {
									strcpy(cliente[i],cliente[i+1]);
									printf("\nCliente excluido\n");
										
							 }
							 contcli--;
					 	}
						}while(v!=00);
		    break;
		   	case '7':
				   			for(i=0;i<contpro;i++)
								 printf("Produto %d-%s\n",i,produto[i]);
								do
								{
									printf("Qual produto deseja excluir(DIGITE O NUMERO) ou digite 00 para sair: \n");
								    scanf("%d",&v);
								 if(v!=00)
								   {
												for(i=v;i<contpro-1;i++)
												{
													strcpy(produto[i],produto[i+1]);
													estoque[i]=estoque[i+1];
													preco[i]=preco[i+1];
													printf("Produto excluido!\n");
												}
												contpro--;
								 	 }
								}while(v!=00);
				 	break;
	   }

  	}while(valor!='0');
  	system("cls");
}
  
  /*
	 //cadastro de clientes//
		printf("\nDigite o nome do cliente %d ou espaco para sair\n",contcli);
		gets(resp);
		strcpy(cliente[contcli],resp);
	 contcli++;
	 while(contcli<TFC && !strcmp(resp,"\n"))
	 {
	 	printf("\nDigite o nome do cliente %d ou enter para sair\n",contcli);
		 gets(resp);
		 if(strcmp(resp,"\n")==0)
		 {
			strcpy(cliente[contcli],resp);
	 	contcli++;
	  }
  }
  printf("Digite a opcao desejada:1-Vendas\n2-Relatorio de clientes\n3-Relatorio de produtos\n4-Exclusao de produtos\n5-Exclusao de clientes0-sair\n");
	 scanf("%d",&i);
	 while(i!=0)
	 {
	 	switch(i)
	 	{
	 		//venda//
	 		case 1:
	 		printf("\nDigite o nome do cliente\n");
	 		fflush(stdin);
	  	gets(resp);
	  	while(!strcmp(resp,"\n")   &&  TL<TFV)
	  	{
	 		 for(i=0;i<contcli && !strcmp(resp,cliente[i]);i++);
	 		 if(i==contcli)
	 		 	printf("\nCliente não existe!\n");
	 		 if(i!=contcli)
	 		 {
	 		 	v=i;
	 		 	printf("PRODUTO                   CODIGO DO PRODUTO");
	 		 	for(i=0;i<contpro;i++)
	 		 	printf("%s\t%d",produto[i],i);
	 		 	printf("digite o codigo do numero desejado:  ");
	 		 	scanf("%d",&cod);
	 		  do
	 		 	{
	 		 		cont=0;
		 		 	if(cod>contpro || cod<0)
		 		 	{
		 		 		printf("Codigo invalido\n");
		 		 		printf("digite o codigo do numero desejado:  ");
	 		 	  scanf("%d",&cod);
							}
	 		  }while(cont!=0);
	 		  printf("digite a quantidade que deseja (VALIDA)");
	 		  scanf("%d",&qtdd);
	 		  do
	 		 	{
	 		 		cont=0;
		 		 	if(qtdd>estoque[cod] || qtdd<0)
		 		 	{
		 		 		printf("Quantidade invalida\n");
		 		 		printf("digite a quantidade que deseja (VALIDA)");
	 		    scanf("%d",&qtdd);
							}
						}while(cont!=0);
						venda[TL][0]=v;
						venda[TL][1]=cod;
						venda[TL][2]=qtdd;
						estoque[cod]=estoque[cod]-qtdd;
						printf("\nDigite o nome do cliente ou enter para sair\n");
	 		  fflush(stdin);
	  	  gets(resp);
					}
			 }
			 for(p=0;p<contcli;p++)
				{
				 printf("Cliente: %d – %s",p, cliente[p]);
					for(i=0;i<TL;i++)
					{
							if(venda[i][0]==p)
							{
								printf("Produto: %d – %s   	Preco:%f       Quantidade: %d  	Total: %f",venda[i][1],produto[venda[i][1]],preco[venda[i][1]],venda[i][3],preco[venda[i][1]]*venda[i][3]);
								printf("\n");
							}
					}
					printf("\n");
				}
				 break;
		 case 2:
						//relatorio de clientes
						for(i=0;i<contcli;i++)
							printf("Cliente 1- %s\n",cliente[i]);
		 break;
		 case 3:
						//relatorio de produtos
						for(i=0;i<contpro;i++)
							printf("Produto %d-%s    Preco:%f    Estoque:%d\n",i,produto[i],preco[i],estoque[i]);
			break;		
			case 4:
						//exclusao de produtos
						for(i=0;i<contpro;i++)
						 printf("Produto %d-%s\n",i,produto[i]);
						do
						{
							printf("Qual produto deseja excluir(DIGITE O NUMERO) ou digite enter 000 para sair: \n");
						 scanf("%d",&v);
						 if(v!=000)
					   {
									for(i=v;i<contpro-1;i++)
									{
										strcpy(produto[i],produto[i+1]);
										estoque[i]=estoque[i+1];
										preco[i]=preco[i+1];
										printf("Produto excluido!\n");
									}
									contpro--;
					 	 }
						}while(v!=000);
			break;
			case 5:
						//exclusao de clientes
						for(i=0;i<contcli;i++)
						printf("Cliente %d-  %s\n",i,cliente[i]);
					 do 
						{
							printf("Qual cliente deseja excluir(DIGITE O NUMERO) ou digite 000 para sair:\n ");
						 scanf("%d",&v);
						 if(v=000)
						 {
							 for(i=v;i<contcli-1;i++)
									strcpy(cliente[i],cliente[i+1]);
								contcli--;		
							}
						}
						while(v!=000);
			break;
			}		 
		}
		getch();
	}
	 */
	
	

