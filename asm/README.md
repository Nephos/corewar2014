Asm
======
	Transforme le RedCode en OpCode Corewar


Fonctionnement
======

TODO
------
- Header avec le nombre magique

Étapes
------
	1. Lire ligne par ligne le fichier envoyé et récupérer les commandes.
	2. Parser les ' ' (et '\t'), ',' ...
	3. Récupérer la commande en *tab par split et sauvegarde des labels
	4. Calculer les arguments (évaluation)
	5. Remplacement des flags par l'adresse (évaluation des labels)
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
		char		*data;
		/* if the char[X] is a label, there is 256 possibilities */
		/* so 256 labels, so s_list_label can be a simple struct s_label[256] */
		short		*types;
		/* not -1 is a label */
		s_list_op	*next;
	};

	/* we don't need it bc we will use a short *type not char *type */
	/* but if we use 256 labels only, we don't need a chained list */
	struct s_label
	{
		char		*name;
		int		addr;
	};

Problèmes
------
	A. Gestion des labels
	  1. Passage des appels dans un tableau à double entrée ?

