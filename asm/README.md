Asm
======
	Transforme le RedCode en OpCode Corewar


Fonctionnement
======

TODO
------
	-

Étapes
------
	1. Lire ligne par ligne le fichier envoyé.
	   1.1. Supprimer les lignes qui commencent par #
	2. Gestion des arguments
	   2.1. Supprimer les ' ' et '\t' inutile (hors des '"' et '\'', après/avant les ','
	3. Parser les ' ' (et '\t')
	4. Récupérer la commande en *tab
	5. Calculer les arguments (évaluation)
	6. Ecrire le resultat à la suite dans le fichier de sortie

Problèmes
------
	A. Gestion des labels
	  1. Passage des appels dans un tableau à double entrée ?
