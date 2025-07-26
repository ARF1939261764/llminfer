#ifndef __LLMINFER_BUFFER_H
#define __LLMINFER_BUFFER_H

#include "base/alloc.h"
#include "base/base.h"
#include <cstddef>
namespace llminfer_base {

class buffer_t {
public:
  buffer_t(size_t size, device_allocator_t *allocator = nullptr,
           void *ptr = nullptr, bool use_external = false);
  ~buffer_t(void);
  size_t get_size(void) { return size; }
  device_type_t get_device_type(void) { return device_type; }
  void *get_ptr(void) const;
  bool is_external(void) { return use_external; }
  void cpyfrom(buffer_t *src_ptr);
  void cpyfrom(buffer_t &src_ptr);

private:
  buffer_t() = default;
  device_allocator_t *allocator;
  void *ptr = nullptr;
  size_t size;
  bool use_external;
  device_type_t device_type = device_type_t::UNKNOW;
};

} // namespace llminfer_base

#endif
