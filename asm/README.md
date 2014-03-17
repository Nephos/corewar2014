Asm
======
	Transforme le RedCode en OpCode Corewar


Fonctionnement
======

TODO
------

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

Algorithme
------
	Tant que asm_get_next_cmd(FILE) != NULL
	     |récupérer la ligne
	     |la spliter
	     |checker les labels: si definit, ajout à un tableau (liste chainée ? OUI)
	     |		(int addr, char *name)
	     |récupérer l'opcode sortant (liste chainée ? OUI)
	     |		stockage des labels -> L1/L2... ? (char* type et char* valeur)

Fichiers
------
<lists.h>
	struct s_list_label
	{
		char		*name;
		int		addr;
		s_list_label	*next;
	};
	struct s_list_op
	{
		char		*data;	//if the char[X] is a label, there is 256 possibilities
					//so 256 labels, so s_list_label can be a simple struct s_label[256]
		char		*types;	//0 is a label, 1 is everything else
		s_list_op	*next;
	};
	struct s_label			//if we use 256 labels only, we don't need a chained list
	{
		char		*name;
		int		addr;
	};

Problèmes
------
	A. Gestion des labels
	  1. Passage des appels dans un tableau à double entrée ?
