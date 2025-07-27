#include "models/llama2/llama2.h"
#include "base/base.h"
#include "json/json.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using namespace llminfer_base;
using json = nlohmann::json;

namespace llminfer_models {
/**
 * @brief Construct a new llama2::llama2 object
 *
 * @param model_path
 * @param device_type
 */
llama2::llama2(string model_path, device_type_t device_type)
    : model_path(model_path) {}
/**
 * @brief
 *
 * @param model_path
 */
void llama2::load_model(string model_path) {
  ifstream *tokenizer;
  string tokenizer_path;
  if(model_path == ""){
    model_path = this->model_path;
  }
  tokenizer_path = model_path + "/tokenizer.json";
  tokenizer = new ifstream(tokenizer_path);
  
  json data = json::parse(*tokenizer);
  cout << data << endl;
}
} // namespace llminfer_models
