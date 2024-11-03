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
   tytul->Top=900; tytul->Left=152;
   tytul_wjazd->Enabled = true;

}
//---------------------------------------------------------------------------
__fastcall TForm1::~TForm1()
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
   start->Visible=false; high_score->Visible=false; label_high_score->Visible=false;
   tlo_tytul->Visible=false;

   tlo->Visible=true;
   score->Visible=true;
   statek->Visible=true;
   zycie1->Visible=true; zycie2->Visible=true; zycie3->Visible=true;

   //pojawianie sie niebieskich wrogow
   //1-2
   lvl1_niebieski1->Visible=true; lvl1_niebieski1->Left=55; lvl1_niebieski1->Top=-100;
   lvl1_niebieski2->Visible=true; lvl1_niebieski2->Left=115; lvl1_niebieski2->Top=-100;
   //3-4
   lvl1_niebieski3->Visible=true; lvl1_niebieski3->Left=175; lvl1_niebieski3->Top=-100;
   lvl1_niebieski4->Visible=true; lvl1_niebieski4->Left=235; lvl1_niebieski4->Top=-100;
   //5-6
   lvl1_niebieski5->Visible=true; lvl1_niebieski5->Left=295; lvl1_niebieski5->Top=-100;
   lvl1_niebieski6->Visible=true; lvl1_niebieski6->Left=355; lvl1_niebieski6->Top=-100;
   //7-8
   lvl1_niebieski7->Visible=true; lvl1_niebieski7->Left=415; lvl1_niebieski7->Top=-100;
   lvl1_niebieski8->Visible=true; lvl1_niebieski8->Left=475; lvl1_niebieski8->Top=-100;
   //9-10
   lvl1_niebieski9->Visible=true; lvl1_niebieski9->Left=535; lvl1_niebieski9->Top=-100;
   lvl1_niebieski10->Visible=true; lvl1_niebieski10->Left=595; lvl1_niebieski10->Top=-100;
   //11-12
   lvl1_niebieski11->Visible=true; lvl1_niebieski11->Left=655; lvl1_niebieski11->Top=-100;
   lvl1_niebieski12->Visible=true; lvl1_niebieski12->Left=715; lvl1_niebieski12->Top=-100;

   //przylatywanie wrogow
   lvl1->Enabled=true;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::tytul_wjazdTimer(TObject *Sender)
{
   if(tytul->Top >= 78) tytul->Top-=15;
   else if(tytul->Top <= 78) {
     high_score->Visible=true; label_high_score->Visible=true;
     tytul_wyjazd_czekaj->Enabled=true;
     tytul_wjazd->Enabled=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::tytul_wyjazd_czekajTimer(TObject *Sender)
{
   start->Visible=true;
   tytul_wyjazd_czekaj->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lvl1Timer(TObject *Sender)
{
   if(lvl1_niebieski1->Top <= 150){
     lvl1_niebieski1->Top+=15;
     lvl1_niebieski2->Top+=15;
     lvl1_niebieski3->Top+=15;
     lvl1_niebieski4->Top+=15;
     lvl1_niebieski5->Top+=15;
     lvl1_niebieski6->Top+=15;
     lvl1_niebieski7->Top+=15;
     lvl1_niebieski8->Top+=15;
     lvl1_niebieski9->Top+=15;
     lvl1_niebieski10->Top+=15;
     lvl1_niebieski11->Top+=15;
     lvl1_niebieski12->Top+=15;
   } else if(lvl1_niebieski1->Top >= 150) lvl1->Enabled=false;
}
//---------------------------------------------------------------------------

