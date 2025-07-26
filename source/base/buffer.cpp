#include "base/buffer.h"
#include "assert.h"
#include <iostream>
namespace llminfer_base {
/**
 * @brief Construct a new buffer t::buffer t object
 * 
 * @param size 
 * @param allocator 
 * @param ptr 
 * @param use_external 
 */
buffer_t::buffer_t(size_t size, device_allocator_t *allocator, void *ptr,
                   bool use_external)
    : size(size), allocator(allocator), ptr(ptr), use_external(use_external) {
  this->device_type = allocator->get_device_type();
  if (use_external) {
    assert((ptr != nullptr) && "Error:ptr must not be null");
  } else {
    assert((allocator != nullptr) && "Error:allocator must not be null");
    this->ptr = allocator->allocate(size);
    assert((this->ptr != nullptr) && "Error:Out of memory");
  }
}
/**
 * @brief Destroy the buffer t::buffer t object
 * 
 */
buffer_t::~buffer_t(void){
  if((use_external == false) && (ptr != nullptr)){
    allocator->release(ptr);
  }
}
/**
 * @brief 
 * 
 * @return void* 
 */
void *buffer_t::get_ptr(void) const {
  return this->ptr;
}

} // namespace llminfer_base