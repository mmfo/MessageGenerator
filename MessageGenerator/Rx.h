#pragma once
#include "../../COMMON/IDD.h"
#include "../../COMMON/UdpSocket/UDPServer.h"
#include <thread>
using namespace std;
class Rx
{
public:
	UDPServer server;
	int dataMsgRecCounter;
	int *stop = 0;
	Rx(int * stop) {
		this->stop = stop;
		this->dataMsgRecCounter = 0;
		this->server = UDPServer(MSGGEN_PORT);
		thread t1(&Rx::getDataMessages, this);
		t1.detach();
	}
	void getDataMessages() {
		Message dataMessage;
		while (*stop==0)
		{
			this->server.recieveData(&dataMessage, MANAGER_PORT(RECEIVER));
			this->dataMsgRecCounter++;
			//check the validity
			if(dataMessage.header.msgSync != MSG_SYNC|| dataMessage.header.Opcode!= DATA_MSG_OPCODE){
				cout << "meesage generator" << "  " << "Rx"<< "     erorr 12" << endl;
				cout << "meesage generator" << "  " << "Rx" << "     erorr 12      "<<hex<<dataMessage.header.msgSync << endl;

				
			}
			this_thread::sleep_for(chrono::milliseconds(1000));
			/*if(dataMessage.header.msgCounter)
			dataMessage.header.msgCounter++;*/
		}
	}
};

