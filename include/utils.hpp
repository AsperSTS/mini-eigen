#pragma once
#include <cstddef>
#include<iostream>
#include <random>
#include<vector>
#include<type_traits>

namespace utils{

    class Matrix{
        public:
            // DEPRECATED

            // Get the row size
            template <typename T> static std::size_t row_size(const std::vector<std::vector<T>>& m){
                // On stand by: Validate if is not empty
                return m.size();
            }
            // Get the col[0] size
            template <typename T> static std::size_t col_size(const std::vector<std::vector<T>>& m){
                // On stand by: Validate if is not empty
                if(!is_not_empty(m)){
                    return 0;
                }
                return m[0].size();
            }

            // True if the matrix is not empty, false otherwise
            template <typename T> static bool is_not_empty(const std::vector<std::vector<T>>& m){
                if(m.empty()){
                    return false;
                }
                if(m[0].empty()){
                    return false;
                }
                return true;
            }

            // True if the matrix is uniform
            template <typename T> static bool is_uniform(const std::vector<std::vector<T>>& m){
                if (!is_not_empty(m)) {
                        return false;
                    }
                for(size_t i=1u; i<m.size(); i++){
                    if(m[0].size()!=m[i].size()){
                        return false;
                    }
                }
                return true;
            }
            // Validate if the matrix is square or not
            template <typename T> static bool is_square(const std::vector<std::vector<T>>& m){
                if(!is_not_empty(m)){
                    return false;
                }
                if(!is_uniform(m)){
                    return false;
                }
                return row_size(m) == col_size(m);
            }

            // Validate the size of two matrix; Asume the same size for each column as the column[0]
            template <typename T> static bool is_same_size(const std::vector<std::vector<T>>& m1, const std::vector<std::vector<T>>& m2){
                if(!is_not_empty(m1) || !is_not_empty(m2)){
                    return false; //Check here if its possible to return void or something to let the other side to know the validations failed
                }
                if(row_size(m1)!=row_size(m2) || col_size(m1)!=col_size(m2)){
                    return false;
                }
                return true;
            }

            template <typename T> static std::vector<std::vector<T>> gen_random_matrix(std::size_t row_n, std::size_t col_n){
                std::vector<std::vector<T>> res(row_n, std::vector<T> (col_n));
                std::mt19937 rng(std::random_device{}());

                if constexpr(std::is_floating_point_v<T>){
                    std::uniform_real_distribution<T> dist(0.0f, 2.0f);
                    for(auto& row:res){
                        for(auto&& val:row){
                            val = dist(rng);
                        }
                    }
                } else if constexpr (std::is_integral_v<T> && !std::is_same_v<T, bool>) {
                    std::uniform_int_distribution<T> dist(1,10);
                    for(auto& row:res){
                        for(auto&& val:row){
                            val = dist(rng);
                        }
                    }
                } else if constexpr(std::is_same_v<T, bool>){
                    // The weight of the bernoulli param means 60% chance or whatever the value is, to get true as res
                    std::bernoulli_distribution dist(0.6);
                    for(auto& row:res){
                        for(auto&& val:row){
                            val = dist(rng);
                        }
                    }
                }
                return res;
            }
    };

    class IO{
        public:
            template <typename T> static void print2dMatrix(const std::vector<std::vector <T>>& m1){
                if(!Matrix::is_not_empty(m1)){
                    std::cout<<"The matrix is empty\n";
                    return;
                }
                for(auto&& row: m1){
                    std::cout<<"[";
                    bool first = true;
                    for(auto&& val: row){
                        if(!first){
                            std::cout<<", ";
                        }
                        std::cout<<val;
                        first = false;
                    }
                    std::cout<<"]\n";
                }
                std::cout<<"\n";
            }
    };
}
