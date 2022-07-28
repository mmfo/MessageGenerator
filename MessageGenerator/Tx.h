#pragma once
#include "../../COMMON/IDD.h"
#include "../../COMMON/UdpSocket/UDPClient.h"
#include <thread>
using namespace std;

class Tx
{
public:
	UDPClient client;
	int dataMsgSendCounter;
	int* stop;
	Tx(int* stop) {
		this->stop = stop;
		this->dataMsgSendCounter = 0;
		this->client = UDPClient(5);////
		thread t1(&Tx::sendDataMessages, this);
		t1.detach();
	}
	void sendDataMessages() {
		Message dataMessage;
		dataMessage.header.msgCounter = 0;
		dataMessage.header.msgSync = MSG_SYNC;
		dataMessage.header.Opcode = DATA_MSG_OPCODE;
		while (*stop == 0)
		{
			if (this->client.sendTheMessage(dataMessage, MANAGER_PORT(TRANSMITTER)) == -1)
				cout << "error in msg generator tx" << endl;
			else {
				this->dataMsgSendCounter++;
				dataMessage.header.msgCounter++;
				this_thread::sleep_for(chrono::milliseconds(1000));
			}
		}
	}
};

