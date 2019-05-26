//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CPort.hpp"
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Setup;
	TButton *Start;
	TButton *Stop;
	TButton *Plot;
	TButton *Save;
	TButton *Load;
	TButton *Clear;
	TGroupBox *Display_Format;
	TRadioButton *Display_Hex;
	TRadioButton *Display_ASCII;
	TRadioButton *Display_Numeric;
	TMemo *Memo1;
	TEdit *Edit1;
	TButton *Send_Asc;
	TGroupBox *Send_Format;
	TGroupBox *Auto_Send;
	TGroupBox *Last_Receive_Time;
	TGroupBox *Byte_Count;
	TGroupBox *ASCII_Line_Change_Character;
	TGroupBox *Auto_Log;
	TCheckBox *AT;
	TRadioButton *Send_Hex;
	TRadioButton *Send_ASCII;
	TRadioButton *Send_Numeric;
	TRadioButton *No;
	TRadioButton *CR;
	TRadioButton *LF;
	TRadioButton *CRLF;
	TRadioButton *LFCR;
	TTimer *Timer1;
	TTimer *Timer2;
	TTimer *Timer3;
	TTimer *Timer4;
	TShape *Shape1;
	TStaticText *StaticText1;
	TCheckBox *last_recv_time;
	TCheckBox *byte_ct;
	TCheckBox *auto_sd;
	TSaveDialog *SaveDialog1;
	TCheckBox *auto_lg;
	TEdit *auto_send_time;
	TLabel *Label1;
	TEdit *auto_log_time;
	TLabel *Label2;
	TButton *author;
	TComPort *ComPort1;
	void __fastcall SetupClick(TObject *Sender);
	void __fastcall StartClick(TObject *Sender);
	void __fastcall StopClick(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Send_AscClick(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall Timer4Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall authorClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
