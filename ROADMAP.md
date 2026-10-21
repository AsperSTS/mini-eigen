# Roadmap del Proyecto: Motor Matemático, Geometría y Machine Learning en C++

> **Filosofía**: Construcción profunda y artesanal en C++ moderno. Sin atajos de IA, priorizando el entendimiento riguroso de memoria, álgebra y algoritmos para forjar maestría técnica.

---

## Fase 1: Cimientos y Álgebra Matricial Básica (Mini-Eigen)
- [x] Configuración de compilación moderna con CMake y estándares C++17
- [x] Separación de estructura `include/` y `src/`
- [x] Validaciones modulares de matrices en `utils.hpp` (`is_not_empty`, `is_square`, `is_same_size`, `is_uniform`)
- [x] Función de formateo e impresión en consola (`utils::IO::print2dMatrix`)
- [ ] Operaciones elementales con matrices 2D:
  - [x] Suma de matrices (`Sum`)
  - [x] Resta de matrices (`Substract`)
  - [x] Multiplicación por escalar (`ScalarMultiply`)
  - [x] Transposición de matrices (`Transpose`)
  - [ ] Multiplicación de matrices (Dot product 2D / `Multiply`)
  - [ ] Traza de una matriz (`Trace`)

---

## Fase 2: Geometría Computacional y Vectores
- [ ] Álgebra vectorial (normas $L_1$, $L_2$, $L_\infty$, producto punto y producto cruz 3D)
- [ ] Geometría 2D/3D:
  - [ ] Representación de puntos, rectas, segmentos y planos
  - [ ] Intersecciones (recta-recta, recta-plano)
  - [ ] Distancia de un punto a una recta y a un plano
  - [ ] Envolvente convexa (*Convex Hull* - Algoritmo de Graham Scan)
  - [ ] Detección de colisiones básicas (cajas AABB y círculos/esferas)

---

## Fase 3: Sistemas de Ecuaciones y Descomposiciones Matriciales
- [ ] Determinante de una matriz (método de cofactores y eliminación Gaussiana)
- [ ] Inversa de matrices (Gauss-Jordan)
- [ ] Solucionador de sistemas de ecuaciones lineales ($Ax = b$):
  - [ ] Eliminación Gaussiana con pivoteo parcial
  - [ ] Descomposición LU
  - [ ] Descomposición QR (Gram-Schmidt)
  - [ ] Descomposición en Valores Singulares (SVD) básica

---

## Fase 4: Métodos Numéricos y Cálculo
- [ ] Búsqueda de raíces de funciones no lineales:
  - [ ] Método de Bisección
  - [ ] Método de Newton-Raphson
- [ ] Diferenciación numérica (aproximaciones por diferencias finitas)
- [ ] Integración numérica (Regla del Trapecio y Regla de Simpson)
- [ ] Ecuaciones diferenciales ordinarias (EDO):
  - [ ] Método de Euler
  - [ ] Método de Runge-Kutta de orden 4 (RK4)

---

## Fase 5: Métricas de Distancia y Algoritmos de Machine Learning
- [ ] Calculadora de métricas de distancia (Euclidiana, Manhattan, Minkowski, Coseno)
- [ ] **k-NN (k-Nearest Neighbors)** con colas de prioridad
- [ ] **Regresión Lineal y Logística** (Descenso de gradiente batch/estocástico)
- [ ] **K-Means Clustering** (agrupamiento no supervisado)
- [ ] **Random Forest / Árboles de Decisión** (Gini / Entropía)
- [ ] **Redes Neuronales (MLP)**:
  - [ ] Capas densas y funciones de activación (ReLU, Sigmoid, Softmax)
  - [ ] Forward Pass y Backpropagation

---

## Fase 6: Alto Rendimiento y Maestría en C++ Moderno
- [ ] Migración a matrices planas 1D continuas (`filas * columnas`)
- [ ] Manejo de errores profesional con `enum class` y `std::expected` (C++23)
- [ ] Expresiones plantilla (*Expression Templates*) para evaluación perezosa
- [ ] Paralelización con OpenMP o subprocesos estándar (`std::jthread`, `std::execution::par`)
- [ ] Integración con gestor de paquetes **vcpkg**
