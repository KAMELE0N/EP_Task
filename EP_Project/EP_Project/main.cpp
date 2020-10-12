#include <iostream>
#include <memory>

#include "Buffer.h"
#include "PrinterThread.h"
#include "ProducerThread.h"
#include "BufferThreadBase.h"



int main()
{
    std::cout << "Program will terminate after RETURN key press" << std::endl;
    int producerInterval = 500;
    int consumerInterval = 2000;


    unsigned int batchSize = 1;
    const unsigned int bufferSize = 100;
    // TODO change to singleton 
    std::shared_ptr<Buffer> mainBuffer = std::make_shared<Buffer>(bufferSize, batchSize);

    // Create threads wrappers
    std::unique_ptr <BufferThreadBase> producerPtr = std::make_unique<ProducerThread>(mainBuffer);
    std::unique_ptr <PrinterThread> bufferPrinterPtr = std::make_unique<PrinterThread>(mainBuffer);

    // Create a thread using member function
    producerPtr->start(producerInterval);
    bufferPrinterPtr->start(consumerInterval);

    // Wait for user input
    std::cin.get();

    // Close threads
    producerPtr->join();
    bufferPrinterPtr->join();
}