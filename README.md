### **Types**

Inside a header file called `stdint.h` are the declarations of a number of other types that allow us to very precisely define the size (in bits) and sign (signed or unsigned) of an integer. Two types in particular will be useful to us in this project.

- `uint8_t` is a type that stores an 8-bit unsigned (i.e., not negative) integer. We can treat each byte of a WAV file’s header as a `uint8_t` value.
- `int16_t` is a type that stores a 16-bit signed (i.e., positive or negative) integer. We can treat each sample of audio in a WAV file as an `int16_t`value.

**Implementation**

- The program accepts three command-line arguments: `input` represents the name of the original audio file, `output` represents the name of the new audio file that should be generated, and `factor` is the amount by which the volume of the original audio file should be scaled.
    - For example, if `factor` is `2.0`, then your program should double the volume of the audio file in `input` and save the newly generated audio file in `output`.
- The program should first read the header from the input file and write the header to the output file. Recall that this header is always exactly 44 bytes long.
    - Note that `volume.c` already defines a variable for you called `HEADER_SIZE`, equal to the number of bytes in the header.
- The program should then read the rest of the data from the WAV file, one 16-bit (2-byte) sample at a time. The program should multiply each sample by the `factor` and write the new sample to the output file.
    - We may assume that the WAV file will use 16-bit signed values as samples. In practice, WAV files can have varying numbers of bits per sample, but we’ll assume 16-bit samples for this project.
- The program, if it uses `malloc`, must not leak any memory.

**Execution**

The program should behave per the examples below.

`$ ./volume input.wav output.wav 2.0`

When you listen to `output.wav` (as by double-clicking on `output.wav` in the file browser or running `open output.wav` from the terminal), it should be twice as loud as `input.wav`!

`$ ./volume input.wav output.wav 0.5`

When you listen to `output.wav`, it should be half as loud as `input.wav`!
