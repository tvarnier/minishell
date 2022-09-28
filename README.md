# MINISHELL [[Sujet](https://github.com/tvarnier/minishell/blob/master/subject.pdf)]

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

```
 ❯ ./minishell
minishell ■ cd srcs
srcs ■ pwd
/Users/tvarnier/minishell/srcs
srcs ■ ls -l
total 88
-rw-r--r--  1 tvarnier  2018  3043 Sep 28 13:22 args_alloc.c
-rw-r--r--  1 tvarnier  2018  2171 Sep 28 13:22 args_split.c
drwxr-xr-x  8 tvarnier  2018   272 Sep 28 13:22 builtins
-rw-r--r--  1 tvarnier  2018  1594 Sep 28 13:22 command_builtins.c
-rw-r--r--  1 tvarnier  2018  2510 Sep 28 13:22 command_launch.c
-rw-r--r--  1 tvarnier  2018  1795 Sep 28 13:22 command_system.c
-rw-r--r--  1 tvarnier  2018  1863 Sep 28 13:22 env.c
-rw-r--r--  1 tvarnier  2018  2425 Sep 28 13:22 env_set.c
-rw-r--r--  1 tvarnier  2018  1103 Sep 28 13:22 error.c
-rw-r--r--  1 tvarnier  2018  1499 Sep 28 13:22 main.c
-rw-r--r--  1 tvarnier  2018  1753 Sep 28 13:22 print.c
drwxr-xr-x  4 tvarnier  2018   136 Sep 28 13:22 read
-rw-r--r--  1 tvarnier  2018  1472 Sep 28 13:22 struct_shell.c
srcs ■ kwame
kwame: command not found.
srcs □ exit
 ❯
```
