#include <iostream>
#include <vector>
#include "matrix.hpp"
#include "utils.hpp"

// Función para centralizar casos de prueba manuales y valores esperados
void run_matrix_tests() {
    std::cout << "--- Ejecutando banco de pruebas de matrices ---\n";

    // =========================================================================
    // 1. CASO 2x2
    // =========================================================================
    std::vector<std::vector<float>> m2x2_a = {
        {1.0f, 2.0f},
        {3.0f, 4.0f}
    };
    std::vector<std::vector<float>> m2x2_b = {
        {5.0f, 6.0f},
        {7.0f, 8.0f}
    };
    /*
      [Operación]: Sum (A + B)
      - Método: Suma elemento a elemento en cuadrícula idéntica.
      - Hint: Dos bucles o recorrido plano si las dimensiones coinciden.
      - Resultado esperado:
        [  6.0,  8.0 ]
        [ 10.0, 12.0 ]

      [Operación]: Substract (A - B)
      - Método: Resta elemento a elemento.
      - Hint: Mismas restricciones de dimensión que la suma.
      - Resultado esperado:
        [ -4.0, -4.0 ]
        [ -4.0, -4.0 ]

      [Operación]: ScalarMultiply (A * 2.5f)
      - Método: Multiplicar cada celda por un escalar k.
      - Hint: No cambia dimensiones; útil para gradientes y escalado.
      - Resultado esperado:
        [ 2.5,  5.0 ]
        [ 7.5, 10.0 ]

      [Operación]: Transpose (A^T)
      - Método: Intercambio de ejes (filas se convierten en columnas).
      - Hint: T[j][i] = A[i][j]. La dimensión pasa de (R x C) a (C x R).
      - Resultado esperado:
        [ 1.0, 3.0 ]
        [ 2.0, 4.0 ]

      [Operación]: Multiply / DotProduct2D (A * B)
      - Método: Producto matricial estándar fila por columna: C[i][j] = sum_k(A[i][k] * B[k][j]).
      - Hint: cols(A) debe ser igual a rows(B). Algoritmo clásico con 3 bucles anidados i, j, k.
      - Resultado esperado:
        [ 19.0, 22.0 ]
        [ 43.0, 50.0 ]

      [Operación]: Determinant (det(A))
      - Método: Fórmula para 2x2: (a*d - b*c).
      - Hint: Representa el factor de escala de área/volumen y si la matriz es invertible.
      - Resultado esperado: 1*4 - 2*3 = -2.0f

      [Operación]: Inverse (A^-1)
      - Método: (1 / det) * [  d, -b ]
                            [ -c,  a ]
      - Hint: Requiere que det != 0. Si det == 0, retornar std::nullopt.
      - Resultado esperado:
        [ -2.0,  1.0 ]
        [  1.5, -0.5 ]

      [Operación]: Trace (tr(A))
      - Método: Suma de la diagonal principal sum_i(A[i][i]).
      - Hint: Solo definida para matrices cuadradas.
      - Resultado esperado: 1.0 + 4.0 = 5.0f
    */

    // =========================================================================
    // 2. CASO 3x3
    // =========================================================================
    std::vector<std::vector<float>> m3x3_a = {
        {1.0f, 2.0f, 3.0f},
        {0.0f, 1.0f, 4.0f},
        {5.0f, 6.0f, 0.0f}
    };
    std::vector<std::vector<float>> m3x3_b = {
        {2.0f, 0.0f, -1.0f},
        {1.0f, 3.0f,  2.0f},
        {0.0f, 1.0f,  1.0f}
    };
    /*
      [Operación]: Sum (A + B)
      - Resultado esperado:
        [ 3.0, 2.0, 2.0 ]
        [ 1.0, 4.0, 6.0 ]
        [ 5.0, 7.0, 1.0 ]

      [Operación]: Substract (A - B)
      - Resultado esperado:
        [ -1.0, 2.0,  4.0 ]
        [ -1.0, -2.0, 2.0 ]
        [  5.0, 5.0, -1.0 ]

      [Operación]: Multiply (A * B)
      - Método: Fila de A punto Columna de B.
      - Resultado esperado:
        [ 4.0,  9.0, 6.0 ]
        [ 1.0,  7.0, 6.0 ]
        [ 16.0, 18.0, 7.0 ]

      [Operación]: Transpose (A^T)
      - Resultado esperado:
        [ 1.0, 0.0, 5.0 ]
        [ 2.0, 1.0, 6.0 ]
        [ 3.0, 4.0, 0.0 ]

      [Operación]: Determinant (det(A))
      - Método: Regla de Sarrus o expansión por cofactores / eliminación Gaussiana.
      - Hint: Reducir a triangular superior hace det = producto de diagonal.
      - Resultado esperado: 1*(0 - 24) - 2*(0 - 20) + 3*(0 - 5) = -24 + 40 - 15 = 1.0f

      [Operación]: Inverse (A^-1)
      - Método: Gauss-Jordan aumentando [A | I], o matriz adjunta dividida por det.
      - Hint: Como det(A) = 1, la inversa tiene valores enteros exactos.
      - Resultado esperado:
        [ -24.0,  18.0,  5.0 ]
        [  20.0, -15.0, -4.0 ]
        [  -5.0,   4.0,  1.0 ]

      [Operación]: Trace (tr(A))
      - Resultado esperado: 1.0 + 1.0 + 0.0 = 2.0f
    */

    // =========================================================================
    // 3. CASO 4x4
    // =========================================================================
    std::vector<std::vector<float>> m4x4_a = {
        {2.0f, 0.0f, 0.0f, 1.0f},
        {0.0f, 1.0f, 0.0f, 0.0f},
        {1.0f, 0.0f, 3.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 2.0f}
    };
    std::vector<std::vector<float>> m4x4_b = {
        {1.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 2.0f, 0.0f, 1.0f},
        {2.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 1.0f, 0.0f, 2.0f}
    };
    /*
      [Operación]: Multiply (A * B)
      - Resultado esperado:
        [ 2.0, 1.0, 2.0, 2.0 ]
        [ 0.0, 2.0, 0.0, 1.0 ]
        [ 7.0, 0.0, 4.0, 0.0 ]
        [ 0.0, 2.0, 0.0, 4.0 ]

      [Operación]: Determinant (det(A))
      - Método: Eliminación Gaussiana con pivoteo parcial (evita división por cero).
      - Hint: Para 4x4 o mayor, cofactores es O(n!); Gaussiana es O(n^3).
      - Resultado esperado: 12.0f

      [Operación]: LU Decomposition (A = L * U)
      - Método: Descomposición de Doolittle o Crout.
      - Hint: L es triangular inferior con 1s en la diagonal; U es triangular superior.
      - Utilidad: Resolver Ax = b velozmente mediante sustitución progresiva y regresiva.
    */

    // =========================================================================
    // 4. CASO 64x64 (Escala media para benchmarking y optimización)
    // =========================================================================
    using DataType = bool;
    auto m64_a = utils::Matrix::gen_random_matrix<DataType>(64,64);
    auto m64_b = utils::Matrix::gen_random_matrix<DataType>(64,64);
    /*
      [Operación]: Sum (A + B)
      - Resultado esperado: Matriz 64x64 con cada celda = 3.0f.

      [Operación]: Multiply (A * B)
      - Resultado esperado: Matriz 64x64 con cada celda = sum_k(1.0 * 2.0) = 64 * 2.0 = 128.0f.
      - Hint de optimización: Reordenar bucles i-k-j en vez de i-j-k para recorrer la memoria
        por filas en vez de saltar por columnas en B (reduce dramáticamente fallos de caché).

      [Operación]: Benchmarking
      - Hint: Usar <chrono> (std::chrono::high_resolution_clock) para comparar el tiempo
        de ejecución entre la versión 2D habitual y la futura versión 1D aplanada.
    */

    // Ejecución inicial de prueba
    auto res = Matrix::Sum(m2x2_a, m2x2_b);
    if (res.has_value()) {
        std::cout<<"\nSUM 2x2\n";
        utils::IO::print2dMatrix(res.value());
    }


    auto res2 = Matrix::Sum(m64_a, m64_b);
    if(res2.has_value()){
        std::cout<<"\nSUM 64x64\n";
        utils::IO::print2dMatrix(res2.value());
    }



    res.reset();
    res = Matrix::Transpose(m3x3_a);
    if(res.has_value()){
        std::cout<<"\n TRANSPOSE OF 3x3\n";
        utils::IO::print2dMatrix(res.value());
    }

    res.reset();
    res = Matrix::ScalarMultiply(m3x3_a, 5.4);
    if(res.has_value()){
        std::cout<<"\n SCALAR MULTIPLY 3x3\n";
        utils::IO::print2dMatrix(res.value());
    }


    auto trace = Matrix::Trace(m3x3_a);
    if(trace.has_value()){
        std::cout<<"\n TRACE A 3x3\n";
        std::cout<<"Trace of A: "<<trace.value()<<"\n";
    }

    res.reset();
    res = Matrix::Multiply(m3x3_a, m3x3_b, MultMethod::Naive);
    if(res.has_value()){
        std::cout<<"\n NAIVE MULTIPLY 3x3\n";
        utils::IO::print2dMatrix(res.value());
    }

}

int main() {
    run_matrix_tests();
    return 0;
}
