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
        TImage *strzal1;
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
        TImage *strzal2;
        TImage *strzal3;
        TImage *strzal4;
        TImage *strzal5;
        TImage *strzal6;
        TTimer *strzal1_lot;
        TTimer *strzal2_lot;
        TTimer *strzal3_lot;
        TTimer *strzal4_lot;
        TTimer *strzal5_lot;
        TTimer *strzal6_lot;
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
        void __fastcall strzal1_lotTimer(TObject *Sender);
        void __fastcall strzal2_lotTimer(TObject *Sender);
        void __fastcall strzal3_lotTimer(TObject *Sender);
        void __fastcall strzal4_lotTimer(TObject *Sender);
        void __fastcall strzal5_lotTimer(TObject *Sender);
        void __fastcall strzal6_lotTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        __fastcall ~TForm1();
        int ktory_statek, ktory_strzal;
        bool gra_rozpoczeta, ktory_wrog;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 