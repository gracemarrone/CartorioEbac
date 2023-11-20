#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço da memória
#include <locale.h> // biblioteca de localização da região para interpretação de textos
#include <string.h> // biblioteca que trabalha com strings

// CRIANDO FUNÇÕES QUE SERÃO UTILIZADAS AO LONGO DO SISTEMA SERÃO SEPARADAS EM 3 BLOCOS DE FUNÇÃO REGISTRO / CONSULTA / EXCLUIR

int registrar()
{
	setlocale(LC_ALL,"portuguese");
	printf("VOCÊ ESCOLHEU A OPÇÃO REGISTRAR NOMES\n\n");
	
	// Declaração das variáveis do tipo string
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	//primeiro é necessário criar um arquivo para armazenar as informações, para isso iremos criar uma variável chamada arquivo
	char arquivo [40];
	
	//perguntar as informações
	//a primeira informação que será cadastrada e não deve se repetir será o cpf, então ele também será linkado ao nome do arquivo de banco de dados
	printf("Digite o cpf que será cadastrado:");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); // Responsável por criar uma cópia da string cpf e envia-la para o string arquivo armazenar
	
	FILE *file; // cria um arquivo para servir de banco de dados
	file = fopen(arquivo,"w"); // cria e abre o arquivo para escrever as informações 
	fprintf(file,cpf); // gravar no file (criado) o cpf
	fclose(file); // fecha o file

	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome que será cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome que será cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo que será cadastrado:");
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
	char conteudo [200]; // variável que irá armazenar o contéudo do arquivo
	
	printf("Digite o CPF que deseja consultar:\n\n");
	scanf("%s",cpf);
	
	// procura o arquvivo dentro da estrutura FILE que está localizada dentro da biblioteca stdlib
	FILE *file; 
	file = fopen(cpf,"r"); //file recebe comando para abrir cpf no modo leitura
	
	if (file == NULL)
	{
		printf("O CPF digite não foi localizado.");
	}
	
	while (fgets(conteudo,200,file) != NULL)
	{
		printf("As informações do CPF digitado são:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");	
}

int excluir()
{
	setlocale(LC_ALL,"portuguese"); 
	
	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja excluir do sistema:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\n");
		printf("Cliente não localizado no sistema.\n \n");		
	}
	else
	{
		remove(cpf); //função que irá excluir o arquvio
		printf("Cliente excluído com sucesso.\n\n");
	}
	system ("pause");
}


// CRIAÇÃO DA FUNÇÃO PRINCIPAL

int main()
{
	setlocale(LC_ALL,"portuguese"); // inserindo a localização de acordo com a região
	
	int opcao=0; // alocação de espaço na memória da variável opção
	int laco=1;
	
	// INÍCIO LAÇO DE REPETIÇÃO
	for(laco=1; laco=1;)
	{
		system("cls");
		
		// INÍCO DO MENU
		printf("########## CARTÓRIO DA EBAC ##########\n\n\n");
		printf("Escolha uma das opções do menu abaixo:\n\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Excluir nomes\n");
		printf("\n\tOpção:");	
		
		// FIM DO MENU
			
		scanf("%d",&opcao); // escanear a escolha do usuário
		
		system("cls");
		
		// INÍCIO DO PROCESSO DE SELEÇÃO DO USUÁRIO
		
		switch(opcao)
		{
			case 1:
				registrar(); //chamando a função registrar
				break;
			case 2:
				consultar(); //chamando a função consultar
				break;
			case 3:
				excluir(); //chamdndo a função excluir
				break;
			default:
				printf("Está opção não está disponível\n\n");
				system("pause");
		}
		

				
		// FIM DO PROCESSO DE SELEÇÃO
		
	} 
	// FIM DO LAÇO DE REPETIÇÃO	
		
}

