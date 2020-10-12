#pragma once
#include "BufferThreadBase.h"

class PrinterConsumerThread : public BufferThreadBase
{
	public:
		PrinterConsumerThread() : BufferThreadBase(std::make_shared<Buffer>(1, 1)) {};
		PrinterConsumerThread(std::shared_ptr<Buffer> buffer) : BufferThreadBase(buffer) {};
		virtual ~PrinterConsumerThread() {};

		void run(int sleepTime) override;
};

