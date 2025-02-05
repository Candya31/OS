Exercice 1 :

Question 1.1

Real correspond au temps réel 
User correspond au temps que le systeme a été en mode utilisateur 
Sys correspond au temps que le temps a été en mode systeme

J'ai pour affichage : 

real    0m5.006s
user    0m0.001s
sys     0m0.005s

Je constate que sleep 5 consomme rien au CPU. Il s'agit d'une simple attente.


Question 1.2 :

Avec int, je constate que le programme tourne pendant énormément de temps :
time ./loopcpu
^C
real    43m37.955s
user    43m37.926s
sys     0m0.010s

J'ai dû faire cltr C pour arrêter le programme. Donc, j'ai remplacé int par long int comme int a une plage de valeurs entre [−32767 ; +32767] seulement.
Ce qui me donne :

real    0m6.610s
user    0m6.610s
sys     0m0.000s


Question 1.3 :
La commande exécutée est : time ./loopsys

Ce qui m'affiche :

real    0m4.395s
user    0m0.921s
sys     0m3.474s

Je constate que la somme du mode user et du mode sys est bien égale à real
et que le temps passé en mode systeme est supérieur au temps passé en mode utilisateur, ce qui est normal car avec getpid() on accede au noyau comme c'est un appel systeme.

Exercice 3 :

Question 3.2 :

Ça prend bien le temps nécessaire.

./mytimes "sleep 5" "sleep 10"
Temps d'exécution de la commande : 5.00 secs
Temps d'exécution de la commande : 10.00 secs

Question 4.2 : J'obtiens ceci avec ./mytimes "sleep 5" ./loopcpu ./loopsys :

Statistiques de "sleep 5" :
Temps total : 5.002081 s
Temps utilisateur : 0.000000 s
Temps système : 0.000000 s
Temps utilisateur fils : 0.000000 s
Temps système fils : 0.000000 s

Statistiques de "./loopcpu" :
Temps total : 6.568616 s
Temps utilisateur : 0.000000 s
Temps système : 0.000000 s
Temps utilisateur fils : 6.560000 s
Temps système fils : 0.000000 s

Statistiques de "./loopsys" :
Temps total : 4.368833 s
Temps utilisateur : 0.000000 s
Temps système : 0.000000 s
Temps utilisateur fils : 1.090000 s
Temps système fils : 3.270000 s


Exercice 5 :

Question 5.1 : La prioriété est de 80 qui est une prioriété faible.
Question 5.2 : Maintenant, la prioriété est de 99.
Question 5.3 :

Les affichages que j'ai obtenus sont les suivants avec : ./mytimes "./loopcpu" & ./mytimes "./loopcpu" & ./mytimes "./loopcpu" & ./mytimes "nice -19 ./loopcpu" & ./mytimes "./loopcpu" & ./mytimes "./loopcpu" & ./mytimes "./loopcpu" & ./mytimes "./loopcpu" & ./mytimes "./loopcpu" &

Statistiques de "./loopcpu" :
Temps total : 7.263207 s
Temps utilisateur : 0.000000 s
Temps système : 0.000000 s
Temps utilisateur fils : 7.260000 s
Temps système fils : 0.000000 s

Statistiques de "./loopcpu" :
Temps total : 7.294150 s
Temps utilisateur : 0.000000 s
Temps système : 0.000000 s
Temps utilisateur fils : 7.280000 s
Temps système fils : 0.000000 s

Statistiques de "./loopcpu" :
Temps total : 7.300622 s
Temps utilisateur : 0.000000 s
Temps système : 0.000000 s
Temps utilisateur fils : 7.290000 s
Temps système fils : 0.000000 s

Statistiques de "./loopcpu" :
Temps total : 7.307859 s
Temps utilisateur : 0.000000 s
Temps système : 0.000000 s
Temps utilisateur fils : 7.300000 s
Temps système fils : 0.000000 s

Statistiques de "./loopcpu" :
Temps total : 7.312810 s
Temps utilisateur : 0.000000 s
Temps système : 0.000000 s
Temps utilisateur fils : 7.300000 s
Temps système fils : 0.000000 s

Statistiques de "./loopcpu" :
Temps total : 7.327132 s
Temps utilisateur : 0.000000 s
Temps système : 0.000000 s
Temps utilisateur fils : 7.310000 s
Temps système fils : 0.000000 s

Statistiques de "nice -19 ./loopcpu" :
Temps total : 7.331693 s
Temps utilisateur : 0.000000 s
Temps système : 0.000000 s
Temps utilisateur fils : 7.320000 s
Temps système fils : 0.000000 s

Statistiques de "./loopcpu" :
Temps total : 7.334484 s
Temps utilisateur : 0.000000 s
Temps système : 0.000000 s
Temps utilisateur fils : 7.300000 s
Temps système fils : 0.000000 s

Statistiques de "./loopcpu" :
Temps total : 7.333380 s
Temps utilisateur : 0.000000 s
Temps système : 0.000000 s
Temps utilisateur fils : 7.320000 s
Temps système fils : 0.000000 s

Je constate que plus la prioriété est basse, plus elle prend du temps à se terminer.