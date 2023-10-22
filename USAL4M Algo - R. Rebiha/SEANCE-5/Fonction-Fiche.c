================
	Function
================

1. Definition de la fonction
=============================

TypeRetour nomFonction (listeParametre){
	corpsFonction.
}

- TypeRetour => Le type de la variable que retourne la valeur/resultat de sortie. Si la fonction ne retourne pas de resultat, elle effectue un "service"/une procedure et dans cas le type de retour est "void" (vide en anglais).
- listeParamtre => liste de "type variable" separe par des ",". Ces variable sont LOCALS: elles vivent uniquement a l'interieur de la fonction. Autrement dit, la portée des variables est dit locale : en dehors de la fonction, il n'y plus rien en memoire.
- corpsFonction => ensemble des instructions.

2. Appel de fonction
====================
- L'appel de la fonction se fait endehors de la definition de la fonction. 
-A l'appel on founit les valeurs des parametres requits par la fonction, i.e., listeParametre

3. Parametre necessaires à l'appel
==================================
- On doit fournir des valeurs au variable locale dans la listeParametre.

4. Exemple:
===========

void DisBonjour (int nombreDeBjrs){//Definition
	for(int d = 0; d < nombreDeBjrs, d++){
		printf("Bonjour");
	}
}

int main(){
	DisBonjour(10);//Appel avec valeur de parametre 10.
return 0; 	
}