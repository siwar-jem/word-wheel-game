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
	system("color f5");
	cout<<"\n\n\033[91m    _____      _______     ______        ______      _______      _______                   _______"<<endl;
	cout<<"    |             |        |     |       |     |        |            |          |\\   |      |      |"<<endl;
	cout<<"    I____         |        |_____|       |_____|        |            |          | \\  |      |   ___  "<<endl;
	cout<<"         |        |        |     |       |   \\          |            |          |  \\ |      |      |"<<endl;
	cout<<"     ____I        |        |     |       |    \\         |         ___I___       |   \\|      I______I\n\n\n"<<endl;
	string replay;	
	do{
		
		opening op;
		string lang;
		string level;
		
		lang=op.Setlanguage();
		op.wecoming();
	
	
		level=op.level();
		
		//remplissage du vector qui contient les mots de la langue choisie
		string c;
		vector<string> list_dic(0);
		list_dic=read_dic(lang);
		
		
		gamesetup game;
		system("cls");
		game.generate_word(list_dic);
	
		horloge hg;
		
		if(level=="hard")
		hg.set_max(60);
		if(level=="medium")
		hg.set_max(120);
		if(level=="easy")
		hg.set_max(180);
	
		hg.start();
		cout<<"\033[33m------------>  you have "<<hg.get_nb_sec()<<" seconds"<<endl<<endl;
		cout<<"\033[34m                                                   give a word "<<endl;
		cout<<"                                                        ";
		cin>>c;
		
		while(!hg.depass())
		{
			hg.get_time();
			game.verifWord(c);
			cout<<"\033[34m                                                   give a word"<<endl;
			cout<<"                                                        ";
			cin>>c;			
		}
	
		cout<<endl<<endl<<"\033[31m	                                   ----------GAME OVER----------"<<endl<<endl;
		game.score();
		game.update(op.get_name());
		game.affiche_suggested_correct_word();
		
	
		string ch;
		cout<<endl<<"\033[33m                              do you want to know the correct answers (yes or no)"<<endl;
		cout<<"                                                       ";
		cin>>ch;
		if (ch=="yes")

		game.affiche_solution();
		
		cout<<"\n\n";
		cout<<"\033[33m REPLAY ?? (yes or no )\n";
		cin>>replay;
		cout<<"\n	                                   ***********************************\n\n";	
		system("cls");
	}while(replay=="yes");
	cout<<"\n\n	                                   -------------------------------- \n  	                                               GAME OVER ";
		
	
}
