#!/bin/bash
nombre=1
utilisateur1="jean-michel"
utilisateur2="jean"
utilisateur3="michel"

declare -a utilisateurs

# creation des utilisateurs + mise dans le tableau
while [ $nombre -lt 4 ]
do
    utilisateur="utilisateur${nombre}"
    sudo useradd "${!utilisateur}"
    utilisateurs[$nombre]="${!utilisateur}"
    let "nombre=nombre+1"
done

# enumeration des utilsateurs
for i in ${!utilisateurs[@]}
do
echo "l'utilisateur $i est ${utilisateurs[$i]}"
done
