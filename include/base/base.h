#ifndef __LLMINFER_BASE_H
#define __LLMINFER_BASE_H

namespace llminfer_base {

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
