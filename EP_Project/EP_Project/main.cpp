#include <iostream>
#include <memory>
#include "Buffer.h"
#include "BufferTaskBase.h"
#include "PrinterConsumerTask.h"
#include "ProducerTask.h"


int main()
{
    int batchSize = 1;
    const size_t bufferSize = 100;

    // TODO change to singleton 
    std::unique_ptr<Buffer> mainBuffer = std::make_unique<Buffer>(bufferSize, batchSize);

    //simpleBufferTest(mainBuffer);

    BufferTaskBase* producerTaskPtr = new ProducerTask();
    BufferTaskBase* consumerTaskPtr = new PrinterConsumerTask();
    // Create a thread using member function
    producerTaskPtr->start(1000);
    consumerTaskPtr->start(2000);
    Sleep(10000);
    producerTaskPtr->join();
    consumerTaskPtr->join();
    delete producerTaskPtr;
    delete consumerTaskPtr;
}

void simpleBufferTest(std::unique_ptr<Buffer> mainBuffer) {
    std::vector<float> a = { 3, 1, 2 };
    mainBuffer->add(a);

    std::vector<float> b = mainBuffer->get();

    for (auto& i : b) {
        std::cout << i << std::endl;
    }
}
