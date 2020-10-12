#pragma once
#include <iostream>
#include <vector>
#include <atomic>

// Maybe convert to template
class Buffer
{
	public:
		Buffer(int size, int batchSize);
		virtual ~Buffer();

		void add(std::vector<float> newData);
		std::vector<float> get();

	private:
		float* _buffer;
		std::atomic<int> _head;
		std::atomic<int> _tail;

		int _totalSize;
		int _batchSize;
		int _dataCount;

		void clear();
		void addSingle(float newData);
		float getSingle();
};

