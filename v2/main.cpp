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
#include "cstdlib"

#include "gamesetup.h"
#include "opening.h"
#include "horloge.h"


using namespace std;


int main() {

	string replay;	
	do{
		system("color f5");
		opening op;
		string lang;
		string level;
		lang=op.Setlanguage();
		op.wecoming();
		system("cls");
		system("color f4");
		level=op.level();
		
		//remplissage du vector qui contient les mots de la langue choisie
		string c;
		vector<string> list_dic(0);
		list_dic=read_dic(lang);
		
		
		gamesetup game;
		game.generate_word(list_dic);
	
		horloge hg;
		
		if(level=="hard")
		hg.set_max(60);
		if(level=="medium")
		hg.set_max(120);
		if(level=="easy")
		hg.set_max(180);
	
		hg.start();
		cout<<"you have "<<hg.get_nb_sec()<<" seconds"<<endl<<endl;
		cout<<"donner une mot "<<endl;
		cin>>c;
		
		while(!hg.depass())
		{
			hg.get_time();
			game.verifWord(c);
			cout<<"donner un mot "<<endl;
			cin>>c;	
			
		}
		system("cls");
		system("color f2");
		cout<<endl<<endl<<"----------GAME OVER----------"<<endl<<endl;
		game.score();
		game.update(op.get_name());
		game.affiche_suggested_correct_word();
		
		system("color f4");
		string ch;
		cout<<endl<<"voulez vous s'avoir les solutions(yes or no)"<<endl;
		cin>>ch;
		if (ch=="yes")

		game.affiche_solution();
		
		cout<<"\n\n***********************************\n";
		cout<<"REPLAY ?? (yes or no )\n";
		cin>>replay;
		cout<<"\n***********************************\n\n";	
	}while(replay=="yes");
	cout<<"\n\n-------------------------------- \n    GAME OVER ";
		
	
}
