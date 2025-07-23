
#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string
int registro() //função resposavel por cadastrar os usuários no sistemas
{
	//inicio criação e variáveis/string
   char arquivo [40];
   char cpf[40];
   char nome [40];
   char sobrenome [40];
   char cargo[40];
   //final da criação e variáveis
   
   printf("Digite o CPF A ser cadastrado:"); //colentando informação do usuário
   scanf("%s", cpf); //%s refere-se a string
   
   strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings 
   
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");	//cria o arquivo "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo "a" significa atualizar
	fprintf(file,","); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");// registra o nome que vai ser cadastrado
	scanf("%s" ,nome);// refere-se a string
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,nome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen (arquivo, "a");//cria o arquivo
	fprintf(file, ",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//sobrenome que vai ser cadastrado
	scanf("%s",sobrenome);//refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,sobrenome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen (arquivo, "a");//cria o arquivo
	fprintf(file, ",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//registra o cargo no sistema
	scanf("%s", cargo);//refere-se a string
	
	file = fopen (arquivo, "a");//cria o arquivo
	fprintf(file,cargo);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	system("pause");
}

int consulta()
{
	  setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//consulta no sistema o CPF
	scanf("%s",cpf);//refere a string
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");//cria o arquivo "r" significa ler
	
	if(file == NULL)//quando não for localizado, ele volta para pagina inicial
	{
		printf("Não foi possivel abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file ) != NULL) //while = enquanto
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");//pausa a execução do programa até que o usuário aperte alguma tecla
	
    
    
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //string conjunto de variavel
	
	remove(cpf);//remove o arquivo
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");//cria o arquivo
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
}



int main()



    {
 	int opcao=0; //definindo as variaveis
 	int laco=1;
 	
 	for(laco=1;laco=1;)
 	{
	 
	 
	    system("cls"); //responsavel por limpar a tela
 	    setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
    
        printf("### Cartório da Ebac ###\n\n"); // inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n"); // o \n pula linha 
	    printf("\t1 - Registrar nomes\n"); //t da um espaco no comeco
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("opcao: "); //fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuario

        system("cls");//responsavel por limpar a tela
        
        
        switch(opcao)
		{
		case 1:
        registro();
		break;
				
		case 2:
	    consulta();
		break;
					
		case 3:
	    deletar();
		break;
		
			
		default:
		printf("Essa opção não está disponível!\n");
		system("pause");
		break; //fim da sessao
		}
		
}
}
    
