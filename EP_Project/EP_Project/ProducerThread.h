#pragma once
#include "BufferThreadBase.h"

class ProducerThread : public BufferThreadBase
{
	public:
		ProducerThread() : BufferThreadBase(std::make_shared<Buffer>(1, 1)) {};
		ProducerThread(std::shared_ptr<Buffer> buffer) : BufferThreadBase(buffer) {};
		virtual ~ProducerThread() {};

		void run(int sleepTime) override;
};

