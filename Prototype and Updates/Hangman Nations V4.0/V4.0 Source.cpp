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
			cout<<"\n\n\n\n\n";
			break;
		case 1:
			cout<<"\t\n";
			cout<<"\t\n";
			cout<<"\t ( )\n";
			cout<<"\t\n";
			cout<<"\t\n";
			break;
		case 2:
			cout<<"\n";
			cout<<"\t\n";
			cout<<"\t ( )\n";
			cout<<"\t /|\\\n";
			cout<<"\t\n";
			break;
		case 3:
			cout<<"\n";
			cout<<"\t\n";
			cout<<"\t ( )\n";
			cout<<"\t /|\\\n";
			cout<<"\t / \\\n";
			break;
		case 4:
			cout<<"\t        |\n";
			cout<<"\t        |\n";
			cout<<"\t ( )    |\n";
			cout<<"\t /|\\    |\n";
			cout<<"\t / \\    |\n";
			break;
		case 5:
			cout<<"\t________|\n";
			cout<<"\t  |     |\n";
			cout<<"\t ( )    |\n";
			cout<<"\t /|\\    |\n";
			cout<<"\t / \\    |\n";
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
		cout<<"\n\nGAME OVER!\n__________"<<"\n\nThe Correct Answer is : "<<word<<endl<<endl;
	}
	else
	{
		cout<<"\n\nYOU WIN!\n________";
	}
	cout<<endl;
	system("pause");
	system("cls");
}

void rules()															//When called, Game Rules will be printed on screen
{
	system("cls");
	cout<<"HANGMAN : Nations / RULES:\n_________________________\n\n";
	cout<<"Your Objective is to guess the name of a country, one letter at a time.\nEvery time you guess a letter,\nif you guess right, that letter's location(s) in the country name will be revealed.\nIf you guess wrong, you get a mistake point.\nBe Careful! 5 Mistake points, and your avatar will be hanged!\n\nA GAME BY AJIL PAPPACHAN\n\nCHEESE BRAIN || ICAT\n\n";
	system("pause");
	system("cls");
}

int main()
{
	PlaySound(TEXT("Bgm.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	system("color 8f");
	int opt;
	do
	{
		cout<<"HANGMAN : Nations\n_________________\n";
		cout<<"\n1.PLAY\n2.RULES\n3.EXIT\n\nEnter Choice : ";
		cin>>opt;
		switch(opt)
		{
			case 1:
				play();
				break;
			case 2:
				rules();
				break;
			case 3:
				break;
			default:
				cout<<"Invalid Option!\n";
				system("pause");
				system("cls");
				break;
		}
		
	}while(opt!=3);
	return 0;
}
