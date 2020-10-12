#include "ProducerThread.h"

void ProducerThread::run(int sleepTime) {
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		std::cout << "Producer ping" << std::endl;	// Debug log

		// TODO Add producer logic 
		Sleep(_sleepTime);
	}
}