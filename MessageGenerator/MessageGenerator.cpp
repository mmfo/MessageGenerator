#include <iostream>
#include <string>
#include "Tx.h"
#include "Rx.h"
using namespace std;
bool checkEqualMsgSend_Get(Tx tx, Rx rx) {
	return tx.dataMsgSendCounter == rx.dataMsgRecCounter;
}
int main()
{
	std::cout << "Hello World!\n";
	//create data meesage
	//send to manager Transmitter  every 1 second 
	//get from manager's Receiver
		  //check validity of 
		  // 
	//countSend==countReceive
	//checkTime
	char input;
	cout << "Enter s to start the test, and q to end." << endl;
	cin >> input;
	while (input != 's') {
		cin >> input;
	}
	time_t begin_time = time(NULL);
	int stop = 0;
	// Beginning the test
	Rx rx(&stop);
	Tx tx(&stop);
	cin >> input;
	while (input != 'q') {
		cin >> input;
	}
	stop = 1;
	time_t end_time = time(NULL);
	this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << "Number of sent messages: " << tx.dataMsgSendCounter << endl;
	cout << "Number of received messages: " << rx.dataMsgRecCounter << endl;
	cout << "The duration of the test: " << end_time - begin_time << " sec" << endl;
	
	return 0;
};