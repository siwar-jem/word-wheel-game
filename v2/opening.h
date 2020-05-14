#ifndef OPENING_H
#define OPENING_H
#include<iostream>
#include<cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include<time.h>
#include <unistd.h>
#include<fstream>
#include<vector>
#include<map>
#include <iostream>
#include <string>


using namespace std;


class opening
{

string language;
string lvl;
string name;
public:
	void wecoming()
	{
		cout << "---------------WELCOM IN THIS WORD WHEEL GAME! ---------------\n" <<endl<<endl<< "the creators are:\n" << "Najemeddine Marzouki\n" << "Houssem Sassi\n" << "Meriam Chaieb\n" << "Siwar Jemai" << endl;
		string rep;
		cout << "Do you want to know the rules ? (yes or no)"<<endl;
		cin >> rep;
		if (rep == "yes" and language=="francais"){
			cout<<endl<<"**************************************************************************"<<endl<<endl;
			cout << "REGLES DU JEU\n.Generalites:\n    -Ce  jeux est jouer par un unique joueur\n    -La communication est faite a travers le terminal \n    -Chaque joueur doit commencer par inscrire ses coordonnees (nom et prenom) afin d'acceder au jeu\n    -Le joueur doit choisir le niveau de difficulte dans lequel il va jouer\n    -La duree de la partie du jeux depend de la difficuté deja choisie \n       * Niveau facile:       5 minutes de jeux\n       * Niveau moyen:	      3 minutes de jeux\n       * Niveau difficile:    2 minutes de jeux\n    -Le joueur invite a saisir des mots construit seulement a partir des 9 lettres deja donnees\n    -La partie est renouvlable\n"; 
			cout<<"	 \n.Mots acceptes:\n    -Le joueur est invite a saisir des mots construit seulement a partir des 9 lettres deja données\n    -Le plus petit mot est de longuer  de trois lettres\n    -Le plus long mot est de longueur 9 lettres \n    -Chaque lettre doit etre utiliser une seule fois sauf dans le cas ou la lettre se repete deja dans les 9 lettres deja donnees \n    -Le calcul de score se fait suivant la regle suivante: chaque lettre d'un mot valide vous donne acces à 5 points de plus pour votre score \n";
			cout<<endl<<endl<<"**************************************************************************"<<endl;	
		}else if(rep == "yes" and language=="anglais"){
			
			cout<<endl<<"**************************************************************************"<<endl<<endl;
			cout << ".General:\n   - This game is played by a single player\n    - Communication is made through the terminal\n    - Each player must start by entering their contact details (name and surname) in order to access the game\n    - The player must choose the level of difficulty in which he will play\n    - The duration of the game depends on the difficulty already chosen\n       * Easy level: 5 minutes of games\n       * Medium level: 3 minutes of games\n       * Difficult level: 2 minutes of games\n    - The player invited to enter words constructed only from the 9 letters already given\n    - The game is renewable"; 
			cout<<"	 \n.Words accepted:\n    - The player is invited to enter words constructed only from the 9 letters already given\n    - The smallest word is three letters long\n    - The longest word is 9 letters long\n    - Each letter must be used only once except in the case where the letter is already repeated in the 9 letters already given\n    - The score calculation is done according to the following rule: each letter of a valid word gives you access to 5 more points for your score";
			cout<<endl<<endl<<"**************************************************************************"<<endl;	
			
			
			
			
		}
		string nom;
		cout<<endl<<"donner votre nom d'utilisateur"<<endl;
		cin>>nom;
		name=nom;
	}
	string get_name(){
		return name;
	}
	string Setlanguage()
	{
		while (true)
		{
			string l;
			cout << "please set your language(lowercase):[francais , anglais , arabe] "<<endl;
			cin >> l;
			if ((l == "francais") || (l == "anglais") || (l == "arabe")) {
				language=l;
				return l;
				break;
			}
			else {
				cout << "incorrect language\n";
			}
		}
	};
	string level()
	{
		while (true)
		{
			string l;
			cout << "choose the level(hard,medium,easy): "<<endl;
			cin >> l;
			if ((l == "hard") || (l == "medium") || (l == "easy")) {
				lvl = l;
				return lvl;
				break;
			}
		}
	};

};

#endif
