#include "PrinterThread.h"

void PrinterThread::run(int sleepTime) {
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		std::cout << std::endl << "Buffer content:" << std::setprecision(2) << std::endl;

		std::vector<float> bufferContent = _buffer->get();
		for (auto& i : bufferContent) {
			std::cout << i << " ";
		}

		Sleep(_sleepTime);
	}
}