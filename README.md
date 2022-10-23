# Projet-Mini-info-1
Le projet de l'UE mise à niveau en informatique 1 (algorithmique).

## Tuto github
### Récupération de ce dossier sur ton ordi

A réaliser que la première fois.

 -Aller dans le dossier où le projet sera mis dans le terminal.
 -_git clone mettreIciURL_
 -il demande ton nom utilisateur puis un password. Obtention du password:
                                                   - setting du compte github (à droite, icone avatar)
                                                    - devellopeur setting 
                                                    - generate new token
                                                    - donner un nom et une date d'expiration au token
                                                    - copier coller la suite de chiffre et lettre donner à la fin qd on a validé le token
                                                    - la garder quelque part, c'est ce qu'il faudra donner à chaque fois que 'password' est demandé
- Tu as dans ton répertoire un dossier avec le nom du projet récupéré

### Modification et envoie

-Recupère la dernière version du projet avant de travailler: 

            _git pull_
            
-Fais les modif voulues et sauvegarde

-Fais :     _git add . _                                                              (le point pour dire que tu voudras tout renvoyer)

-Fais :     _git commit -m "iciTuEcrisLaModifApportéePourNePasS'YPerdre" _           (tu confirmes l'envoie)

-Fais :     _git push --set-upstream origin NomBrancheOùEnvoi  _                      (vrai envoie sur serveur)

La  prochaine fois que tu travailles, tu peux refaire le git pull dans ton dossier projet (dans le terminal) pour bien récup les MàJ.

### Branches

  On peut créer plusieurs branches sur github, de base il y a la main. Cela permet de travailler à plusieurs, chacun sur une branche (pour éviter des   problèmes entre ma version de code et ta version).

Chacun fais les 'git push' (voir plus haut) en indiquant son nom de branche.
Quand on veut mettre en commun nos deux branche (nos deux travaux) on clique sur petit icone avec fleche.
Si il y a des fichiers en commun dans nos deux branches il va y avoir 'conflit' (quelle est la version qu'on garde). Il faut donc résoudre les conflits dans le fichier concerné.
Quand il n'y a plus de conflit, les documents des deux branches sont à nouveau identique, on peut continuer notre travaille sur notre branche jusqu'à la prochaine fois qu'on fais une mise en commun.
