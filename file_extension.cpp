#include "file_extension.hpp"

#include <algorithm>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace fs = std::filesystem;

void set_ext_from_list(std::string& comp, std::string& raw,
                       fs::path const& path) {
                        
  std::vector<std::string> known_comp_ext{".jpg", ".jpeg", ".jfif", ".pjpeg",
                                          ".pjp", ".png",  ".bmp",  ".webp"};
  std::vector<std::string> known_raw_ext{
      ".3fr",  ".ari", ".arw", ".bay", ".braw", ".crw", ".cr2",  ".cr3", ".cap",
      ".data", ".dcs", ".dcr", ".dng", ".drf",  ".eip", ".erf",  ".fff", ".gpr",
      ".iiq",  ".k25", ".kdc", ".mdc", ".mef",  ".mos", ".mrw",  ".nef", ".nrw",
      ".obm",  ".orf", ".pef", ".ptx", ".pxn",  ".r3d", ".raf",  ".raw", ".rwl",
      ".rw2",  ".rwz", ".sr2", ".srf", ".srw",  ".tif", ".tiff", ".x3f"};

  bool found_comp{false};
  bool found_raw{false};

  for (auto& dir_entry : fs::directory_iterator(path)) {
    if (dir_entry.is_regular_file()) {
      std::string file_ext = dir_entry.path().extension().string();

      if (!found_comp && std::find(known_comp_ext.begin(), known_comp_ext.end(),
                                   file_ext) != known_comp_ext.end()) {
        comp = file_ext;
        found_comp = true;
        if (found_raw) break;
      }
      if (!found_raw && std::find(known_raw_ext.begin(), known_raw_ext.end(),
                                  file_ext) != known_raw_ext.end()) {
        raw = file_ext;
        found_raw = true;
        if (found_comp) break;
      }
    }
  }

  if (!found_comp && !found_raw)
    throw std::runtime_error{"no extensions found"};
  else if (!found_comp)
    throw std::runtime_error{"no comp file extension found"};
  else if(!found_raw)
    throw std::runtime_error{"no raw file extension found"};
}