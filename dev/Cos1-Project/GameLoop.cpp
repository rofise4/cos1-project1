#include "Game.h"
#include <Windows.h>
#include "Drafting.h"

bool game::initializeMouse(HANDLE hInput)
{
    //DWORD is unsigned 32 bit type for storing modes, this is to initialize mode in that type
    DWORD mode;

    //read the mode settings &mode and check to make sure its a non zero
    if (!GetConsoleMode(hInput, &mode))
    {
        //if cannot read console settings immediately fails command
        return false;
    }
    //enables mouse input events, enables extended console setting input modes needed for quick edit |= switches flags on and | combines them
    mode |= ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;
    //disables quick edit with not opporator
    mode &= ~ENABLE_QUICK_EDIT_MODE;
    //set the console modes, then check to make sure the returning value is a non zero
    return SetConsoleMode(hInput, mode) != 0;
}
COORD game::getClicks(HANDLE hInput)
{
    //input record is storing what input takes place, key stroke, mouse click, position etc. its saving it to a variable called input.
    INPUT_RECORD input;
    //storing number of events as variable events, which is needed with the api functions below
    DWORD events;
    //creating a loop that will run input checking until it gets a mouse click with coordinates that satisfy as being within the game board.
    bool clicked = false;
    //starting invalid coordinates for use in determing if valid click will be within grid later to change state of clicked
    COORD selected = { -1,-1 };
    while (!clicked)
    {
        //error handling, readconsole input is taking the hInput stream and saving the input to &input, its requesting 1 input and saving the number recorded to &events
        bool success = ReadConsoleInput(hInput, &input, 1, &events);

        if (success == false)
        {
            //providing a failsafe for input errors outside of out of bound clicks
            return { -1, -1 };
        }
        //if input got stored an event == to a mouse event, comparison statment
        if (input.EventType == MOUSE_EVENT)
        {
            //record mouse event to mouse through the input of mouse event
            MOUSE_EVENT_RECORD mouse = input.Event.MouseEvent;
            //dweventflags == 0 confirms its a mouse click and not scrolling
            //dwbuttonstate checks the type of button press and from left 1st is using bitwise and to makesure its a left click
            if (mouse.dwEventFlags == 0 && (mouse.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED))
            {
                //saving mouse position x and y to integers for doing math to calculate where on the board it falls.
                //side note ive typed mouse so many times its starting to look like moose to me. could be the late night side effect.
                int mouseX = mouse.dwMousePosition.X;
                int mouseY = mouse.dwMousePosition.Y;
                //board is 5x5 each tile is 5 wide and 3 tall, the display off sets x + 15, y + 4. This is checking to see if the coordinates are outside of the board.
                if (mouseX < 15 || mouseX >= 40 || mouseY < 4 || mouseY >= 19)
                {
                    //outof bounds confirmed skip the loop and restart
                    continue;
                }
                //reversing the math on the column display of (x * 5) + 15 and (y * 3) + 4 and saving to the coordinate variable selected
                selected.X = (mouseX - 15) / 5;
                selected.Y = (mouseY - 4) / 3;
                //setting clicked to true to end the loop
                clicked = true;
            }
        }
    }
    //returning the coordinates of selected
    return selected;
}

void game::run()
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    initializeMouse(hInput);
    bool gameRunning = true;
    Drafting drafting;
    drafting.resetDraftV();
    drafting.startDraft();
    drafting.resetConsole();
    setPosition(0, 22);
    std::cout << "P1 purchased " << "\n";
    for (int piece : drafting.getP1Pieces())
    {
        std::cout << piece << " ";
    }
    std::cout << "\n";
    std::cout << "P2 purchased " << "\n";
    for (int piece : drafting.getP2Pieces())
    {
        std::cout << piece << " ";
    }
    std::cout << "\n";
    drafting.displayBudget();
    Sleep(10000);
    drafting.resetConsole();
    setupPieces();

    while (gameRunning)
    {
        gameRunning = Turn();

    }
    // Sleep(1000);
     //board1.placeP(&pl2p1, 1, 5);
     //pl2p1.Isp2(true);
     //board1.placeP(&pl1p5, 3, 5);
     //Sleep(1000);
     //pl1p3.getmovesp1(board1);
     //Sleep(1000);
     //board1.DrawBoard();
     //Sleep(1000);
     //board1.resetOccupied();
     //board1.DrawBoard();
     //Sleep(1000);
     //p1r1.getmovesp1(board1);
     //board1.DrawBoard();
     //Sleep(1000);
     //board1.resetOccupied();
     //board1.DrawBoard();
     //Sleep(1000);
     //board1.placeP(&p1r1, 4, 4);
     //board1.DrawBoard();
     //Sleep(1000);
     //p1r1.getmovesp1(board1);
     //board1.DrawBoard();
     //Sleep(1000);
     //board1.resetOccupied();
     //board1.placeP(&p1kn1, 5, 3);
     //p1kn1.getmovesp1(board1);
     //board1.DrawBoard();


}