#pragma once
#include "BufferThreadBase.h"

class ConsumerThread : public BufferThreadBase
{
	public:
		ConsumerThread() : BufferThreadBase(std::make_shared<Buffer>(1, 1)) {};
		ConsumerThread(std::shared_ptr<Buffer> buffer) : BufferThreadBase(buffer) {};
		virtual ~ConsumerThread() {};

		void run(int sleepTime) override;
};

