#include "Buffer.h"

Buffer::Buffer(int size, int batchSize) {
	_buffer = new float[size];
	_batchSize = batchSize;
	_totalSize = size;
	_dataCount = 0;
}

Buffer::~Buffer() {
	delete[] _buffer;
}

void Buffer::add(std::vector<float> newData) {
	// TODO ADD THREAD LOCKS
	for (auto& i : newData) {
		addSingle(i);
	}
}

std::vector<float> Buffer::get() {
	// TODO ADD THREAD LOCKS
	// TODO ADD separate readMutex
	// TODO ADD isBatchReady flag -> only then read
	// TODO Check isEmty -> however it should not oddur after implementing isBatchReady
	std::vector<float> returnVector {};
	while (_dataCount != 0) {
		returnVector.push_back(getSingle());
	}

	return returnVector;
}

void Buffer::clear() {
	// TODO ADD THREAD LOCKS

}

void Buffer::addSingle(float newData) {
	// TODO Check is full and handle tail shift
	_buffer[_head] = newData;
	_head = (_head+1) % _totalSize;
	_dataCount++;
}

float Buffer::getSingle() {
	float returnValue = _buffer[_tail];
	_tail = (_tail+1) % _totalSize;
	_dataCount--;
	// TODO Check if empty
	return returnValue;
}