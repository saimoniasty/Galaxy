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
#include <vector>
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
        TImage *lvl1_niebieski_template;
        TTimer *lvl1;
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
        TTimer *przeladowanie;
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
        void __fastcall przeladowanieTimer(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
private:
        //wrogowie
        std::vector<TImage*> wrogowie_niebiescy;
        std::vector<TImage*> wrogowie_zieloni;
        std::vector<TImage*> wrogowie_rozowi;
        std::vector<TImage*> wrogowie_czerwoni;
        //pozycje do resizowania labeli
        int initialFontSize_high, initialFontSize_score;
        int initialLeft_high, initialLeft_score;
        int initialTop_high, initialTop_score;
        std::vector<int> initialLeft;
        std::vector<int> initialTop;
        //pomocnicze
        int ktory_statek; //animacja statku
        int ktory_strzal; //odlicza ktory jest strzal
        bool gra_rozpoczeta;  //czy gra sie zaczela
        bool animacja_wrog; //animacja wrogow
        int wynik; //wynik w grze	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        __fastcall ~TForm1();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 