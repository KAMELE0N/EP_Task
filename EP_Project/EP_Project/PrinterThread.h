#pragma once
#include "BufferThreadBase.h"

class PrinterThread : public BufferThreadBase
{
	public:
		PrinterThread() : BufferThreadBase(std::make_shared<Buffer>(1, 1)) {};
		PrinterThread(std::shared_ptr<Buffer> buffer) : BufferThreadBase(buffer) {};
		virtual ~PrinterThread() {};

		void run(int sleepTime) override;
};

