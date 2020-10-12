#include "PrinterConsumerTask.h"

PrinterConsumerTask::PrinterConsumerTask() {

}

PrinterConsumerTask::~PrinterConsumerTask() {

}

void PrinterConsumerTask::execute(int sleepTime){
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		std::cout << "Consumer ping" << std::endl;
		Sleep(_sleepTime);
	}
}