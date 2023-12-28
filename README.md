# 8bp
8 bit Puncture actions using function pointers in C++

### Build and Run
`g++ -g -o punc_fps punc_fps.cpp -lstdc++ && ./punc_fps`

### Console Output

    data = 0x56369f942f00
    p_bits As Hex u16 reverse:
    
    00c8 00aa 00a0 0096 008c 0081 0080 0033 0032 0025 0023 0022 0021 001e 0008 0004 0002 0001 
    
    data As Hex u8 reverse:
    
    ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff 7f ff ff ff 7f 7f ff 7f 7f 3f ff ff ff ff ff ff ff ff ff 3f ff 0f 7f ff 7f 1f 
    
    p_bytes As Hex u16 reverse:
    
    0019 0015 0014 0012 0011 0010 0006 0004 0003 0001 0000 
    
    p_bytes_num_puncs As Hex u8 reverse:
    
    01 01 01 01 01 02 02 04 01 01 03 
    
    p_bytes_punctures As Hex u8 reverse:
    
    01 04 01 40 10 03 0c 2e 40 01 16 
    
    data bytes after condense_even_byte_pairs() As Hex u8 reverse:
    
    ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff 7f ff ff ff 3f ff 7f ff 1f ff ff ff ff ff ff ff ff ff 3f ff 0f ff 7f ff 0f ff 
    
    p_bytes_num_puncs after condense_even_byte_pairs() As Hex u8 reverse:
    
    01 02 00 01 03 00 02 04 01 04 00 
    
    p_words after condense_even_byte_pairs() As Hex u16 reverse:
    
    000c 000a 0009 0008 0003 0002 0001 0000 
    
    p_words_num_puncs after condense_even_byte_pairs() As Hex u8 reverse:
    
    01 02 01 03 02 04 01 04 
    
    data words after condense_even_word_pairs() As Hex u16 reverse:
    
    ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff ffff 7fff ffff 3fff ffff 0fff ffff ffff ffff ffff ffff 03ff ffff 07ff ffff 
    
    p_words_num_puncs after condense_even_word_pairs() As Hex u8 reverse:
    
    01 02 04 00 06 00 05 00 
    
    p_dwords after condense_even_word_pairs() As Hex u16 reverse:
    
    0006 0005 0004 0001 0000 
    
    p_dwords_num_puncs after condense_even_word_pairs() As Hex u8 reverse:
    
    01 02 04 06 05 

    data dwords after condense_even_dword_pairs() As Hex u32 reverse:
    
    ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff 7fffffff ffffffff 03ffffff ffffffff ffffffff ffffffff 001fffff ffffffff 
    
    p_dwords_num_puncs after condense_even_dword_pairs() As Hex u8 reverse:
    
    01 06 00 0b 00 
    
    p_u64s after condense_even_dword_pairs() As Hex u16 reverse:
    
    0003 0002 0000 
    
    p_u64s_num_puncs after condense_even_dword_pairs() As Hex u8 reverse:
    
    01 06 0b 
    
