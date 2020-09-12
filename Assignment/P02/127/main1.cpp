#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Card
{
	string data;
	Card* next = NULL;
	Card* before = NULL;
};
class MyStack
{
private:
	int numCards = 0;
	Card* head, * tail;
public:
	MyStack()
	{
		head = NULL;
		tail = NULL;
	}
	~MyStack()
	{
	}
	void removeTopCard();
	void addCard(string value);
	bool isEmpty();
	char checkFirstCh();
	char checkSecCh();
	string getTailData();
	int getNumCards();
	Card* getHead();
	Card* getTail();
	void setNumCards(int cards);
	void setHead(Card* ptr);
	void setTail(Card* ptr);
};
//purpose: closes gap in dynamic array
//receives: array, number of stacks, and current index
//returns: condensed array
void closeGap(MyStack* piles, int& numStacks, int ci);
//purpose: initially fills stacks with single card per stack
//receives: card data, dynamic array
//returns: filled array and if the data was recieved correctly
bool fill(MyStack*, bool&, int);
//purpose: plays game
//receives: dynamic stack
//returns: completed stack and number of piles when finished
int playGame(MyStack*, int&);
//purpose: open files
void openFile(ifstream&);
//purpose: shows output
//receives: current iteration of game
void output(int);
const int NUMSTACKS = 52;

int main()
{
	MyStack* piles;
	bool cont = 1;	//when true program continues playing
	int runNum = 0;	//number of iterations
	while (cont == 1)
	{
		int num = NUMSTACKS;
		piles = new MyStack[NUMSTACKS];	//allocation for game
		if (fill(piles, cont, NUMSTACKS))	//if filled correctly continue
		{
			runNum++;
			int stacks = playGame(piles, num);
      if (stacks == 1){
        cout << stacks << " pile remaining: ";
      }
      else
			  cout << stacks << " piles remaining: ";
			//displays number of cards per stack after completion
			for (int i = 0; i < stacks; i++)
			{
        if(i+1==stacks){
          cout << piles[i].getNumCards();
        }
        else
				  cout << piles[i].getNumCards() << ' ';
			}
			cout << '\n';
		}
		//deallocation of array
		delete[] piles;
	}
  cout << '\n';
	//End of program
	return 0;
}

bool fill(MyStack* piles, bool& cont, int numS)
{
	string temp;
	for (int i = 0; i < numS; i++)
	{
		//checks each input for correct data
		cin >> temp;
		if (temp == "#")
			cont = false;
		piles[i].addCard(temp);
	}
	return cont;
}
int playGame(MyStack* piles, int& numP)
{
	bool cont = true; //continue is true
	int ci = 1; //begin with ci at 1
	//checks for more than one piles remaining
	while (cont == true && numP > 1)
	{
		//if still within the bounds of remaining piles
		if (ci <= numP)
		{
			if (ci == 0)
				ci++; //if on index 0, nothing can be done, go to next
			else if (ci <= 2) //checks one space to the left if 
			{
				//compares first and second chars for move
				if ((piles[ci].checkFirstCh() == piles[ci -
					1].checkFirstCh() || piles[ci].checkSecCh() ==
					piles[ci - 1].checkSecCh()))
				{
					//moves card one index left and closes the gap
					piles[ci - 1].addCard(piles[ci].getTailData());
					piles[ci].removeTopCard();
					if (piles[ci].isEmpty())
						closeGap(piles, numP, ci);
					ci--;
				}
				else
					ci++;
			}
			//if potentially movable 3 spaces
			else if (ci > 2 && ci < numP)
			{
				//checks for 3 moves left first
				if ((piles[ci].checkFirstCh() == piles[ci -
					3].checkFirstCh() || piles[ci].checkSecCh() ==
					piles[ci - 3].checkSecCh()))
				{
					//moves if chars match
					piles[ci - 3].addCard(piles[ci].getTailData());
					piles[ci].removeTopCard();
					if (piles[ci].isEmpty())
						closeGap(piles, numP, ci);
					ci = ci - 3;
				}
				//if not 3, then checks 1 index
				else if ((piles[ci].checkFirstCh() == piles[ci -
					1].checkFirstCh() || piles[ci].checkSecCh() ==
					piles[ci - 1].checkSecCh()))
				{
					//moves if chars match
					piles[ci - 1].addCard(piles[ci].getTailData());
					piles[ci].removeTopCard();
					if (piles[ci].isEmpty())
						closeGap(piles, numP, ci);
					ci--;
				}
				else
					ci++;
			}
			//if index exceeds number of cards then game is over
			else if (ci >= numP)
				cont = false;
		}
	}
	return numP;
}
//purpose: closes gap within game
//receives: dynamic array, num stacks rem, and current index
//returns: array with all stacks shifted left one after current index
void closeGap(MyStack* piles, int& numStacks, int ci)
{
	if (numStacks > 1)
	{
		for (int i = ci; i < (numStacks - 1); i++)
		{
			piles[i].setHead(piles[i + 1].getHead());
			piles[i].setTail(piles[i + 1].getTail());
			piles[i].setNumCards(piles[i + 1].getNumCards());
		}
		piles[numStacks - 1].setHead(NULL);
		piles[numStacks - 1].setTail(NULL);
		numStacks--;
	}
}
//purpose: displays data 
void output(int num)
{
	cout << "\nSet " << num << ":\n";
}
void MyStack::removeTopCard()
{
	if (tail != head)
	{
		tail = tail->before;
		delete tail->next;
		tail->next = NULL;
		numCards--;
	}
	else
	{
		delete head;
		head = NULL;
		tail = NULL;
		numCards--;
	}
}
//purpose: adds card to top of the stack
//receives: card data in form of string
//returns: new top card as tail of stack
void MyStack::addCard(string value)
{
	Card* temp = new Card;
	temp->data = value;
	temp->next = NULL;
	temp->before = tail;
	if (head == NULL)
	{
		temp->before = NULL;
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	numCards++;
}
//purpose: checks to see if the stack is empty
//returns: true value is empty, false if not empty
bool MyStack::isEmpty()
{
	if (head == NULL && tail == NULL)
		return true;
	else
		return false;
}
//purpose: checks first character of data in card
char MyStack::checkFirstCh()
{
	return tail->data.at(0);
}
//purpose: checks second character of data in card
char MyStack::checkSecCh()
{
	return tail->data.at(1);
}
//returns: tail data of a stack
string MyStack::getTailData()
{
	return tail->data;
}
//returns: number of cards in a stack
int MyStack::getNumCards()
{
	return numCards;
}
//returns: head card in a stack
Card* MyStack::getHead()
{
	return head;
}
//returns:tail card in a stack
Card* MyStack::getTail()
{
	return tail;
}
//purpose: sets number of cards in a stack
void MyStack::setNumCards(int cards)
{
	numCards = cards;
}
//purpose: sets head card pointer to new card
void MyStack::setHead(Card* ptr)
{
	head = ptr;
}
//purpose: sets tail card pointer to new card
void MyStack::setTail(Card* ptr)
{
	tail = ptr;
}
