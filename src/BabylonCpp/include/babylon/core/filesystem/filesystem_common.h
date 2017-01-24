#ifndef BABYLON_CORE_FILESYSTEM_FILESYSTEM_COMMON_H
#define BABYLON_CORE_FILESYSTEM_FILESYSTEM_COMMON_H

#include <babylon/babylon_global.h>

namespace BABYLON {
namespace Filesystem {

inline std::string extension(const std::string& filename)
{
  size_t pos = filename.find_last_of(".");
  if (pos == std::string::npos) {
    return "";
  }
  return filename.substr(pos + 1);
}

} // end of Filesystem
} // end of namespace BABYLON

#endif // end of BABYLON_CORE_FILESYSTEM_FILESYSTEM_COMMON_H