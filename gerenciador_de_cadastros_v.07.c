#include <stdio.h> //Biblio comunica��o usu�rio
#include <stdlib.h>  //Bibllio de aloca��o de espa�o em mem. (bd)
#include <locale.h> //Bibilio de aloca��es de texto por regi�o
#include <string.h> //Bibblio respons�vel por tratar das strings

int registrar() //Op��o 1 (Cadastro de usu�rio)
{
	//Cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char setor[40];
	//Final cria��o de vari�veis/string
	
	
	printf("Por favor, digite o CPF a ser cadastrado: "); //Coletando inform��o do usu�rio
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //FILE = BIBLIOTECA PARA CRIAR O ARQUIVO 
	file = fopen(arquivo,"w"); //Fun��o que abre(fopen) e escreve ("w") o arquivo
	fprintf(file,cpf); //Salvo valor da vari�vel
	fclose(file); //Fun��o para fechar o arquivo que estava sendo lido
	
	file = fopen(arquivo, "a"); //FUN�AO PARA ATUALIZAR ("a") O ARQUIVO
	fprintf(file, ",");	
	fclose(file); //Fun��o para fechar o arquivo que estava sendo lido
	
	printf("Por favor, digite o nome a ser cadastrado: "); //Coletando inform��o do usu�rio
	scanf("%s",nome);//%s se refere a string
	
	file = fopen(arquivo, "a"); //FUN�AO PARA ATUALIZAR ("a") O ARQUIVO
	fprintf(file,nome);
	fclose(file); //Fun��o para fechar o arquivo que estava sendo lido
	
	file = fopen(arquivo, "a"); //FUN�AO PARA ATUALIZAR ("a") O ARQUIVO
	fprintf(file,",");
	fclose(file); //Fun��o para fechar o arquivo que estava sendo lido
	
	printf("Por favor, digite o sobrenome a ser cadastrado: "); //Coletando inform��o do usu�rio
	scanf("%s",sobrenome);//%s se refere a string
	
	file = fopen(arquivo, "a"); //FUN�AO PARA ATUALIZAR ("a") O ARQUIVO
	fprintf(file,sobrenome);
	fclose(file); //Fun��o para fechar o arquivo que estava sendo lido
	
	file = fopen(arquivo, "a"); //FUN�AO PARA ATUALIZAR ("a") O ARQUIVO
	fprintf(file,",");
	fclose(file); //Fun��o para fechar o arquivo que estava sendo lido
	
	printf("Por favor, digite o setor a ser cadastrado: "); //Coletando inform��o do usu�rio
	scanf("%s",setor);//%s se refere a string
	
	file = fopen(arquivo, "a"); //FUN�AO PARA ATUALIZAR ("a") O ARQUIVO
	fprintf(file,setor);
	fclose(file); //Fun��o para fechar o arquivo que estava sendo lido

	system("cls");
	printf("\n\nUsu�rio registrado com sucesso!\n\n");
	system("pause");
	system("cls");
}

int consultar() //Op��o 2 (Consultar cadastro)
{
    setlocale(LC_ALL, "Portuguese"); //Lingaguem

	//Cria��o vari�veis/string
    char cpf[40];
    char conteudo[200];
    //Fim cria��o vari�vel/string

    printf("Por favor, digite o CPF a ser consultado: "); //Coletando inform��o do usu�rio
    scanf("%s", cpf); //%s se refere a string

    FILE *file;
    file = fopen(cpf, "r"); //Fun��o para ler o arquivo

    if(file == NULL)
    {
        printf("CPF n�o encontrado. \n");//Mensagem se CPF n�o for encontrado
        system("pause");
    }
    else
    {
        while(fgets(conteudo, 200, file) != NULL)
        {
            char *token; //VARI�VEL USADA PARA ARMAZENAR CADA SUBSTRING DA VARIAVEL "CONTEUDO" SEPARADA PELO CARACTERE " , "
            
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

    fclose(file); //Fun��o para fechar o arquivo que estava sendo lido
}

int deletar() //Op��o 3 (Deletar cadastro)
{
	setlocale(LC_ALL, "Portuguese"); //Lingaguem
	
	//Cria��o vari�vel/string
	char cpf[40];
	//Fim cria��o vari�vel/string
	
	printf("Por favor, digite o CPF que deseja excluir: "); //Coletando inform��o do usu�rio
	scanf("%s",cpf); //%s se refere a string
	
	FILE *file;
	file = fopen(cpf, "r"); //FUN�AO PARA LER ("r") O ARQUIVO
	
	if(file == NULL)
	{
		printf("\n CPF n�o encontrado. \n\n"); //Mensagem caso CPF n�o seja encontrado
		system("pause");
	}
	else
	{
		fclose(file);//Fun��o para fechar o arquivo que estava sendo lido
		remove(cpf); //Fun��o que remove o CPF encontrado
		printf("\n\nCPF foi encontrado e exclu�do com sucesso! \n\n\n"); //Mensagem caso CPF seja encontrado e deletado
		system("pause");
		system("cls");
	}
}


int main() //Menu inicial
{
	//Cria��o de vari�veis
	int opcao=0; 
	int inf=1;
	char senhadigitada[10]="a";
	int comparacao; //vari�vel para comparar duas vari�veis e verificar se possuem o mesmo n�mero.
	
	//Fim cria��o vari�veis
	
	printf(" --------------------------\n");
	printf("|  GERENCIADOR DE CADASTROS |\n");
	printf(" --------------------------\n\n");
	printf("## Login de administrador ##\n\n");
	printf("Digite sua senha: "); //solicita senha de acesso adm
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");//fun��o compara��o de strings
	
	if(comparacao == 0)
	{
		system("cls");
		
		for(inf=1; inf=1;)
		{

			setlocale(LC_ALL, "Portuguese"); //Lingaguem
	
			//in�cio menu
			printf(" --------------------------\n");
			printf("|  GERENCIADOR DE CADASTROS   |\n");
			printf(" --------------------------\n\n");
			printf("Bem-vindo(a). Escolha uma op��o: \n\n");
			printf("1 - Registrar usu�rio(s)\n");
			printf("2 - Consultar usu�rio(s)\n");
			printf("3 - Deletar usu�rio(s)\n");
			printf("4 - Sair\n\n");
		
			printf(" -------------------------------------------------------------\n");
			printf("| Esse Software � propriedade de 'Jhordan Ademir dos Santos'. |\n");
			printf(" -------------------------------------------------------------\n\n");
			printf("Op��o: "); 
			//fim menu
	
			scanf("%d" , &opcao); //armazenando resposta
		
			system("cls"); //Respons�vel por limpar a tela
		
			switch(opcao) //In�cio sele��o do menu
			{
				case 1:
				registrar(); //Chamada de fun��es
				break;
			
				case 2:
				consultar();
				break;
			
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema! At� logo :) \n\n");
				return 0;
				break;
				
				default:
				printf("Op��o inv�lida!\n");
				system("pause");
				break;	
			}	//fim da escolha
		}
	}
	
	else
		printf("\nSenha incorreta!");
}
