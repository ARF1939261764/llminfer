#include "base/base.h"
#include "stdio.h"
#include <cuda_runtime_api.h>
#include "assert.h"
#include "target/cpu/cpu_alloc.h"
#include "base/buffer.h"

using namespace llminfer_base;

extern int main_cu();

int main(void){
  int id = -1;
  cudaError_t state = cudaGetDevice(&id);
  cpu_device_allocator_t device_allocator(device_type_t::CPU);
  void *ptr = device_allocator.allocate(1024);
  device_allocator.release(ptr);
  printf("state = %d,id=%d\r\n",state,id);
  {
    buffer_t buffer(1024,&device_allocator);
  }
  printf("bbb\r\n");

  assert(((void*)1 != nullptr) && "Error:Out of memory");

  return 0;
}
