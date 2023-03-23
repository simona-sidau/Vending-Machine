#ifndef LAB910_CONSOLE_H
#define LAB910_CONSOLE_H


#include "../Service/Service.h"
#include "../Service/CoinService.h"
#include "../Domain/Validator.h"

class Console {
private:
    Service service;
    CoinService coinService;
public:
    Console(Service &service, CoinService &coinService);
    ~Console() = default;
    void showAdminMenu();
    void showUserMenu();
    void showMainMenu();
    void runMenu();

};


#endif //LAB910_CONSOLE_H
