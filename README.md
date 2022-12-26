# Cache Simulator

This simulator accept a memory access trace file and simulate the cache behavior. It can simulate direct mapping, fully associative and set associative cache. It can also simulate random replacement and LRU replacement policy. It supports write back and write through policy. 
The program is written in standard C++ and has minimum third-party dependencies. It has a Makefile to ensure the consistency of compilation in different environments. The program uses some C++11 features, such as bitset<T>, so it must be compiled in a compiler that supports C++11, but now the mainstream compilers such as GCC and VS have supported it. The encoding of the program is UTF-8.

## I/O format

You can find the example input and output files in the `input` and `output` directory.

The input file is a cache access trace file. Each line of the file is a memory access record, which is a letter and a 32-bit hexadecimal number. The letter is `l` or `s`, which means load or save. The hexadecimal number is the memory address. We recommand you to make the lower 2 bits of the memory address to be zero, which means that the memory address is aligned to 4 bytes.

The output file is a main memory access trace file, for example, DRAM access trace. The trace file is acceptable by DRAM simulators, like Ramulator. Each line of the file is a memory access record, which is a 32-bit hexadecimal number and a letter. The letter is `R` or `W`, which means read or write.

# Usage

## Compile
Compile the program with CMake:

```sh
mkdir build
cd build
cmake ..
make
```

Now you should see the execuatble `build/CacheSim`.

## Run

All the changeable parameters are defined in `run.sh`. You can change the parameters in this file and run the program with:

```
bash run.sh
```

## Results
`output/output.trace` is the output memory access pattern.

`output/stdout.txt` is the standard output of CacheSim, redirected to a file.

## Acknowledgement
This project is based on the [CacheSim](https://github.com/jiangxincode/CacheSim） project.
