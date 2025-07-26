#include "target/cpu/cpu_alloc.h"
#include "base/base.h"
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
namespace llminfer_base {
/**
 * @brief
 *
 * @param size
 * @return void*
 */
void *cpu_device_allocator_t::allocate(size_t size) const {
  void *ptr;
  if (size == 0) {
    return nullptr;
  }
  ptr = malloc(size);
  assert((ptr != nullptr) && "Error:Out of memory");
  return ptr;
}
/**
 * @brief
 *
 * @param ptr
 */
void cpu_device_allocator_t::release(void *ptr) const {
  if (ptr == nullptr) {
    return;
  }
  free(ptr);
}
/**
 * @brief
 *
 * @param src_ptr
 * @param dest_ptr
 * @param size
 * @param memcpy_kind
 * @param stream
 * @param need_sync
 */
void cpu_device_allocator_t::memcpy(const void *src_ptr, void *dest_ptr,
                                    size_t size, memcpy_kind_t memcpy_kind,
                                    void *stream, bool need_sync) const {
  if (memcpy_kind == memcpy_kind_t::kMemcpyCPU2CPU) {
    std::memcpy(dest_ptr, src_ptr, size);
  } else if (memcpy_kind == memcpy_kind_t::kMemcpyCPU2CUDA) {
    // TODO
  }
}
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
void cpu_device_allocator_t::memcpy(const void *src_ptr, void *dest_ptr,
                                    size_t size, device_type_t src_dev_type,
                                    device_type_t dest_dev_type, void *stream,
                                    bool need_sync) const {
  if ((src_dev_type == device_type_t::CPU) &&
      (dest_dev_type == device_type_t::CPU)) {
    memcpy(src_ptr, dest_ptr, size, memcpy_kind_t::kMemcpyCPU2CPU, stream,
           need_sync);
  }
  else{
    //TODO
  }
}
/**
 * @brief
 *
 * @param ptr
 * @param size
 * @param value
 * @param stream
 * @param need_sync
 */
void cpu_device_allocator_t::memset(void *ptr, size_t size, uint8_t value,
                                    void *stream, bool need_sync) {
  std::memset(ptr, value, size);
}
} // namespace llminfer_base