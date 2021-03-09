# MINISHELL [[Sujet](https://github.com/tvarnier/42/blob/master/system/minishell/subject.pdf)]

<br>

Le projet Minishell consiste à créer un Shell basique.

Il nous permet de nous plonger au coeur d’un système Unix et de découvrir une partie importante de l’API d’un tel système : la création et la synchronisation de processus.

<br>

## LANCER LE PROJET

<br>

Lancer la commande `make` pour compiler le projet.

Il suffit ensuite de lancer la commande `./minishell`

### FONCTIONNALITÉS ET PARTICULARITÉS

 * Les lignes de commande sont simples, pas de pipes, pas de redirections ou autres fonctions avancées
 * Les exécutables sont ceux que l’on peut trouver dans les chemins indiqués dans la variable `PATH` (`echo $PATH` pour l'afficher)
 * Gestion des variables d'environnements (`env` pour les affichers)
 * Builtins intégrés : `echo`, `cd`, `setenv`, `unsetenv`, `env`, `exit`
 * Gestion des expansions `$` et `~`

<br>

## EXEMPLE D'UTILSATION

<br>

<div width="75%">
  <img src="https://github.com/tvarnier/42/blob/master/system/minishell/img/example.png" width="75%">
</div>
