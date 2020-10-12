#include "ProducerTask.h"
void ProducerTask::run(int sleepTime) {
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		std::cout << "Producer ping" << std::endl;
		Sleep(_sleepTime);
	}
}