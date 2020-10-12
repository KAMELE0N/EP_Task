#include <iostream>
#include <memory>
#include "Buffer.h"
#include "BufferThreadBase.h"
#include "PrinterConsumerThread.h"
#include "ProducerThread.h"


int main()
{
    std::cout << "Program will terminate after any user input" << std::endl;

    int batchSize = 1;
    const size_t bufferSize = 100;

    // TODO change to singleton 
    std::shared_ptr<Buffer> mainBuffer = std::make_shared<Buffer>(bufferSize, batchSize);

    // Create threads wrappers
    std::unique_ptr <BufferThreadBase> producerTaskPtr = std::make_unique<ProducerThread>();
    std::unique_ptr <BufferThreadBase> consumerTaskPtr = std::make_unique<PrinterConsumerThread>();

    // Create a thread using member function
    producerTaskPtr->start(1000);
    consumerTaskPtr->start(2000);

    // Wait for user input
    std::cin.get();

    // Close threads
    producerTaskPtr->join();
    consumerTaskPtr->join();
}