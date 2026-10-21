#pragma once
#include"utils.hpp"
#include<cstddef>
#include<vector>
#include<optional>


/* PENDIENTES
 * -validaciones separadas
 * -vectores 1d para aplanar 2d

 - [x] Suma de matrices (`sumMatrix`)
 - [x] Resta de matrices
 - [ ] Multiplicación por escalar
 - [ ] Transposición de matrices
 - [ ] Multiplicación de matrices (Dot product 2D)
 */
enum class MultMethod{Auto, Naive, Blocked, Strassen,Hadamard};
/*
    1. Métodos de Multiplicación y Limitaciones
    Estándar / Naive ($O(n^3)$):
    Tres bucles clásicos ($i, j, k$). Sencillo, pero se vuelve muy lento con matrices grandes por accesos repetidos a memoria.

    Por bloques / Tiling ($O(n^3)$ optimizado):
    Divide la matriz en sub-bloques pequeños que quepan enteros en la caché L1/L2. Ideal para matrices medianas/grandes (ej. 64x64 en adelante).

    Algoritmo de Strassen ($O(n^{2.807})$):
    Reduce multiplicaciones recursivas usando 7 productos en vez de 8.
    Limitante: sobrecosto alto por sumas intermedias y menor precisión numérica; solo conviene para matrices gigantes ($n > 512$).

    Hadamard / Element-wise ($A \odot B$):
    Multiplica celda por celda ($A[i][j] \cdot B[i][j]$).
    Limitante: no es producto matricial algebraico; se usa exclusivamente en Deep Learning (activaciones).
 */

class Matrix{

    public:

        template <typename T> static std::optional<std::vector<std::vector<T>>> Sum(const std::vector<std::vector<T>>& matriz1,const std::vector<std::vector<T>>& matriz2 ){

            if(!utils::Matrix::is_same_size(matriz1, matriz2)){
                return std::nullopt;
            }
            std::size_t row_n = utils::Matrix::row_size(matriz1);
            std::size_t col_n = utils::Matrix::col_size(matriz1);
            std::vector<std::vector<T>> res(row_n, std::vector<T> (col_n));

            for(std::size_t i=0; i<matriz1.size();i++){
                for(std::size_t j=0; j<matriz1[0].size();j++){
                    res[i][j] = matriz1[i][j]+matriz2[i][j];
                }
            }

            return res;
        }

        //Substract matrix (m1,m2) R = m1-m2
        template <typename T> static std::optional<std::vector<std::vector<T>>> Substract(const std::vector<std::vector<T>>& matriz1,const std::vector<std::vector<T>>& matriz2 ){

            // Rebuild the validation pipeline with unit validations
            if(!utils::Matrix::is_same_size(matriz1, matriz2)){
                return std::nullopt;
            }
            std::size_t row_n = utils::Matrix::row_size(matriz1);
            std::size_t col_n = utils::Matrix::col_size(matriz1);
            std::vector<std::vector<T>> res(row_n, std::vector<T> (col_n));
            for(std::size_t i=0; i<matriz1.size();i++){
                for(std::size_t j=0; j<matriz1[0].size();j++){
                    res[i][j] = matriz1[i][j]-matriz2[i][j];
                }
            }

            return res;
        }
        template <typename T, typename S> static std::optional<std::vector<std::vector<T>>> ScalarMultiply(const std::vector<std::vector<T>>& m, S scalar){
            // Rebuild the validation pipeline with unit validations
            if(!utils::Matrix::is_not_empty(m)){
                return std::nullopt;
            }
            auto res = m;
            for(auto& row: res){
                for(auto& val:row){
                    val *= scalar;
                }
            }
            return res;
        }

        template <typename T> static std::optional<std::vector<std::vector<T>>> Transpose(const std::vector<std::vector<T>>& m){

            if(!utils::Matrix::is_not_empty(m)){
                return std::nullopt;
            }
            if(!utils::Matrix::is_uniform(m)){
                return std::nullopt;
            }
            std::size_t row_n = utils::Matrix::row_size(m);
            std::size_t col_n = utils::Matrix::col_size(m);

            std::vector<std::vector<T>> res (col_n, std::vector<T> (row_n));

            for(size_t i=0u; i<utils::Matrix::row_size(m); i++){
                for(size_t j=0u; j<utils::Matrix::col_size(m); j++){
                    res[j][i] = m[i][j];
                }
            }
            return res;
        }

        template <typename T> static std::optional<std::vector<std::vector<T>>> Multiply(const std::vector<std::vector<T>>& m1, const std::vector<std::vector<T>>& m2, MultMethod method = MultMethod::Naive ){
            if(!utils::Matrix::is_not_empty(m1) || !utils::Matrix::is_not_empty(m2)){
                return std::nullopt;
            }
            if(!utils::Matrix::is_uniform(m1) || !utils::Matrix::is_uniform(m2)){
                return std::nullopt;
            }


            std::size_t a = utils::Matrix::row_size(m1);
            std::size_t b = utils::Matrix::col_size(m2);
            std::size_t c = utils::Matrix::col_size(m1); // 👈 Dimensión interna compartida

            std::vector<std::vector<T>> res (a, std::vector<T> (b));
            switch (method) {

                case MultMethod::Auto:{
                    std::cout<<"OPCION AUTO\n";
                    return std::nullopt;
                    break;
                }
                case MultMethod::Naive:{
                    if(utils::Matrix::col_size(m1)!=utils::Matrix::row_size(m2)){
                        return std::nullopt;
                    }
                    for(size_t i=0u; i<a; i++){
                        for(size_t j=0u; j<b; j++){
                            for(size_t k=0u; k<c; k++ ){
                                res[i][j] += m1[i][k]*m2[k][j];
                            }

                        }
                    }
                    return res;
                    break;
                }
                case MultMethod::Blocked:{
                    //Tiling method
                    if(utils::Matrix::col_size(m1)!=utils::Matrix::row_size(m2)){
                        return std::nullopt;
                    }
                    const short BLOCK_SIZE = 8; // Find a way to calculate this number based on the processor cache size. Always Integer.

                    for(size_t out1=0u; out1<m1.size(); out1+BLOCK_SIZE){
                        for(size_t out2=0u; out2<m2.size(); out2+BLOCK_SIZE){

                        }
                    }
                    break;
                }
                case MultMethod::Strassen:{
                    return std::nullopt;
                    break;
                }
                case MultMethod::Hadamard:{
                    // Product Element-Wise: Easy implementation
                    if(m1.size()!= m2.size() || m1[0].size()!=m2[0].size()){
                        return std::nullopt;
                    }
                    std::size_t row_n = utils::Matrix::row_size(m1);
                    std::size_t col_n = utils::Matrix::col_size(m1);
                    std::vector<std::vector<T>> res (row_n, std::vector<T> (col_n));

                    for(size_t i=0u; i<row_n; i++){
                        for(size_t j=0u; j<col_n; j++){
                            res[i][j] = m1[i][j]*m2[i][j];
                        }
                    }

                    return res;
                    break;

                }

            }

        }
        template <typename T> static std::optional<std::vector<std::vector<T>>> Inverse(const std::vector<std::vector<T>>& m){

        }
        /* Return the Trace of a Matrix
         [ 5,  2,  1 ]   ->  (0,0) es 5
         [ 0, -3,  8 ]   ->  (1,1) es -3
         [ 4,  7,  9 ]   ->  (2,2) es 9

         Trace is: 5 + (-3) + 9 = 11.
         */
        template <typename T> static std::optional<T> Trace(const std::vector<std::vector<T>>& m){
            if(!utils::Matrix::is_square(m)){
                return std::nullopt;
            }
            T res = T{0};
            for(size_t i=0u; i<utils::Matrix::row_size(m); i++){
                res+=m[i][i];
            }
            return res;
        }
        template <typename T> static std::optional<std::vector<std::vector<T>>> LuSimplify(const std::vector<std::vector<T>>& m){

        }
        template <typename T> static std::vector<std::vector<float>> Determinant(const std::vector<std::vector<T>>& m){

        }
};
