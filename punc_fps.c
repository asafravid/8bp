
typedef unsigned char (*puncture_func)(unsigned char input);

inline unsigned char puncture_00000000(unsigned char input) { return input;  }
inline unsigned char puncture_00000001(unsigned char input) { return input>>1;  }
inline unsigned char puncture_00000010(unsigned char input) { return ((input & 0xfc) >> 1) | (input & 0x1);  }
inline unsigned char puncture_00000011(unsigned char input) { return input>>2;  }
inline unsigned char puncture_00000100(unsigned char input) { return ((input & 0xf8) >> 1) | (input & 0x3); }
inline unsigned char puncture_00000101(unsigned char input) { return (input >> 1) | puncture_00000010(input >> 1); }
inline unsigned char puncture_00000110(unsigned char input) { return (input & 0x1) | ((input & 0xf8) >> 2);  }
inline unsigned char puncture_00000111(unsigned char input) { return input>>3;  }
inline unsigned char puncture_00001000(unsigned char input) { return ((input & 0xf0) >> 1) | (input & 0x7); }
inline unsigned char puncture_00001001(unsigned char input) { return (input >> 1) | puncture_00000100(input >> 1); }
inline unsigned char puncture_00001010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0xf0) >> 2); }
inline unsigned char puncture_00001011(unsigned char input) { return (input>>2) | puncture_00000010(input >> 2); }
inline unsigned char puncture_00001100(unsigned char input) { return (input & 0x3) | ((input & 0xf0) >> 2); }
inline unsigned char puncture_00001101(unsigned char input) { return (input >> 1) | puncture_00000110(input >> 1);}
inline unsigned char puncture_00001110(unsigned char input) { return (input & 0x1) | ((input & 0xf0) >> 3);  }
inline unsigned char puncture_00001111(unsigned char input) { return input>>4;  }
inline unsigned char puncture_00010000(unsigned char input) { return ((input & 0xe0) >> 1) | (input & 0xf); }
inline unsigned char puncture_00010001(unsigned char input) { return (input >> 1) | puncture_00001000(input >> 1); }
inline unsigned char puncture_00010010(unsigned char input) { return (input & 0x1) | ((input & 0xc)>>1) | ((input & 0xe0) >> 2);  }
inline unsigned char puncture_00010011(unsigned char input) { return (input>>2) | puncture_00000100(input >> 2); }
inline unsigned char puncture_00010100(unsigned char input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0xe0) >> 2); }
inline unsigned char puncture_00010101(unsigned char input) { return (input>>1) | puncture_00001010(input >> 1); }
inline unsigned char puncture_00010110(unsigned char input) { return (input & 0x1) | ((input & 0x8)>>2) | ((input & 0xe0) >> 3);  }
inline unsigned char puncture_00010111(unsigned char input) { return (input >> 3) | puncture_00000010(input >> 3); }
inline unsigned char puncture_00011000(unsigned char input) { return (input & 0x7) | ((input & 0xe0) >> 2); }
inline unsigned char puncture_00011001(unsigned char input) { return (input >> 1) | puncture_00001100(input >> 1); }
inline unsigned char puncture_00011010(unsigned char input) { return (input & 0x1) | ((input & 0x4)>>1) | ((input & 0xe0) >> 3);  }
inline unsigned char puncture_00011011(unsigned char input) { return (input >> 2) | puncture_00000110(input >> 2); }
inline unsigned char puncture_00011100(unsigned char input) { return (input & 0x3) | ((input & 0xe0) >> 3); }
inline unsigned char puncture_00011101(unsigned char input) { return (input >> 1) | puncture_00001110(input >> 1); }
inline unsigned char puncture_00011110(unsigned char input) { return (input & 0x1) | ((input & 0xe0) >> 4);  }
inline unsigned char puncture_00011111(unsigned char input) { return input>>5;  }
inline unsigned char puncture_00100000(unsigned char input) { return ((input & 0xc0) >> 1) | (input & 0x1f); }
inline unsigned char puncture_00100001(unsigned char input) { return (input >> 1) | puncture_00010000(input >> 1); }
inline unsigned char puncture_00100010(unsigned char input) { return (input & 0x1) | ((input & 0x1c)>>1) | ((input & 0xc0) >> 2);  }
inline unsigned char puncture_00100011(unsigned char input) { return (input >> 2) | puncture_00001000(input >> 2); }
inline unsigned char puncture_00100100(unsigned char input) { return (input & 0x3) | ((input & 0x18) >> 1) | ((input & 0xc0) >> 2); }
inline unsigned char puncture_00100101(unsigned char input) { return (input >> 1) | puncture_00010010(input >> 1); }
inline unsigned char puncture_00100110(unsigned char input) { return (input & 0x1) | ((input & 0x18) >> 2) | ((input & 0xc0) >> 3);  }
inline unsigned char puncture_00100111(unsigned char input) { return (input >> 3) | puncture_00000100(input >> 3); }
inline unsigned char puncture_00101000(unsigned char input) { return (input & 0x7) | ((input & 0x10) >> 1) | ((input & 0xc0) >> 2); }
inline unsigned char puncture_00101001(unsigned char input) { return (input >> 1) | puncture_00010100(input >> 1); }
inline unsigned char puncture_00101010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x10) >> 2) | ((input & 0xc0) >> 3);  }
inline unsigned char puncture_00101011(unsigned char input) { return (input >> 2) | puncture_00001010(input >> 2); }
inline unsigned char puncture_00101100(unsigned char input) { return (input & 0x3) | ((input & 0x10) >> 2) | ((input & 0xc0) >> 3); }
inline unsigned char puncture_00101101(unsigned char input) { return (input >> 1) | puncture_00010110(input >> 1); }
inline unsigned char puncture_00101110(unsigned char input) { return (input & 0x1) | ((input & 0x10) >> 3) | ((input & 0xc0) >> 4); }
inline unsigned char puncture_00101111(unsigned char input) { return (input >> 4) | puncture_00000010(input >> 4); }
inline unsigned char puncture_00110000(unsigned char input) { return (input & 0xf) | ((input & 0xc0) >> 2); }
inline unsigned char puncture_00110001(unsigned char input) { return (input >> 1) | puncture_00011000(input >> 1); }
inline unsigned char puncture_00110010(unsigned char input) { return (input & 0x1) | ((input & 0xc) >> 1) | ((input & 0xc0) >> 3); }
inline unsigned char puncture_00110011(unsigned char input) { return (input >> 2) | puncture_00001100(input >> 2); }
inline unsigned char puncture_00110100(unsigned char input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0xc0) >> 3); }
inline unsigned char puncture_00110101(unsigned char input) { return (input >> 1) | puncture_00011010(input >> 1); }
inline unsigned char puncture_00110110(unsigned char input) { return (input & 0x1) | ((input & 0x8) >> 2) | ((input & 0xc0) >> 4); }
inline unsigned char puncture_00110111(unsigned char input) { return (input >> 3) | puncture_00000110(input >> 3); }
inline unsigned char puncture_00111000(unsigned char input) { return (input & 0x7) | ((input & 0xc0) >> 3); }
inline unsigned char puncture_00111001(unsigned char input) { return (input >> 1) | puncture_00011100(input >> 1); }
inline unsigned char puncture_00111010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0xc0) >> 4); }
inline unsigned char puncture_00111011(unsigned char input) { return (input >> 2) | puncture_00001110(input >> 2); }
inline unsigned char puncture_00111100(unsigned char input) { return (input & 0x3) | ((input & 0xc0) >> 4); }
inline unsigned char puncture_00111101(unsigned char input) { return (input >> 1) | puncture_00011110(input >> 1); }
inline unsigned char puncture_00111110(unsigned char input) { return (input & 0x1) | ((input & 0xc0) >> 5); }
inline unsigned char puncture_00111111(unsigned char input) { return input>>6;  }
inline unsigned char puncture_01000000(unsigned char input) { return ((input & 0x80) >> 1) | (input & 0x3f); }
inline unsigned char puncture_01000001(unsigned char input) { return (input >> 1) | puncture_00100000(input >> 1); }
inline unsigned char puncture_01000010(unsigned char input) { return (input & 0x1) | ((input & 0x3c) >> 1) | ((input & 0x80) >> 2); }
inline unsigned char puncture_01000011(unsigned char input) { return (input >> 2) | puncture_00010000(input >> 2); }
inline unsigned char puncture_01000100(unsigned char input) { return (input & 0x3) | ((input & 0x38) >> 1) | ((input & 0x80) >> 2); }
inline unsigned char puncture_01000101(unsigned char input) { return (input >> 1) | puncture_00100010(input >> 1); }
inline unsigned char puncture_01000110(unsigned char input) { return (input & 0x1) | ((input & 0x38) >> 2) | ((input & 0x80) >> 3); }
inline unsigned char puncture_01000111(unsigned char input) { return (input >> 3) | puncture_00001000(input >> 3); }
inline unsigned char puncture_01001000(unsigned char input) { return (input & 0x7) | ((input & 0x30) >> 1) | ((input & 0x80) >> 2); }
inline unsigned char puncture_01001001(unsigned char input) { return (input >> 1) | puncture_00100100(input >> 1); }
inline unsigned char puncture_01001010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x30) >> 2) | ((input & 0x80) >> 3); }
inline unsigned char puncture_01001011(unsigned char input) { return (input >> 2) | puncture_00010010(input >> 2); }
inline unsigned char puncture_01001100(unsigned char input) { return (input & 0x3) | ((input & 0x30) >> 2) | ((input & 0x80) >> 3); }
inline unsigned char puncture_01001101(unsigned char input) { return (input >> 1) | puncture_00100110(input >> 1); }
inline unsigned char puncture_01001110(unsigned char input) { return (input & 0x1) | ((input & 0x30) >> 3) | ((input & 0x80) >> 4); }
inline unsigned char puncture_01001111(unsigned char input) { return (input >> 4) | puncture_00000100(input >> 4); }
inline unsigned char puncture_01010000(unsigned char input) { return (input & 0xf) | ((input & 0x20) >> 1) | ((input & 0x80) >> 2); }
inline unsigned char puncture_01010001(unsigned char input) { return (input >> 1) | puncture_00101000(input >> 1); }
inline unsigned char puncture_01010010(unsigned char input) { return (input & 0x1) | ((input & 0xc) >> 1) | ((input & 0x20) >> 2) | ((input & 0x80) >> 3); }
inline unsigned char puncture_01010011(unsigned char input) { return (input >> 2) | puncture_00010100(input >> 2); }
inline unsigned char puncture_01010100(unsigned char input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0x20) >> 2) | ((input & 0x80) >> 3); }
inline unsigned char puncture_01010101(unsigned char input) { return (input >> 1) | puncture_00101010(input >> 1); }
inline unsigned char puncture_01010110(unsigned char input) { return (input & 0x1) | ((input & 0x8) >> 2) | ((input & 0x20) >> 3) | ((input & 0x80) >> 4); }
inline unsigned char puncture_01010111(unsigned char input) { return (input >> 3) | puncture_00001010(input >> 3); }
inline unsigned char puncture_01011000(unsigned char input) { return (input & 0x7) | ((input & 0x20) >> 2) | ((input & 0x80) >> 3); }
inline unsigned char puncture_01011001(unsigned char input) { return (input >> 1) | puncture_00101100(input >> 1); }
inline unsigned char puncture_01011010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x20) >> 3) | ((input & 0x80) >> 4); }
inline unsigned char puncture_01011011(unsigned char input) { return (input >> 2) | puncture_00010110(input >> 2); }
inline unsigned char puncture_01011100(unsigned char input) { return (input & 0x3) | ((input & 0x20) >> 3) | ((input & 0x80) >> 4); }
inline unsigned char puncture_01011101(unsigned char input) { return (input >> 1) | puncture_00101110(input >> 1); }
inline unsigned char puncture_01011110(unsigned char input) { return (input & 0x1) | ((input & 0x20) >> 4) | ((input & 0x80) >> 5); }
inline unsigned char puncture_01011111(unsigned char input) { return (input >> 5) | puncture_00000010(input >> 5); }
inline unsigned char puncture_01100000(unsigned char input) { return (input & 0x1f) | ((input & 0x80) >> 2); }
inline unsigned char puncture_01100001(unsigned char input) { return (input >> 1) | puncture_00110000(input >> 1); }
inline unsigned char puncture_01100010(unsigned char input) { return (input & 0x1) | ((input & 0x1c) >> 1) | ((input & 0x80) >> 3); }
inline unsigned char puncture_01100011(unsigned char input) { return (input >> 2) | puncture_00011000(input >> 2); }
inline unsigned char puncture_01100100(unsigned char input) { return (input & 0x3) | ((input & 0x18) >> 1) | ((input & 0x80) >> 3); }
inline unsigned char puncture_01100101(unsigned char input) { return (input >> 1) | puncture_00110010(input >> 1); }
inline unsigned char puncture_01100110(unsigned char input) { return (input & 0x1) | ((input & 0x18) >> 2) | ((input & 0x80) >> 4); }
inline unsigned char puncture_01100111(unsigned char input) { return (input >> 3) | puncture_00001100(input >> 3); }
inline unsigned char puncture_01101000(unsigned char input) { return (input & 0x7) | ((input & 0x10) >> 1) | ((input & 0x80) >> 3); }
inline unsigned char puncture_01101001(unsigned char input) { return (input >> 1) | puncture_00110100(input >> 1); }
inline unsigned char puncture_01101010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x10) >> 2) | ((input & 0x80) >> 4); }
inline unsigned char puncture_01101011(unsigned char input) { return (input >> 2) | puncture_00011010(input >> 2); }
inline unsigned char puncture_01101100(unsigned char input) { return (input & 0x3) | ((input & 0x10) >> 2) | ((input & 0x80) >> 4); }
inline unsigned char puncture_01101101(unsigned char input) { return (input >> 1) | puncture_00110110(input >> 1); }
inline unsigned char puncture_01101110(unsigned char input) { return (input & 0x1) | ((input & 0x10) >> 3) | ((input & 0x80) >> 5); }
inline unsigned char puncture_01101111(unsigned char input) { return (input >> 4) | puncture_00000110(input >> 4); }
inline unsigned char puncture_01110000(unsigned char input) { return (input & 0xf) | ((input & 0x80) >> 3); }
inline unsigned char puncture_01110001(unsigned char input) { return (input >> 1) | puncture_00111000(input >> 1); }
inline unsigned char puncture_01110010(unsigned char input) { return (input & 0x1) | ((input & 0xc) >> 1) | ((input & 0x80) >> 4); }
inline unsigned char puncture_01110011(unsigned char input) { return (input >> 2) | puncture_00011100(input >> 2); }
inline unsigned char puncture_01110100(unsigned char input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0x80) >> 4); }
inline unsigned char puncture_01110101(unsigned char input) { return (input >> 1) | puncture_00111010(input >> 1); }
inline unsigned char puncture_01110110(unsigned char input) { return (input & 0x1) | ((input & 0x8) >> 2) | ((input & 0x80) >> 5); }
inline unsigned char puncture_01110111(unsigned char input) { return (input >> 3) | puncture_00001110(input >> 3); }
inline unsigned char puncture_01111000(unsigned char input) { return (input & 0x7) | ((input & 0x80) >> 4); }
inline unsigned char puncture_01111001(unsigned char input) { return (input >> 1) | puncture_00111100(input >> 1); }
inline unsigned char puncture_01111010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x80) >> 5); }
inline unsigned char puncture_01111011(unsigned char input) { return (input >> 2) | puncture_00011110(input >> 2); }
inline unsigned char puncture_01111100(unsigned char input) { return (input & 0x3) | ((input & 0x80) >> 5); }
inline unsigned char puncture_01111101(unsigned char input) { return (input >> 1) | puncture_00111110(input >> 1); }
inline unsigned char puncture_01111110(unsigned char input) { return (input & 0x1) | ((input & 0x80) >> 6); }
inline unsigned char puncture_01111111(unsigned char input) { return input>>7;  }
inline unsigned char puncture_10000000(unsigned char input) { return input & 0x7f;  }
inline unsigned char puncture_10000001(unsigned char input) { return (input >> 1) | puncture_01000000(input >> 1); }
inline unsigned char puncture_10000010(unsigned char input) { return (input & 0x1) | ((input & 0x7c) >> 1); }
inline unsigned char puncture_10000011(unsigned char input) { return (input >> 2) | puncture_00100000(input >> 2); }
inline unsigned char puncture_10000100(unsigned char input) { return (input & 0x3) | ((input & 0x78) >> 1) ; }
inline unsigned char puncture_10000101(unsigned char input) { return (input >> 1) | puncture_01000010(input >> 1); }
inline unsigned char puncture_10000110(unsigned char input) { return (input & 0x1) | ((input & 0x78) >> 2); }
inline unsigned char puncture_10000111(unsigned char input) { return (input >> 3) | puncture_00010000(input >> 3); }
inline unsigned char puncture_10001000(unsigned char input) { return (input & 0x7) | ((input & 0x70) >> 1) ; }
inline unsigned char puncture_10001001(unsigned char input) { return (input >> 1) | puncture_01000100(input >> 1); }
inline unsigned char puncture_10001010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x70) >> 2); }
inline unsigned char puncture_10001011(unsigned char input) { return (input >> 2) | puncture_00100010(input >> 2); }
inline unsigned char puncture_10001100(unsigned char input) { return (input & 0x3) | ((input & 0x70) >> 2) ; }
inline unsigned char puncture_10001101(unsigned char input) { return (input >> 1) | puncture_01000110(input >> 1); }
inline unsigned char puncture_10001110(unsigned char input) { return (input & 0x1) | ((input & 0x70) >> 3); }
inline unsigned char puncture_10001111(unsigned char input) { return (input >> 4) | puncture_00001000(input >> 4); }
inline unsigned char puncture_10010000(unsigned char input) { return (input & 0xf) | ((input & 0x60) >> 1) ; }
inline unsigned char puncture_10010001(unsigned char input) { return (input >> 1) | puncture_01001000(input >> 1); }
inline unsigned char puncture_10010010(unsigned char input) { return (input & 0x1) | ((input & 0xc0) >> 1) | ((input & 0x60) >> 2); }
inline unsigned char puncture_10010011(unsigned char input) { return (input >> 2) | puncture_00100100(input >> 2); }
inline unsigned char puncture_10010100(unsigned char input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0x60) >> 2) ; }
inline unsigned char puncture_10010101(unsigned char input) { return (input >> 1) | puncture_01001010(input >> 1); }
inline unsigned char puncture_10010110(unsigned char input) { return (input & 0x1) | ((input & 0x8) >> 2) | ((input & 0x60) >> 3); }
inline unsigned char puncture_10010111(unsigned char input) { return (input >> 3) | puncture_00010010(input >> 3); }
inline unsigned char puncture_10011000(unsigned char input) { return (input & 0x7) | ((input & 0x60) >> 2) ; }
inline unsigned char puncture_10011001(unsigned char input) { return (input >> 1) | puncture_01001100(input >> 1); }
inline unsigned char puncture_10011010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x60) >> 3); }
inline unsigned char puncture_10011011(unsigned char input) { return (input >> 2) | puncture_00100110(input >> 2); }
inline unsigned char puncture_10011100(unsigned char input) { return (input & 0x3) | ((input & 0x60) >> 3) ; }
inline unsigned char puncture_10011101(unsigned char input) { return (input >> 1) | puncture_01001110(input >> 1); }
inline unsigned char puncture_10011110(unsigned char input) { return (input & 0x1) | ((input & 0x60) >> 4); }
inline unsigned char puncture_10011111(unsigned char input) { return (input >> 5) | puncture_00000100(input >> 5); }
inline unsigned char puncture_10100000(unsigned char input) { return (input & 0x1f) | ((input & 0x40) >> 1); }
inline unsigned char puncture_10100001(unsigned char input) { return (input >> 1) | puncture_01010000(input >> 1); }
inline unsigned char puncture_10100010(unsigned char input) { return (input & 0x1) | ((input & 0x1c) >> 1) | ((input & 0x40) >> 2); }
inline unsigned char puncture_10100011(unsigned char input) { return (input >> 2) | puncture_00101000(input >> 2); }
inline unsigned char puncture_10100100(unsigned char input) { return (input & 0x3) | ((input & 0x18) >> 1) | ((input & 0x40) >> 2) ; }
inline unsigned char puncture_10100101(unsigned char input) { return (input >> 1) | puncture_01010010(input >> 1); }
inline unsigned char puncture_10100110(unsigned char input) { return (input & 0x1) | ((input & 0x18) >> 2) | ((input & 0x40) >> 3); }
inline unsigned char puncture_10100111(unsigned char input) { return (input >> 3) | puncture_00010100(input >> 3); }
inline unsigned char puncture_10101000(unsigned char input) { return (input & 0x7) | ((input & 0x10) >> 1) | ((input & 0x40) >> 2) ; }
inline unsigned char puncture_10101001(unsigned char input) { return (input >> 1) | puncture_01010100(input >> 1); }
inline unsigned char puncture_10101010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x10) >> 2) | ((input & 0x40) >> 3); }
inline unsigned char puncture_10101011(unsigned char input) { return (input >> 2) | puncture_00101010(input >> 2); }
inline unsigned char puncture_10101100(unsigned char input) { return (input & 0x3) | ((input & 0x10) >> 2) | ((input & 0x40) >> 3) ; }
inline unsigned char puncture_10101101(unsigned char input) { return (input >> 1) | puncture_01010110(input >> 1); }
inline unsigned char puncture_10101110(unsigned char input) { return (input & 0x1) | ((input & 0x10) >> 3) | ((input & 0x40) >> 4); }
inline unsigned char puncture_10101111(unsigned char input) { return (input >> 4) | puncture_00001010(input >> 4); }
inline unsigned char puncture_10110000(unsigned char input) { return (input & 0xf) | ((input & 0x40) >> 2) ; }
inline unsigned char puncture_10110001(unsigned char input) { return (input >> 1) | puncture_01011000(input >> 1); }
inline unsigned char puncture_10110010(unsigned char input) { return (input & 0x1) | ((input & 0xc) >> 1) | ((input & 0x40) >> 3); }
inline unsigned char puncture_10110011(unsigned char input) { return (input >> 2) | puncture_00101100(input >> 2); }
inline unsigned char puncture_10110100(unsigned char input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0x40) >> 3) ; }
inline unsigned char puncture_10110101(unsigned char input) { return (input >> 1) | puncture_01011010(input >> 1); }
inline unsigned char puncture_10110110(unsigned char input) { return (input & 0x1) | ((input & 0x8) >> 2) | ((input & 0x40) >> 4); }
inline unsigned char puncture_10110111(unsigned char input) { return (input >> 3) | puncture_00010110(input >> 3); }
inline unsigned char puncture_10111000(unsigned char input) { return (input & 0x7) | ((input & 0x40) >> 3) ; }
inline unsigned char puncture_10111001(unsigned char input) { return (input >> 1) | puncture_01011100(input >> 1); }
inline unsigned char puncture_10111010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x40) >> 4); }
inline unsigned char puncture_10111011(unsigned char input) { return (input >> 2) | puncture_00101110(input >> 2); }
inline unsigned char puncture_10111100(unsigned char input) { return (input & 0x3) | ((input & 0x40) >> 4) ; }
inline unsigned char puncture_10111101(unsigned char input) { return (input >> 1) | puncture_01011110(input >> 1); }
inline unsigned char puncture_10111110(unsigned char input) { return (input & 0x1) | ((input & 0x40) >> 5); }
inline unsigned char puncture_10111111(unsigned char input) { return (input >> 6) | puncture_00000010(input >> 6); }
inline unsigned char puncture_11000000(unsigned char input) { return input & 0x3f;  }
inline unsigned char puncture_11000001(unsigned char input) { return (input >> 1) | puncture_01100000(input >> 1); }
inline unsigned char puncture_11000010(unsigned char input) { return (input & 0x1) | ((input & 0x3c) >> 1) ; }
inline unsigned char puncture_11000011(unsigned char input) { return (input >> 2) | puncture_00110000(input >> 2); }
inline unsigned char puncture_11000100(unsigned char input) { return (input & 0x3) | ((input & 0x38) >> 1) ; }
inline unsigned char puncture_11000101(unsigned char input) { return (input >> 1) | puncture_01100010(input >> 1); }
inline unsigned char puncture_11000110(unsigned char input) { return (input & 0x1) | ((input & 0x38) >> 2) ; }
inline unsigned char puncture_11000111(unsigned char input) { return (input >> 3) | puncture_00011000(input >> 3); }
inline unsigned char puncture_11001000(unsigned char input) { return (input & 0x7) | ((input & 0x3) >> 1) ; }
inline unsigned char puncture_11001001(unsigned char input) { return (input >> 1) | puncture_01100100(input >> 1); }
inline unsigned char puncture_11001010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x30) >> 2); }
inline unsigned char puncture_11001011(unsigned char input) { return (input >> 2) | puncture_00110010(input >> 2); }
inline unsigned char puncture_11001100(unsigned char input) { return (input & 0x3) | ((input & 0x30) >> 2) ; }
inline unsigned char puncture_11001101(unsigned char input) { return (input >> 1) | puncture_01100110(input >> 1); }
inline unsigned char puncture_11001110(unsigned char input) { return (input & 0x1) | ((input & 0x30) >> 3); }
inline unsigned char puncture_11001111(unsigned char input) { return (input >> 4) | puncture_00001100(input >> 4); }
inline unsigned char puncture_11010000(unsigned char input) { return (input & 0xf) | ((input & 0x20) >> 1) ; }
inline unsigned char puncture_11010001(unsigned char input) { return (input >> 1) | puncture_01101000(input >> 1); }
inline unsigned char puncture_11010010(unsigned char input) { return (input & 0x1) | ((input & 0xc) >> 1) | ((input & 0x20) >> 2); }
inline unsigned char puncture_11010011(unsigned char input) { return (input >> 2) | puncture_00110100(input >> 2); }
inline unsigned char puncture_11010100(unsigned char input) { return (input & 0x3) | ((input & 0x8) >> 1) | ((input & 0x20) >> 2) ; }
inline unsigned char puncture_11010101(unsigned char input) { return (input >> 1) | puncture_01101010(input >> 1); }
inline unsigned char puncture_11010110(unsigned char input) { return (input & 0x1) | ((input & 0x8) >> 2) | ((input & 0x20) >> 3); }
inline unsigned char puncture_11010111(unsigned char input) { return (input >> 3) | puncture_00011010(input >> 3); }
inline unsigned char puncture_11011000(unsigned char input) { return (input & 0x7) | ((input & 0x20) >> 2) ; }
inline unsigned char puncture_11011001(unsigned char input) { return (input >> 1) | puncture_01101100(input >> 1); }
inline unsigned char puncture_11011010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x20) >> 3); }
inline unsigned char puncture_11011011(unsigned char input) { return (input >> 2) | puncture_00110110(input >> 2); }
inline unsigned char puncture_11011100(unsigned char input) { return (input & 0x3) | ((input & 0x20) >> 3) ; }
inline unsigned char puncture_11011101(unsigned char input) { return (input >> 1) | puncture_01101110(input >> 1); }
inline unsigned char puncture_11011110(unsigned char input) { return (input & 0x1) | ((input & 0x20) >> 4); }
inline unsigned char puncture_11011111(unsigned char input) { return (input >> 5) | puncture_00000110(input >> 5); }
inline unsigned char puncture_11100000(unsigned char input) { return input & 0x1f;  }
inline unsigned char puncture_11100001(unsigned char input) { return (input >> 1) | puncture_01110000(input >> 1); }
inline unsigned char puncture_11100010(unsigned char input) { return (input & 0x1) | ((input & 0x1c) >> 1) ; }
inline unsigned char puncture_11100011(unsigned char input) { return (input >> 2) | puncture_00111000(input >> 2); }
inline unsigned char puncture_11100100(unsigned char input) { return (input & 0x3) | ((input & 0x18) >> 1) ; }
inline unsigned char puncture_11100101(unsigned char input) { return (input >> 1) | puncture_01110010(input >> 1); }
inline unsigned char puncture_11100110(unsigned char input) { return (input & 0x1) | ((input & 0x18) >> 2) ; }
inline unsigned char puncture_11100111(unsigned char input) { return (input >> 3) | puncture_00011100(input >> 3); }
inline unsigned char puncture_11101000(unsigned char input) { return (input & 0x7) | ((input & 0x10) >> 1) ; }
inline unsigned char puncture_11101001(unsigned char input) { return (input >> 1) | puncture_01110100(input >> 1); }
inline unsigned char puncture_11101010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) | ((input & 0x10) >> 2); }
inline unsigned char puncture_11101011(unsigned char input) { return (input >> 2) | puncture_00111010(input >> 2); }
inline unsigned char puncture_11101100(unsigned char input) { return (input & 0x3) | ((input & 0x10) >> 2) ; }
inline unsigned char puncture_11101101(unsigned char input) { return (input >> 1) | puncture_01110110(input >> 1); }
inline unsigned char puncture_11101110(unsigned char input) { return (input & 0x1) | ((input & 0x10) >> 3); }
inline unsigned char puncture_11101111(unsigned char input) { return (input >> 4) | puncture_00001110(input >> 4); }
inline unsigned char puncture_11110000(unsigned char input) { return input & 0xf;  }
inline unsigned char puncture_11110001(unsigned char input) { return (input >> 1) | puncture_01111000(input >> 1); }
inline unsigned char puncture_11110010(unsigned char input) { return (input & 0x1) | ((input & 0xc) >> 1) ; }
inline unsigned char puncture_11110011(unsigned char input) { return (input >> 2) | puncture_00111100(input >> 2); }
inline unsigned char puncture_11110100(unsigned char input) { return (input & 0x3) | ((input & 0x8) >> 1) ; }
inline unsigned char puncture_11110101(unsigned char input) { return (input >> 1) | puncture_01111010(input >> 1); }
inline unsigned char puncture_11110110(unsigned char input) { return (input & 0x1) | ((input & 0x8) >> 2) ; }
inline unsigned char puncture_11110111(unsigned char input) { return (input >> 3) | puncture_00011110(input >> 3); }
inline unsigned char puncture_11111000(unsigned char input) { return input & 0x7;  }
inline unsigned char puncture_11111001(unsigned char input) { return (input >> 1) | puncture_01111100(input >> 1); }
inline unsigned char puncture_11111010(unsigned char input) { return (input & 0x1) | ((input & 0x4) >> 1) ; }
inline unsigned char puncture_11111011(unsigned char input) { return (input >> 2) | puncture_00111110(input >> 2); }
inline unsigned char puncture_11111100(unsigned char input) { return input & 0x3;  }
inline unsigned char puncture_11111101(unsigned char input) { return (input >> 1) | puncture_01111110(input >> 1); }
inline unsigned char puncture_11111110(unsigned char input) { return input & 0x1;  }
inline unsigned char puncture_11111111(unsigned char input) { return 0;  }



const puncture_func puncture_funcs[256] = {
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

// Puncture and condense example of 1024 bits in O(n*logn)
// =======================================================
// 1024 / 8 = 128 bytes = 64x16b words = 32x32b dwords = 16x64b = 8x128b = 4x256b = 2x512b
// 
// 128x8b:
// =======
// 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 
// 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 
// 
// after 2b puncture per byte (2 bits in each byte are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 
// 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 0x3F 
//
// after byte condensing:
// ======================
// 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 
// 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 0x0F 0xFF 
//
// 64x16b:
// =======
// 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 
// 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 0xFFFF 
//
// after 2b puncture per byte (2 bits in each byte are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 
// 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 0x3F3F 
//
// after byte condensing:
// ======================
// 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 
// 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 0x0FFF 
//
// after word condensing:
// ======================
// 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 
// 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 0x00FF 0xFFFF 
//
// 32x32b:
// =======
// 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 
// 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 0xFFFFFFFF 
//
// after 2b puncture per byte (2 bits in each byte are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 
// 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 0x3F3F3F3F 
//
// after byte condensing:
// ======================
// 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 
// 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 0x0FFF0FFF 
//
// after word condensing:
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
// after 2b puncture per byte (2 bits in each byte are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 
// 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F 
//
// after byte condensing:
// ======================
// 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 
// 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF 
//
// after word condensing:
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
// after 2b puncture per byte (2 bits in each byte are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 
// 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 
//
// after byte condensing:
// ==========================================================================================================
// 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 
// 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 
//
// after word condensing:
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
// after 2b puncture per byte (2 bits in each byte are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F
// 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 
//
// after byte condensing:
// ======================
// 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 
// 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 
//
// after word condensing:
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
// after 2b puncture per byte (2 bits in each byte are punctured according to the above O(1) punc functions):
// ==========================================================================================================
// 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F
// 0x3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F3F 
//
// after byte condensing:
// ======================
// 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 
// 0x0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF0FFF 
//
// after word condensing:
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

