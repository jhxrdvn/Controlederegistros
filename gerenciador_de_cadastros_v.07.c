#include <stdio.h> //Biblio comunicação usuário
#include <stdlib.h>  //Bibllio de alocação de espaço em mem. (bd)
#include <locale.h> //Bibilio de alocações de texto por região
#include <string.h> //Bibblio responsável por tratar das strings

int registrar() //Opção 1 (Cadastro de usuário)
{
	//Criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char setor[40];
	//Final criação de variáveis/string
	
	
	printf("Por favor, digite o CPF a ser cadastrado: "); //Coletando informção do usuário
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //FILE = BIBLIOTECA PARA CRIAR O ARQUIVO 
	file = fopen(arquivo,"w"); //Função que abre(fopen) e escreve ("w") o arquivo
	fprintf(file,cpf); //Salvo valor da variável
	fclose(file); //Função para fechar o arquivo que estava sendo lido
	
	file = fopen(arquivo, "a"); //FUNÇAO PARA ATUALIZAR ("a") O ARQUIVO
	fprintf(file, ",");	
	fclose(file); //Função para fechar o arquivo que estava sendo lido
	
	printf("Por favor, digite o nome a ser cadastrado: "); //Coletando informção do usuário
	scanf("%s",nome);//%s se refere a string
	
	file = fopen(arquivo, "a"); //FUNÇAO PARA ATUALIZAR ("a") O ARQUIVO
	fprintf(file,nome);
	fclose(file); //Função para fechar o arquivo que estava sendo lido
	
	file = fopen(arquivo, "a"); //FUNÇAO PARA ATUALIZAR ("a") O ARQUIVO
	fprintf(file,",");
	fclose(file); //Função para fechar o arquivo que estava sendo lido
	
	printf("Por favor, digite o sobrenome a ser cadastrado: "); //Coletando informção do usuário
	scanf("%s",sobrenome);//%s se refere a string
	
	file = fopen(arquivo, "a"); //FUNÇAO PARA ATUALIZAR ("a") O ARQUIVO
	fprintf(file,sobrenome);
	fclose(file); //Função para fechar o arquivo que estava sendo lido
	
	file = fopen(arquivo, "a"); //FUNÇAO PARA ATUALIZAR ("a") O ARQUIVO
	fprintf(file,",");
	fclose(file); //Função para fechar o arquivo que estava sendo lido
	
	printf("Por favor, digite o setor a ser cadastrado: "); //Coletando informção do usuário
	scanf("%s",setor);//%s se refere a string
	
	file = fopen(arquivo, "a"); //FUNÇAO PARA ATUALIZAR ("a") O ARQUIVO
	fprintf(file,setor);
	fclose(file); //Função para fechar o arquivo que estava sendo lido

	system("cls");
	printf("\n\nUsuário registrado com sucesso!\n\n");
	system("pause");
	system("cls");
}

int consultar() //Opção 2 (Consultar cadastro)
{
    setlocale(LC_ALL, "Portuguese"); //Lingaguem

	//Criação variáveis/string
    char cpf[40];
    char conteudo[200];
    //Fim criação variável/string

    printf("Por favor, digite o CPF a ser consultado: "); //Coletando informção do usuário
    scanf("%s", cpf); //%s se refere a string

    FILE *file;
    file = fopen(cpf, "r"); //Função para ler o arquivo

    if(file == NULL)
    {
        printf("CPF não encontrado. \n");//Mensagem se CPF não for encontrado
        system("pause");
    }
    else
    {
        while(fgets(conteudo, 200, file) != NULL)
        {
            char *token; //VARIÁVEL USADA PARA ARMAZENAR CADA SUBSTRING DA VARIAVEL "CONTEUDO" SEPARADA PELO CARACTERE " , "
            
            printf("\n Registro encontrado para o CPF digitado: \n\n");//Mensagem se o CPF digitado existir.
            
            token = strtok(conteudo, ",");//CAPTURA STRING DA VARIAVEL CONTEUDO, MENOS O " , "
            printf("CPF: %s\n", token);//CPF
            
            token = strtok(NULL, ",");
            printf("NOME: %s\n", token);//NOME
            
            token = strtok(NULL, ",");
            printf("SOBRENOME: %s\n", token);//SOBRENOME
            
            token = strtok(NULL, ",");
            printf("SETOR: %s\n", token);//SETOR
        }
        system("\n pause");
        system("cls");
    }

    fclose(file); //Função para fechar o arquivo que estava sendo lido
}

int deletar() //Opção 3 (Deletar cadastro)
{
	setlocale(LC_ALL, "Portuguese"); //Lingaguem
	
	//Criação variável/string
	char cpf[40];
	//Fim criação variável/string
	
	printf("Por favor, digite o CPF que deseja excluir: "); //Coletando informção do usuário
	scanf("%s",cpf); //%s se refere a string
	
	FILE *file;
	file = fopen(cpf, "r"); //FUNÇAO PARA LER ("r") O ARQUIVO
	
	if(file == NULL)
	{
		printf("\n CPF não encontrado. \n\n"); //Mensagem caso CPF não seja encontrado
		system("pause");
	}
	else
	{
		fclose(file);//Função para fechar o arquivo que estava sendo lido
		remove(cpf); //Função que remove o CPF encontrado
		printf("\n\nCPF foi encontrado e excluído com sucesso! \n\n\n"); //Mensagem caso CPF seja encontrado e deletado
		system("pause");
		system("cls");
	}
}


int main() //Menu inicial
{
	//Criação de variáveis
	int opcao=0; 
	int inf=1;
	char senhadigitada[10]="a";
	int comparacao; //variável para comparar duas variáveis e verificar se possuem o mesmo número.
	
	//Fim criação variáveis
	
	printf(" --------------------------\n");
	printf("|  GERENCIADOR DE CADASTROS |\n");
	printf(" --------------------------\n\n");
	printf("## Login de administrador ##\n\n");
	printf("Digite sua senha: "); //solicita senha de acesso adm
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");//função comparação de strings
	
	if(comparacao == 0)
	{
		system("cls");
		
		for(inf=1; inf=1;)
		{

			setlocale(LC_ALL, "Portuguese"); //Lingaguem
	
			//início menu
			printf(" --------------------------\n");
			printf("|  GERENCIADOR DE CADASTROS   |\n");
			printf(" --------------------------\n\n");
			printf("Bem-vindo(a). Escolha uma opção: \n\n");
			printf("1 - Registrar usuário(s)\n");
			printf("2 - Consultar usuário(s)\n");
			printf("3 - Deletar usuário(s)\n");
			printf("4 - Sair\n\n");
		
			printf(" -------------------------------------------------------------\n");
			printf("| Esse Software é propriedade de 'Jhordan Ademir dos Santos'. |\n");
			printf(" -------------------------------------------------------------\n\n");
			printf("Opção: "); 
			//fim menu
	
			scanf("%d" , &opcao); //armazenando resposta
		
			system("cls"); //Responsável por limpar a tela
		
			switch(opcao) //Início seleção do menu
			{
				case 1:
				registrar(); //Chamada de funções
				break;
			
				case 2:
				consultar();
				break;
			
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema! Até logo :) \n\n");
				return 0;
				break;
				
				default:
				printf("Opção inválida!\n");
				system("pause");
				break;	
			}	//fim da escolha
		}
	}
	
	else
		printf("\nSenha incorreta!");
}
