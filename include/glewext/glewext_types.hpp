#pragma once

#include <GL/glew.h>

namespace glewext {
enum class ShaderType : unsigned int {
  Vertex = GL_VERTEX_SHADER,
  Fragment = GL_FRAGMENT_SHADER
};

enum class TextureUnit : int {
  _0,
  _1,
  _2,
  _3,
  _4,
  _5,
  _6,
  _7,
  _8,
  _9,
  _10,
  _11,
  _12,
  _13,
  _14,
  _15
};

enum class TextureLevel : int {
  Base = 0,
  Level1 = 1,
  Level2 = 2,
  Level3 = 3,
  Level4 = 4,
  Level5 = 5,
  Level6 = 6,
  Level7 = 7,
  Level8 = 8,
  Level9 = 9,
  Level10 = 10,
  Level11 = 11,
  Level12 = 12,
  Level13 = 13,
  Level14 = 14,
  Level15 = 15,
  Level16 = 16,
  Level17 = 17,
  Level18 = 18,
  Level19 = 19,
  Level20 = 20,
  Level21 = 21,
  Level22 = 22,
  Level23 = 23,
  Level24 = 24,
  Level25 = 25,
  Level26 = 26,
  Level27 = 27,
  Level28 = 28,
  Level29 = 29,
  Level30 = 30,
  Level31 = 31
};

enum class TextureInternalFormat : int {
  R = GL_RED,
  RG = GL_RG,
  RGB = GL_RGB,
  RGBA = GL_RGBA,
  R8 = GL_R8,
  RG8 = GL_RG8,
  RGB8 = GL_RGB8,
  RGBA8 = GL_RGBA8,
  // Other
};

enum class TextureBorder : int { NoBorder = 0, Border = 1 };

enum class TextureFormat : int {
  Red = GL_RED,
  RG = GL_RG,
  RGB = GL_RGB,
  BGR = GL_BGR,
  RGBA = GL_RGBA,
  BGRA = GL_BGRA,
  RedInteger = GL_RED_INTEGER,
  RGInteger = GL_RG_INTEGER,
  RGBInteger = GL_RGB_INTEGER,
  BGRInteger = GL_BGR_INTEGER,
  RGBAInteger = GL_RGBA_INTEGER,
  BGRAInteger = GL_BGRA_INTEGER
  // Other
};

enum class GLType : int {
  Byte = GL_BYTE,
  UnsignedByte = GL_UNSIGNED_BYTE,
  Short = GL_SHORT,
  UnsignedShort = GL_UNSIGNED_SHORT,
  Int = GL_INT,
  UnsignedInt = GL_UNSIGNED_INT,
  Float = GL_FLOAT,
  HalfFloat = GL_HALF_FLOAT,
  UnsignedShort565 = GL_UNSIGNED_SHORT_5_6_5,
  UnsignedShort4444 = GL_UNSIGNED_SHORT_4_4_4_4,
  UnsignedShort5551 = GL_UNSIGNED_SHORT_5_5_5_1,
  UnsignedInt8888 = GL_UNSIGNED_INT_8_8_8_8,
  UnsignedInt1010102 = GL_UNSIGNED_INT_10_10_10_2
  // Other
};
}  // namespace glewext