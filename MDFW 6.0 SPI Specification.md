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
    - maybe uses 4th byte for integrity checking

# Opcodes (1 byte)
    - set speed parameter
    - set motor speed
    - send speed parameter
    - send current encoder count
    - stop motor
    - send fault
    - set current to motor

# opcode specification:
    -

# Sending parameters: Current plan
    - send as 3 bytes 
            1st byte: opcode
            2nd, 3rd byte: instruction value
            4th byte: integrity byte

