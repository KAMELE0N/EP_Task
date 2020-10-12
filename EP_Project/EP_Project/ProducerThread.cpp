#include "ProducerThread.h"

void ProducerThread::run(int sleepTime) {
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		std::cout << "Producer ping" << std::endl;	// Debug log

		int randomValue = std::rand();
		float randomSignal = sin(randomValue / 100 % 5000); // Crop signal 
		_buffer->add(randomSignal);

		Sleep(_sleepTime);
	}
}