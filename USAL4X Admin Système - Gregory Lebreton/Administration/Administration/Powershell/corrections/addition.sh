#!/bin/bash
echo "entrer le premier chiffre"
read a
echo "entrer le deuxieme chiffre"
read b

echo "Le résultat de  $a + $b est égal à" $(($a + $b))