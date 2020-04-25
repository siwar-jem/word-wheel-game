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

// des simples fonctions qu'on va l'utiliser dans le reste du travail
//-------------------------------------------------------------------
vector<string> read_dic(string lang)
{
	string href;
	href=lang + ".txt";
	fstream f ("francais.txt");
	vector<string> list_dic(0);
	string s;
	while(!f.eof()){
		getline(f,s);
		list_dic.push_back(s);
	}
	f.close();
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

//-------------------------------------------------------------------



//CLASS OPENING :
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
		if (rep == "yes"){
			cout<<endl<<"**************************************************************************"<<endl<<endl;
			cout << "The rules of the game require each word to consist of at least 3 letters" << endl << "and each word must contain the central letter. In addition to this, every" << endl << "puzzle contains at least one 9 letter word." << endl;
			cout<<endl<<endl<<"**************************************************************************"<<endl;	
		}
	}
	string Setlanguage()
	{
		while (true)
		{
			string l;
			cout << "please set your language(lowercase):[francais , anglais , arabe] "<<endl;
			cin >> l;
			if ((l == "francais") || (l == "anglais") || (l == "arabe")) {
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




//CLASSE HORLOGE  :  
class horloge : public opening{
	int begin_min;
	int begin_hr;
	int begin_sec;
	

	int nb_sec;
	
	int temp_en_seconde(int h, int m,int s ){
		
		return(h*3600+m*60+s );
	}
	public:
		void set_max(int max){	
			nb_sec=max;
		}
		void start(){
			time_t now;
			struct tm nowlocal;
			now=time(NULL);
			nowlocal=*localtime(&now);
			
			begin_hr=nowlocal.tm_hour;
			begin_min=nowlocal.tm_min;
			begin_sec=nowlocal.tm_sec;	
		}
		
		bool depass(){
			
			int temp_ecoule;
			time_t now;
			struct tm nowlocal;
			now=time(NULL);
			nowlocal=*localtime(&now);
			
			temp_ecoule=temp_en_seconde(nowlocal.tm_hour,nowlocal.tm_min,nowlocal.tm_sec)-temp_en_seconde(begin_hr,begin_min,begin_sec) ; 
			return(temp_ecoule>=nb_sec);
		}
		
		void get_time(){
			int temp_ecoule;
			time_t now;
			struct tm nowlocal;
			now=time(NULL);
			nowlocal=*localtime(&now);
			
			temp_ecoule=temp_en_seconde(nowlocal.tm_hour,nowlocal.tm_min,nowlocal.tm_sec)-temp_en_seconde(begin_hr,begin_min,begin_sec) ; 
			cout<<"il vous reste "<<nb_sec-temp_ecoule<<"secondes"<<endl;
		}
		int get_nb_sec(){
			return nb_sec;
		}
	
};




//CLASS GAMESETUP
class gamesetup{	
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
			
			
			cout<<"-----------------------------"<<endl<<endl;
		
			int k=strlen(list[r]);
			int tab[k];
			shuffle(tab,k);
			for(int i=0;i<k;i++){
				cout<<list[r][tab[i]]<<" ";
			}
			cout<<endl<<endl<<"-----------------------------"<<endl;
			
			int j=0,test=0;
			char lettre;
			do
			{
			    j+=1;
				if(j==1){
			    	cout<<"choisit une lettre qui doit se presenter dans tous les mots"<<endl;
			    	cin>>lettre;
				}
				else{
					cin>>lettre;
				}
				for(int k=0;k<strlen(list[r]);k++){
					if(lettre==list[r][k]){
						test=1;
						break;						
					}
					
				}
				if(test==0){
					cout<<"charactere invalide"<<endl;	
				}
			    
			} while (test==0);
			
			central_char=lettre;
			cout<<"valide choise "<<central_char<<endl;
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
		/*
		vector<string> list_of_correct_words(vector<string> list ){
			
			vector<string> correct_words(0);
			map<char,int> mot2;
			map<char,int> mot3;
			int cond,j;
			
			for(int i=0;i<strlen(choosin_word);i++){
				mot2[choosin_word[i]]+=1;
			}
			
			for(int i=0;i<list_dic.size();i++){
				cond=1;
				mot3=mot2;
					
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
			list_cor=correct_words ;	
		}*/
		void verifWord (string s){
			
			int test=0;
			for(int i=0;i<list_cor.size();i++){
				if(s==list_cor[i]){
					written_correct_Word.push_back(list_cor[i]);
					cout<<"-------correct------"<<endl;
					test=1;
					break;
				}
			}
			if(test==0){
				cout<<"--------mot incorrect--------"<<endl;
			}
			
		}
	    void affiche_suggested_correct_word()
		{
	    	cout<<"------correct answers--------"<<endl<<endl;
		    for(int i=0;i<written_correct_Word.size();i++){
					cout<<written_correct_Word[i]<<endl;
			}
			cout<<endl<<endl;	
		}
		void affiche_solution()
		{
			for(int i=0;i<list_cor.size();i++){
				cout<<list_cor[i]<<endl;
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
			cout<<"votre score est "<<score<<endl<<endl;
			score_final=score;
			}
		}		
};





int main(){
	
	
	opening op;
	string lang;
	string level;
	op.wecoming();
	lang=op.Setlanguage();
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
	
	cout<<endl<<endl<<"----------GAME OVER----------"<<endl<<endl;
	game.score();
	game.affiche_suggested_correct_word();
	
	string ch;
	cout<<endl<<"voulez vous s'avoir les solutions(yes or no)"<<endl;
	cin>>ch;
	if (ch=="yes")
	game.affiche_solution();
	
}
	

