# Temas Pendientes y Futuros de C++ Moderno

## 1. Manejo de Errores Moderno
- **`enum class`**: Creación de tipos de errores seguros y fuertemente tipados (evitar números mágicos como `error = 1`).
- **`std::expected<Valor, Error>` (C++23)**: Retornar el valor calculado o la causa exacta del fallo de forma determinista y sin sobrecosto de excepciones.
- **Alternativa en C++17**: Simular `std::expected` con una pequeña estructura propia o `std::variant`.

## 2. Optimización de Memoria en Matrices
- **Matrices Planas (1D continuo)**: Migrar de `std::vector<std::vector<T>>` a `std::vector<T>` continuo (`filas * columnas`).
- **Aprovechamiento de Caché (L1/L2)**: Reducción de *cache misses* y soporte para vectorización automática SIMD.
- **Expression Templates**: Evitar matrices intermedias en operaciones encadenadas (`A + B + C`).

## 3. Gestor de Paquetes y Concurrencia
- Integración de **vcpkg** con CMake para dependencias externas profesionales.
- Paralelización de operaciones intensivas usando subprocesos modernos (`std::jthread` o políticas de ejecución paralela).
