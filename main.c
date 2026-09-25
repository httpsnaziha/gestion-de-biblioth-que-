#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char titre[100];
    char auteur[30];
    char ISBN[14];
} livre;

int ajouterlivre(livre bib[100], int N) {
    if (N >= 100) {
        printf("La bibliotheque est pleine!\n");
        return N;
    }

    printf("-----------------------------------------------------\n");
    printf("Entrez le titre de livre n%d :\n", N+1);
    getchar();
    fgets(bib[N].titre, sizeof(bib[N].titre), stdin);
    bib[N].titre[strcspn(bib[N].titre, "\n")] = '\0';

    printf("Entrez le nom de l'auteur de livre n%d :\n", N+1);
    fgets(bib[N].auteur, sizeof(bib[N].auteur), stdin);
    bib[N].auteur[strcspn(bib[N].auteur, "\n")] = '\0';

    printf("Entrez le ISBN de livre n%d :\n", N+1);
    fgets(bib[N].ISBN, sizeof(bib[N].ISBN), stdin);
    bib[N].ISBN[strcspn(bib[N].ISBN, "\n")] = '\0';

    printf("-----------------------------------------------------\n");
    return N + 1;
}

void rechercherlivrepartitre(livre bib[100], int N) {
    char titre[100];
    bool trouve = false;

    printf("Entrez le titre de livre que vous cherchez: ");
    getchar();
    fgets(titre, sizeof(titre), stdin);
    titre[strcspn(titre, "\n")] = '\0';

    for (int i = 0; i < N; i++) {
        if (strcmp(bib[i].titre, titre) == 0) {
            printf("-----------------------------------------------------\n");
            printf("Livre trouve:\n");
            printf("Titre: %s\n", bib[i].titre);
            printf("Auteur: %s\n", bib[i].auteur);
            printf("ISBN: %s\n", bib[i].ISBN);
            printf("-----------------------------------------------------\n");
            trouve = true;
        }
    }

    if (!trouve) {
        printf("Ce livre n'existe pas!\n");
    }
}

void afficherbibliotheque(livre bib[100], int N) {
    if (N == 0) {
        printf("La bibliotheque est vide!\n");
    } else {
        for (int i = 0; i < N; i++) {
            printf("-----------------------------------------------------\n");
            printf("Livre n%d:\n", i+1);
            printf("Titre: %s\n", bib[i].titre);
            printf("Auteur: %s\n", bib[i].auteur);
            printf("ISBN: %s\n", bib[i].ISBN);
            printf("-----------------------------------------------------\n");
        }
    }
}

int supprimerlivre(livre bib[100], int N) {
    char titre[100];
    bool trouve = false;

    if (N == 0) {
        printf("La bibliotheque est vide!\n");
        return N;
    }

    printf("Entrez le titre de livre a supprimer: ");
    getchar();
    fgets(titre, sizeof(titre), stdin);
    titre[strcspn(titre, "\n")] = '\0';

    for (int i = 0; i < N; i++) {
        if (strcmp(bib[i].titre, titre) == 0) {
            for (int j = i; j < N-1; j++) {
                bib[j] = bib[j+1];
            }
            trouve = true;
            printf("Livre supprime\n");
            return N - 1;
        }
    }

    if (trouve==false) {
        printf("Livre non trouve\n");
    }
    return N;
}

int main() {
    livre bib[100];
    int N = 0, choix;
    bool loop = true;

    while (loop) {
        printf("-----------------------------------------------------\n");
        printf("==== Bibliotheque ====\n");
        printf("1. Ajouter un livre\n");
        printf("2. Rechercher un livre par titre\n");
        printf("3. Afficher tous les livres\n");
        printf("4. Supprimer un livre\n");
        printf("0. Quitter\n");

        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {

            case 1:
                N = ajouterlivre(bib, N);
                break;
            case 2:
                rechercherlivrepartitre(bib, N);
                break;
            case 3:
                afficherbibliotheque(bib, N);
                break;
            case 4:
                N = supprimerlivre(bib, N);
                break;
            case 0:
                loop = false;
                break;
            default:
                printf("Choix invalide\n");
                break;

        }
    }
    return 0;
}
