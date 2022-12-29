# Projet-Mini-info-1


Le projet de l'UE mise à niveau en informatique 1 (algorithmique). 

Le dossier 'Docs' contient la liste des commandes git ainsi que le rapport écrit du projet, le dossier 'src' contient tous les codes. Le rapport écrit explique la répartition des fonctions dans les différents fichiers.
Le code n'affichais pas les même erreurs dans nos deux ordinateurs, c'est pour cela qu'un Docker est réalisé pour essayer d'éviter que le code ne tourne pas chez quelqu'un en focntion de l'environnement. Le début du Dockerfile est le 'vrai' dockerfile, la suite en commentaire est la liste de commande à executer pour y accéder et faire tourner le programme.


----------------
La partie suivante ne concerne pas le correcteur, il s'agit d'un tutoriel github (puisque c'est la première fois qu'on en utilise un) : 

## Tuto github
### Récupération de ce dossier sur ton ordi

A réaliser que la première fois:

 - Aller dans le dossier où le projet sera mis dans le terminal, puis :
 
     git clone mettreIciURL
 
 - il demande ton nom utilisateur puis un password. Obtention du password:
                                                   - setting du compte github (à droite, icone avatar)
                                                    - devellopeur setting 
                                                    - generate new token
                                                    - donner un nom et une date d'expiration au token
                                                    - copier coller la suite de chiffre et lettre donner à la fin qd on a validé le token
                                                    - la garder quelque part, c'est ce qu'il faudra donner à chaque fois que 'password' est demandé
- Tu as dans ton répertoire un dossier avec le nom du projet récupéré

### Modification et envoie

- jsp si nécessaire :sur github, faire merge avec la main (de la main vers nous) pour que notre branche de travail soit identique à la branche final (la branche main)


- Recupère la dernière version du projet sur notre ordi (en local) avant de travailler: 

            git pull
            
- Se place sur la branche de travail:

            git checkout nombranche
            
- Fais les modif voulues et sauvegarde

- Fais : (le point pour dire que tu voudras tout renvoyer)

            git add .               
 
- Fais : (tu confirmes l'envoie)

            git commit -m "iciTuEcrisLaModifApportéePourNePasS'YPerdre"       

- Fais : (vrai envoie sur serveur)

           git push --set-upstream origin NomBranche                      


La  prochaine fois que tu travailles, tu refait le merge (si modif de main) et le git pull dans ton dossier projet (dans le terminal) pour bien récup les MàJ.

### Branches

  On peut créer plusieurs branches sur github, de base il y a la main. Cela permet de travailler à plusieurs, chacun sur une branche (pour éviter des   problèmes entre ma version de code et ta version).

Chacun fais les 'git push' (voir plus haut) en indiquant son nom de branche.
Quand on veut mettre en commun nos deux branche (nos deux travaux) on clique sur petit icone avec fleche. Cad on va comparer notre branche avec la branche main.
Si il y a des fichiers en commun dans les 2 branches il va y avoir 'conflit' (quelle est la version qu'on garde). Il faut donc résoudre les conflits dans le fichier concerné.
Quand il n'y a plus de conflit, les modifs de la branche sont mise sur main. 
On fait ça pr chaque branche, main a donc ensuite toutes les modifs aportées par les branches : main est la version 'finale'.
Mais maintenant, on veut que nos branches à nous soient identiques à main (car ma branche et ta branche sont inégale actuellement). On merge alors dans l'autre sens, de main vers ma branche et du main vers ta branche. 

### enregistrer mot de passe

Pour oublier l'ancien: 

      git config credential.helper ""

Pour enregistrer le nouveau:

      git config credential.helper store

faire un git pull par exemple, tu rentres tes infos et elles seront retenues.

### Couleur en console en C

voir https://www.theurbanpenguin.com/4184-2/ et https://chrisyeh96.github.io/2020/03/28/terminal-colors.html
