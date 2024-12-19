#include "TXLib.h"

struct Button
{

    int x;
    int y;
    int w;
    int h;
    const char* text;

   void draw()
   {
     txSetColor (TX_WHITE, 3);
     txSetFillColor (TX_RED);
     Win32::RoundRect(txDC(), x, y, x+w, y+h, 30, 30);
     txSelectFont("Areal", 35);
     txDrawText(x, y, x+w, y+h, text);
    }

  bool click()
  {
   return (txMouseX()>x && txMouseX()<x+w && txMouseY()>y && txMouseY()<y+h && txMouseButtons() == 1);




  }
};

//!GetAsyncKeyState(VK_ESCAPE)
int main()
{
txCreateWindow (800, 600);
txTextCursor (false);

Button btn1 = {100, 100, 220, 150, "ÈÃÐÀÒÜ"};
Button btn2 = {100, 300, 220, 150, "ÂÛÕÎÄ"};
Button btn3 = {450, 100, 220, 150, "Î ÈÃÐÅ"};

    while(!btn2.click())
    {
     txSetFillColor (TX_BLACK);
     txClear();
     txBegin();

     btn1.draw();
     btn2.draw();
     btn3.draw();

     if(btn1.click())
     {
      txSetFillColor (TX_WHITE);
      txCircle(400, 300, 70);
     }

     if(btn2.click())
     {

      txDestroyWindow();
     }

     txEnd();
     txSleep(10);


    }

return 0;
}

