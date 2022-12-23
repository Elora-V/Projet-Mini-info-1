
FROM ubuntu:20.04
WORKDIR /usr/app/src/
USER root

#installer gcc pour pouvoir compiler
RUN apt-get update && apt-get install build-essential -y


#mettre nos codes dans le docker
ADD src src


#---------------------------------------------------

#commande docker:



#-----------Creation du docker (à faire à chaque fois su'on modifie le code du fichier src)


#sudo docker build -t "elora:projetC" .



#-----------Entrée dans le docker et executer code


#sudo docker run -it "elora:projetC" sh  
#cd src
#make all
#./all



#----------Sortir du docker et supprimer le containeur du docker

#exit
#sudo docker ps -a
# copier coller la colonne CONTAINER ID de "elora:projetC"
#sudo docker rm <l'identifiant copier coller>
 
 
 #--------Supprimer l'image 
 
 # quand on aura plus besoin d'y retourner, ou que le veut recreer le docker (car changement de code)
 
 #sudo docker images
 #copier coller la colonne IMAGE ID de "elora:projetC"
 #sudo docker rmi <identifiant copier coller>
