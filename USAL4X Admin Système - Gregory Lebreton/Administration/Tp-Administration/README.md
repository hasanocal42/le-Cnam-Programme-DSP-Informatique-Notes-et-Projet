## TP ADMINISTRATION

### CONFIGURATION

- Groupes de 4
- Document à rendre sous forme de projet GIT

### CAHIER DES CHARGES

Votre équipe doit développer des scripts pour automatiser l'installation d'environnements de travail pour des développeurs web.
Les scripts seront éxécutés après l'installation d'un système Debian 11 vierge pour installer les outils nécessaires aux utilisateurs des machines.

- scripts installation NGINX / APACHE / VSCODIUM / HUGO-extended 112.* (nginx.sh, apache.sh,  etc...):
    - NGINX doit se lancer au démarrage de la machine et l'index par défaut (/var/www/html/index.nginx-debian.html) doit être supprimé
    - APACHE doit se lancer au démarrage et 
    - VSCODIUM, la dernière version disponible dans les releases du github
    - HUGO-extended 112
    - GIT
    - SUBLIME TEXT
- chaque script doit vérifier qu'il est bien lançé par l'utilisateur root sinon "exit 1" avec message
- le script "main.sh" doit appeler les autres scripts d'installation
- chaque projet doit comporter une branche par developpeur puis merge vers la "main" à la fin
- chaque projet doit comporter un README.md avec la présentation du projet et son UTILISATION

:warning: Installer nginx et apache sur la même machine nécessite l'arrêt de au moins un des services
(nginx ou apache) après installation.

> Note: Pour apache et nginx, les index.html par défaut doivent être supprimés.

### OBJECTIF

- Apprendre à travailler en groupe (division / repartition des tâches).
- Distinguer les commandes à utiliser.
- Rédiger des scripts bash commentés.
- Rechercher et appréhender des concepts nouveaux.

### UTILS

#### IDEMPOTENCE

* exemple idempotence pour nginx:
> Quand nginx est installé il créer des dossiers comme /etc/nginx par exemple. Vérifier l'absence du fichier avant d'installer nginx:
```bash
if [[ -d "/etc/nginx" ]]
then
    echo "nginx est déjà installé"
else
    echo "installation nginx"
    apt-get install nginx    
fi
```

#### DOCUMENTATIONS

- [NGINX](https://nginx.org/en/docs/)
- [APACHE](https://httpd.apache.org/docs/2.4/)
- [VSCODIUM](https://vscodium.com/#install)
- [HUGO](https://gohugo.io/documentation/)
- [GIT](https://git-scm.com/docs/git/fr)
- [SUBLIME TEXT](https://www.sublimetext.com/)

### BAREME

- PRESENTATION / 4 (COMMENTAIRES CODE)
- SCRIPTS COMPLETS / 8 (EFFECTUENT INSTALLATIONS)
- PERTINENCE DU CODE / 4  (CONCISION ET OPTIMISATION)
- IDEMPOTENT / 4 (RELANCER LES SCRIPTS NE CAUSENT AUCUNE ERREUR)

### GROUPE


