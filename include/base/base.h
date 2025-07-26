#ifndef __LLMINFER_BASE_H
#define __LLMINFER_BASE_H

namespace llminfer_base {

enum class data_type_t{
  INT8 = 0,
  INT16 = 1,
  BF16 = 2,
  FP16 = 3,
  FP32 = 4,
  TP32 = 5,
  UNKNOW
};

enum class memcpy_kind_t {
  kMemcpyCPU2CPU = 0,
  kMemcpyCPU2CUDA = 1,
  kMemcpyCUDA2CPU = 2,
  kMemcpyCUDA2CUDA = 3,
  UNKNOW
};

enum class device_type_t { CPU = 0, CUDA = 1, UNKNOW };
} // namespace llminfer_base

#endif
