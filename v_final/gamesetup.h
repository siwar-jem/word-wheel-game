#ifndef GAMESETUP_H
#define GAMESETUP_H
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

vector<string> read_dic(string lang)
{
	vector<string> list_dic(0);
	if(lang=="francais"){

		fstream f ("francais.txt");
		
		string s;
		while(!f.eof()){
			getline(f,s);
			list_dic.push_back(s);
		}
		f.close();
	}
	else if(lang=="anglais"){

		fstream f ("anglais.txt");
	
		string s;
		while(!f.eof()){
			getline(f,s);
			list_dic.push_back(s);
		}
		f.close();
	}
	return list_dic;
}
int strlen(string s) {
    int i;
    i=0;
    while(s[i]!='\0')
        ++i;
    return i;
}
void shuffle(int tab[],int N){ 
	int i,j,deja; /* A prevoir ailleurs */ 
	srand((unsigned) time(NULL)); 
	i=0; 
	while (i<N) { 
		tab[i]=rand()%N;
		deja=0;
		for (j=0;j<i;j++) { 
		if (tab[j]==tab[i]) { 
			deja=1; break; 
			} 
		} 
		if (deja==0) 
			i++; 
	}
}
bool ancien(string nom){
	
	fstream lec_fichier("word_wheel.txt",ios::in);
	vector<string> tab;
	if(lec_fichier.is_open()){
		string line;
		while(getline(lec_fichier,line)){
			tab.push_back(line);
		}
		lec_fichier.close();
	}

	for(int i=0;i<tab.size();i++){
		string ch="";
		for(int j=0;j<strlen(tab[i]);j++){
			char s=tab[i][j];
			
			if(s != tab[0][0]){
				ch+=tab[i][j];
			}else break;
		}
		if(ch==nom){
			return true;
			
		}
	}	
	
}

string to_string(int entier){
	string ch;
	int nb=entier;
	int j;
	while(nb!=0){
		j=nb % 10;
		switch(j){
			case 0:
				{
				ch="0"+ch;
				break;}
			case 1:
				{
				ch="1"+ch;
				break;}
			case 2:
				{
				ch="2"+ch;
				break;}
			case 3:
				{
				ch="3"+ch;
				break;}
			case 4:
				{
				ch="4"+ch;
				break;}
			case 5:
				{
				ch="5"+ch;
				break;}
			case 6:
				{
				ch="6"+ch;
				break;}
			case 7:
				{
				ch="7"+ch;
				break;}
			case 8:
				{
				ch="8"+ch;
				break;}
			case 9:
				{
				ch="9"+ch;
				break;}
		}
		nb=nb/10;
		
	}
	
	return ch;
	
}
class gamesetup
{
	public:
		vector<string> list_cor;// l'ensemble des mots correct
		vector<string> written_correct_Word;// l'ensemble des mots correct inseré par l'utilisateur
		string choosin_word;//mot originale
		char central_char;//charactere qui doit se presenter dans tous les mots
		int score_final ;// le score final
		
		void generate_word(vector<string> list_dic){
			int r;
			vector<string> list(0);
			
			for(int i=0;i<list_dic.size();i++)
			{
				if(strlen(list_dic[i])==9)
					list.push_back(list_dic[i]);	
			}
			srand(time(0));
			r = rand() %list.size() ;
			
			
			cout<<"\033[36m                                         "<<endl<<endl;
		
			int k=strlen(list[r]);
			int tab[k];
			shuffle(tab,k);
			cout<<"                                          ________________________________"<<endl;
			cout<<"                                         /          /         /          /|"<<endl;
			cout<<"                                        /__________/_________/__________/ | "<<endl;
			cout<<"                                        |          |         |          | |"<<endl;
			cout<<"                                        |    "<<list[r][tab[1]]<<"     |  "<<list[r][tab[2]]<<"      | "<<list[r][tab[3]]<<"        | |"<<endl;
			cout<<"                                        |__________|_________|__________|/|"<<endl;
			cout<<"                                        |          |         |          | |"<<endl;
			cout<<"                                        |    "<<list[r][tab[4]]<<"     |    "<<list[r][tab[5]]<<"    |    "<<list[r][tab[6]]<<"     | |"<<endl;
			cout<<"                                        |__________|_________|__________|/|"<<endl;
			cout<<"                                        |          |         |          | |"<<endl;
			cout<<"                                        |    "<<list[r][tab[7]]<<"     |     "<<list[r][tab[8]]<<"   |    "<<list[r][tab[9]]<<"     | |"<<endl;
			cout<<"                                        |__________|_________|__________|/"<<endl;
			cout<<endl<<endl;
			
			central_char=list[r][tab[5]];
			choosin_word=list[r];
			
			
			vector<string> correct_words(0);
			vector<string> correct_words2(0);
			map<char,int> mot2;
			map<char,int> mot3;
			int cond;
			
			for(int i=0;i<strlen(choosin_word);i++){
				mot2[choosin_word[i]]+=1;
			}
			
			for(int i=0;i<list_dic.size();i++){
				cond=1;
				mot3=mot2;
				int j;	
				j=0;
				while (cond==1 & j<strlen(list_dic[i])){
					if(mot3[list_dic[i][j]] ==0){
						cond=0;
					}
					else mot3[list_dic[i][j]] -=1;
					j+=1;
				}
				if(cond==1)
					correct_words.push_back(list_dic[i]);	
			}
			for(int i=0;i<correct_words.size();i++){
				
				if(strlen(correct_words[i])>=3){
					for(int h=0;h<strlen(correct_words[i]);h++){
						if(central_char==correct_words[i][h]){
							correct_words2.push_back(correct_words[i]);
							break;
						}
					}					
				}
				
			}
			list_cor=correct_words2 ;			
			
		
			
		}
		void verifWord (string s){
			int test=0;
			for(int i=0;i<list_cor.size();i++){
				if(s==list_cor[i]){
					for(int l=0;l<written_correct_Word.size();l++){
						if(s==written_correct_Word[l]){
							cout<<"\033[33mword already said\n";
							test=1;								
						}
				
					}
					if (test!=1){
						written_correct_Word.push_back(list_cor[i]);
						cout<<"\033[32mcorrect"<<endl;
						test=2;
					}
		
		
					break;
				}
			}
			if(test==0){
				cout<<"\033[91mwrong word"<<endl;
			}
		}
	    void affiche_suggested_correct_word(){
	    	
			cout<<"\033[32m                           correct answers"<<endl<<endl;
		    for(int i=0;i<written_correct_Word.size();i++){
					cout<<"\033[32m                           "<<written_correct_Word[i]<<endl;
			}
			cout<<endl<<endl;	
		}
	
		void affiche_solution(){
			for(int i=1;i<=list_cor.size();i=i+2){
				string ch="";
				for(int j=0;j<(20-strlen(list_cor[i]));j++){
				ch+=" ";	
				}
			if( i==list_cor.size()-2){
				cout<<"\033[32m 	                                      "<<list_cor[i+1]<<endl;
				break;
				
			}
				cout<<"\033[32m 	                                      "<<list_cor[i]<<ch<<list_cor[i+1]<<endl;
			}
			
		}
	
		void score (){
			vector<string> tab(0) ;
			tab= written_correct_Word ;	  
		    int score=0;
		    int i,j;
		    string ch;
		    FILE * base_d;
			//ce boucle pour calculer le score
		           
			if(tab.size()!=0){
			score=5;
			for(i=0;i<tab.size();i++){
		        ch=tab[i];
		        if (strlen(ch)>=3){
		            
		            for (j=0;j<strlen(ch);j++){
		            	score=score+5;
					}
		        }
			}
			cout<<"\033[36m                                               your score is "<<score<<endl<<endl;
			score_final=score;
			}
			else{
				cout<<"\033[36m                                               your score is "<<score<<endl<<endl;
			}
			
		}
		
		void update(string nom ){
			int entier=score_final;
			fstream lec_fichier("word_wheel.txt",ios::in);
			vector<string> tab;
			if(lec_fichier.is_open()){
				string line;
				while(getline(lec_fichier,line)){
					tab.push_back(line);
				}
				lec_fichier.close();
			}
			
			if(ancien(nom)){
			
			
			
				for(int i=0;i<tab.size();i++){
					string ch="";
					for(int j=0;j<strlen(tab[i]);j++){
						char s=tab[i][j];
						
						if(s != tab[0][0]){
							ch+=tab[i][j];
						}else break;
					}
					if(ch==nom){
						int k=strlen(ch);
						while(k<20){
							ch+=tab[0][0];
							k+=1;
						}
						ch+=to_string(entier);
						tab[i]=ch;
						
						break;
						
					}
				}
				
				
			}
			if(!ancien(nom)){
				
				string ch;
				ch=nom;
				int k=strlen(nom);
				while(k<20){
					ch+=tab[0][0];
					k+=1;
				}
				ch+=to_string(entier);
				tab.push_back(ch);
				
			
				
			}
			ofstream file;
			file.open("word_wheel.txt");
			for(int h=0;h<tab.size();h++){
				file<<tab[h]<<endl;
			}	
		}
		
};

#endif
