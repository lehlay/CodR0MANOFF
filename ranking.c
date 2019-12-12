// Estou alterando algumas coisas pois não está compilando
// Lógica: criei uma struct que lerá o arquivo de ranking e salvará as informaçes nela.
// Ao fim do jogo, compara-se a pontuação do jogador com o que está na struct
// Se ele tiver pontuação maior que alguem do ranking ele entra naquela posição
// A struct é escrita no arquivo de ranking


void ranking(double pontuacao, char* nome, Rkg placar){
 printf("teste aisjaosjiaopjsopa");

    FILE *record;
    int i, a;
    double tempP;
    char tempN[50];

    record = fopen("records.txt", "r");
 printf("teste aisjaosjiaopjsopa");

    for (i=0; i<5; i++){
        fgets(tempN,50, record);
        printf("%s", tempN);
        fscanf (record, "%lf", &placar.p[i]);
        printf("%lf", placar.p[i]);
    }

   rewind(record);

    for (i = 0; i<5; i++){
        if ((placar.p[i]) <=pontuacao){
            tempP = placar.p[i];
            strcpy (tempN, placar.n[i][0]);
            strcpy (placar.n[i][0], nome);
            placar.p[i] = pontuacao;

            for ( a = 5; a>(i+1); a++){
                strcpy (placar.n[a][0], placar.n[a-1][0]);
               placar. p[a] = placar.p[a-1];
            }

            strcpy (placar.n[i+1][0], tempN);
            placar.p[i+1] = tempP;
            break;
        }
    }

    rewind(record);


    //escrevendo a pontuação e o nome no arquivo
    for (i=0; i<5; i++){
         fprintf(record,"%s", placar.n[i][0]);
         fprintf(record, "%lf", placar.p[i]);
    }

    fclose(record);

    for (i=0; i<5; i++){
        printf("%s", placar.n[i][0]);
        printf("%lf", placar.p[i]);
    }


}
