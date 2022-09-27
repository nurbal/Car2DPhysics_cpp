# Car2DPhysics_cpp

C++ port of CarPhysics

## Dependencies

Dependency on Box2D, and pybind11 as a submodules

To get the code:
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

