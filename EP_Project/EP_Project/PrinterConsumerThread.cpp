#include "PrinterConsumerThread.h"

void PrinterConsumerThread::run(int sleepTime){
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		std::cout << "Consumer ping" << std::endl; // Debug log

		// TODO Add consumer logic
		Sleep(_sleepTime);
	}
}