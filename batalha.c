#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct pokemon
    {
        int att, def, hp, numero, velo;
        char nome[15];
        char tipo[15];
    };
    struct play
    {
        int num, vitorias, derrotas;
        char nome[15],nome_poke[5][15];
    };

    typedef struct play Jogador;
    typedef struct pokemon Pokemon;
//arquivo jogadores
    //nome numero vitorias derrotas n°_de_poke poke1 ... pokeN
    int main()
    {
        FILE *arq_j,*arq_p; //ponteiro para o arquivo de jogadores e de pokemons globais


        int escolha=0;
        Jogador player;
        Pokemon poke;
        while(escolha!=5)
        {
           escolha=menu();
            if (escolha == 1 ) //cadastrar jogador
            {
                add_player(&player,&arq_j);
                system("Pause");
                system("cls");
            }
            else if(escolha==2)//lista de jogadores
            {
                lista_de_treinadores(&arq_j,player);
                system("Pause");
                system("cls");
            }
            else if(escolha == 3) //cadastrar pokemons
            {
                add_poke(&poke,&arq_j);
                system("Pause");
                system("cls");
            }
            else if(escolha==4)
            {
                inicia_batalha(arq_j,arq_p);

            }


            }//sai do while
        fclose(arq_j);
        fclose(arq_p);
        return 0;
    }
    int menu(){
        int escolha;
            printf("1 - Cadastrar jogador \n");
            printf("2 - Lista jogadores  \n");
            printf("3 - Cadastrar pokemon \n");
            printf("4 - Batalha \n");
            printf("5 - Sair \n");
            scanf("%i", &escolha);
            return escolha;
    }

    void add_player(Jogador *player,FILE *arq_j)
    {
        arq_j=fopen("info_jogadores.txt","a");
                if(arq_j==NULL) exit(1); //problema no arquivo
                fflush(stdin);
                puts("Digite o nome do Jogador: ");
                gets(player->nome);//como player é um ponteiro e necessario usar -> em vez de .
                printf("Digite o numero deste jogador: ");
                scanf("%d",&player->num);
                player->vitorias=0;//inicia em 0
                player->derrotas=0;
                fprintf(arq_j,"\n%s ",player->nome);
                fprintf(arq_j,"%d ",player->num);
                fprintf(arq_j,"%d ",player->vitorias);
                fprintf(arq_j,"%d ",player->derrotas);
                printf("Quantos pokemons o treinador possiu: ");
                int n_poke;
                scanf("%d",&n_poke);
                fprintf(arq_j,"%d ",n_poke);
                for(int i=0;i<n_poke;i++)
                {
                    printf("Digite o nome do pokemon numero %d: ",i+1);
                    fflush(stdin);
                    gets(player->nome_poke[i]);
                    fprintf(arq_j,"%s ",player->nome_poke[i]);
                }
                fflush(arq_j);//forca gravar os dados agora
    }
    void add_poke(Pokemon* poke,FILE *arq_p)
    {
        arq_p=fopen("info_pokemons.txt","a");//se não existir cria , se existir adiciona ao final
                if(arq_p==NULL) exit(1); //problema no arquivo
                fflush(stdin);
                puts("Digite o nome do Pokemon: ");
                gets(poke->nome);
                fflush(stdin);
                printf("======Atributos======\n");
                puts("Digite o tipo deste pokemon: ");
                gets(poke->tipo);
                printf("ATAQUE: ");
                scanf("%d",&poke->att);
                printf("DEFESA: ");
                scanf("%d",&poke->def);
                printf("HP: ");
                scanf("%d",&poke->hp);
                printf("Numero: ");
                scanf("%d",&poke->numero);
                printf("VELOCIDADE: ");
                scanf("%d",&poke->velo);
                fprintf(arq_p,"%s ",poke->nome);
                fprintf(arq_p,"%s ",poke->tipo);
                fprintf(arq_p,"%d ",poke->numero);
                fprintf(arq_p,"%d ",poke->att);
                fprintf(arq_p,"%d ",poke->def);
                fprintf(arq_p,"%d ",poke->hp);
                fprintf(arq_p,"%d ",poke->velo);
                fflush(arq_p);//forca gravar os dados agora
    }

    void lista_de_treinadores(FILE *arq_j,Jogador player)
    {
        arq_j=fopen("info_jogadores.txt","r");//abre o arquivo em modo leitura
                if(arq_j==NULL) exit(1); //problema no arquivo
                    while(!feof(arq_j)){
                            printf("============================\n");
                fscanf(arq_j,"%s%d%d%d",player.nome,&player.num,&player.vitorias,&player.derrotas);
                printf("%s No:%d V:%d D:%d ",player.nome, player.num, player.vitorias, player.derrotas);
                printf("\nPokemons: ");
                int n_poke;
                fscanf(arq_j,"%d",&n_poke);
                    for(int i=0;i<n_poke;i++)
                    {
                        fscanf(arq_j,"%s ",player.nome_poke);
                        printf("%s ",player.nome_poke);
                    }
                    printf("\n============================\n");
                    }
    }

     void inicia_batalha(FILE* arq_j,FILE* arq_p)
    {

        arq_j=fopen("info_jogadores.txt","r");
        arq_p=fopen("info_pokemons.txt","a");//se não existir cria , se existir adiciona ao final
                if(arq_p==NULL || arq_j==NULL) exit(1);
        Jogador desafiante,oponente,player;//player é temporaria
        int find_d,find_o;//achou desafiante, achou oponente
                fflush(stdin);
                puts("Digite o nome do Desafiante: ");
                gets(desafiante.nome);
                fflush(stdin);
                puts("Digite o nome do Oponente: ");
                gets(oponente.nome);

           while(!feof(arq_j)){
                            //printf("============================\n");
                fscanf(arq_j,"%s%d%d%d",player.nome,&player.num,&player.vitorias,&player.derrotas);
                //printf("%s No:%d V:%d D:%d ",player.nome, player.num, player.vitorias, player.derrotas);
               // printf("\nPokemons: ");
                int n_poke;
                fscanf(arq_j,"%d",&n_poke);
                //printf("%d",n_poke);
                    for(int i=0;i<n_poke;i++)
                    {
                        fscanf(arq_j,"%s ",player.nome_poke);
                        //printf("%s ",player.nome_poke);
                    }
                    //printf("\n============================\n");
                    if(strcmp(player.nome,desafiante.nome)==1)//o nome do desafiante foi encontrado
                        {
                            //a variavel desafiante vai receber os atributos de player
                            desafiante.num=player.num;
                            desafiante.vitorias=player.vitorias;
                            desafiante.derrotas=player.derrotas;
                            strcpy(desafiante.nome_poke,player.nome_poke);
                            find_d=1;
                        }

                        if(strcmp(player.nome,oponente.nome)==1)//o nome do oponente foi encontrado
                        {
                            //a variavel oponente vai receber os atributos de player
                            oponente.num=player.num;
                            oponente.vitorias=player.vitorias;
                            oponente.derrotas=player.derrotas;
                            strcpy(oponente.nome_poke,player.nome_poke);
                            find_o=1;
                        }
                    }
                    if(find_d!=1 ||find_o!=1)
                        printf("Desafiante ou oponente nao encontrado!\n");
                    }



