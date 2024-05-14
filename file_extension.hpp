#include <filesystem>
#include <string>
namespace fs = std::filesystem;

void set_ext_from_list(std::string& comp, std::string& raw,
                                 fs::path const& path);