#include <iostream>

bool firstPlayerField[10][10];
bool secundPlayerField[10][10];

void watterMakr() {
    std::cout << "══════════▄█▀▀▀▀▀▀█▄══▄▀▀▀▀▀▀▄ \n";
    std::cout << "════════▄▀░░░░░░▄▄▄▄▀█░░░░░░░░▀▄\n";
    std::cout << "═══════█░░░░░░▀▀░░░░▀▀█▄▀▀▀▀▀▀▀█▄\n";
    std::cout << "══════█░░░░░░░░▄▄████████▄░▄███████▄\n";
    std::cout << "═════▄▀░░░░░░░▀███████████▄██████████▄\n";
    std::cout << "════█▀░░░░░▄▀▀█▀░▄█▄███▄░▀█░▄█▄███░░░█\n";
    std::cout << "════█▀░░░░░▄▀▀█▀░▄█▄███▄░▀█░▄█▄███░░░█\n";
    std::cout << "═══█░░░░░░░▀▀█▀▀▄▄█████▄▄▀▀▄▄█████▀▀▀█\n";
    std::cout << "══█▀░░░░░░░░░░▀▄▄▄▄▄▄▄▄▄▄▀░░░░░░░░▄█▀\n";
    std::cout << "══█░░░░░░░░░░░░░░░░░░▄▀░░░░░░▀█▀▀▀█▄\n";
    std::cout << "══█░░░░░░░░░░░▄▄▄▄░░░░░░░░░░░░░░░░░█\n";
    std::cout << "█░░░░░░░░▄▀▀░▄▄░▀▀▀▀▀▄▄▄▄▄▄▄▀▀▀▀▀▀█\n";
    std::cout << "══▀█░░░░░█░▀▄▀▀░░▀▀▀▀▀▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    std::cout << "══▄█▄▄░░░▀▄░░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄▄▄▄▄▄▀\n";
    std::cout << "▄▀▀░▀██▄░░░▀▀░░░░░░░░░░░░░░▄▄▄▀▀\n";
    std::cout << "░░░░░░░░░░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀░░░▀█▄\n";
    std::cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█\n";
    return;
}

bool replase (bool field[][10], int size){


    int xBegin;
    int yBegin;
    std::cout <<"Enter coordinates your ship. Begin ship.\n";
    std::cin >> xBegin >> yBegin;
    int xEnd;
    int yEnd;

    if(size ==0){
        std::cout << "incorrect size, captain!\n";
        return false;
    }
    if(size> 1){
        std::cout << "Enter coordinates your ship. End ship.\n";
        std::cin >> xEnd >> yEnd;
    } else{
        xEnd = xBegin;
        yEnd =yBegin;
    }
    if(xEnd < xBegin){
        xBegin = xBegin + xEnd;
        xEnd = xBegin - xEnd;
        xBegin -=xEnd;
    }
    if(yEnd < yBegin){
        yBegin = yBegin + yEnd;
        yEnd = yBegin - yEnd;
        yBegin -=yEnd;
    }
    if(xBegin < 0 || xEnd> 9 || yBegin <0 || yEnd> 9){
        std::cout << "Captain, ship goes out of the field!\n";
        return false;
    }
    int rangeX = xBegin - xEnd;
    int rangeY = yBegin - yEnd;

    if(rangeX != 0) {
        if (rangeX + 1 != size) {
            std::cout << "Incorrect size, captain!" << size << std::endl;
            return false;
        }
        if (rangeY != 0) {
            std::cout << "Incorrect type coptain\n";
            return false;
        }

        int y = yBegin;
        for (int x = xBegin; x <= xEnd; ++x) {
            if (field[x][y]) {
                std::cout << "Attention collision\n";
                return false;

            }

        }
        for (int x = xBegin; x <= xEnd; ++x) {
            field[x][y] = true;
        }
    } else{
        if (rangeY + 1 != size) {
            std::cout << "Incorrect size, captain!" << size << std::endl;
            return false;
        }
        if (rangeX != 0) {
            std::cout << "Incorrect type coptain\n";
            return false;
        }

        int x = xBegin;
        for (int y = yBegin; x <= yEnd; ++x) {
            if (field[x][y]) {
                std::cout << "Attention collision\n";
                return false;

            }

        }
        for (int y = yBegin; x <= yEnd; ++x) {
            field[x][y] = true;
        }
    }
    return true;
}

void placeShip(bool field[][10]){
    for(int i = 0; i<4; ++i){
        std::cout << "Enter T1 ship\n";
        while (!replase(field, 1)){
            std::cout << "Please try agein, captain!\n";
        }
    }
    for(int i = 0; i<3; ++i){
        std::cout << "Enter T2 ship\n";
        while (!replase(field, 2)){
            std::cout << "Please try agein, captain!\n";
        }
    }
    for(int i = 0; i<2; ++i){
        std::cout << "Enter T3 ship\n";
        while (!replase(field, 3)){
            std::cout << "Please try agein, captain!\n";
        }
    }
    std::cout << "Enter T3 ship\n";
    while (!replase(field, 4)){
        std::cout << "Please try agein, captain!\n";
    }
}

bool hit(bool field[][10]) {
    int xHit;
    int yHit;
    std::cout << " Captain, enter coordinate to strike!\n";
    std::cin >> xHit >> yHit;
    if (xHit >=0 && xHit<10 &&yHit>=0 && yHit<10 && field[xHit][yHit] == true){
        std::cout << "Hit, Captain!\n";
        return true;
    } else{
        std::cout <<"Miss, captain!\n";
        return false;
    }
}

int main() {
    std::cout << "Player 1, prepare ships to battle!\n";
    placeShip(firstPlayerField);
    std::cout << "Player 2, prepare ships to battle!\n";
    placeShip(secundPlayerField);

    int firstFleetUnit = 18;
    int secundFleetUnit = 18;
    while (true){
        std::cout << "Player 1, attack!\ n";
        if(hit(secundPlayerField)){
            secundFleetUnit -= 1;
        }
        if(secundFleetUnit == 0){
            std::cout << "Captain! Your win!\n";
            watterMakr();
            break;
        }
        std::cout << "Player 2, attack!\ n";
        if(hit(firstPlayerField)){
            firstFleetUnit -= 1;
        }
        if(firstFleetUnit == 0){
            std::cout << "Captain! Your win!\n";
            watterMakr();
            break;
        }
    }

}