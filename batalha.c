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
        int num, vitorias, derrotas,nome_poke[5][15];
        char nome[15];
    };

    typedef struct play Jogador;
    typedef struct pokemon Pokemon;
    FILE *arq_j,*arq_p; //ponteiro para o arquivo de jogadores e de pokemons globais


    int main()
    {
        if(arq_j==NULL || arq_p==NULL) exit(1); //problema no arquivo

        int escolha=1;
        Jogador player;
        Pokemon poke;
        while(escolha!=5)
        {
           escolha=menu();
            if (escolha == 1 ) //cadastrar jogador
            {
                arq_j=fopen("info_jogadores.txt","a");
                fflush(stdin);
                puts("Digite o nome do Jogador: ");
                gets(player.nome);//como player é um ponteiro e necessario usar -> em vez de .
                printf("Digite o numero deste jogador: ");
                scanf("%d",&player.num);
                player.vitorias=0;//inicia em 0
                player.derrotas=0;
                fprintf(arq_j,"\n%s ",player.nome);
                fprintf(arq_j,"%d ",player.num);
                fprintf(arq_j,"%d ",player.vitorias);
                fprintf(arq_j,"%d ",player.derrotas);
                printf("Quantos pokemons o treinador possiu: ");
                int n_poke;
                scanf("%d",&n_poke);
                for(int i=0;i<n_poke;i++)
                {
                    printf("Digite o nome do pokemon numero %d: ",i+1);
                    fflush(stdin);
                    gets(player.nome_poke[i]);
                    fprintf(arq_j,"Nome %i pokemon : %s ",i+1,player.nome);
                }
                fflush(arq_j);//forca gravar os dados agora
                system("Pause");
                system("cls");
            }
            else if(escolha==2)
            {
                arq_j=fopen("info_jogadores.txt","r");//abre o arquivo em modo leitura
                while(!feof(arq_j)) //roda ate o fim do arquivo
                {
                fscanf(arq_j,"%s %d %d %d\n",player.nome,&player.num,&player.vitorias,&player.derrotas);
                printf("%s %d %d %d\n",player.nome,player.num,player.vitorias,player.derrotas);
                }
                system("Pause");
                system("cls");
            }
            else if(escolha == 3) //cadastrar pokemons
            {
                arq_j=fopen("info_jogadores.txt","a");//se não existir cria , se existir adiciona ao final
                fflush(stdin);
                puts("Digite o nome do Pokemon: ");
                gets(poke.nome);
                fflush(stdin);
                printf("======Atributos======\n");
                puts("Digite o tipo deste pokemon: ");
                gets(poke.tipo);
                printf("ATAQUE: ");
                scanf("%d",&poke.att);
                printf("DEFESA: ");
                scanf("%d",&poke.def);
                printf("HP: ");
                scanf("%d",&poke.hp);
                printf("Numero: ");
                scanf("%d",&poke.numero);
                printf("VELOCIDADE: ");
                scanf("%d",&poke.velo);
                fprintf(arq_p,"Nome : %s ",poke.nome);
                fprintf(arq_p,"Tipo: %s ",poke.tipo);
                fprintf(arq_p,"Numero: %d ",poke.numero);
                fprintf(arq_p,"ATK: %d ",poke.att);
                fprintf(arq_p,"DEF: %d ",poke.def);
                fprintf(arq_p,"HP: %d ",poke.hp);
                fprintf(arq_p,"VEL: %d ",poke.velo);
                fflush(arq_p);//forca gravar os dados agora
                system("Pause");
                system("cls");
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


