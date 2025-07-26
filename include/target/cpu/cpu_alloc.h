#ifndef __LLMINFER_CPU_ALLOC_H
#define __LLMINFER_CPU_ALLOC_H

#include "base/alloc.h"
#include "base/base.h"

namespace llminfer_base {
/**
 * @brief device_allocator_t
 *
 */
class cpu_device_allocator_t : public device_allocator_t {
public:
  cpu_device_allocator_t(device_type_t device_type)
      : device_allocator_t(device_type) {};
  virtual void *allocate(size_t size) const override;
  virtual void release(void *ptr) const override;
  virtual void memcpy(const void *src_ptr, void *dest_ptr, size_t size,
                      memcpy_kind_t memcpy_kind = memcpy_kind_t::UNKNOW,
                      void *stream = nullptr,
                      bool need_sync = false) const override;
  virtual void memcpy(const void *src_ptr, void *dest_ptr, size_t size,
                      device_type_t src_dev_type, device_type_t dest_dev_type,
                      void *stream = nullptr,
                      bool need_sync = false) const override;

  virtual void memset(void *ptr, size_t size, uint8_t value, void *stream,
                      bool need_sync = false) override;
};
} // namespace llminfer_base

#endif
