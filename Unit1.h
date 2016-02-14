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
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TTrudne : public TForm
{
__published:	// IDE-managed Components
        TShape *Tlo;
        TImage *B;
        TTimer *TimerP;
        TImage *P;
        TTimer *Lewo;
        TTimer *Prawo;
        TImage *P2;
        TTimer *Prawo2;
        TTimer *Lewo2;
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        TImage *Image5;
        TImage *Image6;
        TImage *Image7;
        TImage *Image8;
        TImage *Image9;
        TButton *Button1;
        TImage *putin;
        TTimer *Timer;
        TImage *Image10;
        TImage *bean;
        void __fastcall TimerPTimer(TObject *Sender);
        void __fastcall LewoTimer(TObject *Sender);
        void __fastcall PrawoTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Lewo2Timer(TObject *Sender);
        void __fastcall Prawo2Timer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall TimerTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TTrudne(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTrudne *Trudne;
//---------------------------------------------------------------------------
#endif
 