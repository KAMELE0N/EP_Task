#include "PrinterThread.h"

void PrinterThread::run(int sleepTime) {
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		std::cout << std::endl << "Buffer content: " << std::setprecision(2);

		std::vector<float> bufferContent = _buffer->get();

		if(bufferContent.size() > 0) {
			for (auto& i : bufferContent) {
				std::cout << i << " ";
			}
		} else {
			std::cout << " Buffer Empty";
		}

		Sleep(_sleepTime);
	}
}