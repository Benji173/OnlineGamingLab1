#include <winsock2.h>
#include <iostream>
#include "Net.h"

using namespace std;

void playerA();
void playerB();

Net *p1Net = new Net();


int main(array<System::String ^> ^args)
{
	p1Net->initialise();

	string a;

	std::cout << "Please enter either a or b";

	std::cin>>a;
	if(a == "a")
	{
		playerA();
	}
	else if(a == "b")
	{
		playerB();
	}
	else
	{
		std::cout << "Please enter either a or b!";
	}



	system("PAUSE");
    return 0;

}


void playerA()
{
	std::cout << "Entered A \n";
	char *ip = "149.153.102.42";
	int port = 28000;
	p1Net->setupUDP(port,ip);

	std::cout << "please enter your msg \n";
	string msg;
	cin>>msg;
	char *messageChar = &msg[0];
	p1Net->sendData("149.153.102.36",28001,messageChar);
}

void playerB()
{
	std::cout << "Entered B \n";
	char *ip = "149.153.102.36";
	int port = 28001;
	p1Net->setupUDP(port,ip);

	char message[200]="";
	
	while(true)
	{
		p1Net->receiveData(message);
		cout<<message;

		if(message[0])
		{
			break;
		}

	}
}