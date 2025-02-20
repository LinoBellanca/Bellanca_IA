# Bellanca_IA
 
 Tout le contenu important se trouve dans le dossier Game et Meshes pour les AnimBlueprints (Plus le BP_Checkpoint dans Cours_AI mais il est pas si important que ça en vrai)

 Pour voir l'IA en action, la map TrueLevel
 Pour tester l'IA, la map Map

 L'IA en question est le BP_MaskGrunt
 
 Il peut :
 -Détecter le joueur avec un AIPerception
	-Le AIPerception suit les mouvements de la tête du mesh grâce à une fonction CPP, ainsi il peut tourner la tête pour voir tout autour de lui
	-Quand il détecte le joueur, il joue une animation de sursaut où il ne bouge plus et ne peut plus rien faire d'autre, il passe ensuite en mode Traque et/ou Inspection
		-En mode Inspection, il s'approchera doucement du joueur en le visant, si le joueur reste dans son champs de vision pendant + de 5 secondes, il lui tire dessus
		-Si le joueur s'approche de beaucoup trop près de lui, il lui tire aussi dessus même si les 5 secondes ne se sont pas écoulées
	-Si le joueur quitte le champs de vision, le mode traque prend le dessus
		-En mode Traque, il récupère la dernière position du joueur avant que ce dernier ne quitte son champs de vision, puis il court vers cette position
		-Une fois sur la position, il tournera la tête pour tenter de trouver le joueur
			-S'il redétecte le joueur, il passera directement en mode inspection sans faire l'animation de sursaut
			-S'il ne voit plus le joueur au bon d'un certain temps, il l'oublie, la prochaine fois qu'il le vera il rejouera l'animation de sursaut
	-Quand le joueur meurt, il ne peut plus le détecter

 -Patrouiller de points en points
	-Quand il arrive sur un Checkpoint, il regarde à gauche et à droite avant de reprendre sa marche
	-Quand il arrive au bout de sa liste de Checkpoints, il la reprend à l'envers ([A to B to C to B to A] au lieu de [A to B to C to A])
	-Quand sa prochaine destination est derrière lui (quand il arrive au bout de sa liste de Checkpoints ou au début si'il la prend à l'envers),
	il joue une animation où il fait un 180° (50% de chance de se tourner soit du côté gauche soit du côté droit)
	-Toutes les 10 secondes il a 1 chance sur 4 de s'arrêter pour faire une animation alternative ou il se remet en place pendant quelques secondes


	
RESPECT DE LA DEMANDE CLIENT (ce que j'ai fait qui était demandé dans le document de base, il y a pas tout, tous les extraits de paragraphes sont repris tel qu'écrits à la base):
-Objectif principal : (monter la garde, doit empecher le joueur d'accéder à une zone, créer un obstacle sur la route du joueur vers son objectif … )

-Attente/Idle : Le personnage adopte une posture d’inactivité, montrant qu’il est inactif. Par exemple, regarde autour de lui, 
Animation requise : (animation de respiration, rotation légère de la tête, posture naturelle.) 
se déclenche lors de la fin d’un cycle de patrouille.

-Patrouille : Le personnage parcourt un chemin prédéfini.
Animation requise : Marche d’un point A vers un point B.
niveau programmation : Points de patrouille (coordonnées spécifiques ou zones dynamiques).
Comportement secondaire (remplaçant la patrouille)

-Le joueur est detecter
Description : Lorsque le joueur entre dans le champ de vision, l’ennemi change son comportement et devient méfiant.
Animation requise : regard fixe vers le joueur, position suspicieuse. marche prudemment
vers le joueur, posture défensive
Se déclenche lorsque le joueur entre dans la zone de vision de l’ennemi.

-confirmation de la présence du joueur :
l’ennemie attaque
Animation requise : regard fixe vers le joueur, attaque
se déclecnhe lorsque le joueur reste plus de 5 seconde dans le champs de vision de
l’ennemi



DEMANDE ORIGINALE :
I] fiche du personnage :
● Nom
● Rôle dans le jeu : (Ennemi, PNJ neutre, allié, boss…)
● Objectif principal : (monter la garde, doit empecher le joueur d'accéder à une zone,
donner des indices lors d’un dialogue, créer un obstacle sur la route du joueur vers
son objectif … )
● Contexte narratif ?
II] Fiche actions / aniamtions :
- Attente/Idle : Le personnage adopte une posture d’inactivité, montrant qu’il est inactif.
Par exemple, se gratte la tête, regarde autour de lui,inspecte un objet.
Animation requise : (animation de respiration, rotation légère de la tête, posture naturelle.)
se déclenche lors de la fin d’un cycle de patrouille.
- Patrouille : Le personnage parcourt un chemin prédéfini.
Animation requise : Marche d’un point A vers un point B.
niveau programmation :
Points de patrouille (coordonnées spécifiques ou zones dynamiques).
Gestion des obstacles (contourner, sauter, s'arrêter).
Comportement secondaire (remplaçant la patrouille) :
- Action alternative lors de la patrouille :
Par exemple : inspecter des objets de l’environnment, interagir avec l’environnement (fouiller
une caisse, discuter avec d'autres PNJ … ).
Animation requise : accroupissement, regard détaillé d’un objet, animation de discussion.
Se déclenche lors de la fin d’une ronde ou autre
- Le joueur est detecter mais pas repéré
Description : Lorsque le joueur entre dans le champ de vision (défini par un cône ou une
zone sur la mini-map), l’ennemi change son comportement et devient méfiant.
Animation requise : regard fixe vers le joueur, position suspicieuse. marche prudemment
vers le joueur, posture défensive, menace verbale.
Se déclenche lorsque le joueur entre dans la zone de vision de l’ennemi.
confirmation de la présence du joueur :
l’ennemie attaque ou alerte ses allies et le joueur est repréré :
Animation requise : Sursaut, regard fixe vers le joueur, cri d’alerte, attaque ou fuite.
se déclecnhe lorsque le joueur reste plus de 5 seconde dans le champs de vision de
l’ennemi



NOTES :
-J'ai préféré mettre le Sursaut quand le joueur est détecté plutôt qu'à la confirmation car c'est plus logique selon moi
-Aussi à la base je voulait mettre un système de masques que le joueur met pour que l'IA ait différentes réactions au bout des 5 secondes
-Vu que le contexte narratif est un "?" j'y ai mit ce qui me passait par la tête, du coup, pour refléter ce "?" on sait pas vraiment si c'est le joueur le gentil et les gardes les méchant ou l'inverse
	-On joue une espèce de créature qui doit s'échapper d'un complexe que ça soit une prison ou un labo je suis pas sûr
	-La créature a un design qui fait un peu peur, mais ses animations le rendent ridicule
	-il est complétement inoffensif avec ses petits bras et ça justifie le fait qu'il n'attaque pas juste les gardes et qu'il doit les éviter à tout prix
	-De même avec les gardes, je leur ait donné des masques à gaz pour qu'on ne voit pas leurs expressions et pour justifier leur champs de vision étroit
	(c'est d'ailleurs aussi pour ça qu'on est dans un batiment sombre, pour qu'ils ne voient pas de très loin)
	-Ils ont un gros fusil bien en évidence pour bien montrer qu'ils sont dangereux et qu'on ne doit pas les croiser, mais on peut les voir parfois se remettre bien dans leur combinaison (élément de gameplay)
-Le TrueLevel paraît impossible mais en vrai j'ai déjà réussi plusieurs fois (mais jamais sans me faire repéré au moins une fois par contre)