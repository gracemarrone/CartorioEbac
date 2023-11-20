#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o da mem�ria
#include <locale.h> // biblioteca de localiza��o da regi�o para interpreta��o de textos
#include <string.h> // biblioteca que trabalha com strings

// CRIANDO FUN��ES QUE SER�O UTILIZADAS AO LONGO DO SISTEMA SER�O SEPARADAS EM 3 BLOCOS DE FUN��O REGISTRO / CONSULTA / EXCLUIR

int registrar()
{
	setlocale(LC_ALL,"portuguese");
	printf("VOC� ESCOLHEU A OP��O REGISTRAR NOMES\n\n");
	
	// Declara��o das vari�veis do tipo string
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	//primeiro � necess�rio criar um arquivo para armazenar as informa��es, para isso iremos criar uma vari�vel chamada arquivo
	char arquivo [40];
	
	//perguntar as informa��es
	//a primeira informa��o que ser� cadastrada e n�o deve se repetir ser� o cpf, ent�o ele tamb�m ser� linkado ao nome do arquivo de banco de dados
	printf("Digite o cpf que ser� cadastrado:");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); // Respons�vel por criar uma c�pia da string cpf e envia-la para o string arquivo armazenar
	
	FILE *file; // cria um arquivo para servir de banco de dados
	file = fopen(arquivo,"w"); // cria e abre o arquivo para escrever as informa��es 
	fprintf(file,cpf); // gravar no file (criado) o cpf
	fclose(file); // fecha o file

	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome que ser� cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome que ser� cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo que ser� cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consultar()
{
	setlocale(LC_ALL,"portuguese");
	
	char cpf [40]; 
	char conteudo [200]; // vari�vel que ir� armazenar o cont�udo do arquivo
	
	printf("Digite o CPF que deseja consultar:\n\n");
	scanf("%s",cpf);
	
	// procura o arquvivo dentro da estrutura FILE que est� localizada dentro da biblioteca stdlib
	FILE *file; 
	file = fopen(cpf,"r"); //file recebe comando para abrir cpf no modo leitura
	
	if (file == NULL)
	{
		printf("O CPF digite n�o foi localizado.");
	}
	
	while (fgets(conteudo,200,file) != NULL)
	{
		printf("As informa��es do CPF digitado s�o:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");	
}

int excluir()
{
	setlocale(LC_ALL,"portuguese"); 
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja excluir do sistema:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\n");
		printf("Cliente n�o localizado no sistema.\n \n");		
	}
	else
	{
		remove(cpf); //fun��o que ir� excluir o arquvio
		printf("Cliente exclu�do com sucesso.\n\n");
	}
	system ("pause");
}


// CRIA��O DA FUN��O PRINCIPAL

int main()
{
	setlocale(LC_ALL,"portuguese"); // inserindo a localiza��o de acordo com a regi�o
	
	int opcao=0; // aloca��o de espa�o na mem�ria da vari�vel op��o
	int laco=1;
	
	// IN�CIO LA�O DE REPETI��O
	for(laco=1; laco=1;)
	{
		system("cls");
		
		// IN�CO DO MENU
		printf("########## CART�RIO DA EBAC ##########\n\n\n");
		printf("Escolha uma das op��es do menu abaixo:\n\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Excluir nomes\n");
		printf("\n\tOp��o:");	
		
		// FIM DO MENU
			
		scanf("%d",&opcao); // escanear a escolha do usu�rio
		
		system("cls");
		
		// IN�CIO DO PROCESSO DE SELE��O DO USU�RIO
		
		switch(opcao)
		{
			case 1:
				registrar(); //chamando a fun��o registrar
				break;
			case 2:
				consultar(); //chamando a fun��o consultar
				break;
			case 3:
				excluir(); //chamdndo a fun��o excluir
				break;
			default:
				printf("Est� op��o n�o est� dispon�vel\n\n");
				system("pause");
		}
		

				
		// FIM DO PROCESSO DE SELE��O
		
	} 
	// FIM DO LA�O DE REPETI��O	
		
}

