#include <filesystem>
#include <iostream>

#include "file_extension.hpp"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
  std::cout
      << "Welcome to RAW REMOVER\n"
      << "this program checks every image in the folder where it's executed\n"
      << "and deletes the raw image if it doesn't find the matching compressed "
         "image\n\n";

  std::string comp_ext;
  std::string raw_ext;

  fs::path path{"."};

  enum Extension_mode { prompt_user, auto_from_list };
  Extension_mode ext_mode{auto_from_list};

  switch (ext_mode) {
    case prompt_user:
      std::cout << "insert compressed image extension (including \".\"): ";
      std::cin >> comp_ext;
      std::cout << "insert raw image extension (including \".\"): ";
      std::cin >> raw_ext;
      break;
    case auto_from_list:
      set_ext_from_list(comp_ext, raw_ext, path);
      break;
  }

  for (auto& dir_entry : fs::directory_iterator(".")) {
    if (dir_entry.is_regular_file()) {
      auto file = dir_entry.path();
      if (file.extension().string() == raw_ext &&
          !exists(file.replace_extension(comp_ext))) {
        std::cout << "deleting: " << dir_entry << '\n';
        fs::remove(dir_entry);
      }
    }
  }
}