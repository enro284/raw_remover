#include <algorithm>
#include <iostream>
#include <string>
int main() {
  std::string raw_list{
      ".3fr, .ari, .arw, .bay, .braw, .crw, .cr2, .cr3, .cap, .data, .dcs, "
      ".dcr, "
      ".dng,.drf, .eip, .erf, .fff, .gpr, .iiq, .k25, .kdc, .mdc, .mef, .mos, "
      ".mrw,.nef, .nrw, .obm, .orf, .pef, .ptx, .pxn, .r3d, .raf, .raw, .rwl, "
      ".rw2,.rwz,.sr2, .srf, .srw, .tif, .tiff, .x3f "};

  std::string comp_list{".jpg, .jpeg, .jfif, .pjpeg, .pjp, .png, .bmp, .webp"};

  raw_list.erase(std::remove(raw_list.begin(), raw_list.end(), ' '),
                 raw_list.end());

  for (auto it = raw_list.begin(); it < raw_list.end(); ++it) {
    switch (*it) {
      case '.':
        it = raw_list.insert(it, '\"');
        ++it;
        break;
      case ',':
        it = raw_list.insert(it, '\"');
        ++it;
        break;
      default:
        break;
    }
  }

  comp_list.erase(std::remove(comp_list.begin(), comp_list.end(), ' '),
                  comp_list.end());

  for (auto it = comp_list.begin(); it < comp_list.end(); ++it) {
    switch (*it) {
      case '.':
        it = comp_list.insert(it, '\"');
        ++it;
        break;
      case ',':
        it = comp_list.insert(it, '\"');
        ++it;
        break;
      default:
        break;
    }
  }

  std::cout << raw_list << '"' << "\n\n";
  std::cout << comp_list << '"' << "\n\n";
}
