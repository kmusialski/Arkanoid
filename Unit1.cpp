#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTrudne *Trudne;

int x=-8;
int y=-8;
int a =-3;
int gracz = 0;
int wygrana = 10;

bool kolizja(TImage * pilka, TImage * cegla)
{
if(     pilka->Left >= cegla->Left-pilka->Width &&
        pilka->Left <= cegla->Left+pilka->Width &&
        pilka->Top >=cegla->Top-pilka->Height &&
        pilka->Top <= cegla->Top+cegla->Height)
        {
        return true;

        }
        else
        {
        return false;
        }
}

//---------------------------------------------------------------------------
__fastcall TTrudne::TTrudne(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TTrudne::TimerPTimer(TObject *Sender)
{
        B->Left+=x;
        B->Top+=y;

//odbijanie pilki

        if(B->Left - 5 <= Tlo ->Left) x = -x;

//odbijanie od gory

       // if(B->Top - 5 <= Tlo ->Top) y = -y;

//odbijanie od prawej

        if(B->Left + B->Width+5 >=Tlo->Width) x = -x;

//przegrana
        if(B->Top >= P->Top+ P -> Height + 15)  //jezeli gora pilki jest wyzej niz gora paletki + jej wysokosc to
        {
                TimerP ->Enabled = false;
                B->Visible = false;
                Button1->Caption = "Przegrana gracz 1";
                Button1->Visible=true;
                gracz =1;


        }
        if(B->Top+ B->Height <= P2->Top )
        {
                TimerP ->Enabled = false;
                B->Visible = false;
                Button1->Caption = "Przegrana gracz 2";
                Button1->Visible=true;
                gracz = 2;
        } // odbijanie od paletki
        else if(B->Left > P->Left-B->Width/2 && B->Left < P->Left+P->Width &&
        B->Top+B ->Height > P->Top)
        {
                if(y>0) y = -y;
                gracz = 1;
        }
        else if(B->Left >P2->Left-B->Width/2 && B->Left <P2->Left+P2->Width &&
        B->Top-5 <= P2->Top)
        {
        if(y<0) y=-y;
        gracz = 2;
        }
        if(wygrana <= 0)
        {
                TimerP->Enabled=false;
                B->Visible = false;
                if (gracz == 1)
                {
                 Button1->Caption="Wygral gracz 1" ;
                Button1->Visible = true;
                bean->Visible = true;
                }
                else
                {
                Button1->Caption="Wygral gracz 2";
                Button1->Visible = true;
                putin->Visible = true;
                }
        }
//blok1
        if(kolizja(B, Image1) && Image1->Visible==true)
{ x = -x; y = -y; Image1->Visible=false; wygrana--;P2->Width = 50;}
//blok2
        if(kolizja(B, Image2) && Image2->Visible==true)
{ x = -x; y = -y; Image2->Visible=false; wygrana--;}
//blok3
        if(kolizja(B, Image3) && Image3->Visible==true)
{ x = -x; y = -y; Image3->Visible=false; wygrana--;}
//blok4
        if(kolizja(B, Image4) && Image4->Visible==true)
{ x = -x; y = -y; Image4->Visible=false; wygrana--;}
//blok5
        if(kolizja(B, Image5) && Image5->Visible==true)
{ x = -x; y = -y; Image5->Visible=false; wygrana--;P->Width = 50;}
//blok6
        if(kolizja(B, Image6) && Image6->Visible==true)
{ x = -x; y = -y; Image6->Visible=false; wygrana--;TimerP->Interval = 5;}
//blok7
       if(kolizja(B, Image7) && Image7->Visible==true)
{ x = -x; y = -y; Image7->Visible=false; wygrana--;}
//blok8
        if(kolizja(B, Image8) && Image8->Visible==true)
{ x = -x; y = -y; Image8->Visible=false; wygrana--;}
//blok9
        if(kolizja(B, Image9) && Image9->Visible==true)
{ x = -x; y = -y; Image9->Visible=false; wygrana--;}
//blok10
        if(kolizja(B, Image10) && Image10->Visible==true)
{ x = -x; y = -y; Image10->Visible=false; wygrana--;}
 }
//---------------------------------------------------------------------------
void __fastcall TTrudne::LewoTimer(TObject *Sender)
{
if(P->Left > 10)P->Left -= 35;
}
//---------------------------------------------------------------------------
void __fastcall TTrudne::PrawoTimer(TObject *Sender)
{
if(P->Left+P->Width < Tlo-> Width - 10) P ->Left += 35;
}
//---------------------------------------------------------------------------
void __fastcall TTrudne::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if( Key == VK_LEFT) Lewo->Enabled=true;
 if (Key == VK_RIGHT) Prawo->Enabled=true;
 if (Key == 0x41 ) Lewo2->Enabled=true;
 if (Key == 0x44 ) Prawo2->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TTrudne::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if( Key == VK_LEFT) Lewo->Enabled=false;
    if (Key == VK_RIGHT) Prawo->Enabled=false;
     if (Key == 0x41 ) Lewo2->Enabled=false;
     if (Key == 0x44 ) Prawo2->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TTrudne::Lewo2Timer(TObject *Sender)
{
if(P2->Left > 10)P2->Left -= 35;
}
//---------------------------------------------------------------------------
void __fastcall TTrudne::Prawo2Timer(TObject *Sender)
{
if(P2->Left+P2->Width < Tlo-> Width - 10)
P2 ->Left += 35;
}
//----------------------------------------------------------------------------

void __fastcall TTrudne::Button1Click(TObject *Sender)
{
    B->Left = random(350);
    B->Top =random(350);
    B->Visible = true;

    x= (random(2)% 8) - 8;
    y = (random(2)% 8) - 8;
    TimerP->Enabled = true;
    wygrana = 10;
    Image1->Visible = true;     Image6->Visible = true;
    Image2->Visible = true;     Image7->Visible = true;
    Image3->Visible = true;     Image8->Visible = true;
    Image4->Visible = true;     Image9->Visible = true;
    Image5->Visible = true;     Image10->Visible = true;
    P2->Width = 100;
    P->Width = 100;
    TimerP->Interval = 20;
    Button1->Visible =false;
    putin->Visible =false;
    bean->Visible =false;

}
//---------------------------------------------------------------------------

void __fastcall TTrudne::TimerTimer(TObject *Sender)
{
          Image10->Left+=a;
          if(Image10->Left - 5 <= Tlo ->Left) a = -a;
          if(Image10->Left + B->Width+5 >=Tlo->Width) a = -a;

}
//---------------------------------------------------------------------------

