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
		Buffer(int size, int batchSize);
		virtual ~Buffer();

		void add(float newData);
		std::vector<float> get();
		std::vector<float> peek();

	private:
		float* _buffer;
		std::atomic<int> _head = 0;
		std::atomic<int> _tail = 0;

		int _totalSize;
		int _batchSize;
		int _dataCount;

		std::mutex readWriteMutex;

		void clear();
		float getSingle();
};

