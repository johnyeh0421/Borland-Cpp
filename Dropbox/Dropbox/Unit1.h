//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.WebBrowser.hpp>
#include <FMX.Edit.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Authenticator.OAuth.hpp>
#include <REST.Client.hpp>
#include <REST.Response.Adapter.hpp>
#include <REST.Authenticator.Simple.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TWebBrowser *WebBrowser1;
	TButton *Button1;
	TMemo *Memo1;
	TEdit *Edit1;
	TButton *Button2;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TRESTResponse *RESTResponse1;
	TRESTResponseDataSetAdapter *RESTResponseDataSetAdapter1;
	TOAuth2Authenticator *OAuth2Authenticator1;
	TButton *Button3;
	TButton *Button4;
	TSimpleAuthenticator *SimpleAuthenticator1;
	TLabel *Label1;
	TEdit *Edit2;
	TLabel *Label2;
	TButton *Button5;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit3;
	TButton *Button6;
	TEdit *Edit4;
	TLabel *Label5;
	TButton *Button7;
	TButton *Button8;
	TMemo *Memo2;
	TTimer *Timer1;
	TButton *Button9;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall WebBrowser1DidFinishLoad(TObject *ASender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall RESTRequest1AfterExecute(TCustomRESTRequest *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
