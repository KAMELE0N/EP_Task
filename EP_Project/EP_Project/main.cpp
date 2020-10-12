#include <iostream>
#include <memory>

#include "Buffer.h"
#include "PrinterThread.h"
#include "ProducerThread.h"
#include "ConsumerThread.h"
#include "BufferThreadBase.h"



int main()
{
    std::cout << "Program will terminate after any user input" << std::endl;
    int producerInterval = 1000;
    int consumerInterval = 2000;
    int printerInterval = 10000;


    int batchSize = 1;
    const size_t bufferSize = 100;
    // TODO change to singleton 
    std::shared_ptr<Buffer> mainBuffer = std::make_shared<Buffer>(bufferSize, batchSize);

    // Create threads wrappers
    std::unique_ptr <BufferThreadBase> producerPtr = std::make_unique<ProducerThread>();
    std::unique_ptr <BufferThreadBase> consumerPtr = std::make_unique<ConsumerThread>();
    std::unique_ptr <PrinterThread> bufferPrinterPtr = std::make_unique<PrinterThread>();

    // Create a thread using member function
    producerPtr->start(producerInterval);
    consumerPtr->start(consumerInterval);
    bufferPrinterPtr->start(printerInterval);

    // Wait for user input
    std::cin.get();

    // Close threads
    producerPtr->join();
    consumerPtr->join();
    bufferPrinterPtr->join();
}