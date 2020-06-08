#include<iostream>
#include<string.h>
using namespace std;

void showtries(int tries,int mistakes)									//Prints the Number of tries and Mistake Points on top of the screen
{
	cout<<"Tries    : "<<tries;
	cout<<"\tMistakes : "<<mistakes;
	cout<<endl<<endl;
}

void drawhangman(int mistakes)											//Prints a part of the Hangman whenever the player makes a mistake
{
//	system("color f4");
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
	cout<<"Guess The Word : \n\n";
	char print;
	for(int c=0;c<=strlen(word);c++)
	{
		print='_';
		for(int i=0;i<=guesses.length();i++)
		{
			if(word[c]==guesses[i])
			print=guesses[i];
		}
		cout<<print<<" ";
	}
	cout<<endl<<endl;
}

int isrepeated(char guess,string guesses)								//Checks if the recieved guess has been made before
{
		int flag=0;
	for(int i=0;i<=guesses.length();i++)
	{
		if(guesses[i]==guess)
		{
			flag=1;
		}
	}
	return flag;
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
	int check=-1;
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
	if (check==strlen(word) || mistakes==5) end=true;
	return end;
}

void play()																//When called, Starts the Game
{
	system("color 8f");
	int tries=-1,mistakes=0;
	char guess, word[20] = "INDIA";
	string guesses = "";
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
	if(isrepeated(guess,guesses)==1) { cout<<"\n\nLetter Already Guessed!\n"; system("pause"); continue; }
	guess=toupper(guess);
	checkerror(guess,word,mistakes);
	guesses+=guess;
	}while(mistakes<=5);
	if(mistakes==5)
	{
		cout<<"\n\nGAME OVER!\n__________";
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
	cout<<"HANGMAN RULES:\n\n";
	cout<<"Your Objective is to guess the name of a country, one letter at a time.\nEvery time you guess a letter,\nif you guess right, that letter's location(s) in the country name will be revealed.\nIf you guess wrong, you get a mistake point.\nBe Careful! 5 Mistake points, and your avatar will be hanged!\n\nA GAME BY AJIL PAPPACHAN\n\nCHEESE BRAIN || ICAT\n\n";
	system("pause");
	system("cls");
}

int main()
{
	system("color 8f");
	int opt;
	do
	{
		cout<<"HANGMAN\n_______\n";
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
