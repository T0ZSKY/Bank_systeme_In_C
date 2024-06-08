#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define FICHIER_UTILISATEURS "utilisateurs.txt"

void reset() {
    printf("\033[0m");
}


void vert() {
    printf("\033[32m");
}

void rouge() {
    printf("\033[31m");
}

void bleu() {
    printf("\033[34m");
}


int main()
{
    int choix1 = 0;
    char nom[20];
    char mdp[20];
    int solde;
    int mdp_admin = 1234;
    int mdp_entre = 0;
    int mdp_suppr = 4321; 
    int mdp_entre_suppr = 0;


    while (1) { // boucle infinie pour répéter le menu principal


vert();

       printf("###                                                            ###                          ##\n");
printf("##                                                             ##                          ##\n");
printf("##       ####    #####     ######  ##  ##    ####              ##      ##  ##             #####    ####    ##  ##\n");
printf("#####       ##   ##  ##   ##  ##   ##  ##   ##  ##             #####   ##  ##              ##     ##  ##   #######\n");
printf("##  ##   #####   ##  ##   ##  ##   ##  ##   ######             ##  ##  ##  ##              ##     ##  ##   ## # ##\n");
printf("##  ##  ##  ##   ##  ##    #####   ##  ##   ##                 ##  ##   #####              ## ##  ##  ##   ##   ##\n");
printf("######    #####   ##  ##       ##    ######   #####            ######       ##               ###    ####    ##   ##\n");
printf("                               ####                                      #####\n");


bleu();
        printf("1. Creer un compte\n");
        printf("2. Consulter un compte\n");
        printf("3. Panel administrateur\n");
        printf("4. Quitter\n");
        printf("5. Supprimer tout les comptes\n");
        printf("Votre choix : ");

reset();

        scanf("%d", &choix1);

        switch (choix1) {
            case 1:
                system("cls");
                printf("Entrez votre nom: ");
                scanf("%s", nom);
                printf("Entrez votre mot de passe pour votre compte: ");
                scanf("%s", mdp);
                printf("Entrez le solde de depart de votre compte: ");
                scanf("%d", &solde);
                printf("Votre compte a ete cree avec succes\n");

                // Sauvegarder les informations dans le fichier texte
                FILE *fichier = fopen(FICHIER_UTILISATEURS, "a");
                if (fichier) {
                    fprintf(fichier, "%s;%s;%d\n", nom, mdp, solde);
                    fclose(fichier);
                }

                fflush(stdin);
                printf("Appuyez sur une entrer pour continuer...\n");
                getchar();
                system("cls");

                break;

            case 2:
                printf("Entrez votre nom: ");
                scanf("%s", nom);
                printf("Entrez votre mot de passe: ");
                scanf("%s", mdp);

                // Charger les informations à partir du fichier texte
                fichier = fopen(FICHIER_UTILISATEURS, "r");
                if (fichier) {
                    char ligne[1024];
                    int trouve = 0;
                    while (fgets(ligne, 1024, fichier)) {
                        char *token = strtok(ligne, ";");
                        char nom_lu[20];
                        char mdp_lu[20];
                        int solde_lu;
                        strcpy(nom_lu, token);
                        token = strtok(NULL, ";");
                        strcpy(mdp_lu, token);
                        token = strtok(NULL, ";");
                        solde_lu = atoi(token);
                        mdp_lu[strcspn(mdp_lu, "\n")] = 0; // supprimer le caractère de fin de ligne
                        if (strcmp(nom_lu, nom) == 0 && strcmp(mdp_lu, mdp) == 0) {
                            printf("Connexion reussie!\n");
                            printf("Solde du compte : %d\n", solde_lu);
                            trouve = 1;
                            fflush(stdin);
                            printf("Appuyez sur une entrer pour continuer...\n");
                            getchar();
                            system("cls");
                            break;
                        }
                    }
                    if (!trouve) {
                        printf("Erreur : compte non trouve\n");
                        fflush(stdin);
                            printf("Appuyez sur une entrer pour continuer...\n");
                            getchar();
                            system("cls");
                    }
                    fclose(fichier);
                } else {
                    printf("Erreur : impossible de lire le fichier\n");
                }

                break;

case 3:
    system("cls");
    printf("rentrer le mdp admin :\n");
    scanf("%d", &mdp_entre);

    if (mdp_entre != mdp_admin) {
        printf("Erreur : mot de passe incorrect\n");
        fflush(stdin);
        printf("Appuyez sur une entrer pour continuer...\n");
        getchar();
        system("cls");
        break;
    } else {
        // Afficher tous les comptes existants
        fichier = fopen(FICHIER_UTILISATEURS, "r");
        if (fichier) {
            char ligne[1024];
            while (fgets(ligne, 1024, fichier)) {
                char *token = strtok(ligne, ";");
                char nom_lu[20];
                char mdp_lu[20];
                int solde_lu;
                strcpy(nom_lu, token);
                token = strtok(NULL, ";");
                strcpy(mdp_lu, token);
                token = strtok(NULL, ";");
                solde_lu = atoi(token);
                mdp_lu[strcspn(mdp_lu, "\n")] = 0; // supprimer le caractère de fin de ligne
                printf("Nom : %s, Solde : %d\n", nom_lu, solde_lu);
            }
            fclose(fichier);
        } else {
            printf("Erreur : impossible de lire le fichier\n");
        }
        fflush(stdin);
        printf("Appuyez sur une entrer pour continuer...\n");
        getchar();
        system("cls");
    }
    break;

            case 4:
                printf("Au revoir!\n");
                return 0; // quitte le programme




            case 5:
                system("cls");
                printf("rentrer le mdp admin pour supprimer les comptes :\n");
                scanf("%d", &mdp_entre_suppr);
                
                if(mdp_entre_suppr == mdp_suppr) {
                    remove(FICHIER_UTILISATEURS);
                    printf("Tous les comptes ont ete supprimes\n");
                    fflush(stdin);
                    printf("Appuyez sur une entrer pour continuer...\n");
                    getchar();
                    system("cls");
                    break;
                }
                
                
                
                if (mdp_entre_suppr != mdp_suppr) {
                    printf("Erreur : mot de passe incorrect\n");
                    fflush(stdin);
                    printf("Appuyez sur une entrer pour continuer...\n");
                    getchar();
                    system("cls");
                    break;
                }

               




            default:
                printf("Erreur de saisie\n");
                system("cls");
                break;
        }
    }

    return 0;
}