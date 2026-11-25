# Base64 — A C Implementation

A self-built Base64 encoder and decoder written in C, developed to explore bit manipulation, binary data representation, and file handling.

## About the Project

This project is an attempt to understand and implement the Base64 encoding mechanism from scratch rather than relying on predefined encoding libraries.

The primary objective was to apply fundamental C programming concepts to a practical problem, particularly:

- Bitwise operations and bit manipulation
- Binary file reading using `fread()`
- Byte-level data processing
- Bit shifting, masking, and combining
- Handling data in fixed-size blocks
- Understanding padding in Base64 encoding

## How Base64 Works

Base64 converts binary data into a textual representation using a set of 64 characters.

The encoding process works as follows:

1. Read the input data in blocks of 3 bytes (24 bits).
2. Divide those 24 bits into four groups of 6 bits each.
3. Convert each 6-bit value into its corresponding Base64 character.
4. Use padding (`=`) when the input does not contain a complete 3-byte block.

**Example:**

```text
Input:       ABC

ASCII:       01000001 01000010 01000011

6-bit groups:
             010000 010100 001001 000011

Decimal:     16 20 9 3

Base64:      QUJD
```

## Implementation

The project contains separate experiments and implementations exploring the encoding and decoding processes.

### Encoding

The encoder reads an input file in binary mode and processes its contents in 3-byte blocks.

The resulting 24-bit block is divided into four 6-bit values using bitwise shifts and operations.

### Decoding

The decoder performs the reverse operation:

- Reads encoded data in groups of four characters.
- Maps Base64 characters back to their corresponding 6-bit values.
- Combines the values into a 24-bit block.
- Extracts the original bytes.

## Technologies Used

- **Language:** C
- **Standard libraries:** `stdio.h`, `stdint.h`, `stdlib.h`, `string.h`
- **Compiler:** GCC
- **Environment:** Linux

## Compilation and Execution

Make sure GCC is installed.

### Compile the encoder

```bash
gcc base64_1.c -o base64
```

### Run the encoder

```bash
./base64 input_file
```

To save the output:

```bash
./base64 input_file > encoded.txt
```

### Compile the decoder

```bash
gcc decoder.c -o decoder
```

### Run the decoder

```bash
./decoder encoded.txt
```

To redirect decoded output:

```bash
./decoder encoded.txt > decoded_file
```

## Learning Outcomes

Building this project helped me understand how abstract encoding mechanisms translate into actual bit-level operations.

Some of the key concepts explored were:

- How three 8-bit bytes are transformed into four 6-bit values.
- How bitwise shifts can extract and rearrange individual bit groups.
- How C handles binary file input through `fread()`.
- Why incomplete input blocks require special handling.
- How padding maintains the structure of Base64 output.

## Current Status

This is an educational implementation and an ongoing learning project.

The implementation is experimental, and edge cases involving padding, incomplete blocks, and decoder validation still need further testing and refinement.

It is not intended to replace established Base64 utilities or production-ready libraries.

## Future Improvements

- Improve handling of incomplete input blocks.
- Implement reliable padding and decoding validation.
- Support robust binary file-to-file encoding and decoding.
- Improve error handling and command-line arguments.
- Test against standard Base64 implementations.

---

**Author:** [sukrit210](https://github.com/sukrit210)

**Repository:** [Base64](https://github.com/sukrit210/Base64)

