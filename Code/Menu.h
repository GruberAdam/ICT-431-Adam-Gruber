//Adam Gruber
//28.03.2019
//Version 1.0
//Bataille Navale
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


void menu() {
    int choix;
    do {
        do {
            printf("1 - Jouer\n2 - Regles du jeu\n3 - Options\n4 - Quitter\n");
            printf("Faitez votre choix :");
            scanf("%d", &choix);
            if (choix < 1 || choix > 4) {
                printf("Veuillez choirsir un nombre entre 1 et 4\n\n");
            }
        }
        while (choix < 1 || choix > 4);

        switch (choix) {
            case 1: {
                break;
            }
            case 2: {
                printf("La bataille navale consiste a couler tout les bateaux enemis. Pour cela entrez une ligne (entre 1 et 10)\net une colonne (entre A et J) une fois tous coule essayer de battre le meilleur joueur\n(le score et compte avec le temps mit pour couler les bateaux) \n\n\n");
                break;
            }
            case 3: {
                printf("Options :\n\n\n");
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Vous avez surment entre une lettre donc evitez de faire ca si il vous plait\n\n\n");
                break;
            }
        }

    }
    while (choix != 1);
}





