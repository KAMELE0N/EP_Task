#include "ConsumerThread.h"

void ConsumerThread::run(int sleepTime){
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		//std::cout << "Consumer ping" << std::endl; // Debug log

		// TODO Add consumer logic -> consuming done by printerThread
		Sleep(_sleepTime);
	}
}