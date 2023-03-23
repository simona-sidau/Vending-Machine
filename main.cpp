#include "UI/Console.h"
#include "Repository/RepoInFile.h"
#include "Tests/Tests.h"
#include "Domain/Coin.h"
#include "Service/CoinService.h"

int main() {

    Tests test;
    RepoInFile<Product> repoInFile("products.txt");
    Service service(repoInFile);

    RepoInFile<Coin> Coinrepo("coins0.txt");
    CoinService coinService(Coinrepo);

    Console console(service, coinService);

    test.testAll();
    console.runMenu();
}
