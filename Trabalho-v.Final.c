#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct{

    char nome[15];
    char raca[20];
    char classe[20];
    char sexo[10];
    int level;
    int forca;
    int def;
    int hp;
    int magia;
    int id;
    int xp;
    int pts;
}personagem;
void menu(personagem P[]);
void criarpersonagem(personagem P[],int *qtd, int *cont);
void mostrarpersonagem(personagem P[],int *qtd);
void localizarpersonagem(personagem P[],int qtd);
void editar(personagem P[],int *qtd);
void deletarpersonagem(personagem P[], int *qtd, int *cont);
void jogar(personagem P[],int qtd);
void criarinimigo(personagem inimigo[]);
void status(personagem inimigo ,personagem aux);
void status2(personagem inimigo , personagem aux, int continimigo, int ponts);
int main()
{
    personagem persona[20];
    menu(persona);
    return 0;
}
void criarpersonagem(personagem P[],int *qtd, int *cont){
    int contnome,i;
    int contagem;
    char sex,clas;
    char race;
        srand(time(NULL));
        personagem aux;

        printf("Digite o nome do personagem [nome menor ou igual 10 caracteres]: ");
        scanf("%s",P[*cont].nome);
        aux = P[*cont];
        contnome=strlen(P[*cont].nome);
        for(i=0;i<*cont;i++){
            if(strcmp(aux.nome, P[i].nome)==0){
                printf("\n\nESSE PERSONAGEM JA EXISTE\n\n");
                menu(P);
            }
        }
        if(contnome>10){
            printf("\n\nNome invalido!!!!!\n\n");
            menu(P);
        }
        printf("Informe o genero do personagem: \n1-Masculino\n2-Feminino\n");
        scanf("%s",&sex);

        contagem=strlen(&sex);

        if(contagem > 1){
            printf("\n\nOPCAO INVALIDA\n\n");
            menu(P);
        }
        switch(sex){
            case '1':
                strcpy(P[*cont].sexo,"Masculino");
                break;
            case '2':
                strcpy(P[*cont].sexo, "Feminino");
                break;
            default:
                printf("\n\nOPCAO INVALIDA\n\n");
                menu(P);

        }
        printf("\n");
        P[*cont].level=1;
        printf("Escolha a raca: \n");
        printf("1-humano\n2-elfo\n3-ogro\n");
        scanf("%s",&race);
        contagem = strlen(&race);
        if(contagem > 1){
            printf("\n\nOPCAO INVALIDA\n\n");
            menu(P);
        }
        switch(race){
            case '1':
                strcpy(P[*cont].raca,"Humano");
                break;
            case '2':
                strcpy(P[*cont].raca,"Elfo");
                break;
            case '3':
                strcpy(P[*cont].raca,"Ogro");
                break;
            default:
                printf("\n\n");
                printf("\n\nOPCAO INVALIDA\n\n");
                menu(P);
        }

        printf("Escolha a classe: \n");
        printf("1-Guerreiro\n2-Arqueiro\n3-Mago\n");
        scanf("%s",&clas);
        contagem=strlen(&clas);
        if(contagem > 1){
            printf("\n\nOPCAO INVALIDA\n\n");
            menu(P);
        }
        switch(clas){
            case '1':
                strcpy(P[*cont].classe,"Guerreiro");
                P[*cont].def=20;
                P[*cont].forca=10;
                P[*cont].magia=0;
                P[*cont].hp=650;
                P[*cont].pts=0;
                break;
            case'2':
                strcpy(P[*cont].classe,"Arqueiro");
                P[*cont].def=15;
                P[*cont].forca=15;
                P[*cont].magia=0;
                P[*cont].hp=550;
                P[*cont].pts=0;
                break;
            case '3':
                strcpy(P[*cont].classe, "Mago");
                P[*cont].def=5;
                P[*cont].magia=25;
                P[*cont].forca=0;
                P[*cont].hp=450;
                P[*cont].pts=0;
                break;
            default:
                printf("\n\nOPCAO INVALIDA\n\n");
                menu(P);
        }
        P[*cont].id = (rand()%100)+1;
        printf("\n\nPERSONAGEM CRIADO COM SUCESSO, SEU ID EH %d\n\n",P[*cont].id);
        *cont = *cont + 1;
        *qtd = *qtd + 1;
        menu(P);


        system("PAUSE");

        system("cls");

}
void mostrarpersonagem(personagem P[],int *qtd){
    int i;

    if(*qtd == 0){
        printf("\n\nNAO HA PERSONAGENS\n\n");
    }

    for(i=0;i<*qtd;i++){
            printf("\n\t\t    \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
                        printf("\t\t    \xBA Nome: %s\n",P[i].nome);
                        printf("\t\t    \xBA Sexo: %s\n",P[i].sexo);
                        printf("\t\t    \xBA Raca: %s\n",P[i].raca);
                        printf("\t\t    \xBA Classe: %s\n",P[i].classe);
                        printf("\t\t    \xBA Level: %d\n",P[i].level);
                        printf("\t\t    \xBA Forca: %d\n",P[i].forca);
                        printf("\t\t    \xBA Defesa: %d\n",P[i].def);
                        printf("\t\t    \xBA Vida: %d\n",P[i].hp);
                        printf("\t\t    \xBA Magia: %d\n",P[i].magia);
                        printf("\t\t    \xBA ID do personagem: %d\n",P[i].id);
                        printf("\t\t    \xBA Maior pontuacao:%d\n",P[i].pts);
            printf("\t\t    \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
            printf("\n\n");



    }


    menu(P);
}

int inteiro(personagem P[],int qtd,int dmc){
    int i;
    for( i=0;i<qtd;i++){
        if( dmc == P[i].id){
            return i;
        }
	}
	return -1;
}

void localizarpersonagem(personagem P[],int qtd){
	int i,acha,achou=0,z;
	system("PAUSE");
	system("cls");
	personagem aux;
	for(i;i<qtd;i++){
		printf("Nome:%s\n",P[i].nome);
		printf("ID:%d\n",P[i].id);
		printf("\n--------------------\n");
	}
	printf("\nDigite o ID do personagem que deseja ver:\n");
	scanf("%d",&acha);
	achou=inteiro(P,qtd,acha);

	  if(achou>=0){
            aux=P[achou];
            printf("Nome: %s\n",aux.nome);
            printf("Sexo: %s\n",aux.sexo);
            printf("Raca: %s\n",aux.raca);
            printf("Classe: %s\n",aux.classe);
            printf("Level: %d\n",aux.level);
            printf("Forca: %d\n",aux.forca);
            printf("Defesa: %d\n",aux.def);
            printf("Vida: %d\n",aux.hp);
            printf("Magia: %d\n",aux.magia);
            printf("ID do personagem: %d\n",P[achou].id);
            printf("Maior pontuacao:%d\n",aux.pts);
            menu(P);

        }else{

            printf("ESSE PERSONAGEM NAO EXISTE\n\n");
            menu(P);
        }

}

void jogar(personagem P[],int qtd){
    int saida,pegarid,ataque,num,i;
    int continimigo,ponts;
    continimigo = 0;
    ponts = 0;
    if(qtd == 0){
        printf("\nNAO EXISTEM PERSONAGENS\n");
        menu(P);
    }
    printf("\nEscolha com qual personagem deseja jogar\n");
    printf("\n");
    for(i=0;i<qtd;i++){
        printf("Nome: %s\n",P[i].nome);
        printf("HP: %d\n",P[i].hp);
        printf("Genero: %s\n",P[i].sexo);
        printf("Classe: %s\n",P[i].classe);
        printf("Raca: %s\n",P[i].raca);
        printf("Nivel: %d\n",P[i].level);
        printf("Forca: %d\n",P[i].forca);
        printf("Defesa: %d\n",P[i].def);
        printf("Magia: %d\n",P[i].magia);
        printf("ID: %d\n",P[i].id);
        printf("\n\n");
    }
       printf("digite o id do personagem:\n");
       scanf("%d",&pegarid);
	   personagem aux, inimigo[3];
       pegarid=inteiro(P,qtd,pegarid);
       printf("\nPERSONAGEM %s ESCOLHIDO\n",P[pegarid].nome);
       if(pegarid<0){
        printf("\nPERSONAGEM NAO EXISTE\n");
        menu(P);
       }
       criarinimigo(inimigo);
       aux=P[pegarid];
       personagem auxinimigo;
       auxinimigo=inimigo[rand()%3];
       aux.xp=0;
       do{
            status(auxinimigo , aux);
            printf("1-ataque fisico\n 2-ataque magico\n 3-menu\n");
            scanf("%d",&ataque);
            if(ataque==1){
                    num=rand()%12;
                    if(num==7){
                auxinimigo.hp=auxinimigo.hp-(aux.forca*2);
                    }else{
                auxinimigo.hp=auxinimigo.hp-aux.forca;
                    }
            }else
            if(ataque==2){
                if(num==7){
                  auxinimigo.hp=auxinimigo.hp-(aux.magia*3);
                }else{
                auxinimigo.hp=auxinimigo.hp-aux.magia;
                }
            }
            if(ataque==3){
            		menu(P);
			}
        if(auxinimigo.hp<=0){
           printf("inimigo morto\n");
           continimigo+=1;
           ponts+=100;
           for(i=0;i<qtd;i++){
           	P[pegarid].pts=ponts;
           	P[pegarid].level+=1;
           	P[pegarid].def+=2;
           	P[pegarid].hp+=20;
           	if(P[pegarid].magia==0){
           		P[pegarid].forca+=3;

			}else{
           		P[pegarid].magia+=2;
			}

		   }
           printf("\n");
           aux.level=aux.level+1;
           aux.xp=aux.xp+100;
           aux.hp=aux.hp+35;
           aux.def=aux.def+10;
           auxinimigo.hp=auxinimigo.hp+50;
           auxinimigo.forca=auxinimigo.forca=20;
           auxinimigo.def=auxinimigo.def+15;

           if(aux.magia==0){
           aux.forca=aux.forca+15;
           }else{
               aux.magia=aux.magia+15;
           }
           auxinimigo=inimigo[rand()%3];
        }else{
            aux.hp=aux.hp-auxinimigo.forca;
        }
        if(aux.hp<=0){
            status2(auxinimigo , aux, continimigo,ponts);
            menu(P);
        }

       }while(aux.hp>=0);


}
void criarinimigo(personagem inimigo[]){
 strcpy(inimigo[0].nome , "inimigo1");
 inimigo[0].hp=100;
 inimigo[0].forca=35;
 inimigo[0].def=10;
 strcpy(inimigo[1].nome , "inimigo2");
 inimigo[1].hp=120;
 inimigo[1].forca=30;
 inimigo[1].def=20;
 strcpy(inimigo[2].nome , "inimigo3");
 inimigo[2].hp=130;
 inimigo[2].forca=45;
 inimigo[2].def=30;

}
void status(personagem inimigo ,personagem aux){
        printf(" _________________________________________ \n");
        printf("|                                         |\n");
        printf("|                  hp %d   xp %d          |\n",aux.hp,aux.xp);
        printf("|                                         |\n");
        printf("|                 jogador                 |\n");
        printf("|                     *                   |\n");
        printf("|                   *-#-*                 |\n");
        printf("|                    * *                  |\n");
        printf("|                                         |\n");
        printf("|                                         |\n");
        printf("|              nivel monster %d           |\n",aux.level);
        printf("|                    hp %d                |\n",inimigo.hp);
        printf("|                     *                   |\n");
        printf("|                    *M*                  |\n");
        printf("|                                         |\n");
        printf("|_________________________________________|\n");
        printf("\n");
}
void status2(personagem inimigo , personagem aux, int continimigo, int ponts){
        printf("                morreu!!!  \n");
        printf("                jogador   \n");
        printf("                  |               \n");
        printf("                --+--             \n");
        printf("                  |                     \n");
        printf("                  |                       \n");
        printf("        GAME OVER                   \n");
        printf("\n");
        printf("quantidade de inimigos mortos %d\n",continimigo);
        printf("Sua pontuacao: %d\n",ponts);
        printf("\n\n");
}
void editar(personagem P[], int *qtd){
    int i, acha,cont;
    char newname[15],op;
    char op2,op3,op4;
    if(*qtd == 0){
        printf("\nNAO EXISTEM PERSONAGENS\n");
        menu(P);
    }
    for(i=0;i<*qtd;i++){
        printf("Nome: %s\n",P[i].nome);
        printf("HP: %d\n",P[i].hp);
        printf("Genero: %s\n",P[i].sexo);
        printf("Classe: %s\n",P[i].classe);
        printf("Raca: %s\n",P[i].raca);
        printf("Nivel: %d\n",P[i].level);
        printf("Forca: %d\n",P[i].forca);
        printf("Defesa: %d\n",P[i].def);
        printf("Magia: %d\n",P[i].magia);
        printf("ID: %d\n",P[i].id);
        printf("\n\n");
    }
    printf("Digite o ID do personagem que deseja editar: ");
    scanf("%d",&acha);
    int aux;
    int achou = 0;
    for(i=0;i<*qtd;i++){
        if(acha == P[i].id){

            achou = 1;
            aux = i;

        }
    }
	if(achou !=1){
		printf("\nESSE PERSONAGEM NAO EXISTE\n");
		menu(P);
	}
    if(achou == 1){
        printf("\nDigite oque deseja editar no personagem selecionado\n");
            printf("1-Nome\n2-Classe\n3-genero\n4-raca\n5-cancelar\n");
            scanf("%s",&op);
            cont = strlen(&op);
            if(cont > 1){
                printf("\nOPCAO INVALIDA\n");
                menu(P);
            }
            switch(op){
                case '1':
                    printf("Deseja Alterar o nome do personagem %s ?",P[aux].nome);
                    printf("\n1-SIM\n2-NAO\n");
                    scanf("%s",&op2);
                    cont = strlen(&op2);
                    if(cont > 1){
                        printf("\nOPCAO INVALIDA\n");
                        menu(P);
                    }
                    switch(op2){
                        case '1':
                            printf("Digite o novo nome: ");
                            scanf("%s",newname);
                            strcpy(P[aux].nome, newname);
                            printf("\n\n");
                            printf("NOME ALTERADO COM SUCESSO\n");
                            menu(P);
                        case '2':
                            menu(P);

                    }
                case '2':
                    printf("Deseja alterar a classe do personagem %s ?",P[aux].nome);
                    printf("\n1-SIM\n2-NAO\n");
                    scanf("%s",&op2);
                    cont = strlen(&op2);
                    if(cont > 1){
                        printf("\nOPCAO INVALIDA\n");
                        menu(P);
                    }
                    switch(op2){
                        case '1':
                            printf("Escolha a classe\n");
                            printf("\n1-Guerreiro\n2-Arqueiro\n3-Mago\n");
                            scanf("%s",&op3);
                            cont = strlen(&op3);
                            if(cont > 1){
                                printf("\nOPCAO INVALIDA\n");
                                menu(P);
                            }
                            switch(op3){
                                case '1':
                                    strcpy(P[i].classe, "Guerreiro");
                                    P[aux].def=20;
                                    P[aux].forca=10;
                                    P[aux].magia=0;
                                    P[aux].hp=600;
                                    P[aux].level=1;
                                    printf("\nTROCA DE CLASSE REALIZADA COM SUCESSO\n");
                                    menu(P);

                                case '2':
                                    strcpy(P[i].classe, "Arqueiro");
                                    P[aux].def=15;
                                    P[aux].forca=15;
                                    P[aux].magia=0;
                                    P[aux].hp=500;
                                    P[aux].level=1;
                                    printf("\nTROCA DE CLASSE REALIZADA COM SUCESSO\n");
                                    menu(P);

                                case '3':
                                    strcpy(P[i].classe, "Mago");
                                    P[aux].def=5;
                                    P[aux].magia=25;
                                    P[aux].forca=0;
                                    P[aux].hp=450;
                                    P[aux].level=1;
                                    printf("\nTROCA DE CLASSE REALIZADA COM SUCESSO\n");
                                    menu(P);

                            }


                    }

                    case '3':
                    printf("\nDeseja alterar o genero do personagem %s?\n",P[aux].nome);
                    printf("\n1-SIM\n2-NAO\n");
                    scanf("%s",&op2);
                    cont = strlen(&op2);
                    if(cont > 1){
                        printf("\nOPCAO INVALIDA\n");
                        menu(P);
                    }
                    switch(op2){
                        case '1':
                            printf("\nEscolha o novo genero do personagem %s\n",P[aux].nome);
                            printf("\n1-Feminino\n2-Masculino\n");
                            scanf("%s",&op3);
                            cont = strlen(&op3);
                            if(cont > 1){
                                printf("\nOPCAO INVALIDA\n");
                                menu(P);
                            }
                            switch(op3){
                                case '1':
                                    strcpy(P[aux].sexo,"Feminino");
                                    printf("\nTROCA DE GENERO REALIZADA COM SUCESSO\n");
                                    menu(P);

                                case '2':
                                    strcpy(P[aux].sexo,"Masculino");
                                    printf("\nTROCA  DE GENERO REALIZADA COM SUCESSO\n");
                                    menu(P);

                            }

                            case '2':
                                printf("\nTroca de genero cancelada\n");
                                menu(P);

                    }



            		case '4':
            			printf("Deseja alterar a raca do personagem %s?\n",P[aux].nome);
            			printf("\n1-SIM\n2-NAO\n");
            			scanf("%s",&op2);
            			cont = strlen(&op2);
            			if(cont > 1){
                            printf("\nOPCAO INVALIDA\n");
                            menu(P);
            			}
            			switch(op2){
            			    case '1':
                                printf("\nEscolha a nova raca do personagem %s\n",P[aux].nome);
                                printf("\n1-HUMANO\n2-ELFO\n3-OGRO\n");
                                scanf("%s",&op4);
                                cont = strlen(&op4);
                                if(cont > 1){
                                    printf("\nOPCAO INVALIDA\n");
                                    menu(P);
                                }
                                switch(op4){
                                    case '1':
                                        strcpy(P[aux].raca,"Humano");
                                        printf("\nTROCA DE RACA REALIZADA COM SUCESSO\n");
                                        menu(P);

                                    case '2':
                                        strcpy(P[aux].raca,"Elfo");
                                        printf("\nTROCA DE RACA REALIZADA COM SUCESSO\n");
                                        menu(P);

                                    case '3':
                                        strcpy(P[aux].raca,"Ogro");
                                        printf("\nTROCA RACA  REALIZADA COM SUCESSO\n");
                                        menu(P);
                                }


                            case '2':
                                printf("\nTroca de raca cancelada\n");
                                menu(P);


            			}
                    case '5':
                        printf("\nEdicao de personagem cancelada\n");
                        menu(P);
                    default:
                        printf("\nOpcao invalida\n");
                        menu(P);

            }

    }else if(achou = 0){
        menu(P);
    }
}


void deletarpersonagem(personagem P[], int *qtd, int *cont){
    int i;
    int ver,contlet,aux,achou;
    char op;
    if(*qtd == 0){
        printf("\nNAO EXISTEM PERSONAGENS\n");
        menu(P);
    }
    for(i=0;i<*qtd;i++){
        printf("Nome: %s\n", P[i].nome);
        printf("ID: %d\n",P[i].id);
        printf("\n\n");
    }
    printf("Informe o ID do personagem que deseja deletar: ");
    scanf("%d",&ver);
    for(i=0;i<*qtd;i++){
        if(ver == P[i].id){
            aux = i;
            achou = 1;
        }

    }
    if(achou == 1){
        printf("Deseja realmente deletar o personagem %s ?",P[aux].nome);
            printf("\n1-SIM\n2-NAO\n");
            scanf("%s",&op);
            contlet = strlen(&op);
            if(contlet > 1){
                printf("\nOPCAO INVALIDA\n");
                menu(P);
            }
            switch(op){
                case '1':
                P[aux] = P[*qtd-1];
                    *qtd = *qtd - 1;
                    *cont = *cont - 1;
                    printf("\n\nPersonagem excluido com sucesso\n\n");
                    menu(P);
                case '2':
                    printf("\n\nFUNCAO CANCELADA\n\n");
                    menu(P);

            }
    }else if(achou != 1){
        printf("\n\nNAO EXISTE PERSONAGEM COM ESSE ID\n\n");
        menu(P);
    }
    menu(P);
}

void menu(personagem P[]){
    char op,canc;
    int contletra=0;
    static int qtd=0;
    static int cont = 0;
    system("PAUSE");
    system("cls");
    printf("\n\n\n");
        printf("\n\t\t    \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\t\t    \xBA                                      \xBA\n");
        printf("\t\t    \xBA BEM VINDO AO HEROES OF ETERNITY      \xBA\n");
        printf("\t\t    \xBA                                      \xBA\n");
        printf("\t\t    \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
		printf("\t\t\t     \xC9\xCD\xCD\xCD\xCD\xCD\xB9 MENU \xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
		printf("\t\t\t     \xBA  1- CRIAR PERSONAGEM     \xBA\n");
		printf("\t\t\t     \xBA  2- JOGAR                \xBA  \n");
		printf("\t\t\t     \xBA  3- MOSTRAR PERSONAGEM   \xBA  \n");
		printf("\t\t\t     \xBA  4- LOCALIZAR PERSONAGEM \xBA  \n");
		printf("\t\t\t     \xBA  5- EDITAR PERSONAGEM    \xBA  \n");
		printf("\t\t\t     \xBA  6- DELETAR PERSONAGEM   \xBA  \n");
		printf("\t\t\t     \xBA  7- SAIR DO JOGO         \xBA  \n");
		printf("\t\t\t     \xBA                          \xBA  \n");
		printf("\t\t\t     \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
		printf("\t\t\t       Digite a opcao: ");
    scanf("%s",&op);
    system("cls");
    contletra=strlen(&op);
    if(contletra>1){
    	printf("\nOPCAO INVALIDA\n");
    	menu(P);
	}
    		switch(op){
        		case '1':
            		criarpersonagem(P,&qtd,&cont);
        		case '2':
            		jogar(P, qtd);
        		case '3':
            		mostrarpersonagem(P,&qtd);
        		case '4':
            		localizarpersonagem(P,qtd);
				case '5':
					editar(P,&qtd);
        		case '6':
            		deletarpersonagem(P,&qtd, &cont);
        		case '7':
        			printf("\nDeseja mesmo sair do jogo?\n");
        			printf("Digite 1 para sair\n");
					printf("Digite 2 para voltar ao menu\n");
        			scanf("%s",&canc);
        			contletra = strlen(&canc);
        			if(contletra > 1){
                        printf("\n\nOPCAO INVALIDA\n\n");
                        menu(P);
        			}
        			switch(canc){
        				case '1':
        					exit(0);
        					break;
						case '2':
							menu(P);
						default:
							printf("\n\nOPCAO INVALIDA\n\n");
							menu(P);

                    }
        		default:
        		printf("\n\nOPCAO INVALIDA\n\n");
        		menu(P);
        }

}



