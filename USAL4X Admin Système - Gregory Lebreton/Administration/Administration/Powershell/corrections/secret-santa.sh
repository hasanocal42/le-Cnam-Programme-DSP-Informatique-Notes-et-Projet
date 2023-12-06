#! /bin/bash

echo "entrez le nombre de participants: "
read nb

declare -a participants

# entrer le nom de chaque participants et mise dans le tableau
i=1
while [ $i -le $nb ]
do
    echo "entrer le nom du participant $i :"
    read participant
    participants+=("$participant")
    let "i=i+1"
done

# on mélange le tableau
declare -a participantsmixes
participantsmixes=( $(shuf -e "${participants[@]}") )

# on output le tout (pour 4 participants A B C et D, : A offre à B qui offre a C qui offre a D qui offre a A)
i=1
while [ $i -lt $nb ]
do
    echo "${participantsmixes[(($i-1))]}  offre un cadeau à ${participantsmixes[i]}"
    let "i=i+1"
done

echo "${participantsmixes[(($nb-1))]}  offre un cadeau à ${participantsmixes[0]}"
