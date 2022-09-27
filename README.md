# Car2DPhysics_cpp

C++ port of CarPhysics

## Dependencies

### Build system

- CMake >= 3.0

### Python dependencies

- Dependency on pygame, you may install it via pip for example.
- Dependency on Box2D, and pybind11 as a submodules.

To get the code of these two libraries:
```
git submodule update --init --recursive
```

## Build CPP module

```
mkdir build
cd build
cmake ..
make
```

## Run testbench example

```
cd python
python testbench.py
```

