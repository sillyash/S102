# S102 · Manipulation d'images PPM

### Ash MERIENNE & Mathias PETIBON

## Sommaire

- [Mode d'emploi](#mode-demploi)
	- [Ouverture et lecture d'images](#ouverture-et-lecture-dimages)
    - [Manipulation de l'image](#manipulation-de-limage)
    - [Enregistrement de l'image](#enregistrement-de-limage)

> *note: les liens internes ne fonctionnent pas sur Replit*

<br>

## Mode d'emploi

### Ouverture et lecture d'images

Le programme exécutable, une fois lancé, apparaît dans un terminal.

Une fois les tests automatiques effectués, le programme va demander à l'ultilisateur de rentrer un nom de fichier à charger:

	Lecture fichier... ("images/nom.ppm" pour acceder au dossier)
	Saisissez un nom de fichier ppm  >>> 

Il faut alors entrer un **nom** ou **chemin** vers un fichier d'extension **.ppm**.

Il existe par défaut un dossier ***images*** qui contient déjà une image, ***exCouleur.ppm***.

Pour charger cette images, il faudrait donc entrer _"images/exCouleur"_ ou _"images/exCouleur.ppm"_ (l'extenson de fichier est optionelle).

	Saisissez un nom de fichier ppm  >>> images/exCouleur

*Remarque: le chemin vers le fichier doit partir du dossier racine du programme, donc déposez vos fichiers de façon à ce que l'exécutable puisse y accéder depuis son dossier.*

<br>

### Manipulation de l'image

Une fois l'image chargée, un menu vous propose un vaste choix de modifications possibles.

	Entrez:
		1 - pour afficher l'image (Linux or Replit only)
		2 - pour mettre en composante rouge
		3 - pour mettre en niveaux de gris
		4 - pour mettre en noir et blanc
		...
		13 - pour quitter le programme
	>>> 

Il suffit alors de rentrer le numéro souhaité pour effectuer l'opération désirée.

Vous aurez souvent à utiliser des sous menus, le principe est le même que pour le menu principal.

Parfois, un paramètre vous sera demandé et il faudra alors rentrer la valeur souhaitée pour effectuer l'opération.

	>>> 7
	Veuillez entrer un constraste supérieur à 1  >>> 1.5


Pour arrêter les modifications et quitter le menu, entrez le numéro désigné par la dernière section du menu.

	13 - pour quitter le programme


<br>

### Enregistrement de l'image

Après avoir quitté le menu, le programme vous demandera si vous suhaiter saub=vegarder l'image que vous avez modifiée.

	Souhaitez vous enregistrer l'image ? (y/n)  >>> 

Si vous souhaitez sauvegarder votre fichier, répondez "y", sinon répondez avec n'importe quel autre caractère.

	Souhaitez vous enregistrer l'image ? (y/n)  >>> y

Si vous avez choisi de sauvegarder l'image, le programme vous demandera le nom et/ou le chemin dans lequel vous voulez sauvegarder votre fichier. 

	Ecriture du fichier... ("images/nom.ppm" pour acceder au dossier)
	Saisissez un nom de fichier ppm  >>> 

A la même manière que lorsque vous avez [ouvert votre fichier](#ouverture-et-lecture-dimages), il faut rentrer un nom de fichier ou un chemin qui part du dossier dans lequel se trouve le programme.

	Saisissez un nom de fichier ppm  >>> images/coquelicot.ppm

A nouveau, l'extension de fichier .ppm est optionelle mais peut également être entrée.

***Attention: Ne rentrez pas le même nom de fichier que celui qui est ouvert dans le programme, sous risque de perdre votre travail.***

Suite à ça, si les instructions ont été suivies, le terminal devrait afficher le texte suivant et se fermer/terminer l'exécution d'instructions.

	Fichier ecrit! Image sauvegardee.
	
	A bientot!

Vous pourrez retrouver votre image à l'endroit spécifié lors de la sauvegarde.

*Remarque: il est recommandé de sauvegarder les images dans le dossier "images"*


<br><br> **[Retour au sommaire](#sommaire)**

