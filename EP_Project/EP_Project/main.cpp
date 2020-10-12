#include <iostream>
#include <memory>
#include "Buffer.h"


int main()
{
    int batchSize = 1;
    const size_t bufferSize = 100;

    // TODO change to singleton 
    std::unique_ptr<Buffer> mainBuffer = std::make_unique<Buffer>(bufferSize, batchSize);
}
