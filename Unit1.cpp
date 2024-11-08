//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
   tytul->Top=900; tytul->Left=152;
   ktory_statek=1; ktory_wrog=true; gra_rozpoczeta=false;
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
     if(Key==VK_SPACE){
       if(ktory_strzal==1){
         sndPlaySound("snd/strzal.wav",SND_ASYNC);
         ktory_strzal++;
         strzal1->Top = statek->Top+28; strzal1->Left = statek->Left+17;
         strzal1->Visible=true;
         strzal1_lot->Enabled=true;
       }
       else if(ktory_strzal==2){
         sndPlaySound("snd/strzal.wav",SND_ASYNC);
         ktory_strzal++;
         strzal2->Top = statek->Top+28; strzal2->Left = statek->Left+53;
         strzal2->Visible=true;
         strzal2_lot->Enabled=true;
       }
       else if(ktory_strzal==3){
         sndPlaySound("snd/strzal.wav",SND_ASYNC);
         ktory_strzal++;
         strzal3->Top = statek->Top+28; strzal3->Left = statek->Left+17;
         strzal3->Visible=true;
         strzal3_lot->Enabled=true;
       }
       else if(ktory_strzal==4){
         sndPlaySound("snd/strzal.wav",SND_ASYNC);
         ktory_strzal++;
         strzal4->Top = statek->Top+28; strzal4->Left = statek->Left+53;
         strzal4->Visible=true;
         strzal4_lot->Enabled=true;
       }
       else if(ktory_strzal==5){
         sndPlaySound("snd/strzal.wav",SND_ASYNC);
         ktory_strzal++;
         strzal5->Top = statek->Top+28; strzal5->Left = statek->Left+17;
         strzal5->Visible=true;
         strzal5_lot->Enabled=true;
       }
       else if(ktory_strzal==6){
         sndPlaySound("snd/strzal.wav",SND_ASYNC);
         ktory_strzal++;
         strzal6->Top = statek->Top+28; strzal6->Left = statek->Left+53;
         strzal6->Visible=true;
         strzal6_lot->Enabled=true;
       }
     }
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
   switch(ktory_statek){
    case 1:
    statek->Picture->LoadFromFile("img/statek1.bmp"); ktory_statek=2;
    break;

    case 2:
    statek->Picture->LoadFromFile("img/statek2.bmp"); ktory_statek=3;
    break;

    case 3:
    statek->Picture->LoadFromFile("img/statek3.bmp"); ktory_statek=1;
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
   statek_animacja->Enabled=true;
   ktory_strzal=1;
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
     lvl1_niebieski1->Top+=10;
     lvl1_niebieski2->Top+=10;
     lvl1_niebieski3->Top+=10;
     lvl1_niebieski4->Top+=10;
     lvl1_niebieski5->Top+=10;
     lvl1_niebieski6->Top+=10;
     lvl1_niebieski7->Top+=10;
     lvl1_niebieski8->Top+=10;
     lvl1_niebieski9->Top+=10;
     lvl1_niebieski10->Top+=10;
     lvl1_niebieski11->Top+=10;
     lvl1_niebieski12->Top+=10;
   } else if(lvl1_niebieski1->Top >= 150) {lvl1->Enabled=false; latanie_wrogow->Enabled=true;}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::latanie_wrogowTimer(TObject *Sender)
{
   if(ktory_wrog){
     lvl1_niebieski1->Top=157; lvl1_niebieski2->Top=157; lvl1_niebieski3->Top=157;
     lvl1_niebieski4->Top=157; lvl1_niebieski5->Top=157; lvl1_niebieski6->Top=157;
     lvl1_niebieski7->Top=157; lvl1_niebieski8->Top=157; lvl1_niebieski9->Top=157;
     lvl1_niebieski10->Top=157; lvl1_niebieski11->Top=157; lvl1_niebieski12->Top=157;
     ktory_wrog=false;
   } else{
     lvl1_niebieski1->Top=160; lvl1_niebieski2->Top=160; lvl1_niebieski3->Top=160;
     lvl1_niebieski4->Top=160; lvl1_niebieski5->Top=160; lvl1_niebieski6->Top=160;
     lvl1_niebieski7->Top=160; lvl1_niebieski8->Top=160; lvl1_niebieski9->Top=160;
     lvl1_niebieski10->Top=160; lvl1_niebieski11->Top=160; lvl1_niebieski12->Top=160;
     ktory_wrog=true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::strzal1_lotTimer(TObject *Sender)
{
   if(strzal1->Visible || strzal1->Top>=120){
     strzal1->Top-=10;
   }else strzal1_lot->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::strzal2_lotTimer(TObject *Sender)
{
   if(strzal2->Visible || strzal2->Top>=120){
     strzal2->Top-=10;
   }else strzal2_lot->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::strzal3_lotTimer(TObject *Sender)
{
   if(strzal3->Visible || strzal3->Top>=120){
     strzal3->Top-=10;
   }else strzal3_lot->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::strzal4_lotTimer(TObject *Sender)
{
   if(strzal4->Visible || strzal4->Top>=120){
     strzal4->Top-=10;
   }else strzal4_lot->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::strzal5_lotTimer(TObject *Sender)
{
   if(strzal5->Visible || strzal5->Top>=120){
     strzal5->Top-=10;
   }else strzal5_lot->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::strzal6_lotTimer(TObject *Sender)
{
   if(strzal6->Visible || strzal6->Top>=120){
     strzal6->Top-=10;
   }else strzal6_lot->Enabled=false;
}
//---------------------------------------------------------------------------

