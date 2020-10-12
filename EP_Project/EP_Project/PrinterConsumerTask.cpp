#include "PrinterConsumerTask.h"

void PrinterConsumerTask::run(int sleepTime){
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		std::cout << "Consumer ping" << std::endl;
		Sleep(_sleepTime);
	}
}