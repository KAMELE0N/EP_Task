#pragma once
#include "BufferTaskBase.h"
class ProducerTask : public BufferTaskBase
{
	public:
		ProducerTask();
		virtual ~ProducerTask();
		void run(int sleepTime) override;
};
