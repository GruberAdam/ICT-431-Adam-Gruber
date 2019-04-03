//Adam Gruber
//28.03.2019
//Version 1.0
//Bataille Navale
#define NB_DE_BATEAUX 4
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma  execution_character_set("utf-8")
int nombre_de_bateaux_coule = 0;
int colonnes;
int lignes;
int nombre_lignes_tableau = 10;
int nombre_colonnes_tableau = 10;
char display[10][10];   //TODO A REMPLACER LE 10
int hidden[10][10];     //TODO A REMPLACER LE 10
int ship_2_block[4][4];
int colonne_cordonnee = 0;
int ligne_cordonnee = 0;
int random_row = 0;
int random_column = 0;
int t;
int vie_du_bateau1 = 0;
int vie_du_bateau2 = 0;
char colonne;
int displayComp [8];
int z;
float temps;
clock_t t1, t2;



int main() {
    printf("%d",CLOCKS_PER_SEC);



    t1 = clock();

    score();
    generateShips();
    displayArray();
    game();
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("\ntemps = %f\n", temps);

    scanf("%d");
}
int game() {
    for (lignes = 0;lignes<10;lignes++){
        printf("\n");
        for (colonnes = 0;colonnes<10;colonnes++) {
            printf("%d",hidden[lignes][colonnes]);
        }
    }

    while(nombre_de_bateaux_coule!=NB_DE_BATEAUX) {
        ligne_cordonnee = 0;
        colonne_cordonnee = 0;
        while ((ligne_cordonnee < 1) || ((ligne_cordonnee > 10)) || (colonne_cordonnee > 10) ||
               (colonne_cordonnee < 1)) {     //To avoid numbers going higher than 10 or lower than 1
            printf("\n");
            printf("Ligne :");
            scanf("%d", &ligne_cordonnee);

            do {
                colonne_cordonnee = 0;
                printf("Entrez la colonne ENTRE A - J:");
                scanf("%s", &colonne);
                colonne_cordonnee = colonne;
                if (colonne_cordonnee > 74) {
                    colonne_cordonnee = colonne_cordonnee - 32;
                }
                colonne_cordonnee = colonne_cordonnee - 64;
            }
            while(colonne_cordonnee>10);
        }


        colonne_cordonnee--;
        ligne_cordonnee--;

        printf("\n\n\n\n\n\n\n\n\n\n");

        if (hidden[ligne_cordonnee][colonne_cordonnee] == 0) {
            display[ligne_cordonnee][colonne_cordonnee] = 250;
        }
        if (display[ligne_cordonnee][colonne_cordonnee] + 256 == 178) {

        }
        else {
            if (hidden[ligne_cordonnee][colonne_cordonnee] !=0) {
                display[ligne_cordonnee][colonne_cordonnee] = 177;

            }

        }
        z=0;
        while (z<4) {
            //printf("begin:%d",z);
            displayComp[1] = display[ship_2_block[0][z]][ship_2_block[1][z]] + 256;
            displayComp[2] = display[ship_2_block[2][z]][ship_2_block[3][z]] + 256;
            //printf("\nASIC Value1: %d",displayComp[1]);
            //printf("\nASIC Value2: %d",displayComp[2]);
            if ((displayComp[1] == 177) && (displayComp[2] == 177)) {
                //printf("\nMATCH");
                //printf("\nASIC Value: %d",displayComp[1]);
                //printf("\nASIC Value2: %d",displayComp[2]);
                display[ship_2_block[0][z]][ship_2_block[1][z]] = 178;
                display[ship_2_block[2][z]][ship_2_block[3][z]] = 178;
                printf("End%d",z);
                nombre_de_bateaux_coule++;

            }
            z++;
        }








        displayArray();
    }







}

int displayArray(){
    printf("\nNombre de bateaux existants :%d\n",NB_DE_BATEAUX);
    printf("Nombre de bateaux coule     :%d\n",nombre_de_bateaux_coule);
    printf("\n %c = Rate   %c = Touche    %c = Coule",250,177,178);



    printf("\n\n             A   B   C   D   E   F   G   H   I   J \n           ");    //Print Comment line
    printf("%c""%c", 218, 196);                                                           //Print Header of 1st line

    for (int j = 0; j < 9; j++) {                                                           //Print Content of 1st line
        printf("%c""%c""%c""%c", 196, 196, 194, 196);
    }
    printf("%c""%c""%c""\n", 196, 196, 191);                                          //Print trailer of first line

    for (int i = 0; i < 10; i++) {                                                          //Print Numbering
        printf("        ");
        printf("%d", i + 1);

        if (i < 9) { printf("  "); }                                             //Numbering < 10
        else { printf(" "); }                                             //Numbering >= 10

        //Print Grid
        for (int j = 0; j < 10; j++) {
            printf("%c", 179);
            printf(" ""%c"" ",display[i][j]);                                                    //Print the content
        }
        printf("%c""\n", 179);
    }
    printf("           ");
    printf("%c", 192);
    printf("%c", 196);

    for (int j = 0; j < 9; j++) {                                                           //Print last line
        printf("%c""%c""%c""%c", 196, 196, 193, 196);
    }
    printf("%c""%c""%c""\n", 196, 196, 217);

}
int ship_number = 4;

int generate2BlockShipHorizontal() {
    for (lignes = 0; lignes < 10; ++lignes) {
        for (colonnes = 0; colonnes < 10; colonnes++) {
            hidden[lignes][colonnes] = 0;
        }

    }
    int Cycle = 0;
    srand((unsigned) time(&t));
    while (Cycle < 4) {
        random_row = rand() % 10;   //Generating 2 random numbers
        random_column = rand() % 9;


        if (hidden[random_row][random_column] == 0 && hidden[random_row][random_column + 1] == 0) {
            hidden[random_row][random_column] = ship_number;
            hidden[random_row][random_column + 1] = ship_number;
            ship_2_block[0][Cycle] = random_row;
            ship_2_block[1][Cycle] = random_column;
            ship_2_block[2][Cycle] = random_row;
            ship_2_block[3][Cycle] = random_column + 1;
            Cycle++;
            ship_number++;

        } else {

        }

        printf("\n");
        for (lignes = 0; lignes < 4; lignes++) {
            printf("\n");
            for (colonnes = 0; colonnes < 2; colonnes++) {
                printf("%d", ship_2_block[lignes][colonnes]);
            }
        }
    }
}

int score(){
    char pirate[256]="EStebaNO";

    FILE*SCORE;
    SCORE=fopen("Score.txt", "r+");
    fprintf(SCORE,"%s""\n",pirate);
    fclose(SCORE);
}

int generateShips(){
    generate2BlockShipHorizontal();

}

