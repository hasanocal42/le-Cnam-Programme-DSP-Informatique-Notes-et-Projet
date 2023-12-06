# ADMINISTRATION LINUX
<a id="markdown-administration-linux" name="administration-linux"></a>

![](docs/admin-linux.jpg)

## INTRODUCTION
<a id="markdown-introduction" name="introduction"></a>

L'administration d'un serveur Linux "Headless" se fait principalement par ligne de commande.
Il convient donc de connaître l'environnement tant au niveau du système de fichiers que des processus s'éxécutant sur le système. 
Il éxiste également des utilitaires incontournables pour aider l'administrateur dans ses tâches quotidiennes.


## PLAN
<a id="markdown-plan" name="plan"></a>
<!-- TOC -->

- [ADMINISTRATION LINUX](#administration-linux)
    - [INTRODUCTION](#introduction)
    - [PLAN](#plan)
    - [LES PRINCIPALES COMMANDES D'ADMINISTRATION](#les-principales-commandes-dadministration)
        - [PARTITIONS ET SYSTEMES DE FICHIERS](#partitions-et-systemes-de-fichiers)
            - [fdisk - Édition de la table des partitions :](#fdisk---%C3%A9dition-de-la-table-des-partitions-)
            - [swap](#swap)
            - [mkfs - Création d'un système de fichiers :](#mkfs---cr%C3%A9ation-dun-syst%C3%A8me-de-fichiers-)
            - [fsck - Vérification d'un système de fichiers :](#fsck---v%C3%A9rification-dun-syst%C3%A8me-de-fichiers-)
            - [mount - Insertion de partition dans le système :](#mount---insertion-de-partition-dans-le-syst%C3%A8me-)
            - [umount - Démontage d'un système de fichiers :](#umount---d%C3%A9montage-dun-syst%C3%A8me-de-fichiers-)
        - [DISTRIBUTION INSTALLATION DE LOGICIELS](#distribution-installation-de-logiciels)
            - [tar - Gestion d'archives :](#tar---gestion-darchives-)
            - [rpm - Gestion des paquetages RedHat:](#rpm---gestion-des-paquetages-redhat)
            - [apt - Gestion des paquets Debian :](#apt---gestion-des-paquets-debian-)
            - [deb - Gestion des paquets deb](#deb---gestion-des-paquets-deb)
        - [GESTION DES PROCESSUS](#gestion-des-processus)
            - [ps - État des processus :](#ps---%C3%A9tat-des-processus-)
            - [kill - Envoyer un signal à un processus :](#kill---envoyer-un-signal-%C3%A0-un-processus-)
        - [GESTIONS DES UTILISATEURS / GROUPES / PERMISSIONS](#gestions-des-utilisateurs--groupes--permissions)
            - [UTILISATEURS](#utilisateurs)
            - [GROUPES](#groupes)
            - [PERMISSIONS](#permissions)
                - [CHMOD](#chmod)
                - [CHOWN](#chown)
        - [UTILITAIRES RESEAU](#utilitaires-reseau)
            - [route - Gestion de la table de routage du noyau :](#route---gestion-de-la-table-de-routage-du-noyau-)
            - [netstat - Statistiques réseau:](#netstat---statistiques-r%C3%A9seau)
            - [arp - Gestion de la table ARP du noyau :](#arp---gestion-de-la-table-arp-du-noyau-)
            - [ping - demande d'écho vers d'autres hôtes :](#ping---demande-d%C3%A9cho-vers-dautres-h%C3%B4tes-)
            - [traceroute - Chemin pour joindre un hôte :](#traceroute---chemin-pour-joindre-un-h%C3%B4te-)
            - [tcpdump - Examen du trafic réseau :](#tcpdump---examen-du-trafic-r%C3%A9seau-)
            - [telnet - Connexion TCP/IP :](#telnet---connexion-tcpip-)
            - [nmap - Scan réseau non natif](#nmap---scan-r%C3%A9seau-non-natif)
            - [ssh - Exécution sécurisée d'un shell distant.](#ssh---ex%C3%A9cution-s%C3%A9curis%C3%A9e-dun-shell-distant)
            - [rsync - Synchronisation de répertoire](#rsync---synchronisation-de-r%C3%A9pertoire)
            - [ftp - Transferts de fichiers obsolète:](#ftp---transferts-de-fichiers-obsol%C3%A8te)
            - [wget - Rapatrier le contenu d'une URL:](#wget---rapatrier-le-contenu-dune-url)
            - [curl - Afficher le contenu d'une ressource web:](#curl---afficher-le-contenu-dune-ressource-web)
    - [SYSTEMD](#systemd)
        - [DEFINITION:](#definition)
        - [PRINCIPE:](#principe)
        - [UTILISATION DE SYSTEMCTL:](#utilisation-de-systemctl)
            - [STATUT SYSTEM](#statut-system)
            - [GESTION DES SERVICES](#gestion-des-services)
            - [CREATION DE SERVICE](#creation-de-service)
    - [CRON](#cron)
        - [DEFINITION:](#definition)
        - [PRINCIPE:](#principe)
        - [UTILISATION:](#utilisation)
    - [EXERCICES](#exercices)
        - [AJOUTES UN UTILISATEUR](#ajoutes-un-utilisateur)
        - ["MARK THE DATE"](#mark-the-date)
        - [INSTALLATION DE PAQUETS](#installation-de-paquets)
        - [APPELES UN AMI](#appeles-un-ami)
    - [ALLER PLUS LOIN](#aller-plus-loin)

<!-- /TOC -->

## LES PRINCIPALES COMMANDES D'ADMINISTRATION
<a id="markdown-les-principales-commandes-d'administration" name="les-principales-commandes-d'administration"></a>

### PARTITIONS ET SYSTEMES DE FICHIERS
<a id="markdown-partitions-et-systemes-de-fichiers" name="partitions-et-systemes-de-fichiers"></a>

#### fdisk - Édition de la table des partitions :
<a id="markdown-fdisk---%C3%A9dition-de-la-table-des-partitions-%3A" name="fdisk---%C3%A9dition-de-la-table-des-partitions-%3A"></a>
```bash
fdisk /dev/hda
```

> [WIKI](https://doc.ubuntu-fr.org/fdisk)

#### swap
<a id="markdown-swap" name="swap"></a>
- mkswap - Création d'une zone de swap :
```bash
mkswap /dev/hda2
mkswap /boot/swap_file
```

- swapon - Activation d'une zone de swap :
```bash
swapon /dev/hda2
```

Note: -a active toutes les zones de swap de /etc/fstab.

- swapoff - Désactivation d'une zone de swap :
```bash
swapoff /dev/hda2
```

#### mkfs - Création d'un système de fichiers :
<a id="markdown-mkfs---cr%C3%A9ation-d'un-syst%C3%A8me-de-fichiers-%3A" name="mkfs---cr%C3%A9ation-d'un-syst%C3%A8me-de-fichiers-%3A"></a>

```bash
mkfs.ext2 /dev/hda3

mkfs.ext3 /dev/hda4

mkfs.vfat /dev/hda5
```

> [WIKI](https://debian-facile.org/doc:systeme:mkfs)

#### fsck - Vérification d'un système de fichiers :
<a id="markdown-fsck---v%C3%A9rification-d'un-syst%C3%A8me-de-fichiers-%3A" name="fsck---v%C3%A9rification-d'un-syst%C3%A8me-de-fichiers-%3A"></a>
- Réparation automatique d'un système ext2/ext3:
```bash
fsck.ext2 -p /dev/hda3
```
- Vérification d'une partition Windows:
```bash
fsck.vfat /dev/hda4
```

#### mount - Insertion de partition dans le système :
<a id="markdown-mount---insertion-de-partition-dans-le-syst%C3%A8me-%3A" name="mount---insertion-de-partition-dans-le-syst%C3%A8me-%3A"></a>
- Monter une partition Windows:
```bash
mount -t vfat /dev/hda4 /mnt/dos/
```
- Monter toutes les partitions de /etc/fstab:
```bash
mount -a
```
- Montage d'un répertoire distant par NFS:
```bash
mount 192.1.1.254:/home /home/users/
```

- Options avec -o ou dans /etc/fstab :
```bash
mount -o
    default : rw,suid,dev,exec,auto,nouser,async,

    remount : changer les attributs d'un système monté,

    rw : lecture-écriture,

    ro : lecture seule,

    noauto : ne pas monter automatiquement avec -a,

    nodev : interdire les fichiers spéciaux,

    noexec : pas de fichiers exécutables,

    nosuid ; ignorer les bits Set-UID/GID,

    sync : écritures synchrones,

    user : peut être monté par un utilisateur.

    Types de systèmes de fichiers courants :

    ext2, ext3, msdos, vfat, proc, iso9660, udf, smb.
```

#### umount - Démontage d'un système de fichiers :
<a id="markdown-umount---d%C3%A9montage-d'un-syst%C3%A8me-de-fichiers-%3A" name="umount---d%C3%A9montage-d'un-syst%C3%A8me-de-fichiers-%3A"></a>

```bash
mount -a : démonte tous les systèmes dans /etc/mtab.

umount /dev/hda4

umount /mnt/dos

umount -a
```

> [WIKI](https://doc.ubuntu-fr.org/mount_fstab)

### DISTRIBUTION INSTALLATION DE LOGICIELS
<a id="markdown-distribution-installation-de-logiciels" name="distribution-installation-de-logiciels"></a>

Les logiciels Linux peuvent s'installer de différentes manières, il éxiste des dépots distants(serveurs) hébergeants des paquets installables via la commande "apt install", des paquets binaires sous forme d'éxécutables au format ".deb" pour les distributions Debian (rpm pour Red Hat) mais aussi des installateurs possédant leurs propres dépôts comme flatpak ou snap.

#### tar - Gestion d'archives :
<a id="markdown-tar---gestion-d'archives-%3A" name="tar---gestion-d'archives-%3A"></a>

Sous Debian, les archives sont au format ".tar":
```bash
tar
    -c : création d'archive,

    -x : extraction d'archive,

    -t : consultation d'archive,

    -f : nom du fichier archive,

    -v : mode volubile,

    -z : (dé)compresser avec g(un)zip,

    -j : (dé)compresser avec b(un)zip2.
```
- créer une archive compressée du répertoire distrib/:
```bash
tar -czf archive.tar.gz distrib/
```
- liste le contenu de l'archive:
```bash
tar -tvf archive.tar
```
- extrait le contenu d'une archive compressée:
```bash
tar -xjf archive.tar.bz2
```

- installation classique:
```bash
tar -xzf application-1.01.tar.gz

cd application-1.01

./configure

make && make install
```

#### rpm - Gestion des paquetages RedHat:
<a id="markdown-rpm---gestion-des-paquetages-redhat%3A" name="rpm---gestion-des-paquetages-redhat%3A"></a>

```bash
rpm 
-h : affichage de la progression du travail.

rpm -ivh paquet.rpm: installation d'un paquetage

rpm -Uvh paquet.rpm: mise à jour/installation d'un paquetage

rpm -Fvh paquet.rpm: mise à jour d'un paquetage déjà installé

rpm -e paquet: désinstallation d'un paquetage,

rpm -qa: liste de tous les paquetages installés

rpm -qf /chemin/fichier: recherche du paquetage auquel appartient le fichier

rpm -qip paquet.rpm: informations sur un paquetage

rpm -qlp paquet.rpm: liste des fichiers contenus dans le paquetage
```

#### apt - Gestion des paquets Debian :
<a id="markdown-apt---gestion-des-paquets-debian-%3A" name="apt---gestion-des-paquets-debian-%3A"></a>

installation de l'application et ressources éventuelles:
```bash
apt-get install application
```
suppression application et dépendances éventuelles:
```bash
apt-get remove application
```
mise à jour de la base de données interne,
```bash
apt-get update
```
Mise à jour du système.
```bash
apt-get upgrade
```

Les adresses des dépôts intérrogés lors de l'installation des paquets se trouve dans le fichier /etc/apt/sources.list.

Le premier bloc désigne le type de paquets contenus dans ce dépôt. Deux mentions possibles :
- deb qui désigne des paquets d'installation ;
- deb-src qui désigne des paquets sources ; ce type de paquet est utile aux développeurs, il contient les codes sources des paquets d'installation.

Le second bloc désigne l'URL vers le serveur de paquets.

Le troisième bloc identifie votre version de Debian. Vous ne devriez activer l'accès qu'à des dépôts pour Debian et pour votre version courante de Debian. Sinon, vous risquez de causer des instabilités sur votre système et le corrompre. La version de Debian est identifiée par son nom de code de développement.

La dernier bloc identifie les sections du dépôt auxquelles vous souhaitez accéder. Les paquets sont divisés en section selon qu'ils sont maintenus par l'équipe de Debian ou par la communauté des utilisateurs.
Voici la liste des sections pour la distribution Debian:
- stable
- testing
- unstable
- security
- experimental
- backports

> Note: Les adresses de dépôts nécessaires à minima sont:
- .../debian/ bullseye main --> destiné aux packages principaux
- .../debian-security/ bullseye-security main --> destiné aux packages de sécurité
- .../debian/ bullseye-update --> destiné aux packages d'update

Exemple de sources.list pour Debian 11:
```
deb http://deb.debian.org/debian/ bullseye main non-free
deb-src http://deb.debian.org/debian/ bullseye main non-free

deb http://security.debian.org/debian-security bullseye-security main
deb-src http://security.debian.org/debian-security bullseye-security main

deb http://deb.debian.org/debian/ bullseye-updates main
deb-src http://deb.debian.org/debian/ bullseye-updates main
```

Des dépôts non officiels peuvent être ajoutés dans le dossier /etc/apt/sources.list.d/ et permettra d'installer des paquets via la commande:
```bash
sudo apt update && sudo apt install nom-du-paquet
```

> Note: Il est important d'éffectuer la commande "apt update" avant l'installation pour que l'OS récupère la liste des paquets installables du dépôt nouvellement ajouté et ainsi avoir connaissance du nom de ces paquets pour la commande "apt install ...".

Plus d'infos: https://debian-facile.org/doc:systeme:apt:sources.list

> [DOC APT](https://debian-facile.org/doc:systeme:apt:apt)
> [DOC SOURCES.LIST](https://debian-facile.org/doc:systeme:apt:sources.list)

#### deb - Gestion des paquets deb
<a id="markdown-deb---gestion-des-paquets-deb" name="deb---gestion-des-paquets-deb"></a>

Certains éditeurs d'applications vont fournir un paquet installateur en format ".deb", ceux-ci sont installables par voie graphique en double cliquant sur le fichier ou par ligne de commande:
```bash
sudo dpkg -i nom-du-paquet.deb
```

### GESTION DES PROCESSUS
<a id="markdown-gestion-des-processus" name="gestion-des-processus"></a>

#### ps - État des processus :
<a id="markdown-ps---%C3%A9tat-des-processus-%3A" name="ps---%C3%A9tat-des-processus-%3A"></a>

- Affichage long de tous les processus du système:
```bash
ps -ef
    ou
ps -aux
```
- Affichage continu des processus du système:
```bash
top
    -d délai de rafraîchissement.
```

- renice - Changer la courtoisie d'un processus :
Augmenter la courtoisie du processus 12857 de 5 unités:
```bash
renice +5 12857
```

- Diminuer de 5 la courtoisie de tous les processus de root:
```bash
renice -5 -u root
```

#### kill - Envoyer un signal à un processus :
<a id="markdown-kill---envoyer-un-signal-%C3%A0-un-processus-%3A" name="kill---envoyer-un-signal-%C3%A0-un-processus-%3A"></a>
```bash
kill -15 12857
    -l (lettre l) : liste des signaux disponibles
```

- killall - Tuer tous les processus du même nom
```bash
killall -9 boucle_fork
```

- fuser - Liste des processus accédant à un fichier:
```bash
tuer tous les processus accédant à la partition indiquée:
fuser -k -m /dev/hda5
```

### GESTIONS DES UTILISATEURS / GROUPES / PERMISSIONS
<a id="markdown-gestions-des-utilisateurs-%2F-groupes-%2F-permissions" name="gestions-des-utilisateurs-%2F-groupes-%2F-permissions"></a>

Puisque Linux est un système multi-utilisateurs, cela signifie que plusieurs personnes peuvent interagir avec le même système en même temps. Il éxiste donc des commandes pour créer, éffacer des utilisateurs, changer leur mot de passe, les ajouter dans des groupes et un système de permissions sur les fichiers.

Ensuite pour ajouter son mot de passe, taper :
```bash
passwd le-mot-de_passe.
```
La suppression d’un utilisateur est très similaire à l’ajout d’un nouvel utilisateur. Pour supprimer le compte d’un utilisateur, tapez, userdel NomUtilisateur

> Note: Toutes ces commandes étant des commandes d'administration, elles nécessitent d'être executées par l'utilisateur root ou un utilisateur avec les droits sudo.

#### UTILISATEURS
<a id="markdown-utilisateurs" name="utilisateurs"></a>

- adduser est utilisé pour créer un nouvel utilisateur, tandis que passwd est l’ajout d’un mot de passe au compte de cet utilisateur. Pour ajouter une nouvelle personne nommée John, taper:
```bash
sudo useradd john
sudo useradd -m john # création du dossier personnel dans home
sudo useradd -m john -d /tmp/ # création du dossier personnel dans /tmp
sudo useradd -g sudo john # création du user john en l'ajoutant au groupe sudo
sudo useradd -s /bin/bash # création d'un utilisateur utilisant le shell bash 
```

> Note: Un certain nombre d'informations sont proposées lors de la création d'un nouvel utilisateur (numéro de tel, numéro de chambre, etc), il n'est pas systématiquement nécessaire de renseigner tout les champs.

- passwd
```bash
sudo passwd john 
```

- deluser:
```bash
sudo userdel john 
sudo userdel -r john # suppime le dossier personnel également
```

#### GROUPES
<a id="markdown-groupes" name="groupes"></a>

La gestion des groupes se fait via les commandes:
- addgroup pour créer un groupe
```bash
sudo addgroup dev
```

- delgroup pour supprimer un groupe
```bash
sudo delgroup dev
```

- ajouter un utilisateur à un groupe:
```bash
sudo usermod -aG dev john
            # groupe utilisateur
```

- recharger le groupe après un changement (ajout / suppréssion d'utilisateur):
```bash
sudo newgrp dev
```

#### PERMISSIONS
<a id="markdown-permissions" name="permissions"></a>

Les permissions sous Linux se gère d'une manière spécifique afin de gérer l'accès aux dossiers ou fichiers par les différents utilisateurs du système.

##### CHMOD
<a id="markdown-chmod" name="chmod"></a>

Chmod est une autre commande Linux, utilisée pour modifier les permissions de lecture, d’écriture et d’exécution des fichiers et des répertoires.

![](docs/chmod.png)

Il existe trois type de permissions:
- Lecture (r)
- Ecriture (w)
- éxecution (x)

Il existe trois champs de permissions sur les fihiers:
- Propriétaire
- Utilisateurs membre du même groupe que le propriétaire
- Tous les autres utilisateurs qui ne sont ni le propriétaire, ni membre du même groupe que le propriétaire

> Note: Le premier champs tout à gauche va indiquer si l'entrée est de type dossier (d) ou de type fichier (-).

##### CHOWN
<a id="markdown-chown" name="chown"></a>

Chown est une commande pour changer le propriétaire d'un fichier ou d'un dossier.
```bash
chown -R john:john /home/john/ # commande pour attribuer la proprété des fichiers dans le répertoire /home/john à l'utilisateur john (le paramètre -R est pour la récursivité)
```

Référence: https://www.leshirondellesdunet.com/chmod-et-chown

### UTILITAIRES RESEAU
<a id="markdown-utilitaires-reseau" name="utilitaires-reseau"></a>

Les utilitaires réseau ne sont pour la plupart non installé de base sur un système Linux.
Ils sont généralement installables via les commandes "apt install".

> Note: Une bonne partie de ces utilitaires font partie du package "net-tools"

#### route - Gestion de la table de routage du noyau :
<a id="markdown-route---gestion-de-la-table-de-routage-du-noyau-%3A" name="route---gestion-de-la-table-de-routage-du-noyau-%3A"></a>
- ajouter une route statique via l'interface eth0:
```bash
route add -net 192.1.1.0 eth0
```
- ajoute un réseau accessible par une passerelle:
```bash
route add -net 172.1.1.0 gw 192.1.1.5
```
- ajoute une route par défaut:
```bash
route add default eth1
```
- supprime la route par défaut:
```bash
route del default
```

#### netstat - Statistiques réseau:
<a id="markdown-netstat---statistiques-r%C3%A9seau%3A" name="netstat---statistiques-r%C3%A9seau%3A"></a>

- affiche la table de routage du noyau:
```bash
netstat -r
```
- affiche l'état des différentes interfaces:
```bash
netstat -i
```
- affiche l'état des sockets du système:
```bash
netstat -a
```

#### arp - Gestion de la table ARP du noyau :
<a id="markdown-arp---gestion-de-la-table-arp-du-noyau-%3A" name="arp---gestion-de-la-table-arp-du-noyau-%3A"></a>

- afficher toutes les entrées dans le cache ARP:
```bash
arp -a 
```
- supprimer les entrées concernant l'hôte indiqué:
```bash
arp -d hote
```

#### ping - demande d'écho vers d'autres hôtes :
<a id="markdown-ping---demande-d'%C3%A9cho-vers-d'autres-h%C3%B4tes-%3A" name="ping---demande-d'%C3%A9cho-vers-d'autres-h%C3%B4tes-%3A"></a>

- une seule requête et attend au plus 2 secondes:
```bash
ping -c 1 -w 2 192.1.1.53
```
- requête diffusée en broadcast à tous les hôtes du sous-réseau:
```bash
ping -b 192.1.1.255
```

#### traceroute - Chemin pour joindre un hôte :
<a id="markdown-traceroute---chemin-pour-joindre-un-h%C3%B4te-%3A" name="traceroute---chemin-pour-joindre-un-h%C3%B4te-%3A"></a>

```bash
traceroute www.destination.com
```

> option -n ne pas traduire les adresses numériques en noms.

#### tcpdump - Examen du trafic réseau :
<a id="markdown-tcpdump---examen-du-trafic-r%C3%A9seau-%3A" name="tcpdump---examen-du-trafic-r%C3%A9seau-%3A"></a>

- afficher tout ce qui circule sur eth0:
```bash
tcpdump -i eth0
```

- afficher les message depuis / vers le port 23 (telnet):
```bash
tcpdump -i eth0 port telnet
```

#### telnet - Connexion TCP/IP :
<a id="markdown-telnet---connexion-tcp%2Fip-%3A" name="telnet---connexion-tcp%2Fip-%3A"></a>

- connexion sur port 110 (Pop/3) du serveur de courrier:
```bash
telnet mail.isp.com pop-3
```

#### nmap - Scan réseau (non natif)
<a id="markdown-nmap---scan-r%C3%A9seau-non-natif" name="nmap---scan-r%C3%A9seau-non-natif"></a>

- scanner un réseau:
```bash
nmap 192.168.1.0/24
# ou
nmap 192.168.1.*
```

- scanner une / des machine (ports en écoute):
```bash
nmap 192.168.1.15 # une machine 
nmap 192.168.1.0-200 # interval de machines
```

- scanner tous les ports TCP:
```bash
nmap -sT 192.168.1.1
nmap -p T:80 192.168.1.1 # scan le port 80 TCP
```

- scanner tous les ports UDP:
```bash
nmap -sU 192.168.1.1
```

> [DOC](https://nmap.org/book/man.html)

#### ssh - Exécution sécurisée d'un shell distant.
<a id="markdown-ssh---ex%C3%A9cution-s%C3%A9curis%C3%A9e-d'un-shell-distant." name="ssh---ex%C3%A9cution-s%C3%A9curis%C3%A9e-d'un-shell-distant."></a>

```bash
ssh usera@192.168.1.54
```

Pour plus d'informations: https://git.legaragenumerique.fr/CNAM/ssh

#### rsync - Synchronisation de répertoire
<a id="markdown-rsync---synchronisation-de-r%C3%A9pertoire" name="rsync---synchronisation-de-r%C3%A9pertoire"></a>

rsync est une commande plus complète que cp (fonctionne également sur le reseau):
```bash
rsync source/ destination/
```
via SSH:
```bash
# MACHINE LOCALE VERS MACHINE DISTANTE
rsync -az source/ user@machine:/destination/
# MACHINE DISTANTE VERS MACHINE LOCALE
rsync -az user@machine:source/ /destination/
```
principales options:
```bash
rsync
    -a : archive ⇒ préserve les dates, permissions, etc … des fichiers. Inclus l'option récursivité. Option à utiliser quand on veut transférer des répertoires      entiers avec leurs sous-répertoires en préservant toutes les caractéristiques des fichiers.
    -r : la synchro est récursive (elle prend les sous-répertoires). Est inclus dans l'option -a
    -v : verbeux (affichage de ce que fait la commande pendant qu'elle le fait).
    -l : copie les liens symboliques comme liens symboliques. Est inclus dans l'option -a
    -L : remplace les liens symboliques par les fichiers référencés.
    -z : comprime les fichiers pendant le transfert. N'a d’intérêt que pour des transferts à travers des réseaux, car sinon la compression / décompression fait perdre du temps. 
```

:warning: Les permissions et la propriété des dossiers/fichiers changent lots du transfert. Seul root (super-utilisateur) permet de conserver ces dernières moyennat l'ajout des bon paramètres (-po)

> [WIKI](https://doc.ubuntu-fr.org/rsync)

#### ftp - Transferts de fichiers (obsolète):
<a id="markdown-ftp---transferts-de-fichiers-obsol%C3%A8te%3A" name="ftp---transferts-de-fichiers-obsol%C3%A8te%3A"></a>

- commandes usuelles:
```bash
open ftp.serveur.org

cd /chemin/distant/

lcd /chemin/local/

get fichier

put fichier

prompt

mget *.c

mput *.h
```

> Note: Commande obsolète car non crypté, préféré SFTP (par SSH)

#### wget - Rapatrier le contenu d'une URL:
<a id="markdown-wget---rapatrier-le-contenu-d'une-url%3A" name="wget---rapatrier-le-contenu-d'une-url%3A"></a>

```bash
wget http://www.site.com/repertoire/

    -c reprendre un transfert déjà entamé,

    -r charger récursivement les liens,

    -l niveau maximal de récursion,

    -k convertir les liens en pointeurs locaux.
```

#### curl - Afficher le contenu d'une ressource web:
<a id="markdown-curl---afficher-le-contenu-d'une-ressource-web%3A" name="curl---afficher-le-contenu-d'une-ressource-web%3A"></a>

```bash
curl https://www.legaragenumerique.fr
    -O permet d'enregistrer le contenu dans un fichier avec le nom identique à la ressource,

    -o permet d'enregistrer le contenu dans un fichier en choisissant le nom.
```

> Note: L'option -O permet d'enregistrer le contenu dans un fichier avec le nom identique à la ressource.

## SYSTEMD
<a id="markdown-systemd" name="systemd"></a>

![](docs/systemd.jpg)

### 1) DEFINITION:
<a id="markdown-definition%3A" name="definition%3A"></a>

systemd est un gestionnaire de système et de services pour Linux. Il est le système d'init par défaut dans Debian depuis Jessie. Systemd est compatible avec les scripts d'init SysV et LSB. Il peut fonctionner comme un remplaçant de sysvinit.
Les taches de systemd sont organisées en tant qu'unités. Les unités les plus courantes sont les services (.services), les points de montage (.mount), les périphériques (.device), les sockets (.socket) ou les minuteurs (.timer). Par exemple, le démarrage du démon shell sécurisé est effectué par l'unité ssh.service.

Systemd place chaque service dans un groupe de contrôle (cgroup) dédié au service. Les noyaux modernes prennent en charge l'isolation des processus et l'allocation des ressources en fonction des groupes de contrôle. 

Systemd s'exécute comme démon en tant que PID 1. 

### 2) PRINCIPE:
<a id="markdown-principe%3A" name="principe%3A"></a>

systemctl est l'outil principal utilisé pour inspecter et contrôler l'état du système « systemd » et du gestionnaire de service. Vous pouvez par exemple utiliser systemctl pour activer/désactiver les services de manière permanente ou uniquement pour la session en cours.

### 3) UTILISATION DE SYSTEMCTL:
<a id="markdown-utilisation-de-systemctl%3A" name="utilisation-de-systemctl%3A"></a>

#### STATUT SYSTEM
<a id="markdown-statut-system" name="statut-system"></a>

Afficher le statut du système :
```bash
systemctl status
```
Lister les unités échouées :
```bash
$ systemctl --failed
```

#### GESTION DES SERVICES
<a id="markdown-gestion-des-services" name="gestion-des-services"></a>

Lister tout les services en cours d'exécution :
```bash
$ systemctl
```
Activer le service « exemple1 » :
```bash
systemctl start exemple1
```
Désactiver le service « exemple1 » : 
```bash
systemctl stop exemple1
```
Redémarrer le service « exemple1 » immédiatement :
```bash
systemctl restart exemple1
```
Voir le statut du service « exemple1 » :
```bash
systemctl status exemple1
```
Activer « exemple1 » pour être lancé au démarrage :
```bash
systemctl enable example1
```
Désactiver « exemple1 » pour ne pas être lancé au démarrage :
```bash
systemctl disable exemple1
```

#### CREATION DE SERVICE
<a id="markdown-creation-de-service" name="creation-de-service"></a>

Les unités sont définies par des fichiers de configuration individuels appelés fichiers unités. Le type de l'unité est reconnu par le suffixe du nom de fichier, .mount dans le cas d'un point de montage. Les fichiers unités fournis par Debian sont situés dans le répertoire /lib/systemd/system.

Les administrateurs système doivent placer des fichiers d'unités personnalisés dans /etc/systemd/system.

Si un fichier d'unité locale nommé de manière identique existe dans le répertoire /etc/systemd/system, il aura priorité et systemd ignorera le fichier dans le répertoire /lib/systemd/system.

exemple de création de service:
```bash
# cat /etc/systemd/system/exemple.service.d/exemple.conf
[Service]
ExecStart=
ExecStart=/usr/sbin/exemple-service --my-options
```
Tester la configuration:
```bash
init=/lib/systemd/systemd
```

> [WIKI](https://doc.ubuntu-fr.org/creer_un_service_avec_systemd)

## CRON
<a id="markdown-cron" name="cron"></a>

![](docs/cron.png)

### 1) DEFINITION:
<a id="markdown-definition%3A" name="definition%3A"></a>

Cron est un programme qui permet aux utilisateurs des systèmes Unix d’exécuter automatiquement des scripts, des commandes ou des logiciels à une date et une heure spécifiée à l’avance,
ou selon un cycle défini à l’avance.<br>
Cron est la troncation de crontab, lui-même la troncation de chrono table qui signifie « table de planification ».

cron est un daemon, ce qui, dans le jargon informatique, désigne un programme qui s'exécute en arrière-plan. Le service cron (crond) attend ainsi jusqu’au moment spécifié dans le fichier de configuration (que l’on appelle la crontab) puis effectue l’action correspondante et se rendort jusqu’à l’événement suivant.

Le service cron est lancé par le compte root afin de pouvoir s’adapter à l’identité de chacun des utilisateurs. Sur certains Unix, si on le tue (par la commande kill), il est automatiquement relancé par le système. 

### 2) PRINCIPE:
<a id="markdown-principe%3A" name="principe%3A"></a>

![](docs/crontab.png)

### 2) UTILISATION:
<a id="markdown-utilisation%3A" name="utilisation%3A"></a>
- Créer une tâche:
```bash
crontab -e
```
- Lister les tâches:
```bash
crontab -l
```

Pour plus d'informations: 
> https://doc.ubuntu-fr.org/cron
> https://crontab.guru/

## EXERCICES
<a id="markdown-exercices" name="exercices"></a>

### 1) AJOUTES UN UTILISATEUR
<a id="markdown-ajoutes-un-utilisateur" name="ajoutes-un-utilisateur"></a>

- Créer un utilisateur "john" apartenant au groupe docker (créer le groupe docker) et sudo avec un dossier /home/ dédié ayant pour mot de passe "MotDePasse"

### 2) "MARK THE DATE"
<a id="markdown-%22mark-the-date%22" name="%22mark-the-date%22"></a>

- Créer une tâche système appelant un script situé dans le dossier /workspace/scripts/ ayant pour nom date-logger.sh se déclenchant tout les jours de la semaine à 4h00 sauf le dimanche
- Le script date-logger.sh doit lancer une commande inscrivant la date dans le dossier /workspace/log/date-log.log

### 3) INSTALLATION DE PAQUETS
<a id="markdown-installation-de-paquets" name="installation-de-paquets"></a>

- Installer le paquet "nginx" via la ligne de commande et faire que le service se lance au démarrage de l'OS.
- Installer le paquet "VS codium" en ligne de commande

### 4) APPELES UN AMI
<a id="markdown-appeles-un-ami" name="appeles-un-ami"></a>

- Créer une tâche système appelant un script situé dans le dossier /workspace/scripts/ ayant pour nom date-logger.sh qui créer une archive tar appelée backup-logs-10-11-21.tar à partir du dossier /var/log et effectue une copie de cette archive dans un dossier backup-tar situé dans /etc/backups-tar/ avant de supprimer l'archive originale.
* note: le nom de l'archive backup-logs-10-11-21.tar est donné à l'aide de lafonction date pour signifier la date de la sauvegarde, la date est à intégrer dynamiquement.

## ALLER PLUS LOIN
<a id="markdown-aller-plus-loin" name="aller-plus-loin"></a>

- https://overthewire.org/wargames/bandit/
- https://openclassrooms.com/forum/sujet/exercices-bash-57809
