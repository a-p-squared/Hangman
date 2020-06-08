#include<iostream>
#include<string.h>
using namespace std;

void showtries(int tries,int mistakes)
{
	cout<<"Tries    : "<<tries;
	cout<<"\tMistakes : "<<mistakes;
	cout<<endl<<endl;
}

void drawhangman(int mistakes)
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

void printword(char word[],string guesses)
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

bool isrepeated(char guess,string guesses)
{
		bool flag=false;
	for(int i=0;i<=guesses.length();i++)
	{
		if(guesses[i]==guess)
		{
			flag=true;
		}
	}
	return flag;
}

void checkerror(char guess,char word[],int& mistakes)
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

bool checkend(char word[],string guesses,int mistakes)
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

int main()
{
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
	if(isrepeated(guess,guesses)) { cout<<"\n\nLetter Already Guessed!\n"; system("pause"); continue; }
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
	return 0;
}
