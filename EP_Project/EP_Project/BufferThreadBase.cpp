#include "BufferThreadBase.h"

void BufferThreadBase::start(int sleepTime) {
	uthread = new std::thread(BufferThreadBase::execute, this, sleepTime);
}

void BufferThreadBase::join() {
	cancellationToken = true;
	uthread->join();
	delete uthread;
	uthread = nullptr;
}

BufferThreadBase::BufferThreadBase(std::shared_ptr<Buffer> buffer) {
	_buffer = buffer;
};

BufferThreadBase::~BufferThreadBase() {
	if (uthread) {
		delete uthread;
	}
}