#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/times.h>
#include <unistd.h>

//Question 2.1
void lance_commande1(char * commande){
    if (!commande){
        fprintf(stderr, "Commande NULL\n");
        return;
    }
    
    int cmd = system(commande);

    if (cmd==-1){
        fprintf(stderr,"Commande non exécuté correctement\n");
        return;
    }
}

//Question 3.1
void lance_commande2(char * commande){
    if (!commande){
        fprintf(stderr, "Commande NULL\n");
        return;
    }

    struct timeval debut, fin;
    gettimeofday(&debut,NULL);

    int cmd = system(commande);

    gettimeofday(&fin,NULL);

    if (cmd==-1){
        fprintf(stderr,"Commande non exécuté correctement\n");
        return ;
    }

    double t1 = debut.tv_sec + debut.tv_usec / 1000000.0;
    double t2 = fin.tv_sec + fin.tv_usec / 1000000.0;

    printf("Temps d'exécution de la commande : %.2f secs\n",t2-t1);

}

//Question 4.1
void lance_commande(char * commande){
    if (!commande){
        fprintf(stderr, "Commande NULL\n");
        return;
    }

    struct timeval debut, fin;
    double tick = sysconf(_SC_CLK_TCK);
    clock_t clock_debut, clock_fin;
    struct tms deb_info, fin_info;

    //Avant d'executer la commande
    gettimeofday(&debut,NULL);
    clock_debut=times(&deb_info);

    int cmd = system(commande);

    //On recupere le temps après avoir execute la commande
    clock_fin=times(&fin_info);
    gettimeofday(&fin,NULL);

    if (clock_fin == (clock_t)-1) {
        fprintf(stderr, "Erreur de recuperation de temps\n");
        return;
    }

    if (cmd==-1){
        fprintf(stderr,"Commande non exécuté correctement\n");
        return ;
    }

    // Differents temps
    double temps_total = (fin.tv_sec - debut.tv_sec) + (fin.tv_usec - debut.tv_usec) / 1000000.0;
    double temps_utilisateur = (fin_info.tms_utime - deb_info.tms_utime) / tick;
    double temps_systeme = (fin_info.tms_stime - deb_info.tms_stime) / tick;
    double temps_utilisateur_fils = (fin_info.tms_cutime - deb_info.tms_cutime) / tick;
    double temps_systeme_fils = (fin_info.tms_cstime - deb_info.tms_cstime) / tick;

    // Affichages
    printf("\nStatistiques de \"%s\" :\n", commande);
    printf("Temps total : %.6f s\n", temps_total);
    printf("Temps utilisateur : %.6f s\n", temps_utilisateur);
    printf("Temps système : %.6f s\n", temps_systeme);
    printf("Temps utilisateur fils : %.6f s\n", temps_utilisateur_fils);
    printf("Temps système fils : %.6f s\n", temps_systeme_fils);

}

//Question 2.2
int main(int argc, char* argv[]){
    if (argc < 2) {
        fprintf(stderr, "Pas d'argument");
        return 1;
    }
    for (int i=1; i<argc; i++){
        lance_commande(argv[i]);
    }

    return 0;
}