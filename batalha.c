#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INVALIDO -1

    struct pokemon
    {
        int att, def, hp, numero, velo;
        char nome[15],treinador[15];
        char tipo[15];
    };
    struct play
    {
        int num, vitorias, derrotas;
        char nome[15];
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
        while(1)
        {
           escolha=menu();
            if (escolha == 1 ) //cadastrar jogador
            {
                add_player(&player,&arq_j,1);
                system("Pause");
                system("cls");
            }
            else if(escolha==2)//lista de jogadores
            {
                lista_de_treinadores(&arq_j,&arq_p,player);
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
            if(escolha==5)
                break;
            if(escolha==6){
               arq_j=fopen("info_jogadores.txt","w");
               arq_p=fopen("pokedex.txt","w");
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

    void add_player(Jogador *player,FILE *arq_j,int controle)
    {
        arq_j=fopen("info_jogadores.txt","a+");
        if(controle==1)
            {
                if(arq_j==NULL) exit(1); //problema no arquivo
                fflush(stdin);
                puts("Digite o nome do Jogador: ");
                gets(player->nome);//como player é um ponteiro e necessario usar -> em vez de .
                printf("Digite o numero deste jogador: ");
                scanf("%d",&player->num);
                player->vitorias=0;//inicia em 0
                player->derrotas=0;
                }
                fprintf(arq_j,"%s ",player->nome);
                fprintf(arq_j,"%d ",player->num);
                fprintf(arq_j,"%d ",player->vitorias);
                fprintf(arq_j,"%d ",player->derrotas);
                fprintf(arq_j,"\n");
                fflush(arq_j);//forca gravar os dados agora
    }
    void add_poke(Pokemon* poke,FILE *arq_p)
    {
        arq_p=fopen("pokedex.txt","a+");//se não existir cria , se existir adiciona ao final
                if(arq_p==NULL) exit(1); //problema no arquivo
                fflush(stdin);
                puts("Digite o nome do Pokemon: ");
                gets(poke->nome);
                fflush(stdin);
                puts("Digite o nome do Treinador: ");
                gets(poke->treinador);
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
                //salvando info no arquivo pokedex
                fprintf(arq_p,"%s ",poke->treinador);
                fprintf(arq_p,"%s ",poke->nome);
                fprintf(arq_p,"%s ",poke->tipo);
                fprintf(arq_p,"%d ",poke->numero);
                fprintf(arq_p,"%d ",poke->att);
                fprintf(arq_p,"%d ",poke->def);
                fprintf(arq_p,"%d ",poke->hp);
                fprintf(arq_p,"%d ",poke->velo);
                fprintf(arq_p,"\n");
                fflush(arq_p);//forca gravar os dados agora
    }

    void lista_de_treinadores(FILE *arq_j,FILE *arq_p,Jogador player)
    {
        arq_j=fopen("info_jogadores.txt","r");//abre o arquivo em modo leitura

                if(arq_j==NULL) exit(1); //problema no arquivo
                    while(!feof(arq_j)){
                printf("============================\n");
                fscanf(arq_j,"%s%d%d%d\n",player.nome,&player.num,&player.vitorias,&player.derrotas);
                printf("%s No:%d V:%d D:%d \n",player.nome, player.num, player.vitorias, player.derrotas);
                Pokemon temp;
                printf("Pokemons:\n");

                arq_p=fopen("pokedex.txt","r");
                while(!feof(arq_p)){//procura os pokemons no arquivo pokedex
                fscanf(arq_p,"%s %s %s %d",temp.treinador,temp.nome,temp.tipo,&temp.numero);
                fscanf(arq_p,"%d %d %d %d\n",&temp.att,&temp.def,&temp.hp,&temp.velo);
                if(strcmp(temp.treinador,player.nome)==0)//se o treinador desse pokemon tem o mesmo nome do treinador atual
                    printf("->%s Tipo:%s\n",temp.nome,temp.tipo);//mostra qual é o pokemon e seu tipo
                }

                printf("\n============================\n");
                    }
                    fclose(arq_j);
                    fclose(arq_p);
    }

     int inicia_batalha(FILE* arq_j,FILE* arq_p)
    {

        arq_j=fopen("info_jogadores.txt","r+");
        //arq_p=fopen("pokedex.txt","a+");//se não existir cria , se existir adiciona ao final
                if(arq_p==NULL || arq_j==NULL) exit(1);
        Jogador desafiante,oponente,player;//player é temporaria
        int find_d,find_o;//achou desafiante, achou oponente
        int poke_desafiante,poke_oponente;
                fflush(stdin);
                puts("Digite o nome do Desafiante: ");
                gets(desafiante.nome);
                fflush(stdin);
                puts("Digite o nome do Oponente: ");
                gets(oponente.nome);
                if(strcmp(desafiante.nome,oponente.nome)==0)
                {
                    printf("\n%s nao pode batalhar com ele mesmo\n",desafiante.nome);
                    return 0;
                }
                while(!feof(arq_j)){


                fscanf(arq_j,"%s %d %d %d\n",player.nome,&player.num,&player.vitorias,&player.derrotas);
                if(strcmp(desafiante.nome,player.nome)==0)
                {
                    desafiante.num=player.num;
                    desafiante.vitorias=player.vitorias;
                    desafiante.derrotas=player.derrotas;
                    find_d=1;
                    //printf("Desafiante: numero%d win%d lost%d\n",desafiante.num,desafiante.vitorias,desafiante.derrotas);
                }
                if(strcmp(oponente.nome,player.nome)==0)
                {
                    oponente.num=player.num;
                    oponente.vitorias=player.vitorias;
                    oponente.derrotas=player.derrotas;
                    find_o=1;
                   // printf("Oponente: numero%d win%d lost%d\n",oponente.num,oponente.vitorias,oponente.derrotas);
                }
                if(find_d==0 || find_o==0)
                {
                    printf("Desafiante e/ou Oponente nao encontrados\n");
                    return 0;
                }
                else
                    system("cls");
                   int ctrl=batalha(desafiante,oponente,&arq_j,&arq_p);
                   if(ctrl==0)
                    {
                        printf("Batalha invalida");
                        return 0;
                    }


               }


    }

    int batalha(Jogador desafiante,Jogador oponente,FILE* arq_j,FILE* arq_p)
    {
        printf("============================\n");
        printf("\t%s Vs %s\n",desafiante.nome,oponente.nome);
        printf("============================\n");
        arq_p=fopen("pokedex.txt","r+");
        int aux_opo=0,aux_desaf=0;
        Pokemon temp;
        Pokemon* poke_desafiante=malloc(sizeof(Pokemon)*aux_desaf);//pokemons do desafiante
        Pokemon*  poke_oponente=malloc(sizeof(Pokemon)*aux_opo);//pokemons do oponente

                while(!feof(arq_p)){//roda ate o fim do arquivo
                fscanf(arq_p,"%s %s %s %d",temp.treinador,temp.nome,temp.tipo,&temp.numero);
                fscanf(arq_p,"%d %d %d %d\n",&temp.att,&temp.def,&temp.hp,&temp.velo);
                //acha os pokemons do desafiante
                if(strcmp(temp.treinador,desafiante.nome)==0)
                {
                   // printf("Nome:%s Treinador:%s Tipo:%s\n",temp.nome,temp.treinador,temp.tipo);
                    aux_desaf++;
                   // printf("alocamento de poke :%d\n",aux_desaf);
                    poke_desafiante = realloc(poke_desafiante,aux_desaf*sizeof(Pokemon));//desafiante agora tem 1 pokemon
                    strcpy(poke_desafiante[aux_desaf-1].nome,temp.nome);//copia o nome do poke
                    strcpy(poke_desafiante[aux_desaf-1].treinador,temp.treinador);//copia o treinador
                    strcpy(poke_desafiante[aux_desaf-1].tipo,temp.tipo);//copia o tipo
                    poke_desafiante[aux_desaf-1].att=temp.att;
                    poke_desafiante[aux_desaf-1].def=temp.def;
                    poke_desafiante[aux_desaf-1].hp=temp.hp;
                    poke_desafiante[aux_desaf-1].velo=temp.velo;


                }

                //acha os pokemons do oponente
                if(strcmp(temp.treinador,oponente.nome)==0)
                    {
                        //printf("Nome:%s Treinador:%s Tipo:%s\n",temp.nome,temp.treinador,temp.tipo);
                    aux_opo++;
                    poke_oponente = realloc(poke_oponente,aux_opo*sizeof(Pokemon));//desafiante agora tem 1 pokemon
                    strcpy(poke_oponente[aux_opo-1].nome,temp.nome);//copia o nome do poke
                    strcpy(poke_oponente[aux_opo-1].treinador,temp.treinador);//copia o treinador
                    strcpy(poke_oponente[aux_opo-1].tipo,temp.tipo);//copia o tipo
                    poke_oponente[aux_opo-1].att=temp.att;
                    poke_oponente[aux_opo-1].def=temp.def;
                    poke_oponente[aux_opo-1].hp=temp.hp;
                    poke_oponente[aux_opo-1].velo=temp.velo;
                    //poke_oponete é o nome da variavel
                    //[aux_opo-1] //index do alocamento dinamico o aux -1 é pq a cada novo ele add 1 mas o inicio é em 0
                    //.velo é o atributo do string POKEMON
                    }
                }//fim do while

                //exibe os pokemons do j1
                printf("%s pokemons:\n",desafiante.nome);
                for(int i=0;i<aux_desaf;i++)
                {
                    printf("Nome:%s Tipo:%s\n",poke_desafiante[i].nome,poke_desafiante[i].tipo);
                }
                //exibe os pokemons do j2
                printf("%s pokemons:\n",oponente.nome);
                for(int i=0;i<aux_opo;i++)
                {
                    printf("Nome:%s Tipo:%s\n",poke_oponente[i].nome,poke_oponente[i].tipo);
                }


                    int poke_batalha;//quantos pokemons o jogador vai usar na batalha

                    printf("%s deseja utilizar quantos pokemons em batalha? ",desafiante.nome);
                    scanf("%d",&poke_batalha);
                    if(poke_batalha>aux_desaf || poke_batalha>5){
                        printf("Numero de pokemons indisponiveis\n");
                        system("Pause");
                        system("cls");
                        return 0;
                        }
                        //*********** achar e prepara para a batalha ******************** //
                        




        system("Pause");
        system("cls");
        return 1;
    }


