//
// Created by user on 5/1/2022.
//

#include <cassert>
#include <iostream>
#include "Tests.h"
#include "../Domain/Product.h"
#include "../Repository/RepoInMemory.h"
#include "../Repository/RepoInFile.h"
#include "../Service/Service.h"
#include "../Domain/Coin.h"
#include "../Service/CoinService.h"

void Tests::testAll() {
    testDomain();
    testRepoInMemory();
    testRepoInFile();
    testService();
    testVerifyChange();
    testBuyProduct();
}
void Tests::testDomain() {
Product product;
assert(product.getName() == "");
assert(product.getCode() == 0);
assert(product.getPrice() == 0);

product.setName("Milka");
product.setCode(20);
product.setPrice(17.5);

assert(product.getName() == "Milka");
assert(product.getCode() == 20);
assert(product.getPrice() == 17.5);

Product product1(10, "7DAYS", 2.7, 30);
assert(product1.getName() == "7DAYS");
assert(product1.getCode() == 10);
assert(product1.getPrice() == 2.7);

}

void Tests::testRepoInMemory() {
    Product product(1, "Milka", 5, 10);
    Product product1(2, "7DAYS", 3, 10);
    Product product2(3, "CocaCola", 5.5, 10);
    RepoInMemory<Product> repo;

    assert(repo.getAll().size() == 0);

    repo.add(product);
    repo.add(product1);
    repo.add(product2);

    assert(repo.getAll().size() == 3);

    std::vector<Product> products = repo.getAll();

    assert(products[1].getCode() == 2);
    assert(products[1].getName() == "7DAYS");
    assert(products[1].getPrice() == 3);

    repo.update(2, product2);

    products = repo.getAll();

    assert(products[1].getCode() == 2);
    assert(products[1].getName() == "CocaCola");
    assert(products[1].getPrice() == 5.5);

    repo.remove(3);

    products = repo.getAll();
    assert(products.size() == 2);
    assert(products[0].getCode() == 1);
    assert(products[1].getCode() == 2);

}

void Tests::testRepoInFile() {
    RepoInFile<Product> repo("productTest.txt");

    Product product(1, "Milka", 5, 10);
    Product product1(2, "7DAYS", 3, 10);
    Product product2(3, "CocaCola", 5.5, 10);

    repo.add(product);
    repo.add(product1);
    repo.add(product2);

    assert(repo.getAll().size() == 3);

    std::vector<Product> products = repo.getAll();

    assert(products[1].getCode() == 2);
    assert(products[1].getName() == "7DAYS");
    assert(products[1].getPrice() == 3);

    repo.update(2, product2);

    products = repo.getAll();

    assert(products[1].getCode() == 2);
    assert(products[1].getName() == "CocaCola");
    assert(products[1].getPrice() == 5.5);

    repo.remove(3);

    products = repo.getAll();
    assert(products.size() == 2);
    assert(products[0].getCode() == 1);
    assert(products[1].getCode() == 2);

    repo.remove(2);
    repo.remove(1);


}

void Tests::testService() {
    RepoInFile<Product> repo("productTest.txt");

    Service service(repo);

    service.add(1, "Milka", 15, 10);
    service.add(3, "CocaCola", 7, 10);

    std::vector<Product> products = service.read();

    assert(products.size() == 2);


    service.update(1, "Boromir", 3, 15);
    products = service.read();

    assert(products[0].getCode() == 1);
    assert(products[0].getPrice() == 3);
    assert(products[0].getName() == "Boromir");

    service.remove(3);
    products = service.read();

    assert(products.size() == 1);

    repo.remove(1);



}

void Tests::testVerifyChange() {
    RepoInFile<Coin> repoCoin("coinTest.txt");

    CoinService coinService(repoCoin);

    coinService.add(0.1, 3);
    coinService.add(0.5, 10);
    coinService.add(1, 10);
    coinService.add(5, 1);
    coinService.add(10, 1);

    assert(coinService.verifyChange(1.5) == true);
    assert(coinService.verifyChange(5.5) == true);
    assert(coinService.verifyChange(50) == false);

    coinService.remove(0);
    coinService.remove(1);
    coinService.remove(2);
    coinService.remove(3);
    coinService.remove(4);


}

void Tests::testBuyProduct() {
    RepoInFile<Product> repo("productTest.txt");

    Service service(repo);

    service.add(1, "Milka", 15, 10);
    service.add(2, "CocaCola", 7, 10);

    std::vector<Product> products = service.read();
    assert(products[0].getStock() == 10);

    service.buyProduct(1);

    products = service.read();
    assert(products[0].getStock() == 9);

    service.remove(1);
    service.remove(2);



}
