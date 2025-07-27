#include "assert.h"
#include "base/base.h"
#include "base/buffer.h"
#include "stdint.h"
#include "stdio.h"
#include "target/cpu/cpu_alloc.h"
#include <cstdint>
#include <cuda_runtime_api.h>
#include <iostream>
#include <ostream>
#include <vector>
#include "models/llama2/llama2.h"

using namespace llminfer_base;
using namespace llminfer_models;

extern int main_cu();

std::vector<int32_t> bbb;
void func(std::vector<int32_t> &dims) {
  printf("aaa:%d\r\n", dims[0]);
  bbb = dims;
}

void func_test(void) {
  int id = -1;
  cudaError_t state = cudaGetDevice(&id);
  cpu_device_allocator_t device_allocator(device_type_t::CPU);
  {
    std::vector<int32_t> *aaa = new std::vector<int32_t>{0, 1, 2, 3};
    func(*aaa);
  }
  printf("bbbb:%d\r\n", bbb[0]);
  void *ptr = device_allocator.allocate(1024);
  device_allocator.release(ptr);
  printf("state = %d,id=%d\r\n", state, id);
  {
    buffer_t buffer(1024, &device_allocator);
  }

  assert(((void *)1 != nullptr) && "Error:Out of memory");
}

int main(void) {
  llama2 *model;
  func_test();
  model = new llama2("../models/llama-2-7b/",device_type_t::CPU);
  model->load_model();
  return 0;
}
