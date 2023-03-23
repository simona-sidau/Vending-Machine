 cmake_minimum_required(VERSION 3.21)
project(lab910)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab910 main.cpp Domain/Product.cpp Domain/Product.h Repository/IRepo.h Repository/RepoInMemory.h Service/Service.cpp Service/Service.h Repository/RepoInFile.h UI/Console.cpp UI/Console.h Tests/Tests.cpp Tests/Tests.h Domain/Coin.cpp Domain/Coin.h Service/CoinService.cpp Service/CoinService.h Domain/Validator.cpp Domain/Validator.h Repository/RepositoryException.cpp Repository/RepositoryException.h)
