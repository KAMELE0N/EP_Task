#include "ProducerThread.h"

void ProducerThread::run(int sleepTime) {
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		int randomValue = std::rand();
		float randomSignal = sin(randomValue / 100 % 5000); // Crop signal 
		_buffer->add(randomSignal);

		Sleep(_sleepTime);
	}
}