//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *statek;
        TImage *tlo;
        TTimer *Lewo;
        TTimer *Prawo;
        TTimer *statek_animacja;
        TImage *strzal;
        TImage *tytul;
        TImage *tlo_tytul;
        TImage *start;
        TImage *high_score;
        TLabel *label_high_score;
        TTimer *tytul_wjazd;
        TTimer *tytul_wyjazd_czekaj;
        TLabel *score;
        TImage *zycie1;
        TImage *zycie2;
        TImage *zycie3;
        TImage *lvl1_niebieski1;
        TImage *lvl1_niebieski2;
        TImage *lvl1_niebieski3;
        TImage *lvl1_niebieski4;
        TImage *lvl1_niebieski5;
        TImage *lvl1_niebieski6;
        TImage *lvl1_niebieski7;
        TImage *lvl1_niebieski8;
        TImage *lvl1_niebieski9;
        TImage *lvl1_niebieski10;
        TTimer *lvl1;
        TImage *lvl1_niebieski11;
        TImage *lvl1_niebieski12;
        TTimer *latanie_wrogow;
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall LewoTimer(TObject *Sender);
        void __fastcall PrawoTimer(TObject *Sender);
        void __fastcall statek_animacjaTimer(TObject *Sender);
        void __fastcall startClick(TObject *Sender);
        void __fastcall tytul_wjazdTimer(TObject *Sender);
        void __fastcall tytul_wyjazd_czekajTimer(TObject *Sender);
        void __fastcall lvl1Timer(TObject *Sender);
        void __fastcall latanie_wrogowTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        __fastcall ~TForm1();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 