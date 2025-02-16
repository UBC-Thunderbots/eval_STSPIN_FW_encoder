# Abstract
This document contains the specifications and protocol documentation for communicating with the motor driver board, version 6.

# Hardware Specifications
- **Communication mode:** *Full Duplex*
- **Frame format:** *Motorola*
- **Data Size:** *8 Bits*
- **Bit Order:** *Big Endian (MSB First)*

- **Clock**:
    - *CPOL Low*
    - *CPHA 1 Edge (First Edge)*
    - *Up to 32MHz Signals*
    - This configuration is also known as SPI Mode 0.

# How instructions work:
    - instructions are send as one byte opcodes + up to 2 bytes (16 bits) of data.
    - This means that data is stored as *16 bit registers*

# Opcodes (1 byte)
    - MOV ax - 0b10000000
    - GET ax - 0b10000001
    - MOV bx - 0b10010000
    - GET bx - 0b10010001
    - set motor speed ramp - 0b10100000
    - get motor speed - 0b10100001
    - get current encoder count - 0b10110001
    - stop motor - 0b11000000
    - get faults - 0b11010001
    - set current to motor - 0b11100000

# opcode specification:
## MOV

# Sending parameters: Current plan
    - send as 3 bytes 
            1st byte: opcode
            2nd, 3rd byte: instruction value
            4th byte: integrity byte
