#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
#include<windows.h>
#include<mmsystem.h>
#include<time.h>
using namespace std;

string wordlist[] = {"CROATIA","SINGAPORE","HUNGARY","UKRAINE","NETHERLANDS","SOUTH KOREA","CANADA","POLAND","GREECE","THAILAND","AUSTRIA","MALAYSIA",
						"HONG KONG","MEXICO","GERMANY","TURKEY","ITALY","SPAIN","FRANCE","UNITED ARAB EMIRATES","INDIA","AUSTRALIA","AFRICA",
						"UNITED STATES OF AMERICA","CHINA","JAPAN"};

void printhead()
{
	cout<<"\t _     _        ______   ______ ______         ______          ______             _"<<endl;
	cout<<"\t| |   | |  /\\  |  ___ \\ / _____)  ___ \\   /\\  |  ___ \\        |  ___ \\       _   (_)                "<<endl;
	cout<<"\t| |__ | | /  \\ | |   | | /  ___| | _ | | /  \\ | |   | |   _   | |   | | ____| |_  _  ___  ____   ___ "<<endl;
	cout<<"\t|  __)| |/ /\\ \\| |   | | | (___) || || |/ /\\ \\| |   | |  (_)  | |   | |/ _  |  _)| |/ _ \\|  _ \\ /___)"<<endl;
	cout<<"\t| |   | | |__| | |   | | \\____/| || || | |__| | |   | |   _   | |   | ( ( | | |__| | |_| | | | |___ |"<<endl;
	cout<<"\t|_|   |_|______|_|   |_|\\_____/|_||_||_|______|_|   |_|  (_)  |_|   |_|\\_||_|\\___)_|\\___/|_| |_(___/"<<endl;
	cout<<endl;
}

void showtries(int tries,int mistakes)									//Prints the Number of tries and Mistake Points on top of the screen
{
	cout<<"Tries    : "<<tries;
	cout<<"\tMistakes : "<<mistakes;
	cout<<endl<<endl;
}

void drawhangman(int mistakes)											//Prints a part of the Hangman whenever the player makes a mistake
{
	switch(mistakes)
	{
		case 0:
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			break;
		case 1:
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<"                   "<<endl;
			cout<<"                   "<<endl;
			cout<<"                   "<<endl;
			cout<<"     ___           "<<endl;
			cout<<"    / _ \\         "<<endl;
			cout<<"   | (_) |         "<<endl;
			cout<<"    \\___/         "<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			break;
		case 2:
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<"                   "<<endl;
			cout<<"                   "<<endl;
			cout<<"                   "<<endl;
			cout<<"     ___           "<<endl;
			cout<<"    / _ \\         "<<endl;
			cout<<"   | (_) |         "<<endl;
			cout<<"    \\___/         "<<endl;
			cout<<"    _| |_          "<<endl;
			cout<<"   / / \\ \\       "<<endl;
			cout<<"  / /| |\\ \\      "<<endl;
			cout<<" /_/ | | \\_\\     "<<endl;
			cout<<"     |_|           "<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			break;
		case 3:
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<"                   "<<endl;
			cout<<"                   "<<endl;
			cout<<"                   "<<endl;
			cout<<"     ___           "<<endl;
			cout<<"    / _ \\         "<<endl;
			cout<<"   | (_) |         "<<endl;
			cout<<"    \\___/         "<<endl;
			cout<<"    _| |_          "<<endl;
			cout<<"   / / \\ \\       "<<endl;
			cout<<"  / /| |\\ \\      "<<endl;
			cout<<" /_/ | | \\_\\     "<<endl;
			cout<<"    _|_|_          "<<endl;
			cout<<"   / / \\ \\       "<<endl;
			cout<<"  / /   \\ \\      "<<endl;
			cout<<" /_/     \\_\\     "<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			break;
		case 4:
			cout<<""<<endl;
			cout<<"                    _   "<<endl;
			cout<<"                   | |  "<<endl;
			cout<<"                   | |  "<<endl;
			cout<<"                   | |  "<<endl;
			cout<<"     ___           |_|  "<<endl;
			cout<<"    / _ \\          | | "<<endl;
			cout<<"   | (_) |         | |  "<<endl;
			cout<<"    \\___/          | | "<<endl;
			cout<<"    _| |_          |_|  "<<endl;
			cout<<"   / / \\ \\         | |"<<endl;
			cout<<"  / /| |\\ \\        | |"<<endl;
			cout<<" /_/ | | \\_\\       | |"<<endl;
			cout<<"    _|_|_          |_|  "<<endl;
			cout<<"   / / \\ \\         | |"<<endl;
			cout<<"  / /   \\ \\        | |"<<endl;
			cout<<" /_/     \\_\\       | |"<<endl;
			cout<<"                   |_|  "<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			break;
		case 5:
			cout<<"  ___ ___ ___ ___ ___   "<<endl;
			cout<<" |___|___|___|___|___|  "<<endl;
			cout<<"     | |           | |  "<<endl;
			cout<<"     | |           | |  "<<endl;
			cout<<"     | |           | |  "<<endl;
			cout<<"     |_|           |_|  "<<endl;
			cout<<"    / _ \\          | | "<<endl;
			cout<<"   | (_) |         | |  "<<endl;
			cout<<"    \\___/          | | "<<endl;
			cout<<"    _| |_          |_|  "<<endl;
			cout<<"   / / \\ \\         | |"<<endl;
			cout<<"  / /| |\\ \\        | |"<<endl;
			cout<<" /_/ | | \\_\\       | |"<<endl;
			cout<<"    _|_|_          |_|  "<<endl;
			cout<<"   / / \\ \\         | |"<<endl;
			cout<<"  / /   \\ \\        | |"<<endl;
			cout<<" /_/     \\_\\       | |"<<endl;
			cout<<"                   |_|  "<<endl;
			cout<<""<<endl;
			break;
		default:
			break;
	}
	cout<<endl<<endl;
}

void printword(char word[],string guesses)								//Prints Placeholders for the word to guess
{
	cout<<"Guess The Country : \n\n";
	char print;
	for(int c=0;c<=strlen(word);c++)
	{
		print='_';
		for(int i=0;i<=guesses.length();i++)
		{
			if(word[c]==guesses[i])
			print=guesses[i];
			if(word[c]==' ')
			print=' ';
		}
		cout<<print<<" ";
	}
	cout<<endl<<endl;
}

int isrepeated(char guessed,string guesslist)								//Checks if the recieved guess has been made before
{
	for(int i=0;i<=guesslist.length();i++)
	{
		if(guessed==guesslist[i])
		{
			return 1;
		}
	}
	return 0;
}

void checkerror(char guess,char word[],int& mistakes)					//Checks if the guess is correct or wrong
{
	int flag=0;
	for (int i=0;i<=strlen(word);i++)
	{
		if(guess==word[i])
		flag=1;
	}
	if(flag==1)
	{
		cout<<"\n\nCorrect Letter!";
	}
	else
	{
		cout<<"\n\nWrong Letter!";
		mistakes++;
	}
	cout<<endl;
	system("pause");
}

bool checkend(char word[],string guesses,int mistakes)					//checks if all the letters in the words have been guessed
{
	bool end=false;
	int check=-1,spaces=0;
	for(int i=0;i<=strlen(word);i++)
	{
		for(int c=0;c<=guesses.length();c++)
		{
			if(word[i]==guesses[c])
			{
				check++;
				break;
			}
		}
	}
	for(int c=0;c<=strlen(word);c++)
	{
		if(word[c]==' ') spaces++;
	}
	if (check==strlen(word)-spaces || mistakes==5) end=true;
	return end;
}

void play()																//When called, Starts the Game
{
	int tries=-1,mistakes=0;
	char guess, word[20];
	string guesses;
	srand(time(0));
	string randomword = wordlist[rand() % 26];
	for(int i=0;i<=randomword.length();i++)
	{
		word[i]=randomword[i];
	}
	do
	{
	system("cls");
	tries++;
	printhead();
	showtries(tries,mistakes);
	drawhangman(mistakes);
	printword(word,guesses);
	if(checkend(word,guesses,mistakes)) break;
	cout<<"Enter A Guess : ";
	cin>>guess;
	guess=toupper(guess);
	if(isrepeated(guess,guesses)==1) { cout<<"\n\nLetter Already Guessed!\n"; system("pause"); continue; }
	checkerror(guess,word,mistakes);
	guesses+=guess;
	}while(mistakes<=5);
	if(mistakes==5)
	{
		cout<<""<<endl;
		cout<<"   ___   _   __  __ ___    _____   _____ ___ "<<endl;
		cout<<"  / __| /_\\ |  \\/  | __|  / _ \\ \\ / / __| _ \\"<<endl;
		cout<<" | (_ |/ _ \\| |\\/| | _|  | (_) \\ V /| _||   /"<<endl;
		cout<<"  \\___/_/ \\_\\_|  |_|___|  \\___/ \\_/ |___|_|_\\"<<endl;
		cout<<""<<endl;
		cout<<"\nThe Correct Answer is : "<<word<<endl<<endl;
	}
	else
	{
		cout<<""<<endl;
		cout<<" __   _____  _   _  __      _____ _  _ _ "<<endl;
		cout<<" \\ \\ / / _ \\| | | | \\ \\    / /_ _| \\| | |"<<endl;
		cout<<"  \\ V / (_) | |_| |  \\ \\/\\/ / | || .` |_|"<<endl;
		cout<<"   |_| \\___/ \\___/    \\_/\\_/ |___|_|\\_(_)"<<endl;
		cout<<""<<endl;
	}
	cout<<endl;
	system("pause");
	system("cls");
}

void rules()															//When called, Game Rules will be printed on screen
{
	system("cls");
	printhead();
	cout<<"  ___ _   _ _    ___ ___ _ "<<endl;
	cout<<" | _ \\ | | | |  | __/ __(_)"<<endl;
	cout<<" |   / |_| | |__| _|\\__ \\_"<<endl;
	cout<<" |_|_\\\\___/|____|___|___(_)"<<endl;
	cout<<endl;
	cout<<"Your Objective is to guess the name of a country, one letter at a time.\nEvery time you guess a letter,\nif you guess right, that letter's location(s) in the country name will be revealed.\nIf you guess wrong, you get a mistake point.\nBe Careful! 5 Mistake points, and your avatar will be hanged!\n\nA GAME BY AJIL PAPPACHAN\n\nCHEESE BRAIN || ICAT\n\n";
	system("pause");
	system("cls");
}

int main()
{
	PlaySound(TEXT("Bgm.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	system("color 8f");
	char opt;
	do
	{
		printhead();
//	cout<<"   _________"<<endl;
//	cout<<"  ||       ||"<<endl;
//	cout<<" //         \\\\"<<endl;
//	cout<<"|| 1. PLAY   ||"<<endl;
//	cout<<"|| 2. RULES  ||"<<endl;
//	cout<<"|| 3. EXIT   ||"<<endl;
//	cout<<" \\\\         //"<<endl;
//	cout<<"  ||_______||"<<endl;
	cout<<"|| 1. PLAY\n|| 2. RULES\n|| 3. EXIT\n";
	cout<<endl;
	cout<<"Enter Choice : ";
		cin>>opt;
		switch(opt)
		{
			case '1':
				play();
				break;
			case '2':
				rules();
				break;
			case '3':
				break;
			default:
				cout<<"\nInvalid Option!\n";
				system("pause");
				system("cls");
				break;
		}
		
	}while(opt!='3');
	return 0;
}
