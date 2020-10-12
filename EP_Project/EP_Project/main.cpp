#include <iostream>
#include <memory>
#include "Buffer.h"
#include "BufferTaskBase.h"
#include "PrinterConsumerTask.h"
#include "ProducerTask.h"


int main()
{
    std::cout << "Program will terminate after any user input" << std::endl;

    int batchSize = 1;
    const size_t bufferSize = 100;

    // TODO change to singleton 
    std::shared_ptr<Buffer> mainBuffer = std::make_shared<Buffer>(bufferSize, batchSize);

    std::unique_ptr <BufferTaskBase> producerTaskPtr = std::make_unique<ProducerTask>();
    std::unique_ptr <BufferTaskBase> consumerTaskPtr = std::make_unique<PrinterConsumerTask>();
    // Create a thread using member function
    producerTaskPtr->start(1000);
    consumerTaskPtr->start(2000);


    std::cin.get();

    // Close threads
    producerTaskPtr->join();
    consumerTaskPtr->join();
}