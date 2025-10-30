# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`

Question 1:
Jai utilise la fonction sort afin de trier les livres en titre et auteur. Elle permet d'organiser des vecteurs en les comparant. 
jai utilise cette fonction dans ma fonctionnalite 2 getBooksSortedByTitle et getBooksSortedByAuthor dans le fichier library.cpp

Question 2:
Une base de donnee MySQL afin de gerer un milion de livres