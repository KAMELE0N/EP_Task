#pragma once
#include <memory>
#include <thread>
#include <iostream>
#include <Windows.h>
#include "Buffer.h"

class BufferThreadBase
{
	public:
		BufferThreadBase(std::shared_ptr<Buffer> buffer);
		virtual ~BufferThreadBase();


		void start(int sleepTime);
		void join();


	protected:
		// is implemented by its ancestors
		virtual void run(int sleepTime) = 0;
		bool cancellationToken = false;
		int _sleepTime;

	private:
		// static function which points back to the class
		static void execute(BufferThreadBase* cppThread, int sleepTime) {
			cppThread->run(sleepTime);
		}

		std::thread* uthread = nullptr;
		std::shared_ptr<Buffer> _buffer;
};

