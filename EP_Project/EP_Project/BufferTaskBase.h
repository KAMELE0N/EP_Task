#pragma once
#include <thread>
#include <iostream>
#include <Windows.h>

class BufferTaskBase
{
	public:
		BufferTaskBase();
		virtual ~BufferTaskBase();


		void start(int sleepTime);
		void join();


	protected:
		// is implemented by its ancestors
		virtual void run(int sleepTime) = 0;
		bool cancellationToken = false;
		int _sleepTime;

	private:
		// static function which points back to the class
		static void execute(BufferTaskBase* cppThread, int sleepTime) {
			cppThread->run(sleepTime);
		}

		std::thread* uthread = nullptr;
};

