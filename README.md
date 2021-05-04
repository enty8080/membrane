# Membrane

This is an implementation of a native-code HatSploit membrane, designed for portability, embeddability, and low resource utilization.

## Features

* Membrane supports all unix-like systems, for example `macOS`, `iPhoneOS`, `Linux`, `OpenBSD`, `Android`.
* Membrane does not require extra dependencies and can be initialized on small systems with low CPU.
* Membrane can be executed on most CPUs, for example `x86`, `x64`, `aarch64`, `armle`, `mipsle`, `mipsbe`.

## Build

```sh
mkdir build
cd build
cmake ..
make
```
