#include "ProducerTask.h"

ProducerTask::ProducerTask() {

}

ProducerTask::~ProducerTask() {

}

void ProducerTask::run(int sleepTime) {
	_sleepTime = sleepTime;

	while (!cancellationToken) {
		std::cout << "producer ping" << std::endl;
		Sleep(_sleepTime);
	}
}