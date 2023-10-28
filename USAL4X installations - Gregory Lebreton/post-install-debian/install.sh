#!/bin/bash
# authors : https://gitlab.com/Mxaxax - https://gitlab.com/edricus
if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

###################
## USER CREATION ##
###################
printf "\033[32;5m== Creation des utilisateurs...\033[0m\n"

## BELLINUXIEN
if id "bellinuxien" >/dev/null 2>&1; then
  echo -e "\e[93ml'utilisateur bellinuxien existe déjà"
else
	if (whiptail --yesno "Voulez-vous créer l'utilisateur bellinuxien ?" 8 78  --title "Creation de l'utilisateur bellinuxien" 3>&1 1>&2 2>&3); then
  	adduser bellinuxien --gecos "" --disabled-password --quiet
  	PASSWORD=1
  	while [[ $PASSWORD != $VERIF ]]; do
  	  PASSWORD=$(whiptail --passwordbox "Entrez le mot de passe de bellinuxien" 8 78 --title "Creation de l'utilisateur bellinuxien" 3>&1 1>&2 2>&3)
  	  VERIF=$(whiptail --passwordbox "Entrez une nouvelle fois le mot de passe" 8 78 --title "Creation de l'utilisateur bellinuxien" 3>&1 1>&2 2>&3)
  	  if [[ $PASSWORD != $VERIF ]]; then
  	    whiptail --msgbox "Les mots de passe ne correspondent pas !" --title "Creation de l'utilisateur bellinuxien" 8 78
  	  fi
  	done
  	echo "bellinuxien:"$PASSWORD"" | chpasswd
  	usermod -aG sudo bellinuxien
  	cat << EOF > /var/lib/AccountsService/users/bellinuxien
[User]
SystemAccount=true
EOF
  fi
fi

## PERSO / VISITEUR
PERSO='1 1' # ugly workaround to start the space-in-string verfication loop
PASSWORD=1
if (whiptail --yesno "Voulez-vous créer un utilisateur ?" 8 78  --title "Creation d'un utilisateur perso" 3>&1 1>&2 2>&3); then
  while [[ ! -z $(echo $PERSO | grep "[[:space:]]") ]]; do
    PERSO="$(whiptail --inputbox --separate-output --title "Creation d'un utilistateur perso" 3>&1 1>&2 2>&3 \
      "Entrez le nom d'utilisateur à créer" 8 40 visiteur)"
    if [[ ! -z $(echo $PERSO | grep "[[:space:]]") ]]; then
      whiptail --msgbox "Le nom d'utilisateur ne doit pas contenir d'espaces !" --title "Creation d'un utilisateur perso" 8 78
    fi
  done
  if [[ $PERSO == visiteur ]]; then
    if id "visiteur" >/dev/null 2>&1; then
      echo -e "\e[93mL'utilisateur visiteur existe déjà"
    else
      adduser visiteur --gecos "visiteur" --disabled-password --quiet
      usermod -a -G cdrom,floppy,audio,bluetooth,dip,video,plugdev,scanner,netdev,lp,lpadmin visiteur
      echo 'visiteur:visiteur' | chpasswd
    fi
  else
    while [[ $PASSWORD != $VERIF ]]; do
      PASSWORD=$(whiptail --passwordbox "Entrez le mot de passe" 8 78 --title "Creation d'un utilisateur perso" 3>&1 1>&2 2>&3)
      VERIF=$(whiptail --passwordbox "Entrez une nouvelle fois le mot de passe" 8 78 --title "Creation d'un utilisateur perso" 3>&1 1>&2 2>&3)
      if [[ $PASSWORD != $VERIF ]]; then
        whiptail --msgbox "Les mots de passe ne correspondent pas !" --title "Creation d'un utilisateur perso" 8 78
      else
        adduser $PERSO --gecos "${PERSO^}" --disabled-password --quiet
        echo "$PERSO:"$PASSWORD"" | chpasswd
        if (whiptail --yesno "Voulez-vous ajouter cet utilisateur au groupe sudo ?" --title "Creation d'un utilisateur perso" 8 78 3>&1 1>&2 2>&3) then
          usermod -aG sudo $PERSO
        fi
      fi
    done
  fi
  else PERSO=$(id -nu 1000)
fi
if [[ -z $PERSO ]]; then
	PERSO=$(id -nu 1000)
fi

##################
## QUESTIONS DE ##
##################
printf "\033[0;32m== Choix de l'environnement de bureau... \033[0m\n"
DE=$(whiptail --separate-output --title "Environnements de bureau" --radiolist \
  "Quel environnement de bureau utiliser ?" 10 60 3 \
  "MATE" "Leger, convient aux PC anciens" OFF \
  "KDE" "Complexe, adapté au multi-tâche" OFF \
  "GNOME" "Moderne, ergonomie et visuel soigné   " ON 3>&1 1>&2 2>&3)
printf "\033[0;32m== Choix du profil... \033[0m\n"
PROFIL=$(whiptail --separate-output --title "Profils" --checklist \
  "Quels profils d'utilisateurs sur cet ordinateur?" 15 90 10 \
  "Team-Working" "Des logiciels pour le travail collaboratif" ON \
  "Enfants" "Des jeux et des outils éducatifs" OFF \
  "Seniors" "Des outils d'accessibilité" OFF \
  "Gamer" "Des jeux, des jeux ,des jeux" OFF \
  "MAO" "Des logiciels pour la création musicale" OFF \
  "DevOps" "Des logiciels pour s'initier à l'approche DevOps" OFF \
  "Toshiba_toughbook" "Correction de bug pour le son" OFF 3>&1 1>&2 2>&3)

#####################
## PACKAGE MANAGER ##
#####################
printf "\033[0;32m== Configuration de APT... \033[0m\n"
cp files/sources.list /etc/apt/sources.list
dpkg --add-architecture i386
apt-get update -y
apt-get upgrade -y

#############################
## INTERNET ACCESS CONTROL ##
#############################
echo $'[main]\ndns=none' | tee /etc/NetworkManager/conf.d/90-dns-none.conf &>/dev/null
systemctl reload NetworkManager
sed -i '1,4 s/^/#/' /etc/resolv.conf && sed -i -e '$anameserver 1.1.1.2\nnameserver 2606:4700:4700::1112' /etc/resolv.conf
systemctl reload NetworkManager

###################
## BASE PACKAGES ##
###################
printf "\033[0;32m== Installation des programmes de base... \033[0m\n"
apt-get install -yqq -yqq git curl wget zip unzip bash-completion gnome-tweaks snapd flatpak gnome-software-plugin-flatpak libxdo3
flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo

##################
## CONFIG FILES ##
##################
ACCOUNTSSERVICE="/var/lib/AccountsService/users/"$PERSO""

# SOURCES.LIST
printf "\033[0;32m== Ajout des backports dans sources.list... \033[0m\n"
if [ -z "$(grep 'bullseye-backports' /etc/apt/sources.list)" ]; then
  echo "deb http://deb.debian.org/debian bullseye-backports main contrib non-free" >> /etc/apt/sources.list
  apt-get update
fi

# BASHRC
printf "\033[0;32m== Modification de bashrc... \033[0m\n"
mv /home/"$PERSO"/.bashrc /home/"$PERSO"/.bashrc.BACK
cp -r files/bashrc /home/"$PERSO"/.bashrc

################
## INSTALL DE ##
################
if [ -z "$DE" ]; then
  echo -e "\e[91mAucun profil n'a été choisi"
else
  for i in $DE; do
    echo -e "\e[93mVous avez choisis le bureau : $DE"
    case "$i" in
    "MATE")
      if [[ ! -z $(ps -aux | grep mate-panel$) ]]; then
        echo "MATE est déjà installé"
      else
        apt-get purge --autoremove *gnome* *kde* -y
        apt-get install -yqq gnome-system-tools blueman gnome-software ttf-mscorefonts-installer -y
        tasksel install mate-desktop
        sed -i '/XSession/d' $ACCOUNTSSERVICE
        sed -i '/Session/a XSession=mate' $ACCOUNTSSERVICE 
        whiptail --msgbox "Les changements seronts appliqués au prochain redémarrage" 8 78
      fi
      ;;
    "KDE")
      if [[ ! -z $(ps -aux | grep kded4$) ]]; then
        echo "KDE est déjà installé"
      else
        apt-get purge --autoremove *gnome* *mate* -y
        tasksel install kde-desktop
        apt-get install -yqq ttf-mscorefonts-installer -y 
        sed -i '/XSession/d' $ACCOUNTSSERVICE
        sed -i '/Session/a XSession=kde' $ACCOUNTSSERVICE 
        whiptail --msgbox "Les changements seronts appliqués au prochain redémarrage" 8 78
      fi
      ;;
    "GNOME")
      if [[ ! -z $(ps -aux | grep gnome-session$) ]]; then
        echo "GNOME est déjà installé"
      else
        apt-get purge --autoremove *mate* *kde* -y
        tasksel install gnome-desktop
        apt-get install -yqq gnome-tweak-tool gnome-screensaver arc-theme dmz-cursor-theme -y
        sed -i '/XSession/d' $ACCOUNTSSERVICE
        sed -i '/Session/a XSession=gnome' $ACCOUNTSSERVICE 
        whiptail --msgbox "Les changements seronts appliqués au prochain redémarrage" 8 78
      fi
      ;;
    *)
      echo -e "\e[91mUnsupported item $DE !" >&2
      exit 1
      ;;
    esac
  done
fi

#####################
## INSTALL PROFILE ##
#####################
for i in $PROFIL; do
  echo -e "\e[93mVous avez choisi le profil : $PROFIL"
  case "$i" in
  "Enfants")
    echo $'[main]\ndns=none' | tee /etc/NetworkManager/conf.d/90-dns-none.conf
    sed -i '1,6 s/^/#/' /etc/resolv.conf
    sed -i -e '$anameserver 1.1.1.3\nnameserver 2606:4700:4700::1113' /etc/resolv.conf
    apt-get install -yqq veyon-service tuxpaint pingus numptyphysics warmux xmoto slimevolley arduino -y
    apt-get install -yqq -t bullseye-backports gcompris-qt -y
    ;;
  "Seniors")
    # Skype
    wget --timeout 5 --tries 3 https://go.skype.com/skypeforlinux-64.deb
    dpkg -i skypeforlinux-64.deb
    apt-get install -yqq -f
    rm -rf skypeforlinux-64.deb
    # Outlook
    cp files/desktopfiles/outlook.desktop /usr/share/applications/outlook.desktop
    ## Outlook unofficial client
    #curl -s https://api.github.com/repos/julian-alarcon/prospect-mail/releases/latest | grep "browser_download_url.*deb" | cut -d : -f 2,3 | tr -d \" | wget --timeout 5 --tries 3 --show-progress -qi -
    #dpkg -i prospect-mail_*_amd64.deb
    #apt-get install -yqq -f
    #rm -rf prospect-mail_*_amd64.deb
    # Rustdesk install
    cd /tmp && wget https://github.com/rustdesk/rustdesk/releases/download/1.1.9/rustdesk-1.1.9.deb && dpkg -i rustdesk-1.1.9.deb && rm -rf rustdesk-1.1.9.deb
    ;;
  "Gamer")
    yes | apt-get install -yqq veyon-service steam -y 
    # Discord
    wget --timeout 5 --tries 3 -O discord.tar.gz "https://discordapp.com/api/download?platform=linux&format=tar.gz"
    tar -xf discord.tar.gz
    desktop-file-validate Discord/discord.desktop
    mv Discord/discord.desktop /usr/share/applications/
    mv Discord /usr/share/
    ln -s /usr/share/Discord/Discord /usr/bin/discord
    # Autres
    snap install urban-terror warzone2100 flightgear stuntrally extreme-tux-racer tmnationsforever mc-installer mari0-ce liveforspeed opensurge crrcsim-simulator love
    snap install {savagexr,pixels-game} --beta 
    ;;
  "MAO")
    apt-get install -yqq playonlinux lmms audacity mixxx ardour rosegarden soundconverter qtractor -y 
    wget --timeout 5 --tries 3 https://dl.4kdownload.com/app/4kyoutubetomp3_4.6.2-1_amd64.deb
    dpkg -i ./4kyoutubetomp3_4.6.2-1_amd64.deb
    apt-get install -yqq -f
    rm -rf ./4kyoutubetomp3_4.6.2-1_amd64.deb
    ;;
  "Team-Working")
    apt-get install -yqq gimp gitso soundcgimp onverter scribus chromium chromium-l10n vlc brasero pdfarranger -y
    # Signal
    echo 'deb [signed-by=/usr/share/keyrings/signal-desktop-keyring.gpg arch=amd64] https://updates.signal.org/desktop/apt xenial main' > /etc/apt/sources.list.d/signal.list
    wget --timeout 5 --tries 3 -O- https://updates.signal.org/desktop/apt/keys.asc | gpg --dearmor > signal-desktop-keyring.gpg
    cat signal-desktop-keyring.gpg > /usr/share/keyrings/signal-desktop-keyring.gpg
    rm -rf signal-desktop-keyring.gpg
    # Zoom
    wget --timeout 5 --tries 3 https://zoom.us/client/5.13.7.683/zoom_amd64.deb
    dpkg -i zoom_amd64.deb
    apt-get install -yqq -f
    rm -rf zoom_amd64.deb
    # Telegram
    wget --timeout 5 --tries 3 "https://telegram.org/dl/desktop/linux" -O telegram.tar.xz
    tar -xf telegram.tar.xz
    mv Telegram/Telegram /usr/local/bin/telegram
    cp files/telegram-desktop.desktop /usr/share/applications/
    # Autres
    snap install messenger-collabee yakyak whatsdesk && \
    snap install slack --classic 
    snap install cawbird --edge   
    ;;
  "DevOps")
    mkdir devops && git clone https://gitlab.com/Mxaxax/installations.git devops/ && bash devops/devops.sh && rm -rf ./devops/
    ;;
  "Toshiba_toughbook")
    mkdir ./toshiba && git clone https://gitlab.com/garagenum/tools/linux/debian-customizer.git toshiba/ && mv /usr/share/pulseaudio/alsa-mixer/paths/analog-output-speaker.conf /usr/share/pulseaudio/alsa-mixer/paths/analog-output-speaker.conf.BACK && cp -r ./toshiba/custom-debian-conf/system-conf/analog-output-speaker.conf /usr/share/pulseaudio/alsa-mixer/paths/analog-output-speaker.conf
    rm -rf ./toshiba/
    ;;
  *)
    echo -e "\e[91mUnsupported item $PROFIL!" >&2
    exit 1
    ;;
  esac
done

###############
## APPARENCE ##
###############

## Desktop environment
echo "DE is $DE"
echo "User is $PERSO"
if [ "$(echo $DE)" == 'GNOME' ]; then
  apt-get install gettext meson ninja-build dmz-cursor-theme -y
  printf '\n'
  echo "Pour la configuration de gnome, basculer sur $PERSO et executez le script \'gnome.sh\' sans sudo. Si aucun utilisateur n'a été créé, juste executez gnome.sh tout de suite"
  printf '\n'
fi

###########
# Firefox #
###########
## ne fonctionne plus : https://blog.mozilla.org/addons/2019/10/31/firefox-to-discontinue-sideloaded-extensions/
# printf "\033[0;32m== Téléchargement des extensions firefox depuis addons.mozilla.org... \033[0m\n"
# mkdir ./addons
# # Ublock 
# curl -s https://api.github.com/repos/gorhill/uBlock/releases/latest \
# | grep "browser_download_url.*firefox.xpi" \
# | cut -d : -f 2,3 \
# | tr -d \" \
# | wget -qi - -P addons/ublock-origin.xpi

# SOFTWARES INSTALLATION
# printf "\033[0;32m== Installation des logiciels : Element, VScodium...\033[0m\n"
## ELEMENT (logiciel libre de messagerie instantanée)
# apt-get install -yqq software-properties-common apt-get-transport-https wget --timeout 5 --tries 3 -y
# wget --timeout 5 --tries 3 -O- https://packages.riot.im/debian/riot-im-archive-keyring.gpg | gpg --dearmor | tee /usr/share/keyrings/riot-im-archive-keyring.gpg
# echo "deb [signed-by=/usr/share/keyrings/riot-im-archive-keyring.gpg] https://packages.riot.im/debian/ default main" | tee /etc/apt-get/sources.list.d/riot-im.list
# apt-get update -y
# apt-get install -yqq riot-desktop -y

## VSCODIUM (éditeur de code | fork de Visual Studio Code)
# wget --timeout 5 --tries 3 -qO - https://gitlab.com/paulcarroty/vscodium-deb-rpm-repo/raw/master/pub.gpg |
#   gpg --dearmor |
#   dd of=/usr/share/keyrings/vscodium-archive-keyring.gpg
# echo 'deb [ signed-by=/usr/share/keyrings/vscodium-archive-keyring.gpg ] https://download.vscodium.com/debs vscodium main' |
#   tee /etc/apt-get/sources.list.d/vscodium.list
# apt-get update -y && apt-get install -yqq codium -y

# Restart GNOME
# su -c "busctl --user call "org.gnome.Shell" "/org/gnome/Shell" "org.gnome.Shell" "Eval" "s" 'Meta.restart("Restarting…")';" $PERSO
