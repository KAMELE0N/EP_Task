#include "PrinterThread.h"

void PrinterThread::run(int sleepTime) {
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		std::cout << std::endl << "Buffer content: " << std::setprecision(2);

		if (_buffer->isNewDataAvailable()) {
			std::vector<float> bufferContent = _buffer->get();
			for (auto& i : bufferContent) {
				std::cout << i << " \t";
			}
		} else {
			std::cout << " Buffer Empty";
		}

		Sleep(_sleepTime);
	}
}