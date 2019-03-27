
#define NB_DE_VIE_TOTAL 4
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int colonnes;
int lignes;
int nombre_lignes_tableau = 10;
int nombre_colonnes_tableau = 10;
char display[10][10];   //TODO A REMPLACER LE 10
int hidden[10][10];     //TODO A REMPLACER LE 10
int ship_2_block[4][2];
int colonne_cordonnee = 0;
int ligne_cordonnee = 0;
int random_row = 0;
int random_column = 0;
int t;
int vie_du_bateau1 = 0;
int vie_du_bateau2 = 0;
char colonne;



int main() {
    generate2BlockShip();
    displayArray();
    jeu();
}
int jeu() {
    for (lignes = 0;lignes<10;lignes++){
        printf("\n");
        for (colonnes = 0;colonnes<10;colonnes++) {
            printf("%d",hidden[lignes][colonnes]);
        }
    }

    while(vie_du_bateau1+vie_du_bateau2!=NB_DE_VIE_TOTAL) {
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

        if (ship_2_block[0][0] == hidden[ligne_cordonnee]&&ship_2_block[0][1]==hidden[colonne_cordonnee]){
            printf("\n");
            printf("Réussi");
            printf("\n");
        }
        if (hidden[ligne_cordonnee][colonne_cordonnee] == 19){               // 19 = si il deja tiré ou il a raté
            printf("Tu as deja tire ici");

        }

        if (hidden[ligne_cordonnee][colonne_cordonnee]== 20){                //20 = si il a deja tiré sur un bateau
            printf("\nTu as deja tire sur ce bateau");
        }

        if ((hidden[ligne_cordonnee][colonne_cordonnee] == 4) || (hidden[ligne_cordonnee][colonne_cordonnee] == 5)) {
            printf("\nTouche");
            if (hidden[ligne_cordonnee][colonne_cordonnee] == 4) {
                display[ligne_cordonnee][colonne_cordonnee] = 177;
                vie_du_bateau1++;
                hidden[ligne_cordonnee][colonne_cordonnee] = 20;
                if (vie_du_bateau1 == 2){
                    display[ligne_cordonnee][colonne_cordonnee] = 178;    //TODO A TRAVAILLER
                    display[ligne_cordonnee][colonne_cordonnee + 1] = 178;
                    printf(" Coule");
                }

            }
            if (hidden[ligne_cordonnee][colonne_cordonnee] == 5) {
                display[ligne_cordonnee][colonne_cordonnee] = 177;
                vie_du_bateau2++;
                hidden[ligne_cordonnee][colonne_cordonnee] = 20;
                if (vie_du_bateau2 == 2){
                    display[ligne_cordonnee][colonne_cordonnee] = 178;    //TODO A TRAVAILLER
                    display[ligne_cordonnee][colonne_cordonnee + 1] = 178;
                    printf(" Coule");
                }

            }
        }
        if (hidden[ligne_cordonnee][colonne_cordonnee] == 0) {
            printf("\nRate");
            hidden[ligne_cordonnee][colonne_cordonnee] = 19;
            display[ligne_cordonnee][colonne_cordonnee] = 250;
        }



        displayArray();
    }







}
void displayArray(){
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
int generate2BlockShip(){
    for (lignes = 0; lignes < 10; ++lignes) {
        for (colonnes = 0; colonnes <10 ; colonnes++) {
            hidden[lignes][colonnes]= 0;
        }

    }
    int Cycle = 0;
    srand((unsigned)time(&t));
    while ( Cycle < 2){
        random_row = rand() % 10 + 1;   //Generating 2 random numbers
        random_column =rand()% 9 + 1;
        random_row--;
        random_column--;
        printf("\n");
        printf("Colonne random :%d",random_column);
        printf("\n");
        printf("Ligne random : %d",random_row);


        if(hidden[random_row][random_column]==0&&hidden[random_row][random_column+1]==0){
            hidden[random_row][random_column] = ship_number;
            hidden[random_row][random_column + 1] = ship_number ;
            ship_2_block[0][Cycle]= random_row;
            ship_2_block[1][Cycle]= random_column;
            ship_2_block[2][Cycle]= random_row;
            ship_2_block[3][Cycle]= random_column + 1;
            Cycle++;
            ship_number++;

        }
        else{

        }

        printf("\n");
        for (lignes = 0;lignes<4;lignes++){
            printf("\n");
            for (colonnes = 0;colonnes<2;colonnes++) {
                printf("%d",ship_2_block[lignes][colonnes]);
            }
        }
    }
}







