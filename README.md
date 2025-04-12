# Introduction

Sol is a toy programming language, which is supposed to teach me how to build
a compiler. The Sol compiler is implemented in C++23 using ANTLR4 and LLVM.

The name "Sol" is derived from "Operating Systems Language", as it started out
as pseudocode which I used to solve synchronization exercises during an
operating systems course at my university. "Sol" it's also the name for the Sun,
and "Sól" is the name for the Norse goddess of the Sun.

The project uses exceptions and RTTI, but only because the ANTLR4 runtime
requires it. I prefer to not use them if possible.

# Project structure

Repository structure:

- `design/` - design documents for the language,
- `examples/` - example programs in Sol; keep in mind that only programs from
   `examples/first_iteration` work for now,
- `src` - source code of `solc`, the Sol compiler; the entry point for `solc` is
  in `src/driver.cpp`.

# Building

Project uses CMake as it's build system.

Project dependencies:

- ANTLR4
- LLVM
- gtest
- clang

To build, first install the dependencies. You can do so using your distributions
package manager. Building on Windows and MacOS is currently unsupported,
although the code should be portable.

WARNING: `conanfile.txt` is provided, but unsupported. `CMakeLists.txt` doesn't
make use of it. Conan support is work-in-progress.


To build, first create a build folder and configure CMake:

```
project_root/$ mkdir build && cd build && cmake ..
```

To build the compiler:

```
project_root/build/$ cmake --build
```

To run unit tests:

```
project_root/build/$ ctest
```

IMPORTANT: to link object files resulting from compilation, the Sol compiler
invokes `clang`. As such, it must be installed and present in your `$PATH`. A
more sophisticated approach to linking, including a custom language runtime and
support for the GNU `ld` and LLVM `lld` linkers is in the works.

# Usage

Current iteration of the compiler can only compile single file programs.

An example sol program, `procs.sol` is given below:

```
procedure foo(x: int, y: int): int {
	return x + y * y - x / 2;
}

procedure pow2(x: int) {
	return x * x;
}

procedure main() {
	return pow2(10) / foo(2, 2);
}
```

The general usage of the Sol compiler is:

```
$ solc <program_filename> -o <executable_filename>
```

If `-o` is ommited, the resulting executable is named after the program.
Given `<progname>.sol`, the executable will be named `<progname>`. For
example, the `procs.sol` program will produce the `procs` executable.

All options of `solc` can be displayed using `-h`:
```
$ solc -h
```

Compiler debugging information can be showed using `-v`:
```
$ solc -v
```

# TODO

TODO:
- add the full example of Sol to README, to make a good first impression
- add `procs.sol` from the first iteration after the full program to explain
    that we're not there yet
