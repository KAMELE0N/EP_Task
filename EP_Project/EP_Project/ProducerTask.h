#pragma once
#include "BufferTaskBase.h"
class ProducerTask : public BufferTaskBase
{
	public:
		ProducerTask() : BufferTaskBase(std::make_shared<Buffer>(1, 1)) {};
		ProducerTask(std::shared_ptr<Buffer> buffer) : BufferTaskBase(buffer) {};
		virtual ~ProducerTask() {};

		void run(int sleepTime) override;
};

