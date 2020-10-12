#include "BufferTaskBase.h"

void BufferTaskBase::start(int sleepTime) {
	uthread = new std::thread(BufferTaskBase::execute, this, sleepTime);
}

void BufferTaskBase::join() {
	cancellationToken = true;
	uthread->join();
	delete uthread;
	uthread = nullptr;
}

BufferTaskBase::BufferTaskBase() {};

BufferTaskBase::~BufferTaskBase() {
	if (uthread) {
		delete uthread;
	}
}