//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CPort"
#pragma resource "*.dfm"


TForm1 *Form1;

AnsiString send_str;
AnsiString auto_send_time;
AnsiString connect_status;
AnsiString save_path;
char tx_buf[1000] = {0};
int byte_cnt = 0;
char check_auto_log_flag = 1;

AnsiString default_port;
AnsiString default_baud;
AnsiString default_DataBits;
AnsiString default_StopBits;
TComParity* default_Parity;
TComFlowControl* default_FlowContral;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SetupClick(TObject *Sender)
{
    ComPort1->ShowSetupDialog();
	ComPort1->Open();
	default_port = ComPort1->Port;
	Timer1->Enabled = true;
	Timer2->Enabled = true;
	connect_status = BoolToStr(ComPort1->Connected);
	if(connect_status!=0){	//connect successful
         Shape1->Brush->Color = clLime;
         StaticText1->Color = clLime;
    }
	else{
         Shape1->Brush->Color = clRed;
         StaticText1->Color = clRed;
	}
	StaticText1->Caption = (ComPort1->Port).Delete(1,3);
	Display_ASCII->Checked = true;
	Send_ASCII->Checked = true;
	CRLF->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StartClick(TObject *Sender)
{
	Timer1->Enabled = true;
	Timer2->Enabled = true;
	//ComPort1->Port = 'COM3';
	ComPort1->Port = default_port;
//Memo1->Lines->Add(default_port);
	ComPort1->Open();
 	Timer1->Enabled = true;
	Timer2->Enabled = true;
	connect_status = BoolToStr(ComPort1->Connected);
	if(connect_status!=0){	//connect successful
         Shape1->Brush->Color = clLime;
         StaticText1->Color = clLime;
    }
	else{
         Shape1->Brush->Color = clRed;
         StaticText1->Color = clRed;
	}
	StaticText1->Caption = (ComPort1->Port).Delete(1,3);     //com1 -> 1
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StopClick(TObject *Sender)
{
	ComPort1->Close();
    Timer1->Enabled = false;
	Timer2->Enabled = false;
	Timer3->Enabled = false;
	Timer4->Enabled = false;
	Shape1->Brush->Color = clRed;
    StaticText1->Color = clRed;	
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
	  send_str = Edit1->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Send_AscClick(TObject *Sender)
{
 	memset(tx_buf,0,sizeof(tx_buf));
	AnsiString CR_Ins = "\r";           //CR
	AnsiString LF_Ins = "\n";           //LF
	AnsiString CRLF_Ins = "\r\n";         //CRLF
	AnsiString LFCR_Ins = "\n\r";         //LFCR
	AnsiString cpy_send_str =  send_str;
	int tx_len = 0,i;
	//Memo1->Lines->Add("1 = "+cpy_send_str);
	if(CR->Checked == true){
	    cpy_send_str = cpy_send_str.Insert( CR_Ins,cpy_send_str.Length()+1 );
    }
    else if(LF->Checked == true){
        cpy_send_str = cpy_send_str.Insert( LF_Ins,cpy_send_str.Length()+1 );
    }
    else if(CRLF->Checked == true){
        cpy_send_str = cpy_send_str.Insert( CRLF_Ins,cpy_send_str.Length()+1 );
    }
    else if(LFCR->Checked == true){
        cpy_send_str = cpy_send_str.Insert( LFCR_Ins,cpy_send_str.Length()+1 );
    }
    //Memo1->Lines->Add("2 = "+cpy_send_str);
	if(Send_ASCII->Checked == true){
		sprintf(tx_buf,"%s",cpy_send_str);
	}
	else if(Send_Hex->Checked == true){
    	for(i=1;i<=send_str.Length();i++){
			tx_len += sprintf(tx_buf+tx_len,"%02x",cpy_send_str[i]);
		}
		ComPort1->WriteStr(tx_buf);
	}
	else if(Send_Numeric->Checked == true){
    	for(i=1;i<=send_str.Length();i++){
			tx_len += sprintf(tx_buf+tx_len,"%d",cpy_send_str[i]);
		}
        ComPort1->WriteStr(tx_buf);
	}
    ComPort1->WriteStr(tx_buf);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClearClick(TObject *Sender)
{
	Memo1->Clear();
	byte_cnt = 0;	
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    AnsiString str="SerialPort Client Tool ";
    Form1->Caption = str+"("+default_port+" , "+ComPort1->BaudRate+" )";
	AnsiString recv_str = NULL;
    AnsiString last_time = "2015/07/09 15:01:00";
	char hex_str[500] = {0};
	ComPort1->ReadStr(recv_str,500);
	if(recv_str != ""){
    	int i;
    	int tx_len = 0;
		if(Display_ASCII->Checked == true){
				sprintf(hex_str,"%s",recv_str);
		}
		else if(Display_Hex->Checked == true){
			for(i=1;i<=recv_str.Length();i++){
				tx_len += sprintf(hex_str+tx_len,"%02x",recv_str[i]);
			}
		}
		else if(Display_Numeric->Checked == true){
			for(i=1;i<=recv_str.Length();i++){
				tx_len += sprintf(hex_str+tx_len,"%d",recv_str[i]);
			}
		}
		Memo1->Lines->Add(hex_str);
        if(last_recv_time->Checked == true){
			last_time = Date()+Time();
        	last_recv_time->Caption = last_time;
		}
	   	if(byte_ct->Checked == true){
        	byte_cnt += StrToInt(recv_str.Length());
			byte_ct->Caption = byte_cnt;
		}

	}	
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
	memset(tx_buf,0,sizeof(tx_buf));
	AnsiString CR_Ins = "\r";           //CR
	AnsiString LF_Ins = "\n";           //LF
	AnsiString CRLF_Ins = "\r\n";         //CRLF
	AnsiString LFCR_Ins = "\n\r";         //LFCR
	AnsiString cpy_send_str =  send_str;
	int tx_len = 0;
	int i;
	//Memo1->Lines->Add("1 = "+cpy_send_str);
	if(CR->Checked == true){
	    cpy_send_str = cpy_send_str.Insert( CR_Ins,cpy_send_str.Length()+1 );
    }
    else if(LF->Checked == true){
        cpy_send_str = cpy_send_str.Insert( LF_Ins,cpy_send_str.Length()+1 );
    }
    else if(CRLF->Checked == true){
        cpy_send_str = cpy_send_str.Insert( CRLF_Ins,cpy_send_str.Length()+1 );
    }
    else if(LFCR->Checked == true){
        cpy_send_str = cpy_send_str.Insert( LFCR_Ins,cpy_send_str.Length()+1 );
    }
    //Memo1->Lines->Add("2 = "+cpy_send_str);
	if(Send_ASCII->Checked == true){
		sprintf(tx_buf,"%s",cpy_send_str);
	}
	else if(Send_Hex->Checked == true){
    	for(i=1;i<=send_str.Length();i++){
			tx_len += sprintf(tx_buf+tx_len,"%02x",cpy_send_str[i]);
		}
		ComPort1->WriteStr(tx_buf);
	}
	else if(Send_Numeric->Checked == true){
    	for(i=1;i<=send_str.Length();i++){
			tx_len += sprintf(tx_buf+tx_len,"%d",cpy_send_str[i]);
		}
        ComPort1->WriteStr(tx_buf);
	}
    ComPort1->WriteStr(tx_buf);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
	Memo1->Lines->SaveToFile(save_path);	
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
		Memo1->Width = (Form1->ClientWidth)-1;
		Memo1->Height = (Form1->ClientHeight)-268;

		Edit1->Top = ((Form1->ClientHeight)-605)+432;
        Send_Asc->Top = ((Form1->ClientHeight)-605)+432;

		Send_Format->Top = ((Form1->ClientHeight)-605)+464;
		Auto_Send->Top = ((Form1->ClientHeight)-605)+464;

		Last_Receive_Time->Top = ((Form1->ClientHeight)-605)+512;
	    Byte_Count->Top = ((Form1->ClientHeight)-605)+512;

		ASCII_Line_Change_Character->Top = ((Form1->ClientHeight)-605)+560;
        Auto_Log->Top = ((Form1->ClientHeight)-605)+560;

		if(AT->Checked == true){
        	Form1->FormStyle = fsStayOnTop;
		}
		else{
			Form1->FormStyle = fsNormal;
		}
		if(auto_sd->Checked == true){
			if(auto_send_time->Text != ""){
				Timer3->Enabled = true;
        		Timer3->Interval = StrToInt(auto_send_time->Text);
			}
			else{
                 Timer3->Enabled = false;
			}
		}
		else{
			Timer3->Enabled = false;
		}
		if(auto_lg->Checked == true){
            Timer4->Enabled = true;
            Timer4->Interval = StrToInt(auto_log_time->Text)*1000;        //initial 60000
			if(check_auto_log_flag ==1){
				Timer1->Enabled = false;
				Timer2->Enabled = false;
            	Timer3->Enabled = false;
				Timer4->Enabled = false;
                if(SaveDialog1->Execute())
		        {
					save_path = SaveDialog1->FileName+".txt";
				}
            	Timer1->Enabled = true;
				Timer2->Enabled = true;
				check_auto_log_flag = 0;
			}
		}
		else{
             check_auto_log_flag = 1;
		}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::authorClick(TObject *Sender)
{
	Form2->ShowModal();
}
//---------------------------------------------------------------------------
