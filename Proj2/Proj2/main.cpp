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
const int Game::posY[] = { 30,26,22, 18, 14 };
//biến lựa chọn (có thể là menu hoặc di chuyển
char MOVING;
//khởi tạo class game
Game g;

void runGame()
{
    int flashing = 0;
    while (g.IS_RUNNING())
    {
        if (MOVING == 27)
            break;
        if (!g.getPeople()->isDead()) //Nếu người vẫn còn sống
        {
            if (MOVING != ' ')
                g.updatePosPeople(MOVING);//Cập nhật vị trí người theo thông tin từ main
            g.updatePosVehicle();//Cập nhật vị trí xe
            g.updatePosAnimal(); //Cập nhật vị trí 
            g.drawGame(MOVING, flashing);
            if (flashing == 60)
                flashing = 0;
        }
        // Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main


        MOVING = ' ';
        if (g.getPeople()->isImpact(g.getTrucks(), g.NumOfEnemy(), true) ||
            g.getPeople()->isImpact(g.getCars(), g.NumOfEnemy(), false) ||
            g.getPeople()->isImpact(g.getBirds(), g.NumOfEnemy(), true) ||
            g.getPeople()->isImpact(g.getDinausors(), g.NumOfEnemy(), false))
        {
            //đây chỉ là xử lý tạm thời, sẽ thêm hiệu ứng lúc thua ở đây
            g.getPeople()->dead();
            g.effectNextLevelDead();
            GotoXY(133, 30);
            cout << "DEAD";
        }
        if (g.getPeople()->isFinish()) {
            //đây chỉ là xử lý tạm thời, sẽ thêm hiệu ứng qua màn ở đây
            g.effectNextLevelDead();
            GotoXY(133, 30);
            cout << "PASS";
            Sleep(700);
            g.clearEffect();
            clearConsole(40,10);
            drawConsole(40, 10);
            g.resetGame(g.nextLevel());
            flashing = -1;
            MOVING = 'F';
        }
        flashing++;
        Sleep(100);

    }
}

/////////////////////////////////Ham tu them/////////////////////////////////////

void Loading()
{
    //SetConsoleCP(65001);
    //SetConsoleOutputCP(65001);
    //Loading game
    srand(NULL);
    GotoXY(73, 27);
    cout << "LOADING";


    int i = 10;
    GotoXY(43, i++);
    cout << " $$$$$$\\                                           $$\\";
    GotoXY(43, i++);
    cout << "$$  __$$\\                                         \\__ |";
    GotoXY(43, i++);
    cout << "$$ /  \\__|  $$$$$$\\   $$$$$$\\   $$$$$$$\\  $$$$$$$\\ $$\\   $$$$$$$\\    $$$$$$\\";
    GotoXY(43, i++);
    cout << "$$ |       $$  __$$\\ $$  __$$\\ $$  _____|$$  _____|$$ |  $$  __$$\\  $$  __$$\\";
    GotoXY(43, i++);
    cout << "$$ |       $$ |  \\__|$$ / $$ | \\$$$$$$\\  \\$$$$$$\\  $$ |  $$ |  $$ |  $$ / $$ |";
    GotoXY(43, i++);
    cout << "$$ |   $$\\ $$ |      $$ | $$ | \\____$$\\  \\____ $$\\ $$ |  $$ |  $$ |  $$ | $$ |";
    GotoXY(43, i++);
    cout << "\\$$$$$$  | $$ |      \\$$$$$$ | $$$$$$$ | $$$$$$$  |$$ |  $$ |  $$ | \\$$$$$$$ |";
    GotoXY(43, i++);
    cout << "\\______ / \\__|       \\______/ \\_______/ \\_______/ \\__|  \\__|  \\__ |  \\____$$ |";
    GotoXY(43, i++);
    cout << "                                                                    $$\\   $$ |";
    GotoXY(43, i++);
    cout << "                                                                    \\$$$$$$  |";
    GotoXY(43, i++);
    cout << "                                                                     \\______ /";


    GotoXY(45, 32);
    //cout << "│";
    cout << char(179);
    GotoXY(109, 32);
    //cout << "│";
    cout << char(179);
    GotoXY(46, 32);
    for (int i = 29; i < 92; i++) {
        int a = rand() % 50;
        Sleep(a);
        //cout << "█";
        cout << char(219);
    }
}

void textColor(int x)
{
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}

int menu() {
    system("cls");
    int Choose = 1;
    char press;
    do {
        switch (Choose)
        {
        case 1:
        {
            GotoXY(65, 15); textColor(228);
            cout << ">>    N_E_W   G_A_M_E    <<";
            GotoXY(65, 17); textColor(232);
            cout << "     L_O_A_D   G_A_M_E     ";
            GotoXY(65, 19); textColor(232);
            cout << "    R_A_N_K   B_O_A_R_D    ";
            GotoXY(65, 21); textColor(232);
            cout << "     I_N_T_R_O_D_U_C_E     ";
            GotoXY(65, 23); textColor(232);
            cout << "     E_X_I_T   G_A_M_E     ";
            break;
        }
        case 2:
        {
            GotoXY(65, 15); textColor(232);
            cout << "      N_E_W   G_A_M_E      ";
            GotoXY(65, 17); textColor(228);
            cout << ">>   L_O_A_D   G_A_M_E   <<";
            GotoXY(65, 19); textColor(232);
            cout << "    R_A_N_K   B_O_A_R_D    ";
            GotoXY(65, 21); textColor(232);
            cout << "     I_N_T_R_O_D_U_C_E     ";
            GotoXY(65, 23); textColor(232);
            cout << "     E_X_I_T   G_A_M_E     ";
            break;
        }
        case 3:
        {
            GotoXY(65, 15); textColor(232);
            cout << "      N_E_W   G_A_M_E      ";
            GotoXY(65, 17); textColor(232);
            cout << "     L_O_A_D   G_A_M_E     ";
            GotoXY(65, 19); textColor(228);
            cout << ">>  R_A_N_K   B_O_A_R_D  <<";
            GotoXY(65, 21); textColor(232);
            cout << "     I_N_T_R_O_D_U_C_E     ";
            GotoXY(65, 23); textColor(232);
            cout << "     E_X_I_T   G_A_M_E     ";
            break;
        }
        case 4:
        {
            GotoXY(65, 15); textColor(232);
            cout << "      N_E_W   G_A_M_E      ";
            GotoXY(65, 17); textColor(232);
            cout << "     L_O_A_D   G_A_M_E     ";
            GotoXY(65, 19); textColor(232);
            cout << "    R_A_N_K   B_O_A_R_D    ";
            GotoXY(65, 21); textColor(228);
            cout << ">>   I_N_T_R_O_D_U_C_E   <<";
            GotoXY(65, 23); textColor(232);
            cout << "     E_X_I_T   G_A_M_E     ";
            break;
        }
        case 5:
        {
            GotoXY(65, 15); textColor(232);
            cout << "      N_E_W   G_A_M_E      ";
            GotoXY(65, 17); textColor(232);
            cout << "     L_O_A_D   G_A_M_E     ";
            GotoXY(65, 19); textColor(232);
            cout << "    R_A_N_K   B_O_A_R_D    ";
            GotoXY(65, 21); textColor(232);
            cout << "     I_N_T_R_O_D_U_C_E     ";
            GotoXY(65, 23); textColor(228);
            cout << ">>   E_X_I_T   G_A_M_E   <<";
            break;
        }
        }
        press = toupper(_getch());
        if (press == 'W' || press == 72)
        {
            if (Choose != 1) Choose--;
        }
        else if (press == 'S' || press == 80)
        {
            if (Choose != 5) Choose++;
        }
    } while (press != 13);
    system("cls");
    system("color e4");
    return Choose;
}

void PauseGame(HANDLE t)
{
    SuspendThread(t);
}

/////////////////////////////////Ham tu them/////////////////////////////////////

int main()
{
    system("color e4");
    //setup khung
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1290, 690, TRUE);
    FixConsoleWindow();
    DisableResizeWindow();
    Nocursortype();
    ShowScrollbar(0);

    Loading();  //ms them
    system("cls");//ms them
    int choose = menu();//ms them
    int temp;//ms them
    bool pause = false;
    bool run = true;
    thread t1(runGame);
    g.pauseGame(t1.native_handle());

    while (1)
    {
        if (choose == 1)
        {

            //vẽ khung trò chơi và menu

            drawConsole(40, 10);
            //Tọa độ khung menu:
            //Menu Trái: 3, 13
            //Menu phải: 40, 13
            //Chiều ngang: 30

            drawMenu(120, 13);

            GotoXY(70, 3);
            cout << "CROSSING STREET";
            GotoXY(16, 14);
            cout << "MENU";
            GotoXY(10, 16);
            cout << "N : New Game";
            GotoXY(10, 18);
            cout << "P : Pause/Resume Game ";
            GotoXY(10, 20);
            cout << "T : Save Game";
            GotoXY(10, 22);
            cout << "L : Load Game";
            GotoXY(10, 24);
            cout << "G : Setting";
            GotoXY(121, 14);
            cout << "Score";
            GotoXY(121, 22);
            cout << "Level";
            GotoXY(136, 22);
            cout << "High Score";

            //bắt đầu game
            g.startGame();
            run = true;
            //thread t1(runGame);
            //HANDLE handle_t1 = t1.native_handle();


            //reset game sẽ được dùng lại mỗi khi new game hoặc mở load game,
            //số xe, thú tăng theo lv mà người đang chơi, ở đây là 1 nên có 2 xe, thú
            //công thức thì xem kỹ hơn ở trong hàm
            g.resetGame(1);
            MOVING = 'I';
            g.updateScore();
            g.getPeople()->setPos();
            g.resumeGame(t1.native_handle());
            while (run)
            {
                MOVING = toupper(_getch());
                //thêm các menu ở đây
                //tài liệu đồ án thầy có cho 1 số gợi ý về menu
                //để dễ làm nên tui xóa thêm rồi
                //menu: load, save, pause game hay gì đó sẽ thêm ở đây
                //if (STATE == 1) {
                if (MOVING == 27) {
                    g.pauseGame(t1.native_handle());
                    choose = menu();
                    run = false;
                    MOVING = ' ';
                }
                else if (MOVING == 'N') {
                    g.clearEffect();
                    g.pauseGame(t1.native_handle());
                    clearConsole(40, 10);
                    drawConsole(40, 10);
                    g.resetGame(1);
                    g.resumeGame(t1.native_handle());
                    g.updateScore();
                }
                else if (MOVING == 'P') {
                    if (!pause)
                    {
                        pause = true;
                        g.pauseGame(t1.native_handle());
                    }
                    else
                    {
                        pause = false;
                        g.resumeGame(t1.native_handle());
                    }
                }
                else if (MOVING == 'T') {
                    //save game
                    g.pauseGame(t1.native_handle());
                    string s;
                    GotoXY(2, 30);
                    cout << "Input name of file (require .txt):";
                    GotoXY(5, 31);
                    cout << (char)219;
                    GotoXY(5, 31);
                    cin >> s;
                    g.saveGame(s);
                    g.resumeGame(t1.native_handle());
                }
                else if (MOVING == 'L') {
                    g.pauseGame(t1.native_handle());
                    string s;
                    GotoXY(2, 30);
                    cout << "Input name of file (require .txt):";
                    GotoXY(5, 31);
                    cout << (char)219;
                    GotoXY(5, 31);
                    cin >> s;
                    clearConsole(40, 10);
                    drawConsole(40, 10);
                    g.loadGame(s);
                    g.resumeGame(t1.native_handle());
                }
                else if (MOVING == 'G') {
                    //setting
                }
            }
        }
    }

}