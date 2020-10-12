#pragma once
#include "BufferTaskBase.h"

class PrinterConsumerTask : public BufferTaskBase
{
	public:
		PrinterConsumerTask();
		virtual ~PrinterConsumerTask();
		void execute() override;
};

