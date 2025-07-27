

#include "base/alloc.h"
#include "base/base.h"
#include "vector"
#include <cstdint>
#include <vector>

using namespace llminfer_base;

namespace llminfer_tensor {
class dims {
public:
  dims(int32_t dim0 = 0, int32_t dim1 = 0, int32_t dim2 = 0, int32_t dim3 = 0,
       int32_t dim4 = 0, int32_t dim5 = 0, int32_t dim6 = 0, int32_t dim7 = 0)
      : dim(*(new std::vector<int32_t>{dim0, dim1, dim2, dim3, dim4, dim5, dim6,
                                       dim7})) {}
  std::vector<int32_t> get_dims(void) { return dim; }

private:
  std::vector<int32_t> dim;
};
class tensor_t {
public:
  tensor_t(data_type_t data_type, dims *dim, bool need_alloc = false,
           device_allocator_t *allocator = nullptr, void *ptr = nullptr);
};
} // namespace llminfer_tensor
