# Mini-Eigen — Mathematical engine in modern C++

A hand-crafted mathematical engine written in C++17: matrix algebra, computational geometry, numerical methods and machine learning algorithms, all built from scratch to master the theory before touching external libraries.

## Philosophy

This is a deliberately deep learning project: no AI shortcuts, no copying Eigen implementations. The goal is to understand memory, cache behaviour, algebra and algorithms well enough to write them without reference material. Every module ships with its own manual test bank covering 2×2, 3×3, 4×4 and 64×64 cases with documented expected values.

## Current state

- `include/matrix.hpp`: verified `Sum`, `Substract`, `ScalarMultiply` and `Transpose`.
- `include/utils.hpp`: `is_not_empty`, `is_uniform`, `is_square`, `is_same_size` validations, random matrix generation and console formatting (`utils::IO`).
- `src/main.cpp`: runnable test bank exercising every implemented operation.
- Immediate next steps: matrix multiplication (`Multiply`) and matrix trace (`Trace`).

The full roadmap lives in [`ROADMAP.md`](ROADMAP.md): phases 2–6 cover 2D/3D geometry (convex hull, intersections, collision detection), linear system solvers (Gaussian elimination, LU, QR, SVD), numerical methods (Newton-Raphson, RK4), machine learning (k-NN, regression, K-Means, MLP with backpropagation) and performance work (flat 1D matrices, expression templates, parallelisation).

## Development environments

Built and verified on:

- **macOS** — Apple Silicon, Clang, CMake 3.20+, C++17.

It should compile unchanged on **Linux** (GCC/Clang) and **Windows** (MSVC or MinGW via Visual Studio or CMake Tools), although neither has been smoke-tested yet.

## Building

```bash
cmake -S . -B build
cmake --build build --target app
./build/app
```

The `build/` directory, analysis cache and compiled binaries are not distributed.

## Supporting documentation

- [`ROADMAP.md`](ROADMAP.md) — global vision and phase-by-phase progress.
- [`TEMAS_PENDIENTES.md`](TEMAS_PENDIENTES.md) — modern C++ topics to adopt: `enum class`, `std::expected` (C++23), flat matrices for cache locality, expression templates, vcpkg and concurrency with `std::jthread`.
- [`INSTRUCCIONES.md`](INSTRUCCIONES.md) — the project's tutor working rules.

## Licence

MIT.
