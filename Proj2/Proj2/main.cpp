#include "Animal.h"
#include "People.h"
#include "Vehicle.h"
#include "MainHeader.h"
#include "Truck.h"
#include "Car.h"
#include "Bird.h"
#include "Dinausor.h"
#include "Game.h"

//Hình vẽ xe hơi
const char Car::form[][6] = {
        {255, '_','_','_','_',255},
        {'|','|', '_','|','_','\\'},
        {192,'O',196, 'O', 196, 217},
};
//Hình vẽ xe tải
const char Truck::form[][5] = {
    {255,255,255,220,255},
    {220,219,219,219,219},
    {255,'O',255,'O',255}
};
//Hình vẽ chim
const char Bird::form[][3] = {
    {254,' ',254},
    {' ',223,' '},
};
//Hình vẽ thú
const char Dinausor::form[][5] = {
    {' ',' ',' ',' ',254},
    {219,219,219,219, 255},
    {'/','/',' ','/','/'},
};
//Hình vẽ người
const char People::form[][3] = {
    {' ', 234,' '},
    {'/',186,'\\'},
    {'/',' ','\\'},
};
//Vị trí các đường kẻ trong game
//khoảng cách giữa các đường kẻ ngang là 4, dọc là 70
const int Game::posY[] = { 30,26,22, 18, 14};
//biến lựa chọn (có thể là menu hoặc di chuyển
char MOVING;
//khởi tạo class game
Game g(1);

void runGame()
{
    while (g.IS_RUNNING())
    {
        if (!g.getPeople()->isDead()) //Nếu người vẫn còn sống
        {
            if (MOVING != ' ')
                g.updatePosPeople(MOVING);//Cập nhật vị trí người theo thông tin từ main
        }
        // Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main

        g.updatePosVehicle();//Cập nhật vị trí xe
        g.updatePosAnimal(); //Cập nhật vị trí thú
        g.drawGame(MOVING);
        MOVING = ' ';
        if (g.getPeople()->isImpact(g.getTrucks(), g.NumOfEnemy(), true) ||
            g.getPeople()->isImpact(g.getCars(), g.NumOfEnemy(), false) ||
            g.getPeople()->isImpact(g.getBirds(), g.NumOfEnemy(), true) ||
            g.getPeople()->isImpact(g.getDinausors(), g.NumOfEnemy(), false))
        {
            //đây chỉ là xử lý tạm thời, sẽ thêm hiệu ứng lúc thua ở đây
            GotoXY(LEFT + (RIGHT - LEFT) / 2, TOP);
            cout << "Dead";
        }
        if (g.getPeople()->isFinish()) {
            //đây chỉ là xử lý tạm thời, sẽ thêm hiệu ứng qua màn ở đây
            GotoXY(LEFT + (RIGHT - LEFT) / 2, TOP);
            cout << "Finish";
        }
        Sleep(100);

    }
}
int main()
{
    //setup khung
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1290, 690, TRUE);
    FixConsoleWindow();
    DisableResizeWindow();
    ShowScrollbar(0);
    Nocursortype();
    //vẽ menu trước khi vào game (hiện tại là chưa làm)
    // ....


    //vẽ khung trò chơi và menu
    drawConsole(40, 10);
    //Tọa độ khung menu:
    //Menu Trái: 3, 13
    //Menu phải: 40, 13
    //Chiều ngang: 30

    drawMenu(120, 13);

    GotoXY(70, 3);
    cout << "CROSSING STREET";
    GotoXY(4, 14);
    cout << "Menu: load, save...";
    GotoXY(121, 14);
    cout << "Score";
    GotoXY(121, 22);
    cout << "Level";
    GotoXY(136, 22);
    cout << "High Score";

    //bắt đầu game
    g.startGame();
    thread t1(runGame);
    //reset game sẽ được dùng lại mỗi khi new game hoặc mở load game,
    //số xe, thú tăng theo lv mà người đang chơi, ở đây là 1 nên có 2 xe, thú
    //công thức thì xem kỹ hơn ở trong hàm
    g.resetGame(1);
    while (1)
    {
        MOVING = toupper(_getch());
        //thêm các menu ở đây
        //tài liệu đồ án thầy có cho 1 số gợi ý về menu
        //để dễ làm nên tui xóa thêm rồi
        //menu: load, save, pause game hay gì đó sẽ thêm ở đây
    }
}