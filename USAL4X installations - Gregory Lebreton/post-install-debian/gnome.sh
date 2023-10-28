#!/bin/bash
###############
# Preparation #
###############
if [[ -z $PERSO ]]; then
	PERSO=$USER
	STANDALONE=1
fi
HOME="/home/$PERSO"
PICTURES_DIR=$(grep PICTURES ~/.config/user-dirs.dirs | cut -d'=' -f2 | sed 's/"//g; s/$HOME\///')

#############
# Questions #
#############
if [ $STANDALONE -eq 1 ]; then
  THEMES=$(whiptail --title "Thème général" --radiolist "Choisissez votre thème parmi ces choix :" 15 60 5 \
    "Theme 1 :" "Layan-gtk-theme" OFF \
    "Theme 2 :" "Vimix-gtk-themes" OFF \
    "Theme 3 :" "Fluent-gtk-theme" OFF \
    "Theme 4 :" "Qogir-gtk-theme" ON \
    "Theme 5 :" "WhiteSur-gtk-theme" OFF 3>&1 1>&2 2>&3)
fi
##############
# Copy files #
##############
cp -n files/nord.png files/macos-sierra-nevada-mountain.jpg $HOME/"$PICTURES_DIR"/
mkdir $HOME/.local/share/fonts
cp -rn files/ubuntu-mono $HOME/.local/share/fonts/
fc-cache

##################
# General config #
##################
gsettings set org.gnome.desktop.wm.preferences button-layout appmenu:minimize,maximize,close
gsettings set org.gnome.desktop.interface cursor-theme 'DMZ-White'
gsettings set org.gnome.desktop.background picture-uri "file://$(pwd)/files/nord.png"
gsettings set org.gnome.mutter dynamic-workspaces false
gsettings set org.gnome.desktop.wm.preferences num-workspaces 5
gsettings set org.gnome.desktop.interface clock-show-date true
gsettings set org.gnome.shell favorite-apps "['firefox-esr.desktop', 'org.gnome.Nautilus.desktop', 'libreoffice-startcenter.desktop', 'org.gnome.Software.desktop']"
gsettings set org.gnome.desktop.interface monospace-font-name "UbuntuMono Nerd Font Regular 15"
gsettings set org.gnome.shell enabled-extensions "[\
	'user-theme@gnome-shell-extensions.gcampax.github.com',\
	'drive-menu@gnome-shell-extensions.gcampax.github.com',\
	'dash-to-panel@jderose9.github.com',\
	'ding@rastersoft.com',\
	'arcmenu@arcmenu.com'\
	]"

##############
# Extensions #
##############
git clone https://gitlab.com/rastersoft/desktop-icons-ng
(cd desktop-icons-ng ; ./local_install.sh)
git clone https://github.com/home-sweet-gnome/dash-to-panel
(cd dash-to-panel ; git checkout gnome-3.38 ; make install)
git clone https://gitlab.com/arcmenu/ArcMenu.git
(cd ArcMenu ; git checkout gnome-3.36/3.38 ; make install)
dconf load /org/gnome/shell/extensions/ < files/extensions.dump
rm -rf desktop-icons-ng dash-to-panel ArcMenu

#################
# Theme install #
#################
mkdir ./icons ./themes $HOME/.icons
if [ -z "$THEMES" ]; then
  echo -e "\e[91mAucun thème n'a été choisi"
else
  echo -e "\e[93mVous avez choisi le theme : $THEMES"
  case "$THEMES" in
  "Theme 1 :")
    git clone https://github.com/vinceliuice/Layan-gtk-theme.git themes/
    git clone https://github.com/vinceliuice/Tela-icon-theme icons/
    (cd themes/ ; ./install.sh)
    (cd icons/ ; ./install.sh)
    gsettings set org.gnome.desktop.interface gtk-theme "Layan-Dark"
    gsettings set org.gnome.desktop.interface icon-theme "Tela"
    gsettings set org.gnome.shell.extensions.user-theme name "Layan-Dark"
    ;;
  "Theme 2 :")
    git clone https://github.com/vinceliuice/vimix-gtk-themes.git themes/
    git clone https://github.com/vinceliuice/vimix-icon-theme icons/
    (cd themes/ ; ./install.sh)
    (cd icons/ ; ./install.sh)
    gsettings set org.gnome.desktop.interface gtk-theme "vimix-light-doder"
    gsettings set org.gnome.desktop.interface icon-theme "Vimix"
    gsettings set org.gnome.shell.extensions.user-theme name "vimix-dark-doder"
    ;;
  "Theme 3 :")
    git clone https://github.com/vinceliuice/Fluent-gtk-theme.git themes/ 
    git clone https://github.com/vinceliuice/Fluent-icon-theme icons/
    (cd themes/ ; ./install.sh)
    (cd icons/ ; ./install.sh)
    gsettings set org.gnome.desktop.interface gtk-theme "Fluent-Dark"
    gsettings set org.gnome.desktop.interface icon-theme "Fluent"
    gsettings set org.gnome.shell.extensions.user-theme name "Fluent-Dark" 
    ;;
  "Theme 4 :")
    git clone https://github.com/vinceliuice/Qogir-theme themes/
    git clone https://github.com/vinceliuice/Qogir-icon-theme icons/
    (cd themes/ ; ./install.sh)
    (cd icons/ ; ./install.sh)
    gsettings set org.gnome.desktop.interface gtk-theme 'Qogir-Dark'
    gsettings set org.gnome.desktop.interface icon-theme 'Qogir-dark'
    gsettings set org.gnome.shell.extensions.user-theme name 'Qogir-Dark'
    ;;
  "Theme 5 :")
    git clone https://github.com/vinceliuice/WhiteSur-gtk-theme themes/
    git clone https://github.com/keeferrourke/la-capitaine-icon-theme icons/la-capitaine-icon-theme
    (cd themes/ ; ./install.sh)
    mv icons/la-capitaine-icon-theme/ $HOME/.icons
    gsettings set org.gnome.desktop.interface gtk-theme "WhiteSur-Dark"
    gsettings set org.gnome.desktop.interface icon-theme "la-capitaine-icon-theme"
    gsettings set org.gnome.shell.extensions.user-theme name "WhiteSur-Dark"
    gsettings set org.gnome.desktop.background picture-uri "file://$(pwd)/files/macos-sierra-nevada-mountain.jpg"
    ;;
  *)
    echo -e "\e[91mUnsupported item $THEMES!" >&2
    exit 1
    ;;
  esac
fi

############
# Cleaning #
############
rm -rf ./themes
rm -rf ./icons
if [ $STANDALONE -eq 1 ]; then
	busctl --user call "org.gnome.Shell" "/org/gnome/Shell" "org.gnome.Shell" "Eval" "s" 'Meta.restart("Restarting…")';
fi
