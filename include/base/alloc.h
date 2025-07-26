#ifndef __LLMINFER_ALLOC_H
#define __LLMINFER_ALLOC_H

#include "base/base.h"
#include <cstddef>
#include <cstdint>
namespace llminfer_base {

class device_allocator_t {
public:
  /**
   * @brief Construct a new device allocator t object
   *
   * @param type device type.
   */
  device_allocator_t(device_type_t type) : device_type(type) {}
  /**
   * @brief
   *
   * @param size
   * @return void*
   */
  virtual void *allocate(size_t size) const = 0;
  /**
   * @brief
   *
   * @param ptr
   */
  virtual void release(void *ptr) const = 0;
  /**
   * @brief
   *
   * @param src_ptr
   * @param dest_ptr
   * @param byte_size
   * @param memcpy_kind
   * @param stream
   * @param need_sync
   */
  virtual void memcpy(const void *src_ptr, void *dest_ptr, size_t size,
                      memcpy_kind_t memcpy_kind = memcpy_kind_t::kMemcpyCPU2CPU,
                      void *stream = nullptr, bool need_sync = false) const = 0;
  /**
   * @brief 
   * 
   * @param src_ptr 
   * @param dest_ptr 
   * @param size 
   * @param src_dev_type 
   * @param dest_dev_type 
   * @param stream 
   * @param need_sync 
   */
  virtual void memcpy(const void *src_ptr, void *dest_ptr, size_t size,
                      device_type_t src_dev_type, device_type_t dest_dev_type,
                      void *stream = nullptr, bool need_sync = false) const = 0;
  /**
   * @brief
   *
   * @param ptr
   * @param size
   * @param value
   * @param stream
   * @param need_sync
   */
  virtual void memset(void *ptr, size_t size, uint8_t value, void *stream,
                      bool need_sync = false) = 0;
  /**
   * @brief Get the device type object
   *
   * @return device_type_t
   */
  virtual device_type_t get_device_type(void) const { return device_type; }

private:
  device_type_t device_type;
};

} // namespace llminfer_base

#endif
