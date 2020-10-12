#pragma once
#include "BufferTaskBase.h"

class PrinterConsumerTask : public BufferTaskBase
{
	public:
		PrinterConsumerTask();
		virtual ~PrinterConsumerTask();
		void run(int sleepTime) override;
};

