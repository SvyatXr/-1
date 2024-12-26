#include "TXLib.h"

struct Button
{

    int x;
    int y;
    int w;
    int h;
    const char* text;
    bool visible;

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
   return (txMouseX()>x && txMouseX()<x+w && txMouseY()>y && txMouseY()<y+h && txMouseButtons() == 1 && visible);




  }
};

//!GetAsyncKeyState(VK_ESCAPE)
int main()
{
txCreateWindow (1370, 710);
txTextCursor (false);

string PAGE = "menu";

Button btn1 = {200, 100, 220, 150, "������", true};
Button btn2 = {200, 300, 220, 150, "�����", true};
Button btn3 = {750, 100, 220, 150, "� ����", true};
Button btn4 = {750, 300, 220, 150, "���������", true};

    while(!btn2.click())
    {
     txClear();
     txBegin();

    if(PAGE == "menu")
    {

        btn1.draw();
        btn2.draw();
        btn3.draw();
        btn4.draw();

        btn1.visible = true;
        btn2.visible = true;
        btn3.visible = true;
        btn4.visible = true;

        if(btn1.click())
        {
         PAGE="������";
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }

        if(btn3.click())
        {
         PAGE="� ����";
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }
        if(btn4.click())
        {
         PAGE="���������";
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }
     txSetFillColor (TX_BLACK);

    }


     if(PAGE == "���������")
     {
      txSetFillColor(TX_BLACK);
      txTextOut(600, 20, "���������");
      if(GetAsyncKeyState(VK_ESCAPE))
      {
       PAGE="menu";
      }
      txSetFillColor (TX_LIGHTBLUE);

     }

     if(PAGE == "� ����")
     {
      txSetFillColor(TX_BLACK);
      txTextOut(600, 20, "O ����");
      if(GetAsyncKeyState(VK_ESCAPE))
      {
       PAGE="menu";
      }
      txSetFillColor (TX_LIGHTGREEN);
     }

     if(PAGE == "������")
     {
      txSetFillColor(TX_BLACK);
      txTextOut(600, 20, "��������...");
      if(GetAsyncKeyState(VK_ESCAPE))
      {
       PAGE="menu";
      }
      txSetFillColor (TX_YELLOW);
     }





     txEnd();
     txSleep(10);


    }
txDisableAutoPause();
return 0;
}

