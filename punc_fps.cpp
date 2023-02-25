// This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cassert>

#define MODE LINUX_BUILD // || WIN64_BUILD

#if (MODE == LINUX_BUILD)
 #define _aligned_malloc aligned_alloc
 #define _aligned_free free
#endif

#ifndef _ASSERT
 #define _ASSERT assert
#endif

typedef unsigned char      u8;  // 8b
typedef unsigned short     u16; // 16b
typedef unsigned int       u32; // 32b
typedef unsigned long long u64; // 64b

typedef u8 (*puncture_func)(u8 input);


inline u8 puncture_00000000(u8 input) { return (input   ); }
inline u8 puncture_00000001(u8 input) { return (input>>1);  }
inline u8 puncture_00000010(u8 input) { return ((input & 0xfc) >> 1) | (input & 0x1);  }
inline u8 puncture_00000011(u8 input) { return (input>>2);  }
inline u8 puncture_00000100(u8 input) { return ((input & 0xf8) >> 1) | (input & 0x3); }
inline u8 puncture_00000101(u8 input) { return (input >> 1) | puncture_00000010(input >> 1); }
inline u8 puncture_00000110(u8 input) { return (input & 0x1) | ((input & 0xf8) >> 2);  }
inline u8 puncture_00000111(u8 input) { return input>>3;  }
inline u8 puncture_00001000(u8 input) { return ((input & 0xf0) >> 1) | (input & 0x7); }
inline u8 puncture_00001001(u8 input) { return (input >> 1) | puncture_00000100(input >> 1); }
inline u8 puncture_00001010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0xf0) >> 2); }
inline u8 puncture_00001011(u8 input) { return (input>>2) | puncture_00000010(input >> 2); }
inline u8 puncture_00001100(u8 input) { return (input & 0x3) | ((input & 0xf0) >> 2); }
inline u8 puncture_00001101(u8 input) { return (input >> 1) | puncture_00000110(input >> 1);}
inline u8 puncture_00001110(u8 input) { return (input & 0x1) | ((input & 0xf0) >> 3);  }
inline u8 puncture_00001111(u8 input) { return (input>>4);  }
inline u8 puncture_00010000(u8 input) { return ((input & 0xe0) >> 1) | (input & 0xf); }
inline u8 puncture_00010001(u8 input) { return (input >> 1) | puncture_00001000(input >> 1); }
inline u8 puncture_00010010(u8 input) { return (input & 0x1) | ((input & 0xc)>>1) | ((input & 0xe0) >> 2);  }
inline u8 puncture_00010011(u8 input) { return (input>>2) | puncture_00000100(input >> 2); }
inline u8 puncture_00010100(u8 input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0xe0) >> 2); }
inline u8 puncture_00010101(u8 input) { return (input>>1) | puncture_00001010(input >> 1); }
inline u8 puncture_00010110(u8 input) { return (input & 0x1) | ((input & 0x8)>>2) | ((input & 0xe0) >> 3);  }
inline u8 puncture_00010111(u8 input) { return (input >> 3) | puncture_00000010(input >> 3); }
inline u8 puncture_00011000(u8 input) { return (input & 0x7) | ((input & 0xe0) >> 2); }
inline u8 puncture_00011001(u8 input) { return (input >> 1) | puncture_00001100(input >> 1); }
inline u8 puncture_00011010(u8 input) { return (input & 0x1) | ((input & 0x4)>>1) | ((input & 0xe0) >> 3);  }
inline u8 puncture_00011011(u8 input) { return (input >> 2) | puncture_00000110(input >> 2); }
inline u8 puncture_00011100(u8 input) { return (input & 0x3) | ((input & 0xe0) >> 3); }
inline u8 puncture_00011101(u8 input) { return (input >> 1) | puncture_00001110(input >> 1); }
inline u8 puncture_00011110(u8 input) { return (input & 0x1) | ((input & 0xe0) >> 4);  }
inline u8 puncture_00011111(u8 input) { return (input>>5);  }
inline u8 puncture_00100000(u8 input) { return ((input & 0xc0) >> 1) | (input & 0x1f); }
inline u8 puncture_00100001(u8 input) { return (input >> 1) | puncture_00010000(input >> 1); }
inline u8 puncture_00100010(u8 input) { return (input & 0x1) | ((input & 0x1c)>>1) | ((input & 0xc0) >> 2);  }
inline u8 puncture_00100011(u8 input) { return (input >> 2) | puncture_00001000(input >> 2); }
inline u8 puncture_00100100(u8 input) { return (input & 0x3) | ((input & 0x18) >> 1) | ((input & 0xc0) >> 2); }
inline u8 puncture_00100101(u8 input) { return (input >> 1) | puncture_00010010(input >> 1); }
inline u8 puncture_00100110(u8 input) { return (input & 0x1) | ((input & 0x18) >> 2) | ((input & 0xc0) >> 3);  }
inline u8 puncture_00100111(u8 input) { return (input >> 3) | puncture_00000100(input >> 3); }
inline u8 puncture_00101000(u8 input) { return (input & 0x7) | ((input & 0x10) >> 1) | ((input & 0xc0) >> 2); }
inline u8 puncture_00101001(u8 input) { return (input >> 1) | puncture_00010100(input >> 1); }
inline u8 puncture_00101010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x10) >> 2) | ((input & 0xc0) >> 3);  }
inline u8 puncture_00101011(u8 input) { return (input >> 2) | puncture_00001010(input >> 2); }
inline u8 puncture_00101100(u8 input) { return (input & 0x3) | ((input & 0x10) >> 2) | ((input & 0xc0) >> 3); }
inline u8 puncture_00101101(u8 input) { return (input >> 1) | puncture_00010110(input >> 1); }
inline u8 puncture_00101110(u8 input) { return (input & 0x1) | ((input & 0x10) >> 3) | ((input & 0xc0) >> 4); }
inline u8 puncture_00101111(u8 input) { return (input >> 4) | puncture_00000010(input >> 4); }
inline u8 puncture_00110000(u8 input) { return (input & 0xf) | ((input & 0xc0) >> 2); }
inline u8 puncture_00110001(u8 input) { return (input >> 1) | puncture_00011000(input >> 1); }
inline u8 puncture_00110010(u8 input) { return (input & 0x1) | ((input & 0xc) >> 1) | ((input & 0xc0) >> 3); }
inline u8 puncture_00110011(u8 input) { return (input >> 2) | puncture_00001100(input >> 2); }
inline u8 puncture_00110100(u8 input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0xc0) >> 3); }
inline u8 puncture_00110101(u8 input) { return (input >> 1) | puncture_00011010(input >> 1); }
inline u8 puncture_00110110(u8 input) { return (input & 0x1) | ((input & 0x8) >> 2) | ((input & 0xc0) >> 4); }
inline u8 puncture_00110111(u8 input) { return (input >> 3) | puncture_00000110(input >> 3); }
inline u8 puncture_00111000(u8 input) { return (input & 0x7) | ((input & 0xc0) >> 3); }
inline u8 puncture_00111001(u8 input) { return (input >> 1) | puncture_00011100(input >> 1); }
inline u8 puncture_00111010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0xc0) >> 4); }
inline u8 puncture_00111011(u8 input) { return (input >> 2) | puncture_00001110(input >> 2); }
inline u8 puncture_00111100(u8 input) { return (input & 0x3) | ((input & 0xc0) >> 4); }
inline u8 puncture_00111101(u8 input) { return (input >> 1) | puncture_00011110(input >> 1); }
inline u8 puncture_00111110(u8 input) { return (input & 0x1) | ((input & 0xc0) >> 5); }
inline u8 puncture_00111111(u8 input) { return (input>>6);  }
inline u8 puncture_01000000(u8 input) { return ((input & 0x80) >> 1) | (input & 0x3f); }
inline u8 puncture_01000001(u8 input) { return (input >> 1) | puncture_00100000(input >> 1); }
inline u8 puncture_01000010(u8 input) { return (input & 0x1) | ((input & 0x3c) >> 1) | ((input & 0x80) >> 2); }
inline u8 puncture_01000011(u8 input) { return (input >> 2) | puncture_00010000(input >> 2); }
inline u8 puncture_01000100(u8 input) { return (input & 0x3) | ((input & 0x38) >> 1) | ((input & 0x80) >> 2); }
inline u8 puncture_01000101(u8 input) { return (input >> 1) | puncture_00100010(input >> 1); }
inline u8 puncture_01000110(u8 input) { return (input & 0x1) | ((input & 0x38) >> 2) | ((input & 0x80) >> 3); }
inline u8 puncture_01000111(u8 input) { return (input >> 3) | puncture_00001000(input >> 3); }
inline u8 puncture_01001000(u8 input) { return (input & 0x7) | ((input & 0x30) >> 1) | ((input & 0x80) >> 2); }
inline u8 puncture_01001001(u8 input) { return (input >> 1) | puncture_00100100(input >> 1); }
inline u8 puncture_01001010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x30) >> 2) | ((input & 0x80) >> 3); }
inline u8 puncture_01001011(u8 input) { return (input >> 2) | puncture_00010010(input >> 2); }
inline u8 puncture_01001100(u8 input) { return (input & 0x3) | ((input & 0x30) >> 2) | ((input & 0x80) >> 3); }
inline u8 puncture_01001101(u8 input) { return (input >> 1) | puncture_00100110(input >> 1); }
inline u8 puncture_01001110(u8 input) { return (input & 0x1) | ((input & 0x30) >> 3) | ((input & 0x80) >> 4); }
inline u8 puncture_01001111(u8 input) { return (input >> 4) | puncture_00000100(input >> 4); }
inline u8 puncture_01010000(u8 input) { return (input & 0xf) | ((input & 0x20) >> 1) | ((input & 0x80) >> 2); }
inline u8 puncture_01010001(u8 input) { return (input >> 1) | puncture_00101000(input >> 1); }
inline u8 puncture_01010010(u8 input) { return (input & 0x1) | ((input & 0xc) >> 1) | ((input & 0x20) >> 2) | ((input & 0x80) >> 3); }
inline u8 puncture_01010011(u8 input) { return (input >> 2) | puncture_00010100(input >> 2); }
inline u8 puncture_01010100(u8 input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0x20) >> 2) | ((input & 0x80) >> 3); }
inline u8 puncture_01010101(u8 input) { return (input >> 1) | puncture_00101010(input >> 1); }
inline u8 puncture_01010110(u8 input) { return (input & 0x1) | ((input & 0x8) >> 2) | ((input & 0x20) >> 3) | ((input & 0x80) >> 4); }
inline u8 puncture_01010111(u8 input) { return (input >> 3) | puncture_00001010(input >> 3); }
inline u8 puncture_01011000(u8 input) { return (input & 0x7) | ((input & 0x20) >> 2) | ((input & 0x80) >> 3); }
inline u8 puncture_01011001(u8 input) { return (input >> 1) | puncture_00101100(input >> 1); }
inline u8 puncture_01011010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x20) >> 3) | ((input & 0x80) >> 4); }
inline u8 puncture_01011011(u8 input) { return (input >> 2) | puncture_00010110(input >> 2); }
inline u8 puncture_01011100(u8 input) { return (input & 0x3) | ((input & 0x20) >> 3) | ((input & 0x80) >> 4); }
inline u8 puncture_01011101(u8 input) { return (input >> 1) | puncture_00101110(input >> 1); }
inline u8 puncture_01011110(u8 input) { return (input & 0x1) | ((input & 0x20) >> 4) | ((input & 0x80) >> 5); }
inline u8 puncture_01011111(u8 input) { return (input >> 5) | puncture_00000010(input >> 5); }
inline u8 puncture_01100000(u8 input) { return (input & 0x1f) | ((input & 0x80) >> 2); }
inline u8 puncture_01100001(u8 input) { return (input >> 1) | puncture_00110000(input >> 1); }
inline u8 puncture_01100010(u8 input) { return (input & 0x1) | ((input & 0x1c) >> 1) | ((input & 0x80) >> 3); }
inline u8 puncture_01100011(u8 input) { return (input >> 2) | puncture_00011000(input >> 2); }
inline u8 puncture_01100100(u8 input) { return (input & 0x3) | ((input & 0x18) >> 1) | ((input & 0x80) >> 3); }
inline u8 puncture_01100101(u8 input) { return (input >> 1) | puncture_00110010(input >> 1); }
inline u8 puncture_01100110(u8 input) { return (input & 0x1) | ((input & 0x18) >> 2) | ((input & 0x80) >> 4); }
inline u8 puncture_01100111(u8 input) { return (input >> 3) | puncture_00001100(input >> 3); }
inline u8 puncture_01101000(u8 input) { return (input & 0x7) | ((input & 0x10) >> 1) | ((input & 0x80) >> 3); }
inline u8 puncture_01101001(u8 input) { return (input >> 1) | puncture_00110100(input >> 1); }
inline u8 puncture_01101010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x10) >> 2) | ((input & 0x80) >> 4); }
inline u8 puncture_01101011(u8 input) { return (input >> 2) | puncture_00011010(input >> 2); }
inline u8 puncture_01101100(u8 input) { return (input & 0x3) | ((input & 0x10) >> 2) | ((input & 0x80) >> 4); }
inline u8 puncture_01101101(u8 input) { return (input >> 1) | puncture_00110110(input >> 1); }
inline u8 puncture_01101110(u8 input) { return (input & 0x1) | ((input & 0x10) >> 3) | ((input & 0x80) >> 5); }
inline u8 puncture_01101111(u8 input) { return (input >> 4) | puncture_00000110(input >> 4); }
inline u8 puncture_01110000(u8 input) { return (input & 0xf) | ((input & 0x80) >> 3); }
inline u8 puncture_01110001(u8 input) { return (input >> 1) | puncture_00111000(input >> 1); }
inline u8 puncture_01110010(u8 input) { return (input & 0x1) | ((input & 0xc) >> 1) | ((input & 0x80) >> 4); }
inline u8 puncture_01110011(u8 input) { return (input >> 2) | puncture_00011100(input >> 2); }
inline u8 puncture_01110100(u8 input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0x80) >> 4); }
inline u8 puncture_01110101(u8 input) { return (input >> 1) | puncture_00111010(input >> 1); }
inline u8 puncture_01110110(u8 input) { return (input & 0x1) | ((input & 0x8) >> 2) | ((input & 0x80) >> 5); }
inline u8 puncture_01110111(u8 input) { return (input >> 3) | puncture_00001110(input >> 3); }
inline u8 puncture_01111000(u8 input) { return (input & 0x7) | ((input & 0x80) >> 4); }
inline u8 puncture_01111001(u8 input) { return (input >> 1) | puncture_00111100(input >> 1); }
inline u8 puncture_01111010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x80) >> 5); }
inline u8 puncture_01111011(u8 input) { return (input >> 2) | puncture_00011110(input >> 2); }
inline u8 puncture_01111100(u8 input) { return (input & 0x3) | ((input & 0x80) >> 5); }
inline u8 puncture_01111101(u8 input) { return (input >> 1) | puncture_00111110(input >> 1); }
inline u8 puncture_01111110(u8 input) { return (input & 0x1) | ((input & 0x80) >> 6); }
inline u8 puncture_01111111(u8 input) { return (input>>7);  }
inline u8 puncture_10000000(u8 input) { return (input & 0x7f);  }
inline u8 puncture_10000001(u8 input) { return (input >> 1) | puncture_01000000(input >> 1); }
inline u8 puncture_10000010(u8 input) { return (input & 0x1) | ((input & 0x7c) >> 1); }
inline u8 puncture_10000011(u8 input) { return (input >> 2) | puncture_00100000(input >> 2); }
inline u8 puncture_10000100(u8 input) { return (input & 0x3) | ((input & 0x78) >> 1) ; }
inline u8 puncture_10000101(u8 input) { return (input >> 1) | puncture_01000010(input >> 1); }
inline u8 puncture_10000110(u8 input) { return (input & 0x1) | ((input & 0x78) >> 2); }
inline u8 puncture_10000111(u8 input) { return (input >> 3) | puncture_00010000(input >> 3); }
inline u8 puncture_10001000(u8 input) { return (input & 0x7) | ((input & 0x70) >> 1) ; }
inline u8 puncture_10001001(u8 input) { return (input >> 1) | puncture_01000100(input >> 1); }
inline u8 puncture_10001010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x70) >> 2); }
inline u8 puncture_10001011(u8 input) { return (input >> 2) | puncture_00100010(input >> 2); }
inline u8 puncture_10001100(u8 input) { return (input & 0x3) | ((input & 0x70) >> 2) ; }
inline u8 puncture_10001101(u8 input) { return (input >> 1) | puncture_01000110(input >> 1); }
inline u8 puncture_10001110(u8 input) { return (input & 0x1) | ((input & 0x70) >> 3); }
inline u8 puncture_10001111(u8 input) { return (input >> 4) | puncture_00001000(input >> 4); }
inline u8 puncture_10010000(u8 input) { return (input & 0xf) | ((input & 0x60) >> 1) ; }
inline u8 puncture_10010001(u8 input) { return (input >> 1) | puncture_01001000(input >> 1); }
inline u8 puncture_10010010(u8 input) { return (input & 0x1) | ((input & 0xc0) >> 1) | ((input & 0x60) >> 2); }
inline u8 puncture_10010011(u8 input) { return (input >> 2) | puncture_00100100(input >> 2); }
inline u8 puncture_10010100(u8 input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0x60) >> 2) ; }
inline u8 puncture_10010101(u8 input) { return (input >> 1) | puncture_01001010(input >> 1); }
inline u8 puncture_10010110(u8 input) { return (input & 0x1) | ((input & 0x8) >> 2) | ((input & 0x60) >> 3); }
inline u8 puncture_10010111(u8 input) { return (input >> 3) | puncture_00010010(input >> 3); }
inline u8 puncture_10011000(u8 input) { return (input & 0x7) | ((input & 0x60) >> 2) ; }
inline u8 puncture_10011001(u8 input) { return (input >> 1) | puncture_01001100(input >> 1); }
inline u8 puncture_10011010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x60) >> 3); }
inline u8 puncture_10011011(u8 input) { return (input >> 2) | puncture_00100110(input >> 2); }
inline u8 puncture_10011100(u8 input) { return (input & 0x3) | ((input & 0x60) >> 3) ; }
inline u8 puncture_10011101(u8 input) { return (input >> 1) | puncture_01001110(input >> 1); }
inline u8 puncture_10011110(u8 input) { return (input & 0x1) | ((input & 0x60) >> 4); }
inline u8 puncture_10011111(u8 input) { return (input >> 5) | puncture_00000100(input >> 5); }
inline u8 puncture_10100000(u8 input) { return (input & 0x1f) | ((input & 0x40) >> 1); }
inline u8 puncture_10100001(u8 input) { return (input >> 1) | puncture_01010000(input >> 1); }
inline u8 puncture_10100010(u8 input) { return (input & 0x1) | ((input & 0x1c) >> 1) | ((input & 0x40) >> 2); }
inline u8 puncture_10100011(u8 input) { return (input >> 2) | puncture_00101000(input >> 2); }
inline u8 puncture_10100100(u8 input) { return (input & 0x3) | ((input & 0x18) >> 1) | ((input & 0x40) >> 2) ; }
inline u8 puncture_10100101(u8 input) { return (input >> 1) | puncture_01010010(input >> 1); }
inline u8 puncture_10100110(u8 input) { return (input & 0x1) | ((input & 0x18) >> 2) | ((input & 0x40) >> 3); }
inline u8 puncture_10100111(u8 input) { return (input >> 3) | puncture_00010100(input >> 3); }
inline u8 puncture_10101000(u8 input) { return (input & 0x7) | ((input & 0x10) >> 1) | ((input & 0x40) >> 2) ; }
inline u8 puncture_10101001(u8 input) { return (input >> 1) | puncture_01010100(input >> 1); }
inline u8 puncture_10101010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x10) >> 2) | ((input & 0x40) >> 3); }
inline u8 puncture_10101011(u8 input) { return (input >> 2) | puncture_00101010(input >> 2); }
inline u8 puncture_10101100(u8 input) { return (input & 0x3) | ((input & 0x10) >> 2) | ((input & 0x40) >> 3) ; }
inline u8 puncture_10101101(u8 input) { return (input >> 1) | puncture_01010110(input >> 1); }
inline u8 puncture_10101110(u8 input) { return (input & 0x1) | ((input & 0x10) >> 3) | ((input & 0x40) >> 4); }
inline u8 puncture_10101111(u8 input) { return (input >> 4) | puncture_00001010(input >> 4); }
inline u8 puncture_10110000(u8 input) { return (input & 0xf) | ((input & 0x40) >> 2) ; }
inline u8 puncture_10110001(u8 input) { return (input >> 1) | puncture_01011000(input >> 1); }
inline u8 puncture_10110010(u8 input) { return (input & 0x1) | ((input & 0xc) >> 1) | ((input & 0x40) >> 3); }
inline u8 puncture_10110011(u8 input) { return (input >> 2) | puncture_00101100(input >> 2); }
inline u8 puncture_10110100(u8 input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0x40) >> 3) ; }
inline u8 puncture_10110101(u8 input) { return (input >> 1) | puncture_01011010(input >> 1); }
inline u8 puncture_10110110(u8 input) { return (input & 0x1) | ((input & 0x8) >> 2) | ((input & 0x40) >> 4); }
inline u8 puncture_10110111(u8 input) { return (input >> 3) | puncture_00010110(input >> 3); }
inline u8 puncture_10111000(u8 input) { return (input & 0x7) | ((input & 0x40) >> 3) ; }
inline u8 puncture_10111001(u8 input) { return (input >> 1) | puncture_01011100(input >> 1); }
inline u8 puncture_10111010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x40) >> 4); }
inline u8 puncture_10111011(u8 input) { return (input >> 2) | puncture_00101110(input >> 2); }
inline u8 puncture_10111100(u8 input) { return (input & 0x3) | ((input & 0x40) >> 4) ; }
inline u8 puncture_10111101(u8 input) { return (input >> 1) | puncture_01011110(input >> 1); }
inline u8 puncture_10111110(u8 input) { return (input & 0x1) | ((input & 0x40) >> 5); }
inline u8 puncture_10111111(u8 input) { return (input >> 6) | puncture_00000010(input >> 6); }
inline u8 puncture_11000000(u8 input) { return (input & 0x3f);  }
inline u8 puncture_11000001(u8 input) { return (input >> 1) | puncture_01100000(input >> 1); }
inline u8 puncture_11000010(u8 input) { return (input & 0x1) | ((input & 0x3c) >> 1) ; }
inline u8 puncture_11000011(u8 input) { return (input >> 2) | puncture_00110000(input >> 2); }
inline u8 puncture_11000100(u8 input) { return (input & 0x3) | ((input & 0x38) >> 1) ; }
inline u8 puncture_11000101(u8 input) { return (input >> 1) | puncture_01100010(input >> 1); }
inline u8 puncture_11000110(u8 input) { return (input & 0x1) | ((input & 0x38) >> 2) ; }
inline u8 puncture_11000111(u8 input) { return (input >> 3) | puncture_00011000(input >> 3); }
inline u8 puncture_11001000(u8 input) { return (input & 0x7) | ((input & 0x3) >> 1) ; }
inline u8 puncture_11001001(u8 input) { return (input >> 1) | puncture_01100100(input >> 1); }
inline u8 puncture_11001010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x30) >> 2); }
inline u8 puncture_11001011(u8 input) { return (input >> 2) | puncture_00110010(input >> 2); }
inline u8 puncture_11001100(u8 input) { return (input & 0x3) | ((input & 0x30) >> 2) ; }
inline u8 puncture_11001101(u8 input) { return (input >> 1) | puncture_01100110(input >> 1); }
inline u8 puncture_11001110(u8 input) { return (input & 0x1) | ((input & 0x30) >> 3); }
inline u8 puncture_11001111(u8 input) { return (input >> 4) | puncture_00001100(input >> 4); }
inline u8 puncture_11010000(u8 input) { return (input & 0xf) | ((input & 0x20) >> 1) ; }
inline u8 puncture_11010001(u8 input) { return (input >> 1) | puncture_01101000(input >> 1); }
inline u8 puncture_11010010(u8 input) { return (input & 0x1) | ((input & 0xc) >> 1) | ((input & 0x20) >> 2); }
inline u8 puncture_11010011(u8 input) { return (input >> 2) | puncture_00110100(input >> 2); }
inline u8 puncture_11010100(u8 input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0x20) >> 2) ; }
inline u8 puncture_11010101(u8 input) { return (input >> 1) | puncture_01101010(input >> 1); }
inline u8 puncture_11010110(u8 input) { return (input & 0x1) | ((input & 0x8) >> 2) | ((input & 0x20) >> 3); }
inline u8 puncture_11010111(u8 input) { return (input >> 3) | puncture_00011010(input >> 3); }
inline u8 puncture_11011000(u8 input) { return (input & 0x7) | ((input & 0x20) >> 2) ; }
inline u8 puncture_11011001(u8 input) { return (input >> 1) | puncture_01101100(input >> 1); }
inline u8 puncture_11011010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x20) >> 3); }
inline u8 puncture_11011011(u8 input) { return (input >> 2) | puncture_00110110(input >> 2); }
inline u8 puncture_11011100(u8 input) { return (input & 0x3) | ((input & 0x20) >> 3) ; }
inline u8 puncture_11011101(u8 input) { return (input >> 1) | puncture_01101110(input >> 1); }
inline u8 puncture_11011110(u8 input) { return (input & 0x1) | ((input & 0x20) >> 4); }
inline u8 puncture_11011111(u8 input) { return (input >> 5) | puncture_00000110(input >> 5); }
inline u8 puncture_11100000(u8 input) { return (input & 0x1f);  }
inline u8 puncture_11100001(u8 input) { return (input >> 1) | puncture_01110000(input >> 1); }
inline u8 puncture_11100010(u8 input) { return (input & 0x1) | ((input & 0x1c) >> 1) ; }
inline u8 puncture_11100011(u8 input) { return (input >> 2) | puncture_00111000(input >> 2); }
inline u8 puncture_11100100(u8 input) { return (input & 0x3) | ((input & 0x18) >> 1) ; }
inline u8 puncture_11100101(u8 input) { return (input >> 1) | puncture_01110010(input >> 1); }
inline u8 puncture_11100110(u8 input) { return (input & 0x1) | ((input & 0x18) >> 2) ; }
inline u8 puncture_11100111(u8 input) { return (input >> 3) | puncture_00011100(input >> 3); }
inline u8 puncture_11101000(u8 input) { return (input & 0x7) | ((input & 0x10) >> 1) ; }
inline u8 puncture_11101001(u8 input) { return (input >> 1) | puncture_01110100(input >> 1); }
inline u8 puncture_11101010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x10) >> 2); }
inline u8 puncture_11101011(u8 input) { return (input >> 2) | puncture_00111010(input >> 2); }
inline u8 puncture_11101100(u8 input) { return (input & 0x3) | ((input & 0x10) >> 2) ; }
inline u8 puncture_11101101(u8 input) { return (input >> 1) | puncture_01110110(input >> 1); }
inline u8 puncture_11101110(u8 input) { return (input & 0x1) | ((input & 0x10) >> 3); }
inline u8 puncture_11101111(u8 input) { return (input >> 4) | puncture_00001110(input >> 4); }
inline u8 puncture_11110000(u8 input) { return (input & 0xf);  }
inline u8 puncture_11110001(u8 input) { return (input >> 1) | puncture_01111000(input >> 1); }
inline u8 puncture_11110010(u8 input) { return (input & 0x1) | ((input & 0xc) >> 1) ; }
inline u8 puncture_11110011(u8 input) { return (input >> 2) | puncture_00111100(input >> 2); }
inline u8 puncture_11110100(u8 input) { return (input & 0x3) | ((input & 0x8) >> 1) ; }
inline u8 puncture_11110101(u8 input) { return (input >> 1) | puncture_01111010(input >> 1); }
inline u8 puncture_11110110(u8 input) { return (input & 0x1) | ((input & 0x8) >> 2) ; }
inline u8 puncture_11110111(u8 input) { return (input >> 3) | puncture_00011110(input >> 3); }
inline u8 puncture_11111000(u8 input) { return (input & 0x7);  }
inline u8 puncture_11111001(u8 input) { return (input >> 1) | puncture_01111100(input >> 1); }
inline u8 puncture_11111010(u8 input) { return (input & 0x1) | ((input & 0x4) >> 1) ; }
inline u8 puncture_11111011(u8 input) { return (input >> 2) | puncture_00111110(input >> 2); }
inline u8 puncture_11111100(u8 input) { return (input & 0x3);  }
inline u8 puncture_11111101(u8 input) { return (input >> 1) | puncture_01111110(input >> 1); }
inline u8 puncture_11111110(u8 input) { return (input & 0x1);  }
inline u8 puncture_11111111(u8 input) { return 0;  }



const puncture_func g_puncture_funcs[256] = {
    &puncture_00000000,
    &puncture_00000001,
    &puncture_00000010,
    &puncture_00000011,
    &puncture_00000100,
    &puncture_00000101,
    &puncture_00000110,
    &puncture_00000111,
    &puncture_00001000,
    &puncture_00001001,
    &puncture_00001010,
    &puncture_00001011,
    &puncture_00001100,
    &puncture_00001101,
    &puncture_00001110,
    &puncture_00001111,
    &puncture_00010000,
    &puncture_00010001,
    &puncture_00010010,
    &puncture_00010011,
    &puncture_00010100,
    &puncture_00010101,
    &puncture_00010110,
    &puncture_00010111,
    &puncture_00011000,
    &puncture_00011001,
    &puncture_00011010,
    &puncture_00011011,
    &puncture_00011100,
    &puncture_00011101,
    &puncture_00011110,
    &puncture_00011111,
    &puncture_00100000,
    &puncture_00100001,
    &puncture_00100010,
    &puncture_00100011,
    &puncture_00100100,
    &puncture_00100101,
    &puncture_00100110,
    &puncture_00100111,
    &puncture_00101000,
    &puncture_00101001,
    &puncture_00101010,
    &puncture_00101011,
    &puncture_00101100,
    &puncture_00101101,
    &puncture_00101110,
    &puncture_00101111,
    &puncture_00110000,
    &puncture_00110001,
    &puncture_00110010,
    &puncture_00110011,
    &puncture_00110100,
    &puncture_00110101,
    &puncture_00110110,
    &puncture_00110111,
    &puncture_00111000,
    &puncture_00111001,
    &puncture_00111010,
    &puncture_00111011,
    &puncture_00111100,
    &puncture_00111101,
    &puncture_00111110,
    &puncture_00111111,
    &puncture_01000000,
    &puncture_01000001,
    &puncture_01000010,
    &puncture_01000011,
    &puncture_01000100,
    &puncture_01000101,
    &puncture_01000110,
    &puncture_01000111,
    &puncture_01001000,
    &puncture_01001001,
    &puncture_01001010,
    &puncture_01001011,
    &puncture_01001100,
    &puncture_01001101,
    &puncture_01001110,
    &puncture_01001111,
    &puncture_01010000,
    &puncture_01010001,
    &puncture_01010010,
    &puncture_01010011,
    &puncture_01010100,
    &puncture_01010101,
    &puncture_01010110,
    &puncture_01010111,
    &puncture_01011000,
    &puncture_01011001,
    &puncture_01011010,
    &puncture_01011011,
    &puncture_01011100,
    &puncture_01011101,
    &puncture_01011110,
    &puncture_01011111,
    &puncture_01100000,
    &puncture_01100001,
    &puncture_01100010,
    &puncture_01100011,
    &puncture_01100100,
    &puncture_01100101,
    &puncture_01100110,
    &puncture_01100111,
    &puncture_01101000,
    &puncture_01101001,
    &puncture_01101010,
    &puncture_01101011,
    &puncture_01101100,
    &puncture_01101101,
    &puncture_01101110,
    &puncture_01101111,
    &puncture_01110000,
    &puncture_01110001,
    &puncture_01110010,
    &puncture_01110011,
    &puncture_01110100,
    &puncture_01110101,
    &puncture_01110110,
    &puncture_01110111,
    &puncture_01111000,
    &puncture_01111001,
    &puncture_01111010,
    &puncture_01111011,
    &puncture_01111100,
    &puncture_01111101,
    &puncture_01111110,
    &puncture_01111111,
    &puncture_10000000,
    &puncture_10000001,
    &puncture_10000010,
    &puncture_10000011,
    &puncture_10000100,
    &puncture_10000101,
    &puncture_10000110,
    &puncture_10000111,
    &puncture_10001000,
    &puncture_10001001,
    &puncture_10001010,
    &puncture_10001011,
    &puncture_10001100,
    &puncture_10001101,
    &puncture_10001110,
    &puncture_10001111,
    &puncture_10010000,
    &puncture_10010001,
    &puncture_10010010,
    &puncture_10010011,
    &puncture_10010100,
    &puncture_10010101,
    &puncture_10010110,
    &puncture_10010111,
    &puncture_10011000,
    &puncture_10011001,
    &puncture_10011010,
    &puncture_10011011,
    &puncture_10011100,
    &puncture_10011101,
    &puncture_10011110,
    &puncture_10011111,
    &puncture_10100000,
    &puncture_10100001,
    &puncture_10100010,
    &puncture_10100011,
    &puncture_10100100,
    &puncture_10100101,
    &puncture_10100110,
    &puncture_10100111,
    &puncture_10101000,
    &puncture_10101001,
    &puncture_10101010,
    &puncture_10101011,
    &puncture_10101100,
    &puncture_10101101,
    &puncture_10101110,
    &puncture_10101111,
    &puncture_10110000,
    &puncture_10110001,
    &puncture_10110010,
    &puncture_10110011,
    &puncture_10110100,
    &puncture_10110101,
    &puncture_10110110,
    &puncture_10110111,
    &puncture_10111000,
    &puncture_10111001,
    &puncture_10111010,
    &puncture_10111011,
    &puncture_10111100,
    &puncture_10111101,
    &puncture_10111110,
    &puncture_10111111,
    &puncture_11000000,
    &puncture_11000001,
    &puncture_11000010,
    &puncture_11000011,
    &puncture_11000100,
    &puncture_11000101,
    &puncture_11000110,
    &puncture_11000111,
    &puncture_11001000,
    &puncture_11001001,
    &puncture_11001010,
    &puncture_11001011,
    &puncture_11001100,
    &puncture_11001101,
    &puncture_11001110,
    &puncture_11001111,
    &puncture_11010000,
    &puncture_11010001,
    &puncture_11010010,
    &puncture_11010011,
    &puncture_11010100,
    &puncture_11010101,
    &puncture_11010110,
    &puncture_11010111,
    &puncture_11011000,
    &puncture_11011001,
    &puncture_11011010,
    &puncture_11011011,
    &puncture_11011100,
    &puncture_11011101,
    &puncture_11011110,
    &puncture_11011111,
    &puncture_11100000,
    &puncture_11100001,
    &puncture_11100010,
    &puncture_11100011,
    &puncture_11100100,
    &puncture_11100101,
    &puncture_11100110,
    &puncture_11100111,
    &puncture_11101000,
    &puncture_11101001,
    &puncture_11101010,
    &puncture_11101011,
    &puncture_11101100,
    &puncture_11101101,
    &puncture_11101110,
    &puncture_11101111,
    &puncture_11110000,
    &puncture_11110001,
    &puncture_11110010,
    &puncture_11110011,
    &puncture_11110100,
    &puncture_11110101,
    &puncture_11110110,
    &puncture_11110111,
    &puncture_11111000,
    &puncture_11111001,
    &puncture_11111010,
    &puncture_11111011,
    &puncture_11111100,
    &puncture_11111101,
    &puncture_11111110,
    &puncture_11111111
};

// Puncture example of 1024 bits in O(n*logn)
// 1024 / 8 = 128 bytes = 64x16b words = 32x32b dwords = 16x64b = 8x128b = 4x256b = 2x512b
// 
// 128x8b:
// =======
// 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 
// 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 
// 
// after 2b puncture per u8 (2 bits in each u8 are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 
// 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 
//
// after u8 condensing:
// ======================
// 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 
// 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 
//
// 64x16b:
// =======
// 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 
// 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 
//
// after 2b puncture per u8 (2 bits in each u8 are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 
// 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 
//
// after u8 condensing:
// ======================
// 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 
// 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 
//
// after u16 condensing:
// ======================
// 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 
// 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 
//
// 32x32b:
// =======
// 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 
// 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 
//
// after 2b puncture per u8 (2 bits in each u8 are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 
// 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 
//
// after u8 condensing:
// ======================
// 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 
// 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 
//
// after u16 condensing:
// ======================
// 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 
// 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 0x00FFFFFF 
//
// after dword condensing:
// =======================
// 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 
// 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 0x0000FFFF 0xFFFFFFFF 
//
// 16x64b:
// =======
// 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 
// 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFF 
//
// after 2b puncture per u8 (2 bits in each u8 are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 
// 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 
//
// after u8 condensing:
// ======================
// 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 
// 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 
//
// after u16 condensing:
// ======================
// 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 
// 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF 
//
// after dword condensing:
// =======================
// 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 
// 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF 
//
// after 64b condensing:
// =====================
// 0x00000000FFFFFFFF 0xFFFFFFFFFFFFFFFF 0x00000000FFFFFFFF 0xFFFFFFFFFFFFFFFF 0x00000000FFFFFFFF 0xFFFFFFFFFFFFFFFF 0x00000000FFFFFFFF 0xFFFFFFFFFFFFFFFF 
// 0x00000000FFFFFFFF 0xFFFFFFFFFFFFFFFF 0x00000000FFFFFFFF 0xFFFFFFFFFFFFFFFF 0x00000000FFFFFFFF 0xFFFFFFFFFFFFFFFF 0x00000000FFFFFFFF 0xFFFFFFFFFFFFFFFF 
//
// 8x128b:
// =======
// 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
// 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
//
// after 2b puncture per u8 (2 bits in each u8 are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 
// 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 
//
// after u8 condensing:
// ==========================================================================================================
// 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 
// 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 
//
// after u16 condensing:
// ======================
// 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF 
// 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF 
//
// after dword condensing:
// =======================
// 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF 
// 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF 
//
// after 64b condensing:
// =====================
// 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF 
// 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF 
//
// after 128b condensing:
// ======================
// 0x0000000000000000FFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0x0000000000000000FFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
// 0x0000000000000000FFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0x0000000000000000FFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
//
// 4x256b:
// =======
// 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
// 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
//
// after 2b puncture per u8 (2 bits in each u8 are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F
// 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 
//
// after u8 condensing:
// ======================
// 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 
// 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 
//
// after u16 condensing:
// ======================
// 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF 
// 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF 
//
// after dword condensing:
// =======================
// 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF 
// 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF 
//
// after 64b condensing:
// =====================
// 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFFFFFFFFFF 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFFFFFFFFFF 
// 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFFFFFFFFFF 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFFFFFFFFFF 
//
// after 128b condensing:
// ======================
// 0x0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0x0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
// 0x0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0x0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
//
// after 256b condensing:
// ======================
// 0x00000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
// 0x00000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
//
// 2x512b:
// =======
// 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
// 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
//
// after 2b puncture per u8 (2 bits in each u8 are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F
// 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 
//
// after u8 condensing:
// ======================
// 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 
// 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 
//
// after u16 condensing:
// ======================
// 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF 
// 0x00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF 
//
// after dword condensing:
// =======================
// 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF 
// 0x0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF0000FFFFFFFFFFFF 
//
// after 64b condensing:
// =====================
// 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFFFFFFFFFF 
// 0x00000000FFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFFFFFFFFFF 
//
// after 128b condensing:
// ======================
// 0x0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
// 0x0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
//
// after 256b condensing:
// ======================
// 0x00000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
// 0x00000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 
//
// after 512b condensing:
// ======================
// 0x0000000000000000000000000000000000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF >> to below as this is the MSbit part of the 1024b chunk
// 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF 


void build_data(u8* input_data, u16 input_data_len) {
    memset(input_data, 0xFF, input_data_len);
}

u16 build_structures(const u16* punc_bits_indices, u16 puncture_bits_len, u16* punc_bytes_list, u8* bytes_punctures_list, u8* bytes_num_punctures) {
    u16 curr_pbyte_index = -1;
    u16 num_pbytes = 0;

    for (u16 pbit_index = 0; pbit_index < puncture_bits_len; pbit_index++) { // Go over the puncturing bits indices
        u16 pbyte_index = punc_bits_indices[pbit_index] >> 3;
        if (pbyte_index != curr_pbyte_index) { // if new u8 index (to be punctured) encountered
            curr_pbyte_index = pbyte_index;            // update current punctured u8
            punc_bytes_list[num_pbytes] = pbyte_index; // Add current u8 to the punctured bytes list
            num_pbytes++;                              // inc number of punctured bytes
        }
        bytes_punctures_list[num_pbytes-1] |= (1 << (punc_bits_indices[pbit_index] % 8)); // update bit in u8
        bytes_num_punctures[num_pbytes-1]++;                                              // increase number of punctured bits in punctured u8
    }

    return num_pbytes;
}

void puncture_data(u8* input_data, u16 num_punc_bytes, u16* punc_bytes_list, u8* bytes_punctures_list) {
    for (u16 byte_index = 0; byte_index < num_punc_bytes; byte_index++)
        input_data[punc_bytes_list[byte_index]] = g_puncture_funcs[bytes_punctures_list[byte_index]](input_data[punc_bytes_list[byte_index]]);
}


void print_as_bytes(u8* data, u16 data_len, const char* name, bool reverse) {
    printf("%s As Hex u8 %s:\n\n", name, (reverse? "reverse" : ""));

    if (reverse)
        for (data_len; data_len > 0; data_len--)
            printf("%02x ", data[data_len-1]);
    else
        for (u16 i = 0; i < data_len; i++)
            printf("%02x ", data[i]);
    printf("\n\n");
}

void print_as_words(u16* data, u16 data_len, const char* name, bool reverse) {
    printf("%s As Hex u16 %s:\n\n", name, (reverse ? "reverse" : ""));

    if (reverse)
        for (data_len; data_len > 0; data_len--)
            printf("%04x ", data[data_len-1]);
    else
        for (u16 i = 0; i < data_len; i++)
            printf("%04x ", data[i]);
    printf("\n\n");
}

void print_as_dwords(u32* data, u16 data_len, const char* name, bool reverse) {
    printf("%s As Hex u32 %s:\n\n", name, (reverse ? "reverse" : ""));

    if (reverse)
        for (data_len; data_len > 0; data_len--)
            printf("%08x ", data[data_len - 1]);
    else
        for (u16 i = 0; i < data_len; i++)
            printf("%08x ", data[i]);
    printf("\n\n");
}

u16 condense_even_byte_pairs(u8* data, u16* p_bytes, u16 num_punctured_bytes, u8* p_bytes_num_puncs, u16* p_words, u8* p_words_num_puncs) {
    u16 punctured_byte_index = 0;    
    u16 num_punctured_words = 0;
    
    // Work in even index pairs: if punctured u8 index in data is even, 
    // look at this u8 (punctured) and next u8 (might be punctured)
    while (punctured_byte_index < num_punctured_bytes) {
        u16 byte_index_in_data = p_bytes[punctured_byte_index];
        u16 word_index_in_data = byte_index_in_data >> 1;
        u16 num_curr_byte_puncs = p_bytes_num_puncs[punctured_byte_index];
        u16 num_next_byte_puncs;

        if ((byte_index_in_data & 0x1) == 0) {            
            num_next_byte_puncs =
                (byte_index_in_data + 1 == p_bytes[punctured_byte_index + 1]) ? p_bytes_num_puncs[punctured_byte_index + 1] : 0; // next u8 in data contains punctures?

            // Condense u8 pair:
            data[byte_index_in_data] |=
                ((data[byte_index_in_data + 1] & ((1 << num_curr_byte_puncs) - 1)) << (8 - num_curr_byte_puncs));
            data[byte_index_in_data + 1] >>= num_curr_byte_puncs;

            if (num_next_byte_puncs) { // there were punctures in next u8
                p_bytes_num_puncs[punctured_byte_index + 1] += num_curr_byte_puncs;
                p_bytes_num_puncs[punctured_byte_index] = 0; // All punctures reflected in next u8
                punctured_byte_index += 2;
            }
            else {
                punctured_byte_index++;
            }
        }
        else {
            punctured_byte_index++;
            num_next_byte_puncs = 0;
        }

        p_words_num_puncs[num_punctured_words] = num_curr_byte_puncs + num_next_byte_puncs;
        p_words[num_punctured_words] = word_index_in_data;
        num_punctured_words++;
    }
    return num_punctured_words;
}

u16 condense_even_word_pairs(u16* data, u16* p_words, u16 num_punctured_words, u8* p_words_num_puncs, u16* p_dwords, u8* p_dwords_num_puncs) {
    u16 punctured_word_index = 0;
    u16 num_punctured_dwords = 0;

    // Work in even index pairs: if punctured index in data is even, 
    // look at this (punctured) and next (might be punctured)
    while (punctured_word_index < num_punctured_words) {
        u16 word_index_in_data = p_words[punctured_word_index];
        u16 dword_index_in_data = word_index_in_data >> 1;
        u16 num_curr_word_puncs = p_words_num_puncs[punctured_word_index];
        u16 num_next_word_puncs;

        if ((word_index_in_data & 0x1) == 0) {
            num_next_word_puncs =
                (word_index_in_data + 1 == p_words[punctured_word_index + 1]) ? p_words_num_puncs[punctured_word_index + 1] : 0; // next element in data contains punctures?

            // Condense pair:
            data[word_index_in_data] |=
                ((data[word_index_in_data + 1] & ((1 << num_curr_word_puncs) - 1)) << (16 - num_curr_word_puncs));
            data[word_index_in_data + 1] >>= num_curr_word_puncs;

            if (num_next_word_puncs) { // there were punctures in next element
                p_words_num_puncs[punctured_word_index + 1] += num_curr_word_puncs;
                p_words_num_puncs[punctured_word_index] = 0; // All punctures reflected in next element
                punctured_word_index += 2;
            }
            else {
                punctured_word_index++;
            }
        }
        else {
            punctured_word_index++;
            num_next_word_puncs = 0;
        }

        p_dwords_num_puncs[num_punctured_dwords] = num_curr_word_puncs + num_next_word_puncs;
        p_dwords[num_punctured_dwords] = dword_index_in_data;
        num_punctured_dwords++;
    }
    return num_punctured_dwords;
}

u16 condense_even_dword_pairs(u32* data, u16* p_dwords, u16 num_punctured_dwords, u8* p_dwords_num_puncs, u16* p_u64s, u8* p_u64s_num_puncs) {
    u16 punctured_dword_index = 0;
    u16 num_punctured_u64s = 0;

    // Work in even index pairs: if punctured index in data is even, 
    // look at this (punctured) and next (might be punctured)
    while (punctured_dword_index < num_punctured_dwords) {
        u16 dword_index_in_data = p_dwords[punctured_dword_index];
        u16 u64_index_in_data = dword_index_in_data >> 1;
        u16 num_curr_dword_puncs = p_dwords_num_puncs[punctured_dword_index];
        u16 num_next_dword_puncs;

        if ((dword_index_in_data & 0x1) == 0) {
            num_next_dword_puncs =
                (dword_index_in_data + 1 == p_dwords[punctured_dword_index + 1]) ? p_dwords_num_puncs[punctured_dword_index + 1] : 0; // next element in data contains punctures?

            // Condense pair:
            data[dword_index_in_data] |=
                ((data[dword_index_in_data + 1] & ((1 << num_curr_dword_puncs) - 1)) << (32 - num_curr_dword_puncs));
            data[dword_index_in_data + 1] >>= num_curr_dword_puncs;

            if (num_next_dword_puncs) { // there were punctures in next element
                p_dwords_num_puncs[punctured_dword_index + 1] += num_curr_dword_puncs;
                p_dwords_num_puncs[punctured_dword_index] = 0; // All punctures reflected in next element
                punctured_dword_index += 2;
            }
            else {
                punctured_dword_index++;
            }
        }
        else {
            punctured_dword_index++;
            num_next_dword_puncs = 0;
        }

        p_u64s_num_puncs[num_punctured_u64s] = num_curr_dword_puncs + num_next_dword_puncs;
        p_u64s[num_punctured_u64s] = u64_index_in_data;
        num_punctured_u64s++;
    }
    return num_punctured_u64s;
}


int main(int argc, char** argv)
{
    #define INPUT_SIZE_BITS  1500
    #define INPUT_SIZE_BYTES (INPUT_SIZE_BITS/8 + 1)
    #define P_SIZE 18

    u8 * data = (u8*)_aligned_malloc(INPUT_SIZE_BYTES, 512);

    printf("data = %p\n", data);
    _ASSERT((((unsigned long long)data) % 256 == 0));

    //                    u8         0  1   3            4      6       16 ...
    //                           0 1 2  3   4   5  6  7  8   9 10   11  12   13   14   15   16   17 
    const u16 p_bits[P_SIZE] = { 1,2,4, 8, 30, 33,34,35,37, 50,51, 128,129, 140, 150, 160, 170, 200 };

    u16 p_bytes[P_SIZE] = { 0 };          // bytes corresponding to p_bits
    u8 p_bytes_punctures[P_SIZE] = { 0 }; // puncturing mask per u8 (1: puncture, 0: no puncture)
    u8 p_bytes_num_puncs[P_SIZE] = { 0 }; // number of punctured bits per u8

    u16 p_words[P_SIZE] = { 0 };          // words corresponding to p_bits
    u8 p_words_num_puncs[P_SIZE] = { 0 }; // number of punctured bits per u16

    u16 p_dwords[P_SIZE] = { 0 };          // dwords corresponding to p_bits
    u8 p_dwords_num_puncs[P_SIZE] = { 0 }; // number of punctured bits per u32

    u16 p_u64s[P_SIZE] = { 0 };            // u64s corresponding to p_bits
    u8 p_u64s_num_puncs[P_SIZE] = { 0 };   // number of punctured bits per u64

    build_data(data, INPUT_SIZE_BYTES); // Fill the input data (with all ones)

    // num_punctured_bytes: number of bytes in which there are punctures (len(p_bytes) == len(p_bytes_punctures) == len(p_bytes_num_puncs)
    u16 num_punctured_bytes = build_structures(p_bits, P_SIZE, p_bytes, p_bytes_punctures, p_bytes_num_puncs);
    puncture_data(data, num_punctured_bytes, p_bytes, p_bytes_punctures);

    print_as_words((u16*)p_bits, P_SIZE, "p_bits", true);

    print_as_bytes(data, INPUT_SIZE_BYTES, "data", true);
    print_as_words(p_bytes, num_punctured_bytes, "p_bytes", true);
    print_as_bytes(p_bytes_num_puncs, num_punctured_bytes, "p_bytes_num_puncs", true);
    print_as_bytes(p_bytes_punctures, num_punctured_bytes, "p_bytes_punctures", true);

    u16 num_punctured_words = condense_even_byte_pairs(data, p_bytes, num_punctured_bytes, p_bytes_num_puncs, p_words, p_words_num_puncs); // Condense according to example above

    print_as_bytes(data, INPUT_SIZE_BYTES, "data bytes after condense_even_byte_pairs()", true);
    print_as_bytes(p_bytes_num_puncs, num_punctured_bytes, "p_bytes_num_puncs after condense_even_byte_pairs()", true);

    print_as_words(p_words, num_punctured_words, "p_words after condense_even_byte_pairs()", true);
    print_as_bytes(p_words_num_puncs, num_punctured_words, "p_words_num_puncs after condense_even_byte_pairs()", true);

    u16 num_punctured_dwords = condense_even_word_pairs((u16*)data, p_words, num_punctured_words, p_words_num_puncs, p_dwords, p_dwords_num_puncs); // Condense according to example above

    print_as_words((u16*)data, INPUT_SIZE_BYTES>>1, "data words after condense_even_word_pairs()", true);
    print_as_bytes(p_words_num_puncs, num_punctured_words, "p_words_num_puncs after condense_even_word_pairs()", true);

    print_as_words(p_dwords, num_punctured_dwords, "p_dwords after condense_even_word_pairs()", true);
    print_as_bytes(p_dwords_num_puncs, num_punctured_dwords, "p_dwords_num_puncs after condense_even_word_pairs()", true);

    u16 num_punctured_u64s = condense_even_dword_pairs((u32*)data, p_dwords, num_punctured_dwords, p_dwords_num_puncs, p_u64s, p_u64s_num_puncs); // Condense according to example above

    print_as_dwords((u32*)data, INPUT_SIZE_BYTES>>2, "data dwords after condense_even_dword_pairs()", true);
    print_as_bytes(p_dwords_num_puncs, num_punctured_dwords, "p_dwords_num_puncs after condense_even_dword_pairs()", true);

    print_as_words(p_u64s, num_punctured_u64s, "p_u64s after condense_even_dword_pairs()", true);
    print_as_bytes(p_u64s_num_puncs, num_punctured_u64s, "p_u64s_num_puncs after condense_even_dword_pairs()", true);

    _aligned_free(data);
}
