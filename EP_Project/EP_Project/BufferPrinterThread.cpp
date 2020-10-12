#include "BufferPrinterThread.h"

void BufferPrinterThread::run(int sleepTime) {
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		std::cout << "Printer ping" << std::endl; // Debug log

		// TODO Add printing logic
		Sleep(_sleepTime);
	}
}