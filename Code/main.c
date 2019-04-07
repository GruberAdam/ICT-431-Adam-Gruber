//Adam Gruber
//28.03.2019
//Version 1.0
//Bataille Navale
#define NB_DE_BATEAUX 4
#define MAXCHAR 1000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Menu.h"
#pragma  execution_character_set("utf-8")
int nombre_de_bateaux_coule = 0; //Compte le nombre de bateau coulé
int colonnes,lignes; //nb de colonne est de lignes
int colonne_cordonnee = 0,ligne_cordonnee = 0;// Les cordonées
int random_row = 0,random_column = 0;//
char display[10][10];//tableau affiché
int hidden[10][10];//tableau cache
int ship_2_block[4][4];//tableau avec les cordonnées des bateaux
int t,z;
char colonne;//Pour demander la colonne
int displayComp [8];//pour changer la couleur
char nom_pirate;//son nom de pirate
int HighScoreSecondsInt;//pour changer le caractère ascii en int
char HighScoreName[MAXCHAR];//Meilleur joueur (nom)
char HighScoreSeconds[MAXCHAR];//Meilleur joueur (temps)
FILE *fp;//variable txt
char* filename = "Score.txt";//nom du fichier



int main() {
    menu();                     //Apelle la fonction "menu"

    printf("\nQuel est votre nom de pirate :");
    scanf("%s",&nom_pirate);         //Stocke son nom
    score();

    float temps;
    clock_t t1, t2;

    t1 = clock();                //temps au debut
    generateShips();             //Apelle la fonction "generateShips"
    displayArray();              //Apelle la fonction "displayArray"
    game();                      //Apelle la fonction "game"
    t2 = clock();                //temps a la fin
    temps = (int)(t2-t1)/CLOCKS_PER_SEC; //temps échoué pendant le jeu (en secondes)
    printf("\n ton temps = %0.0f secondes\n",temps);

    if (temps<HighScoreSecondsInt){          //Si le temps a été meilleur que le meilleur temps précedent il prend ça place
        fp = fopen(filename, "w");
        fprintf(fp,"%s\n%0.0f",&nom_pirate,temps);
        fclose(fp);
    }
    system("pause");








}
int game() {

    while(nombre_de_bateaux_coule!=NB_DE_BATEAUX) {           //Continue de jouer tant que tout les bateaux ne sont pas coulé
        ligne_cordonnee = 0;
        colonne_cordonnee = 0;
        while ((ligne_cordonnee < 1) || ((ligne_cordonnee > 10)) || (colonne_cordonnee > 10) ||
               (colonne_cordonnee < 1)) {     //To avoid numbers going higher than 10 or lower than 1
            printf("\n");
            printf("Ligne :");
            scanf("%d", &ligne_cordonnee);     //Stocke la ligne dans une varible

            do {
                printf("Entrez la colonne ENTRE A - J:");
                scanf("%s", &colonne);         //stocke la "lettre" dans une varible char
                colonne_cordonnee = colonne;   //convertis la lettre en int donc en ascii
                if (colonne_cordonnee > 90) {     //Si la lettre est plus grand que 90 c'est un miniscule
                    colonne_cordonnee = colonne_cordonnee - 32;  // faire moins 32 pour la rendre en majuscule
                }
                colonne_cordonnee = colonne_cordonnee - 64; // fait -64 pour avoir la colonne
            }
            while(colonne_cordonnee>10);       // Si c'est plus grand que 10 (donc J) il redemande.
        }


        colonne_cordonnee--;         // - 1 pour l'index du tableau
        ligne_cordonnee--;

        printf("\n\n\n\n\n\n\n\n\n\n");

        if (hidden[ligne_cordonnee][colonne_cordonnee] == 0) {          //Si il rate il met la caractère ascii 250(raté)
            display[ligne_cordonnee][colonne_cordonnee] = 250;
        }
        if (display[ligne_cordonnee][colonne_cordonnee] + 256 == 178) {                         //
        }                                                                                       //Si la case n'est pas coulé et que la case n'est pas ratée mettre le caractère ascii 177 (touché)
        else {                                                                                  //
            if (hidden[ligne_cordonnee][colonne_cordonnee] !=0) {                               //
                display[ligne_cordonnee][colonne_cordonnee] = 177;                              //

            }

        }
        z=0;
        while (z<4) {
            displayComp[1] = display[ship_2_block[0][z]][ship_2_block[1][z]] + 256;             //Le statut du bateau en ascii
            displayComp[2] = display[ship_2_block[2][z]][ship_2_block[3][z]] + 256;             //
            if ((displayComp[1] == 177) && (displayComp[2] == 177)) {                         //Si les 2 cases sont touchées elles deviennent le nombre 178 ascii
                display[ship_2_block[0][z]][ship_2_block[1][z]] = 178;
                display[ship_2_block[2][z]][ship_2_block[3][z]] = 178;
                nombre_de_bateaux_coule++;
            }
            z++;
        }








        displayArray();
    }







}

int displayArray(){
    system("CLS");

    printf("\nNombre de bateaux existants :%d\n",NB_DE_BATEAUX);
    printf("Nombre de bateaux coule     :%d\n",nombre_de_bateaux_coule);
    printf("\nMeilleur joueur : %s",HighScoreName);
    printf("Temps en secondes : %d\n",HighScoreSecondsInt);
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
    for (lignes = 0; lignes < 10; ++lignes) {                  //Créer un tableau 10 sur 10 avec des 0 partout
        for (colonnes = 0; colonnes < 10; colonnes++) {        //
            hidden[lignes][colonnes] = 0;                      //
        }                                                      //

    }
    int Cycle = 0;
    srand((unsigned) time(&t));
    while (Cycle < 4) {
        random_row = rand() % 10;   //Génère 2 chiffre aléatoires entre 0 et 10
        random_column = rand() % 9; //Génère 2 chiffre aléatoires entre 0 et 9


        if (hidden[random_row][random_column] == 0 && hidden[random_row][random_column + 1] == 0) {   //Si le bateau a la place pour etre mis il devient 4 dans le tableau caché
            hidden[random_row][random_column] = ship_number;
            hidden[random_row][random_column + 1] = ship_number;
            ship_2_block[0][Cycle] = random_row;           //Stoque la cordonnée dans le tableau ship 2 block
            ship_2_block[1][Cycle] = random_column;
            ship_2_block[2][Cycle] = random_row;
            ship_2_block[3][Cycle] = random_column + 1;
            Cycle++;

        } else {

        }
    }
}



int generateShips(){
    generate2BlockShipHorizontal(); //Apelle la fonction "generate2BlockShipHorizontal"

}
int score(){
    fp = fopen(filename, "r");   // ouvre le fichier en mode "lire"
    if (fp == NULL){             // Si le fichier n'existe pas il sera ouvert en mode "a" (cree un fichier)
        fp = fopen(filename, "a");
        fprintf(fp,"No score set\n9999");     //Ecris "No score set" dans nom et "9999" dans le temps
        fclose(fp);     //ferme le fichier
        fopen(filename,"r"); //L'ouvre en mode "lire"
    }

    fgets(HighScoreName, MAXCHAR, fp);   //Stocke le nom du fichier et les secondes
    fgets(HighScoreSeconds, 20, fp);     //
    HighScoreSecondsInt = atoi(HighScoreSeconds); // Transforme les sencondes en int (atoi = ascii to integer)

    fclose(fp); //ferme le fichier

}
