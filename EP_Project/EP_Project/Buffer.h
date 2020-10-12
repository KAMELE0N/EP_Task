#pragma once
#include <iostream>
#include <vector>
#include <atomic>
#include <mutex>

// Maybe convert to template
class Buffer
{
	public:
		Buffer(int size, int batchSize);
		virtual ~Buffer();

		void add(float newData);
		std::vector<float> get();

	private:
		float* _buffer;
		std::atomic<int> _head;
		std::atomic<int> _tail;

		int _totalSize;
		int _batchSize;
		int _dataCount;

		std::mutex readWriteMutex;

		void clear();
		float getSingle();
};

