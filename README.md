# Membrane

This is an implementation of a native-code HatSploit membrane, designed for portability, embeddability, and low resource utilization.

## Features

* Membrane supports all unix-like systems, for example `macOS`, `iPhoneOS`, `Linux`, `Android`.
* Membrane does not require extra dependencies and can be initialized on small systems with low CPU.
* Membrane can be executed on most CPUs, for example `x86`, `x64`, `aarch64`, `armle`, `mipsle`, `mipsbe`.

## Build

```sh
make membrane
```

**NOTE:** *If you want to cross-compile it for custom targets, you should use custom toolchains, just set `CXX` to path to your cross-compiler*

For example set this:

```Makefile
CXX = g++
```

To this:

```Makefile
CXX = ./my-toolchain/mipsle/gcc
```
