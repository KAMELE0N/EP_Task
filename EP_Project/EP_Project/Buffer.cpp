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

void Buffer::add(float newData) {
	const std::lock_guard<std::mutex> lock(readWriteMutex);

	// TODO Check is full and handle tail shift
	_buffer[_head] = newData;
	_head = (_head + 1) % _totalSize;
	_dataCount++;
}

std::vector<float> Buffer::get() {
	// TODO ADD separate readMutex
	// TODO ADD isBatchReady flag -> only then read
	// TODO Check isEmty -> however it should not oddur after implementing isBatchReady

	const std::lock_guard<std::mutex> lock(readWriteMutex);

	std::vector<float> returnVector {};
	while (_dataCount != 0) {
		returnVector.push_back(getSingle());
	}

	return returnVector;
}

void Buffer::clear() {
	// TODO ADD THREAD LOCKS

}

float Buffer::getSingle() {
	float returnValue = _buffer[_tail];
	_tail = (_tail+1) % _totalSize;
	_dataCount--;
	// TODO Check if empty
	return returnValue;
}