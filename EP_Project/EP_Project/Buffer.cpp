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

std::vector<float> Buffer::peek() {
	const std::lock_guard<std::mutex> lock(readWriteMutex);

	// TODO Remove duplication -> for now it gets the buffer but it is not modyfiing original tail and head
	int peekHead = _head;
	int peekTail = _tail;
	int peekDataCount = _dataCount;

	std::vector<float> returnVector {};
	while (peekDataCount != 0) {
		float value = _buffer[peekTail];
		peekTail = (peekTail + 1) % _totalSize;
		peekDataCount--;

		returnVector.push_back(value);
	}
	return returnVector;
}

void Buffer::clear() {

}

float Buffer::getSingle() {
	float returnValue = _buffer[_tail];
	_tail = (_tail+1) % _totalSize;
	_dataCount--;
	// TODO Check if empty
	return returnValue;
}