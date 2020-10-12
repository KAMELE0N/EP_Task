#include "BufferTaskBase.h"

BufferTaskBase::BufferTaskBase() {

}

BufferTaskBase::~BufferTaskBase() {

}

void BufferTaskBase::stop() {
	cancellationToken = true;
}