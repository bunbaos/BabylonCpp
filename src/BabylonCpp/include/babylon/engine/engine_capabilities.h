#ifndef BABYLON_ENGINE_ENGINE_CAPABILITIES_H
#define BABYLON_ENGINE_ENGINE_CAPABILITIES_H

#include <babylon/babylon_global.h>
#include <babylon/interfaces/igl_rendering_context.h>

namespace BABYLON {

struct BABYLON_SHARED_EXPORT AnisotropicFilterExtension {
  static unsigned int TEXTURE_MAX_ANISOTROPY_EXT;
}; // end of struct TextureAnisotropicFilterExtension

struct BABYLON_SHARED_EXPORT InstancedArrays {
  ::std::function<void(unsigned int, int)> vertexAttribDivisorANGLE;
  ::std::function<void(unsigned int mode, int indexCount,
                       unsigned int indexFormat, unsigned int start,
                       int instancesCount)>
    drawElementsInstancedANGLE;
  ::std::function<void(unsigned int mode, int verticesStart, int verticesCount,
                       int instancesCount)>
    drawArraysInstancedANGLE;
}; // end of struct InstancedArrays

struct BABYLON_SHARED_EXPORT EngineCapabilities {
  /** The maximum textures image */
  int maxTexturesImageUnits;
  int maxVertexTextureImageUnits;
  int maxCombinedTexturesImageUnits;
  /** The maximum texture size */
  int maxTextureSize;
  int maxCubemapTextureSize;
  int maxRenderTextureSize;
  int maxVertexAttribs;
  int maxVaryingVectors;
  int maxVertexUniformVectors;
  int maxFragmentUniformVectors;
  bool standardDerivatives;
  Nullable<GL::WEBGL_compressed_texture_s3tc> s3tc;
  GL::any pvrtc; // WEBGL_compressed_texture_pvrtc;
  GL::any etc1;  // WEBGL_compressed_texture_etc1;
  GL::any etc2;  // WEBGL_compressed_texture_etc;
  GL::any astc;  // WEBGL_compressed_texture_astc;
  GL::any atc;   // WEBGL_compressed_texture_atc;
  bool textureFloat;
  bool vertexArrayObject = false;
  Nullable<GL::EXT_texture_filter_anisotropic>
    textureAnisotropicFilterExtension;
  unsigned int maxAnisotropy;
  bool instancedArrays;
  bool uintIndices;
  bool highPrecisionShaderSupported;
  bool fragmentDepthSupported;
  bool textureFloatLinearFiltering;
  bool textureFloatRender;
  bool textureHalfFloat;
  bool textureHalfFloatLinearFiltering;
  bool textureHalfFloatRender;
  bool textureLOD;
  bool drawBuffersExtension;
  bool depthTextureExtension;
  bool colorBufferFloat;
  GL::EXT_disjoint_timer_query timerQuery;
  bool canUseTimestampForTimerQuery;
}; // end of struct EngineCapabilities

} // end of namespace BABYLON

#endif // end of BABYLON_ENGINE_ENGINE_CAPABILITIES_H
