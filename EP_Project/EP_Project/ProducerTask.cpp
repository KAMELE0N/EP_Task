#include "ProducerTask.h"

ProducerTask::ProducerTask() {

}

ProducerTask::~ProducerTask() {

}

void ProducerTask::execute() {

	while (!cancellationToken) {
		std::cout << "producer ping" << std::endl;
		Sleep(_sleepTime);
	}
}