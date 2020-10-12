#pragma once
#include "BufferTaskBase.h"

class PrinterConsumerTask : public BufferTaskBase
{
	public:
		PrinterConsumerTask() : BufferTaskBase(std::make_shared<Buffer>(1, 1)) {};
		PrinterConsumerTask(std::shared_ptr<Buffer> buffer) : BufferTaskBase(buffer) {};
		virtual ~PrinterConsumerTask() {};

		void run(int sleepTime) override;
};

