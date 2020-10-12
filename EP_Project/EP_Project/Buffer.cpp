#include "Buffer.h"

Buffer::Buffer(unsigned int size, unsigned int batchSize) {
	_buffer = new float[size];
	_batchSize = batchSize;
	_totalSize = size;
	_dataCount = 0;
	_newDataAvailable = false;
}

Buffer::~Buffer() {
	delete[] _buffer;
}

void Buffer::add(float newData) {
	batchBuffer.push_back(newData);

	if (batchBuffer.size() >= _batchSize) {
		const std::lock_guard<std::mutex> lock(readWriteMutex);
		addBatch(batchBuffer);
		_newDataAvailable = true;
		batchBuffer.clear();
	}
}

bool Buffer::isNewDataAvailable() {
	return _newDataAvailable;
}

std::vector<float> Buffer::get() {
	// TODO ADD separate readMutex
	// TODO ADD isBatchReady flag -> only then read
	// TODO Check isEmpty -> however it should not oddur after implementing isBatchReady

	const std::lock_guard<std::mutex> lock(readWriteMutex);

	std::vector<float> returnVector {};
	while (_dataCount != 0) {
		returnVector.push_back(getSingle());
	}

	_newDataAvailable = false;
	return returnVector;
}

void Buffer::addBatch(std::vector<float> newData) {
	for (auto& d : newData) {
		addSingle(d);
	}
}

// Im not 100% sure about this because i coded it during last minutes
void Buffer::addSingle(float newData) {
	int nextIndex = (_head + 1) % _totalSize;
	if (nextIndex == _tail) {
		_tail = (_tail + 1) % _totalSize;
	}

	_buffer[_head] = newData;
	_head = nextIndex;
	_dataCount++;

	if (_dataCount > _totalSize) {
		_dataCount = _totalSize;
	}
}

float Buffer::getSingle() {
	float returnValue = _buffer[_tail];
	_tail = (_tail+1) % _totalSize;
	_dataCount--;
	// TODO Check if empty
	return returnValue;
}