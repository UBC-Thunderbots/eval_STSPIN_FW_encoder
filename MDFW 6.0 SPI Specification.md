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

# How instructions work:
    - instructions are send as one byte opcodes.
    - if instruction needs data passing, send data as a 15 number with one bit paraty (2 clock cycles)

# Opcodes (3bits)
    - 000: set speed parameter
    - 001: set duration parameter
    - 010: set motor speed
    - 011: send speed parameter
    - 100: get duration parameter
    - 101: stop motor
    - 110: 

# Sending parameters: Current plan
    - send as 3 bytes 
            1st byte: 1st bit parity bit for 1st byte, 4 bits for opcode, 3 bits for 2nd and 3rd byte parity)
            2nd ,3rd byte: represent a max motor speed of 45045

