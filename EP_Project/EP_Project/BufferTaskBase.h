#pragma once
#include <thread>
#include <iostream>
#include <Windows.h>

class BufferTaskBase
{
	public:
		BufferTaskBase();
		virtual ~BufferTaskBase();
		static virtual void execute();
		void stop();

	protected:
		bool cancellationToken = false;
		int _sleepTime;
};

