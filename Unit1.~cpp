//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

  int ktory=1;
  bool gra_rozpoczeta=false;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(gra_rozpoczeta){
     if(Key=='D' || Key=='d' || Key==VK_RIGHT) Prawo->Enabled=true;
     if(Key=='A' || Key=='a' || Key==VK_LEFT) Lewo->Enabled=true;
     if(Key==VK_SPACE) sndPlaySound("snd/strzal.wav",SND_ASYNC);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(gra_rozpoczeta){
     if(Key=='D' || Key=='d' || Key==VK_RIGHT) Prawo->Enabled=false;
     if(Key=='A' || Key=='a' || Key==VK_LEFT) Lewo->Enabled=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LewoTimer(TObject *Sender)
{
   if(statek->Left > -10) statek->Left-=10;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PrawoTimer(TObject *Sender)
{
   if(statek->Left+statek->Width < Form1->Width-10) statek->Left+=10;     
}
//---------------------------------------------------------------------------

void __fastcall TForm1::statek_animacjaTimer(TObject *Sender)
{
   switch(ktory){
    case 1:
    statek->Picture->LoadFromFile("img/statek1.bmp"); ktory=2;
    break;

    case 2:
    statek->Picture->LoadFromFile("img/statek2.bmp"); ktory=3;
    break;

    case 3:
    statek->Picture->LoadFromFile("img/statek3.bmp"); ktory=1;
    break;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::startClick(TObject *Sender)
{
   gra_rozpoczeta=true;
   tytul->Visible=false;
   start->Visible=false; high_score->Visible=false; dadada->Visible=false;
   tlo->Visible=true; tlo_tytul->Visible=false;
   statek->Visible=true;
}
//---------------------------------------------------------------------------

