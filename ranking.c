// Estou alterando algumas coisas pois não está compilando
// Lógica: criei uma struct que lerá o arquivo de ranking e salvará as informaçes nela.
// Ao fim do jogo, compara-se a pontuação do jogador com o que está na struct
// Se ele tiver pontuação maior que alguem do ranking ele entra naquela posição
// A struct é escrita no arquivo de ranking


void ranking(double pontuacao, char* nome, Rkg placar){

    FILE *record;
    int i, a, controle;
    double tempP;
    char tempN[50];

    record = fopen("records.txt", "r");

    for (i=0; i<5; i++){
        fgets(tempN,50, record);
        printf("%s", tempN);
        fscanf (record, "%lf ", &placar.p[i]);
        printf("%lf", placar.p[i]);
        printf("\n");

    }

    fclose(record);
    record = fopen("records.txt", "r");
    rewind(record);


   //Identificar uma pontuação menor que a do player
    for (i = 0; i<5; i++){
        if (placar.p[i] <= pontuacao){
            controle = i;
            break;
        }
    }
    fclose(record);
    rewind(record);

    switch (controle){
        case 0: {
            // Salvo o elemento que será substituido e incluo o player no ranking
            tempP = placar.p[i];
            strcpy (tempN, placar.n1);
            strcpy (placar.n1, nome);
            placar.p[i] = pontuacao;
            // Subistituir as outras posições
            for (a = 5; a>(i+1); a++){
                placar. p[a] = placar.p[a-1];
            }
            strcpy (placar.n5, placar.n4);
            strcpy (placar.n4, placar.n3);
            strcpy (placar.n3, placar.n2);
            strcpy (placar.n2, tempN);
            placar.p[i+1] = tempP;
            break;
        }
        case 1: {
            // Salvo o elemento que será substituido e incluo o player no ranking
            tempP = placar.p[i];
            strcpy (tempN, placar.n2);
            strcpy (placar.n2, nome);
            placar.p[i] = pontuacao;
            // Subistituir as outras posições
            for (a = 5; a>(i+1); a++){
                placar. p[a] = placar.p[a-1];
            }
            strcpy (placar.n5, placar.n4);
            strcpy (placar.n4, placar.n3);
            strcpy (placar.n3, tempN);
            placar.p[i+1] = tempP;
            break;
        }
         case 2: {
            // Salvo o elemento que será substituido e incluo o player no ranking
            tempP = placar.p[i];
            strcpy (tempN, placar.n3);
            strcpy (placar.n3, nome);
            placar.p[i] = pontuacao;
            // Subistituir as outras posições
            for (a = 5; a>(i+1); a++){
                placar. p[a] = placar.p[a-1];
            }
            strcpy (placar.n5, placar.n4);
            strcpy (placar.n4, tempN);
            placar.p[i+1] = tempP;
            break;
        }
         case 3: {
                // Salvo o elemento que será substituido e incluo o player no ranking
                tempP = placar.p[i];
                strcpy (tempN, placar.n4);
                strcpy (placar.n4, nome);
                placar.p[i] = pontuacao;
                // Subistituir as outras posições
                for (a = 5; a>(i+1); a++){
                    placar. p[a] = placar.p[a-1];
                }
                strcpy (placar.n5, tempN);
                placar.p[i+1] = tempP;
                break;
            }


         case 4: {
                // Salvo o elemento que será substituido e incluo o player no ranking
                strcpy (placar.n5, nome);
                placar.p[i] = pontuacao;
                break;
            }
        default: {
            printf(" Jogador não entrou no ranking");
            }
    }

    rewind(record);
    record = fopen("records.txt", "w");
    //escrevendo a pontuação e o nome no arquivo
     fprintf(record,"%s", placar.n1);
     fprintf(record, "%lf", placar.p[0]);
     fprintf(record,"%s", placar.n2);
     fprintf(record, "%lf", placar.p[1]);
     fprintf(record,"%s", placar.n3);
     fprintf(record, "%lf", placar.p[2]);
     fprintf(record,"%s", placar.n4);
     fprintf(record, "%lf", placar.p[3]);
     fprintf(record,"%s", placar.n5);
     fprintf(record, "%lf", placar.p[4]);

     fclose(record);
     rewind(record);
     record = fopen("records.txt", "r");

    for (i=0; i<5; i++){
        fgets(tempN,50, record);
        printf("%s", tempN);
        fscanf (record, "%lf", &tempP);
        printf("%lf",tempP);
    }


}
