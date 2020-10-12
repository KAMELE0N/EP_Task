#pragma once
#include <iostream>
#include <vector>
#include <atomic>
#include <mutex>

// Maybe convert to template
// Aims to mimic circular buffer
class Buffer
{
	public:
		Buffer(unsigned int size, unsigned int batchSize);
		virtual ~Buffer();

		void add(float newData);
		std::vector<float> get();

	private:
		unsigned int _totalSize;
		unsigned int _batchSize;
		unsigned int _dataCount;

		float* _buffer;
		std::atomic<int> _head = 0;
		std::atomic<int> _tail = 0;

		std::vector<float> batchVector;
		std::mutex readWriteMutex;

		void clear();
		float getSingle();
		void addSingle(float newData);
		void addBatch(std::vector<float> newData);
};

