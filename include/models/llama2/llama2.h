#ifndef __LLMINFER_MODELS_LLAMA2
#define __LLMINFER_MODELS_LLAMA2
#include "base/base.h"
#include <cstddef>
#include <string>


using namespace std;
using namespace llminfer_base;

namespace llminfer_models {
class llama2 {
public:
  llama2(string model_dir_path, device_type_t device_type);
  /**
   * @brief 
   * 
   * @param model_dir_path 
   */
  void load_model(string model_dir_path = "");
private:
  string model_path;
};
} // namespace llminfer_models

#endif
