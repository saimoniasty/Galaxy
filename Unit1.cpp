//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

bool hit(TImage *s,TImage *w){
   if(s->Top-2 <= w->Top+w->Height-28 && (s->Left+2 >= w->Left+20 && s->Left+2+s->Width-2 <= w->Left+20+w->Width-20) && w->Visible) return true;
   else return false;
}
void sprawdza_hit(TImage *st,TTimer *lot,TImage *w){
   if(hit(st,w)){
     st->Visible=false; w->Visible=false;
     lot->Enabled=false;
   }
}

void skalowanie_tlo(TImage *obraz){
   if(obraz->Picture->Graphic != NULL){
     obraz->Width=Form1->ClientWidth;
     obraz->Height=Form1->ClientHeight;
     obraz->Stretch=true;
   }
}
/*
void skalowanie_obraz(TImage *obraz){
   if(obraz->Picture->Graphic != NULL){
     float scale=(float)Form1->ClientWidth/834;


   }
}
*/

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
   //ustawianie pomocniczych
   tytul->Top=900; tytul->Left=152; //do wjazdu tytulu
   ktory_statek=1; //do animacji statku
   animacja_wrog=true; gra_rozpoczeta=false;
   tytul_wjazd->Enabled = true; //wlaczenie wjazdu tytulu
   wynik=0; //wynik zdobyty w grze
   //do resizowania tekstow jak sie powiekszy okno
   //dla highscore
   initialFontSize_high = label_high_score->Font->Size;
   initialLeft_high = label_high_score->Left;
   initialTop_high = label_high_score->Top;
   //dla score
   initialFontSize_score = score->Font->Size;
   initialLeft_score = score->Left;
   initialTop_score = score->Top;
   //robienie pierwszych wrogow na 1 lvl
   for(int i = 0; i<12; i++) {
        TImage *wrog = new TImage(this);
        wrog->Parent = this;
        wrog->Visible = false; // Ustawienie pocz¹tkowej widocznoœci
        wrogowie_niebiescy.push_back(wrog); // Dodanie elementu do wektora
   }
}
//---------------------------------------------------------------------------
__fastcall TForm1::~TForm1()
{
   //zapisywanie highscore
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(gra_rozpoczeta){
     if(Key=='D' || Key=='d' || Key==VK_RIGHT) Prawo->Enabled=true; //ruch statku w prawo
     if(Key=='A' || Key=='a' || Key==VK_LEFT) Lewo->Enabled=true; //ruch statku w prawo
     if(Key==VK_SPACE){  //strzelanie (moglem lepiej zrobic nie chce mi sie poprawiac)
       if(ktory_strzal==1){
         sndPlaySound("snd/strzal.wav",SND_ASYNC);
         ktory_strzal++;
         strzal1->Top = statek->Top+28; strzal1->Left = statek->Left+35;
         strzal1->Visible=true;
         strzal1_lot->Enabled=true;
       }
       else if(ktory_strzal==2){
         sndPlaySound("snd/strzal.wav",SND_ASYNC);
         ktory_strzal++;
         strzal2->Top = statek->Top+28; strzal2->Left = statek->Left+35;
         strzal2->Visible=true;
         strzal2_lot->Enabled=true;
       }
       else if(ktory_strzal==3){
         sndPlaySound("snd/strzal.wav",SND_ASYNC);
         ktory_strzal++;
         strzal3->Top = statek->Top+28; strzal3->Left = statek->Left+35;
         strzal3->Visible=true;
         strzal3_lot->Enabled=true;
       }
       else if(ktory_strzal==4){
         sndPlaySound("snd/strzal.wav",SND_ASYNC);
         ktory_strzal++;
         strzal4->Top = statek->Top+28; strzal4->Left = statek->Left+35;
         strzal4->Visible=true;
         strzal4_lot->Enabled=true;
       }
       else if(ktory_strzal==5){
         sndPlaySound("snd/strzal.wav",SND_ASYNC);
         ktory_strzal++;
         strzal5->Top = statek->Top+28; strzal5->Left = statek->Left+35;
         strzal5->Visible=true;
         strzal5_lot->Enabled=true;
       }
       else if(ktory_strzal==6){
         sndPlaySound("snd/strzal.wav",SND_ASYNC);
         ktory_strzal++;
         strzal6->Top = statek->Top+28; strzal6->Left = statek->Left+35;
         strzal6->Visible=true;
         strzal6_lot->Enabled=true;
         przeladowanie->Enabled=true;
       }
     }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(gra_rozpoczeta){
     if(Key=='D' || Key=='d' || Key==VK_RIGHT) Prawo->Enabled=false; //koniec ruchu statku
     if(Key=='A' || Key=='a' || Key==VK_LEFT) Lewo->Enabled=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LewoTimer(TObject *Sender)
{
   if(statek->Left > -10) statek->Left-=10; //statek leci w lewo
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PrawoTimer(TObject *Sender)
{
   if(statek->Left+statek->Width < Form1->Width-10) statek->Left+=10; //statek leci w prawo
}
//---------------------------------------------------------------------------

void __fastcall TForm1::statek_animacjaTimer(TObject *Sender)
{
   //animacja statku
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
   //ustawianie pomocniczych przy rozpoczeciu gry
   gra_rozpoczeta=true;
   //wylaczenie tytulowych obiektow
   tytul->Visible=false;
   start->Visible=false; high_score->Visible=false; label_high_score->Visible=false;
   tlo_tytul->Visible=false;
   //wlaczenie obiektow do gry
   tlo->Visible=true;
   score->Visible=true;
   statek->Visible=true;
   statek_animacja->Enabled=true;
   TForm1::ktory_strzal=1;
   zycie1->Visible=true; zycie2->Visible=true; zycie3->Visible=true;

   //pojawianie sie niebieskich wrogow w lvl1
   int startX = 55;
   for (int i = 0; i < 12; i++){
       wrogowie_niebiescy[i]->Picture = lvl1_niebieski_template->Picture;
       wrogowie_niebiescy[i]->Left = startX + i * 60;
       wrogowie_niebiescy[i]->Top = -100;
       wrogowie_niebiescy[i]->Visible = true;
       wrogowie_niebiescy[i]->Transparent=true;
   }

   //przylatywanie wrogow
   lvl1->Enabled=true;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::tytul_wjazdTimer(TObject *Sender)
{
   //wejscie tytulu
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
   //dokonczenie wlaczenia tytulowej strony
   start->Visible=true;
   tytul_wyjazd_czekaj->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lvl1Timer(TObject *Sender)
{
   //przylatywanie wrogow
   if(wrogowie_niebiescy[0]->Top <= 150){
     for(size_t i=0; i<wrogowie_niebiescy.size(); i++){
       wrogowie_niebiescy[i]->Top+=10;
     }
   } else if(wrogowie_niebiescy[0]->Top >= 150) {lvl1->Enabled=false; latanie_wrogow->Enabled=true;}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::latanie_wrogowTimer(TObject *Sender)
{
   //animacja wrogow
   if(animacja_wrog){
     for(size_t i=0; i<wrogowie_niebiescy.size(); i++){
       wrogowie_niebiescy[i]->Top=157;
     }
     animacja_wrog=false;
   } else{
     for(size_t i=0; i<wrogowie_niebiescy.size(); i++){
       wrogowie_niebiescy[i]->Top=160;
     }
     animacja_wrog=true;
   }
}
//---------------------------------------------------------------------------

//wszystkie timery do strzalow

void __fastcall TForm1::strzal1_lotTimer(TObject *Sender)
{
   if(strzal1->Visible && strzal1->Top >= tlo->Top-20){
     strzal1->Top-=20;
   }
   for(size_t i=0;i<wrogowie_niebiescy.size();i++){
     sprawdza_hit(strzal1,strzal1_lot,wrogowie_niebiescy[i]);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::strzal2_lotTimer(TObject *Sender)
{
   if(strzal2->Visible && strzal2->Top >= tlo->Top-20){
     strzal2->Top-=20;
   }
   for(size_t i=0;i<wrogowie_niebiescy.size();i++){
     sprawdza_hit(strzal2,strzal2_lot,wrogowie_niebiescy[i]);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::strzal3_lotTimer(TObject *Sender)
{
   if(strzal3->Visible && strzal3->Top >= tlo->Top-20){
     strzal3->Top-=20;
   }
   for(size_t i=0;i<wrogowie_niebiescy.size();i++){
     sprawdza_hit(strzal3,strzal3_lot,wrogowie_niebiescy[i]);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::strzal4_lotTimer(TObject *Sender)
{
   if(strzal4->Visible && strzal4->Top >= tlo->Top-20){
     strzal4->Top-=20;
   }
   for(size_t i=0;i<wrogowie_niebiescy.size();i++){
     sprawdza_hit(strzal4,strzal4_lot,wrogowie_niebiescy[i]);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::strzal5_lotTimer(TObject *Sender)
{
   if(strzal5->Visible && strzal5->Top >= tlo->Top-20){
     strzal5->Top-=20;
   }
   for(size_t i=0;i<wrogowie_niebiescy.size();i++){
     sprawdza_hit(strzal5,strzal5_lot,wrogowie_niebiescy[i]);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::strzal6_lotTimer(TObject *Sender)
{
   if(strzal6->Visible && strzal6->Top >= tlo->Top-20){
     strzal6->Top-=20;
   }
   for(size_t i=0;i<wrogowie_niebiescy.size();i++){
     sprawdza_hit(strzal6,strzal6_lot,wrogowie_niebiescy[i]);
   }
}
//---------------------------------------------------------------------------

//koniec timerow

void __fastcall TForm1::przeladowanieTimer(TObject *Sender)
{
   //przeladowanie po szesciu strzalach
   TForm1::ktory_strzal=1;
   przeladowanie->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
   //skalowanie rzeczy w starcie
   skalowanie_tlo(tlo_tytul); skalowanie_tlo(tlo); //skalowanie_obraz(tytul);
   /*
   skalowanie_obraz(start); skalowanie_obraz(high_score);
   //skalowanie rzeczy w grze
   skalowanie_obraz(zycie1); skalowanie_obraz(zycie2); skalowanie_obraz(zycie3);
   skalowanie_obraz(strzal1); skalowanie_obraz(strzal2); skalowanie_obraz(strzal3); skalowanie_obraz(strzal4); skalowanie_obraz(strzal5); skalowanie_obraz(strzal6);
   skalowanie_obraz(statek);
   */
   //skalowanie labeli
   float scaleFactor=(float)ClientWidth/849;

   label_high_score->Font->Size=(int)(initialFontSize_high * scaleFactor);

   label_high_score->Left=(int)(initialLeft_high * scaleFactor);
   label_high_score->Top=(int)(initialTop_high * scaleFactor);

   score->Font->Size=(int)(initialFontSize_score * scaleFactor);

   score->Left=(int)(initialLeft_score * scaleFactor);
   score->Top=(int)(initialTop_score * scaleFactor);
}
//---------------------------------------------------------------------------

