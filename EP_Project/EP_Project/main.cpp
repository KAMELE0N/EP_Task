#include <iostream>
#include <memory>
#include "Buffer.h"
#include "BufferTaskBase.h"
#include "PrinterConsumerTask.h"


int main()
{
    int batchSize = 1;
    const size_t bufferSize = 100;

    // TODO change to singleton 
    std::unique_ptr<Buffer> mainBuffer = std::make_unique<Buffer>(bufferSize, batchSize);

    //simpleBufferTest(mainBuffer);
    BufferTaskBase* taskPtr = new PrinterConsumerTask(1000);
    // Create a thread using member function
    std::thread th(&PrinterConsumerTask::execute);

    th.join();
    delete taskPtr;
}

void simpleBufferTest(std::unique_ptr<Buffer> mainBuffer) {
    std::vector<float> a = { 3, 1, 2 };
    mainBuffer->add(a);

    std::vector<float> b = mainBuffer->get();

    for (auto& i : b) {
        std::cout << i << std::endl;
    }
}
