#include "MainHeader.h"

const char Truck::form[][12] = {
        {255, '_','_','_','_','_','_','_','_','_','_',255},
        {'|','|', '_','|',255,'|', '_','|',255,'|', '_','\\'},
        {'|','_', '(','-',')','_', '_','(','-',')', '_','/'},
};
const char Car::form[][12] = {
    {' ', ' ', ' ','_','_','_','_','_', '_','_','_', 255},
    {255, '_','/',' ','/','_','|','|','_','|',' ','\\'},
    {'|','_','(','-',')','_','_','(','-',')','_','/'},
};
const char Bird::form[][5] = {
    {254,254,' ',254,254},
    {255,' ',223,' ',255},
    {255,255,255,255,255},
};
const char Dinausor::form[][5] = {
    {' ',' ',' ',' ',254},
    {219,219,219,219, 255},
    {'/','/',' ','/','/'},
};
const char People::form[][3] = {
    {' ', 234,' '},
    {'/',186,'\\'},
    {'/',' ','\\'},
};
const int Game::posY[] = { 34,30,26,22, 18, 14, 10, 6 };
char MOVING;
bool justWinOrDead = false, soundOn = true;
int menuChoice = 0, setLevel = 1;
Game g(1);
bool IS_RUNNING = 1;
void runGame()
{
    while (IS_RUNNING) {
        //if (!g.getPeople().isDead()) //Nếu người vẫn còn sống
        //{
        //    g.updatePosPeople(MOVING);//Cập nhật vị trí người theo thông tin từ main
        //}
        g.updatePosPeople(MOVING);
        // Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main

        g.updatePosVehicle();//Cập nhật vị trí xe
        g.updatePosAnimal(); //Cập nhật vị trí thú
        g.drawGame(MOVING);
        MOVING = ' ';
        //if (g.getPeople().isImpact(g.getVehicle() ||
        //    g.getPeople().isImpact(g.getAnimal())))
        //{
        //    // Xử lý khi đụng xe hay thú
        //}
        //if (g.getPeople().isFinish()) {
        //    // Xử lý khi về đích

        //}
        Sleep(10);

    }
}
int main()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1290, 690, TRUE);
    FixConsoleWindow();
    DisableResizeWindow();
    ShowScrollbar(0);
    Nocursortype();
    drawConsole(2, 2);
    drawMenu(120, 1);

    g.startGame();
    thread t1(runGame);
    g.resetGame(1);
    while (1)
    {
        MOVING = toupper(_getch());
        
    }
}