# BASH SCRIPTING
<a id="markdown-bash-scripting" name="bash-scripting"></a>

![bash-logo](docs/bash_logo.png)

## PLAN
<a id="markdown-plan" name="plan"></a>

<!-- TOC -->

- [BASH SCRIPTING](#bash-scripting)
    - [PLAN](#plan)
        - [DEFINITION](#definition)
        - [LES VARIABLES](#les-variables)
            - [MANIPULATION DE VARIABLES](#manipulation-de-variables)
            - [LES VARIABLES PREDEFINIES](#les-variables-predefinies)
        - [LES OPERATEURS](#les-operateurs)
            - [LE PIPE](#le-pipe)
            - [LES OPERATEURS RELATIONNELS](#les-operateurs-relationnels)
            - [LES OPERATEURS BOOLEEN](#les-operateurs-booleen)
            - [LES OPERATEURS DE CHAINES DE CARACTERES](#les-operateurs-de-chaines-de-caracteres)
            - [LES OPERATEURS DE FICHIERS](#les-operateurs-de-fichiers)
        - [LES CONDITIONS](#les-conditions)
            - [SIMPLE IF](#simple-if)
            - [IF ELIF ELSE](#if-elif-else)
            - [IF IMBRIQUES](#if-imbriques)
        - [LES BOUCLES](#les-boucles)
            - [LA BOUCLE FOR](#la-boucle-for)
            - [LA BOUCLE WHILE](#la-boucle-while)
            - [LA BOUCLE UNTIL](#la-boucle-until)
        - [LE SWITCH CASE](#le-switch-case)
        - [LES FONCTIONS](#les-fonctions)
            - [LE RETOUR](#le-retour)
        - [EXEMPLES UTILISATION](#exemples-utilisation)
        - [LES TABLEAUX](#les-tableaux)
        - [LES TABLEAUX ASSOCIATIFS](#les-tableaux-associatifs)
    - [EXERCICES](#exercices)

<!-- /TOC -->

### DEFINITION
<a id="markdown-definition" name="definition"></a>

C'est un minilangage de programmation intégré à Linux.
Ce n'est pas un langage aussi complet que peuvent l'être le C, le C++ ou le Java, mais cela permet d'automatiser la plupart des tâches : sauvegarde des données, surveillance de la charge de votre machine, maintenance, etc.

Les différents shells:
- sh : Bourne Shell. L'ancêtre de tous les shells.

- bash : Bourne Again Shell. Une amélioration du Bourne Shell, disponible par défaut sous Linux et Mac OS X.

- ksh : Korn Shell. Un shell puissant assez présent sur les Unix propriétaires, mais aussi disponible en version libre, compatible avec bash.

- csh : C Shell. Un shell utilisant une syntaxe proche du langage C.

- tcsh : Tenex C Shell. Amélioration du C Shell.

- zsh : Z Shell. Shell assez récent reprenant le meilleure de bash, ksh et tcsh.

La configuration du shell Bash se trouve dans ~/.bashrc, ici on peut personnaliser son invie de commande.
Hiérarchie de compatibilité des shells entre eux:

![](docs/shells.png)

Le format de script en bash est le ".sh", une fois le script créé, il faut le rendre éxécutable avec la commande:

```bash
chmod +x nom_du_script.sh
```

Pour l'éxécuter, appliquer "./" devant le nom du script se trouvant dans le répertoire courant:

```bash
./nom_du_script.sh
```


### LES VARIABLES
<a id="markdown-les-variables" name="les-variables"></a>

En informatique, les variables sont des symboles qui associent un nom (l'identifiant) à une valeur. 

- Créer un fichier nommé «test.sh» avec l'éditeur de votre choix; écrivez les lignes: 

```bash
#!/bin/bash        
a=Jean       
b=Bonjour        
c=ans        
d=20        
echo "$b , je m'appelle $a et j'ai $d $c"
```

- Rendre le script éxécutable:

```bash
chmod +x test.sh
```

- Lancer le script:

```bash
./test.sh
```

> Les variables \$a, \$b, \$c, \$d sont remplaçées par leur valeurs respectives

#### MANIPULATION DE VARIABLES
<a id="markdown-manipulation-de-variables" name="manipulation-de-variables"></a>

Nous pouvons stocker le résultat d'une commande dans une variables de cette façon:
```bash
ma_variable=$(whoami) # stocke le resultat de la commande bash "whoami" dans ma_variable
```

:warning: Pour additionner les valeurs des variables \$a et \$b, il faut mettre deux parenthèses pour que bash n'interprète pas le a + b comme une commande soit resultat=\$((a+b))

#### LES VARIABLES PREDEFINIES
<a id="markdown-les-variables-predefinies" name="les-variables-predefinies"></a>

Les principales variables prédéfinies sont :<br>
HOME (équivaut à ~): répertoire de l'utilisateur<br>
PATH : répertoires contenant des fichiers exécutables<br>
MAIL : chemin d'accès aux mails de l'utilisateur<br>
MAILCHECK : temps au bout duquel un mail est traité
IFS : caractère de séparation des arguments<br>
TERM : nom du type de terminal<br>
PS1 : invite principale du shell en mode interpréteur<br>
PS2 : invite secondaire du shell en mode programmation

> [WIKI](https://doc.ubuntu-fr.org/variables_d_environnement)

### LES OPERATEURS
<a id="markdown-les-operateurs" name="les-operateurs"></a>

#### LE PIPE
<a id="markdown-le-pipe" name="le-pipe"></a>

Un tuyau est un milieu fermé qui permet l'écoulement d'un bout à l'autre. Dans le monde réel, les tuyaux sont utilisés pour transporter de la matière. Dans un environnement Linux, un tube est un fichier spécial qui relie la sortie d'un processus à l'entrée d'un autre processus. En bash, un tuyau est le |
pipes permettent de rediriger directement le canal de sortie → d'une commande vers → le canal d'entrée d'autre.
Exemple d'utilisation:
    ls -la > resultat.txt
    cat < resultat.txt
    ls -la | cat 

#### LES OPERATEURS RELATIONNELS
<a id="markdown-les-operateurs-relationnels" name="les-operateurs-relationnels"></a>

Le Shell prend en charge les opérateurs relationnels suivants qui sont spécifiques aux valeurs numériques. Ces opérateurs ne fonctionnent pas pour les valeurs de chaîne à moins que leur valeur ne soit numérique.<br><br>
En partant des valeurs a=10 et B=20:

<img src="docs/bash-operateurs-relationnels.png"/>

#### LES OPERATEURS BOOLEEN
<a id="markdown-les-operateurs-booleen" name="les-operateurs-booleen"></a>

En programmation informatique, un booléen est un type de variable à deux états (généralement notés vrai et faux), destiné à représenter les valeurs de vérité de la logique et l'algèbre booléenne. Il est nommé ainsi d'après George Boole, fondateur dans le milieu du XIXe siècle de l'algèbre portant son nom. Le type de données booléen est principalement associé à des états conditionnels.<br>
Toujours en partant des valeurs a=10 et B=20:

<img src="docs/booleen.png"/>

#### LES OPERATEURS DE CHAINES DE CARACTERES
<a id="markdown-les-operateurs-de-chaines-de-caracteres" name="les-operateurs-de-chaines-de-caracteres"></a>

La chaîne de caractères est conceptuellement une suite ordonnée de caractères, et un type de donnée dans de nombreux langages informatiques (différent int, float, date, etc).<br>
Dans le tableau ci-dessous, a="abc" et b="efg":

<img src="docs/chaine-characteres.png"/>

#### LES OPERATEURS DE FICHIERS
<a id="markdown-les-operateurs-de-fichiers" name="les-operateurs-de-fichiers"></a>

Certains opérateurs peuvent être utilisés pour tester diverses propriétés associées à un fichier Unix.<br>
Supposons qu'un fichier variable contienne un nom de fichier existant "test" dont la taille est de 100 octets et dispose d'une autorisation de lecture, d'écriture et d'exécution sur "-":

![](docs/operateur-fichier.png)


### LES CONDITIONS
<a id="markdown-les-conditions" name="les-conditions"></a>

En informatique, une instruction conditionnelle, (aussi appelé expression conditionnelle), est une fonction d'un langage de programmation, qui effectue différents calculs ou actions, en fonction de l'évaluation d'une condition booléenne, à savoir vraie ou fausse.<br>
On les appellent aussi "tests" pour le fait qu'elle vont "tester" si la condition est remplie.

![](docs/conditions.png)

#### SIMPLE IF
<a id="markdown-simple-if" name="simple-if"></a>

--> Créer un fichier nommé «test-chiffre.sh» avec l'éditeur de votre choix; écrivez les lignes: 

```bash
#!/bin/bash
read -p "Enter number : " n
if test $n -ge 0
then
    echo "$n est un nombre positif."
else
    echo "$n est un nombre negatif."
fi
```

#### IF ELIF ELSE
<a id="markdown-if-elif-else" name="if-elif-else"></a>

Contrairement aux autres langages, le ELSE IF s'écrit ELIF, sinon la structure reste la même qu pour le simple IF.

```bash
VALUE=-10
if [ "$VALUE" -lt 0 ]
then
    echo "VALUE est inférieure à 0"
elif [ "$VALUE" -eq 0 ]
then
    echo "VALUE est 0"
else
    echo "VALUE est supérieure à 0"
fi
```

#### IF IMBRIQUES
<a id="markdown-if-imbriques" name="if-imbriques"></a>

Une instruction conditionnelle peux en contenir une autre:

```bash
VALUE=10
if [ "$VALUE" -lt 0 ]; then
    echo "VALUE est inférieur à 0"
else
    echo "VALUE est supérieur à 0"    
    if [ "$VALUE" -le 10 ]
    then
        echo "VALUE est inférieur ou égal 10"
    else
        echo "VALUE est supérieur à 10"
    fi
fi
```

### LES BOUCLES
<a id="markdown-les-boucles" name="les-boucles"></a>

#### LA BOUCLE FOR
<a id="markdown-la-boucle-for" name="la-boucle-for"></a>

En informatique, la boucle for est une structure de contrôle de programmation qui permet de répéter l'exécution d'une séquence d'instructions.
Une "boucle for" a deux parties : une entête qui spécifie la manière de faire l'itération, et un corps qui est exécuté à chaque itération. 

<img src="docs/boucle-for.png" width="300"/>

exemple 1:
```bash
#!/bin/bash
for i in 1 2 3 4 5
do
echo "Welcome $i times."
done
```

exemple 2 avec i comme itérateur:
```bash
#!/bin/bash
for(( i=1; i<=5; i++))
do
    echo "Bonjour $i fois"
done
```

#### LA BOUCLE WHILE
<a id="markdown-la-boucle-while" name="la-boucle-while"></a>

La boucle WHILE se compose d'une condition qui, tant qu'elle n'est remplie va répéter les instructions contenues entre les blocs suivants DO et DONE.

```bash
NUMBER=1
while [ $NUMBER -lt 5 ]
do
    echo "Le nombre: $((NUMBER++))"
done
```

#### LA BOUCLE UNTIL
<a id="markdown-la-boucle-until" name="la-boucle-until"></a>

La boucle UNTIL est très similaire à la boucle WHILE à l'exception de la condition pour sortir de la boucle. Pour la boucle UNTIL, la condition doit être évaluée à True pour sortir de la boucle d'instruction alors que pour la boucle WHILE, la sortie de la boucle se fait au moment où la condition est évaluée à False.

```bash
NUMBER=1
until [ $NUMBER == 5 ]
do
    echo "Le nombre est: $((NUMBER++))"
done
```

### LE SWITCH CASE
<a id="markdown-le-switch-case" name="le-switch-case"></a>

Le switch case est une forme de IF ELSE prenant en entrée une valeur. 

```bash
# enable `extglob` shell option
shopt -s extglob
# read what user's favourite planet
echo -n "Entrez votre planète favorite: "
read USER_PLANET
case "$USER_PLANET" in
  Terre)
    echo "C'est là où nous sommes!";;
  Mars ) 
    echo "Fan d'Elon Musk alors?!";;
  Lune )
    echo "C'est une planète de rêveurs!";;
  * )
    echo "Je ne connais pas cette planète.";;
esac
```

### LES FONCTIONS
<a id="markdown-les-fonctions" name="les-fonctions"></a>

Les fonctions sont là pour structurer le code et éviter toute duplication d'instructions afin d'optimiser au mieux le code.
Pour définir une fonction en BASH, nous utilisons la structure suivante:
```bash
function nom_de_la_fonction() 
{
    # instructions
}
```

En ajoutant le mot clé "return" à la fin du bloc d'instruction de la fonction,  on peut définir une valeur de sortie (généralement 0 pour réussite et 1 en cas d'échec d'une instruction dans la fonction).

Pour appeler la fonction

```bash
#!/bin/bash

function salut() 
{
    echo "salut `whoami`"
}

salut
```

> Note: En bash les fonctions peuvent prendre des arguments, il faut les passer à la suite de l'appel de la fonction:
```bash
nom_de_la_fonction "argument1" "argument2"
# Ils sont pr la suite référençable par $1 pour l'argument1, $2 argument2, etc...
```

#### LE RETOUR
<a id="markdown-le-retour" name="le-retour"></a>

Une fonction peux retourner une valeur comprise entre 0 et 255, ce qui va permettre de passer son resultat (réussite ou échec) à l'extérieure de celle-ci.
Généralement 0 correspond à une sortie sans erreur et 1 correspond à une sortie avec une erreur.

### EXEMPLES UTILISATION
<a id="markdown-exemples-utilisation" name="exemples-utilisation"></a>

Script pour automatiser la détection de panne matériel avec envoie d'email:

```bash
#!/bin/bash
# but: Detecter des erreurs de matériel
# mainteneur: Lebreton Greg <greg.lebreton@hotmail.com>
# Note : The script must run as a cron-job.
# dernière MAJ : 15/03/2020
##########################################

# journal de logs
LOGGER=/usr/bin/logger
FILE=/var/log/mcelog

# email settings
AEMAIL="greg.lebreton@hotmail.com"
ASUB="H/W Error - $(hostname)"
AMESS="Attention - pb matériel trouvé sur $(hostname) @ $(date). logs: /var/log/mcelog."
OK_MESS="OK: pas de pb matériel trouvé."
WARN_MESS="ERROR: Erreur, pb matériel trouvé."


# Check if $FILE exists or not
if test ! -f "$FILE" 
then   
    echo "Error - $FILE not found or mcelog is not configured for 64 bit Linux systems."
    exit 1
fi

# okay search for errors in file
error_log=$(grep -c -i "hardware error" $FILE)

# error found or not?
if [ $error_log -gt 0 ]
then    # yes error(s) found, let send an email
    echo "$AMESS" | email -s "$ASUB" $AEMAIL
else    # naa, everything looks okay
    echo "$OK_MESS"
fi
```

-----------------

### LES TABLEAUX
<a id="markdown-les-tableaux" name="les-tableaux"></a>

```bash
# déclarer un tableau
declare -a tableau
tableau=( "des pommes", "des poires")

# taille du tableau
echo "taille du tableau : ${#tableau[@]}"

# ajouter un élément au tableau :
tableau[2]="des oranges"

# afficher un élément du tableau
echo "tableau : 0 : ${tableau[0]}"
echo "tableau : 1 : ${tableau[1]}"
echo "tableau : 2 : ${tableau[2]}"

# obtenir la liste des indices du tableau :
echo "les indices sont : ${!tableau[@]}"

# parcourir les éléments du tableau et les afficher :
for i in ${!tableau[@]}
do
echo "dans le tableau $i : ${tableau[$i]}"
done
```

-------------------

### LES TABLEAUX ASSOCIATIFS
<a id="markdown-les-tableaux-associatifs" name="les-tableaux-associatifs"></a>

```bash
# déclarer un tableau associatif
declare -A tableau_associatif
tableau_associatif=( [prenom]="Jean" [nom]="Louis" [os]="GNU/Linux Debian" [taille]="1m77" )

# taille du tableau
echo "taille du tableau : ${#tableau_associatif[@]}"

# ajouter un élément au tableau :
tableau_associatif['age']="il a atteint un age à partir duquel c'est impoli de demander"

# taille du tableau
echo "nouvelle taille du tableau après ajout : ${#tableau_associatif[@]}"

# afficher un élément du tableau
echo "tableau : 'prenom' : ${tableau_associatif['prenom']}"
echo "tableau : 'nom' : ${tableau_associatif['nom']}"
echo "tableau : 'age' : ${tableau_associatif['age']}"

# obtenir la liste des indices du tableau :
echo "les indices sont : ${!tableau_associatif[@]}"

# parcourir les éléments du tableau et les afficher :
for i in ${!tableau_associatif[@]}
do
echo "dans le tableau $i : ${tableau_associatif[$i]}"
done
```

## EXERCICES
<a id="markdown-exercices" name="exercices"></a>

- A) Rédiger un script demandant deux chiffre en entrée et qui procèdera à l'addition de ces chiffres pour donner la somme qu'il affichera en sortie.

- B) Rédiger un script qui affiche un compte à rebours en partant de 10 jusque 0 pour finir avec l'affichage de "BOOM" dans le terminal.<br>
  - Avec une boucle WHILE  
  - Avec une boucle UNTIL

- C) Rédiger un script qui après avoir créer 3 utilisateurs, va les intégrer à un tableau pour ensuite parcourir le tableau itérativement afin d'énumérer son contenu de la façon suivante: l'utilisateur 1 est jean michel, l'utilisateur 2 est...).

- D) Rédiger un script automatisant l'installation de Terraform et nginx sur la machine
et qui éffectue une requête curl sur l'adresse http://localhost pour en afficher le résultat

- E) Rédiger un script pour éffectuer un secret santa à partir d'une liste de personnes demandée à l'utilisateur en input. (read -p)<br>
Le script doit sortir en output: "Jean va offrir un cadeau à Paul" par exemple où Jean et Paul sont des participants renseignés par l'utilisateur en input.
    > - penser à définir le nombre de participants dès le début.<br>
    > - la fonction pour mélanger les valeurs d'un tableau est shuf (diminutif de shuffle an anglais: mélange)