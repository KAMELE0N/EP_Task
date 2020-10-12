#pragma once
#include "BufferThreadBase.h"

class BufferPrinterThread : public BufferThreadBase
{
	public:
		BufferPrinterThread() : BufferThreadBase(std::make_shared<Buffer>(1, 1)) {};
		BufferPrinterThread(std::shared_ptr<Buffer> buffer) : BufferThreadBase(buffer) {};
		virtual ~BufferPrinterThread() {};

		void run(int sleepTime) override;
};

