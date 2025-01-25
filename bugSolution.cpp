#include <iostream>
#include <vector>

int main() {
  // Problematic use of std::vector<bool> with operator[]
  std::vector<bool> vec(5);
  vec[0] = true;
  if (vec[0]) {
    std::cout << "vec[0] is true (might be false depending on implementation)" << std::endl; 
  }

  // Safer use of std::vector<bool> with at()
  std::vector<bool> vec2(5);
  vec2.at(0) = true; 
  if (vec2.at(0)) {
    std::cout << "vec2[0] is true (guaranteed)" << std::endl;
  }

  // Using iterators for safer access and modification
  std::vector<bool> vec3(5);
  for (auto it = vec3.begin(); it != vec3.end(); ++it) {
    *it = false; // Use *it to access and modify values
  }

  return 0;
}
