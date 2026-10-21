# Mini-Eigen — Motor matemático en C++ moderno

Motor matemático artesanal escrito a mano en C++17: álgebra matricial, geometría computacional, métodos numéricos y algoritmos de machine learning, construidos desde cero para dominar la teoría antes de usar librerías externas.

## Filosofía

Este es un proyecto de aprendizaje deliberadamente profundo: nada de atajos de IA ni de copiar implementaciones de Eigen. El objetivo es entender memoria, caché, álgebra y algoritmos hasta poder escribirlos sin referencia. Cada módulo incluye su propio banco de pruebas manuales con casos 2×2, 3×3, 4×4 y 64×64 y valores esperados documentados.

## Estado actual

- `include/matrix.hpp`: `Sum`, `Substract`, `ScalarMultiply` y `Transpose` verificadas.
- `include/utils.hpp`: validaciones `is_not_empty`, `is_uniform`, `is_square`, `is_same_size`, generación aleatoria y formateo en consola (`utils::IO`).
- `src/main.cpp`: banco de pruebas ejecutable de todas las operaciones.
- Pendientes inmediatos: multiplicación matricial (`Multiply`) y traza (`Trace`).

La hoja de ruta completa está en [`ROADMAP.md`](ROADMAP.md): fases 2–6 cubren geometría 2D/3D (convex hull, intersecciones, colisiones), solucionadores de sistemas lineales (Gauss, LU, QR, SVD), métodos numéricos (Newton-Raphson, RK4), machine learning (k-NN, regresión, K-Means, MLP con backpropagation) y optimización de rendimiento (matrices planas 1D, expression templates, paralelización).

## Entornos de desarrollo

Compilado y verificado en:

- **macOS** — Apple Silicon, Clang, CMake 3.20+, C++17.

Debería compilar sin cambios en **Linux** (GCC/Clang) y **Windows** (MSVC o MinGW vía Visual Studio o CMake Tools), aunque no han sido probados todavía.

## Compilación

```bash
cmake -S . -B build
cmake --build build --target app
./build/app
```

El directorio `build/`, la caché de análisis y los binarios no se distribuyen.

## Documentación complementaria

- [`ROADMAP.md`](ROADMAP.md) — visión global y avance fase por fase.
- [`TEMAS_PENDIENTES.md`](TEMAS_PENDIENTES.md) — temas de C++ moderno a adoptar: `enum class`, `std::expected` (C++23), matrices planas para localidad de caché, expression templates, vcpkg y concurrencia con `std::jthread`.
- [`INSTRUCCIONES.md`](INSTRUCCIONES.md) — reglas de trabajo del tutor de C++.

## Licencia

MIT.
