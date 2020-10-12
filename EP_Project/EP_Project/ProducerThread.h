#pragma once
#include "BufferThreadBase.h"
#include <math.h>
#include <ctime>


class ProducerThread : public BufferThreadBase
{
	public:
		ProducerThread() : BufferThreadBase(std::make_shared<Buffer>(1, 1)) {std::srand(std::time(nullptr));};
		ProducerThread(std::shared_ptr<Buffer> buffer) : BufferThreadBase(buffer) {std::srand(std::time(nullptr));};
		virtual ~ProducerThread() {};

		void run(int sleepTime) override;
};

