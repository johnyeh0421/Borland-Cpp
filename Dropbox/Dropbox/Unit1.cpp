//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
bool is_get_access_token_flag;
bool is_get_session_id_flag;
bool start_file_header_flag;
int data_cnt = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	//Form1->Name = "Dropbox Upload File - John_yeh";
	Form1->Caption = "Dropbox Upload File - John_yeh";
	time_t now = time(0);
	tm *ltm = localtime(&now);
	AnsiString time = String(ltm->tm_hour)+":"+String(ltm->tm_min)+":"+String(ltm->tm_sec);
	AnsiString date = Date();
	//Memo1->Lines->Add(time);
	//Memo1->Lines->Add(date);
	Memo2->Lines->Add(date+","+time+",Test Message\r\n");

	AnsiString file_datetime = date+"_"+time;
	AnsiString result,replace_tmp;
	replace_tmp =  StringReplace(file_datetime, "/", "", TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
	result =  StringReplace(replace_tmp, ":", "", TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
	//Memo1->Lines->Add( result );


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	//https://www.dropbox.com/1/oauth2/authorize?client_id=97n798ixg8bzdow&response_type=code&state=bfktaf39kzaj1yk
	//Get Authorzation Code
	AnsiString LURL = "https://www.dropbox.com/1/oauth2/authorize?";
	LURL = LURL + "client_id=xuxbszn0qsdba5x";
	LURL = LURL + "&response_type=code";
	LURL = LURL + "&state=bfktaf39kzaj1yk";
	Memo1->Lines->Add(LURL);
	WebBrowser1->Navigate(LURL);
	Edit1->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WebBrowser1DidFinishLoad(TObject *ASender)
{
	Memo1->Lines->Add(WebBrowser1->URL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	//https://api.dropbox.com/1/oauth2/token?code=YOUR_AUTHORIZATION_CODE&amp;grant_type=authorization_code
	//header
	//Authorization = Basic base64_Encode(appKey:appSecret)
	/*
	AnsiString LURL = "https://api.dropbox.com/1/oauth2/token?";
	LURL = LURL + "code=YOUR_AUTHORIZATION_CODE";
	LURL = LURL + "&amp;grant_type=authorization_code";
	Memo1->Lines->Add(LURL);
	WebBrowser1->Navigate(LURL);
	*/
	is_get_access_token_flag = 1;
	Memo1->Lines->Clear();
	RESTClient1->ResetToDefaults();
	RESTRequest1->ResetToDefaults();
	RESTResponse1->ResetToDefaults();
	RESTResponseDataSetAdapter1->ResetToDefaults();

    //Get Access Token
	AnsiString LURL = "https://api.dropbox.com/1/oauth2/token?code="+Edit1->Text+"&grant_type=authorization_code";
	RESTClient1->BaseURL = LURL;
	RESTClient1->Authenticator = SimpleAuthenticator1;

	RESTRequest1->Method = rmPOST;
	RESTRequest1->AddParameter("Content-Type", "application/x-www-form-urlencoded; charset=UTF-8", TRESTRequestParameterKind::pkHTTPHEADER);
	RESTRequest1->AddAuthParameter("Authorization", "Basic eHV4YnN6bjBxc2RiYTV4Om01aWo2MGJwOWk0YmdwZA==", TRESTRequestParameterKind::pkHTTPHEADER, TRESTRequestParameterOptions() << TRESTRequestParameterOption::poDoNotEncode);
	RESTRequest1->Client = RESTClient1;

	Memo1->Lines->Add(RESTClient1->BaseURL);
	RESTRequest1->Execute();


}
//---------------------------------------------------------------------------
void __fastcall TForm1::RESTRequest1AfterExecute(TCustomRESTRequest *Sender)
{
    Memo1->Lines->Add("RESTRequest1AfterExecute");
	//Memo1->Lines->Add(RESTResponse1->JSONText);
	Memo1->Lines->Add(RESTResponse1->Content);

	if(is_get_access_token_flag){
		//收到的所有資料就是一個JSONObject把JSONValue轉成JSONObject
		TJSONObject *o = (TJSONObject*)RESTResponse1->JSONValue;
		//把 entries 下的資料轉成 JSONArray
		TJSONArray *a = (TJSONArray*)o->GetValue("access_token");
		Memo1->Lines->Add("access_token : " + a->Value());
		Edit2->Text =  a->Value();
		is_get_access_token_flag = 0;
	}
	else if(is_get_session_id_flag){
 		TJSONObject *o = (TJSONObject*)RESTResponse1->JSONValue;
		//把 entries 下的資料轉成 JSONArray
		TJSONArray *a = (TJSONArray*)o->GetValue("session_id");
		Memo1->Lines->Add("session_id : " + a->Value());
		Edit3->Text =  a->Value();
		is_get_session_id_flag = 0;
        start_file_header_flag = 1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	RESTClient1->ResetToDefaults();
	RESTRequest1->ResetToDefaults();
	RESTResponse1->ResetToDefaults();
	RESTResponseDataSetAdapter1->ResetToDefaults();

	OAuth2Authenticator1->TokenType = TOAuth2TokenType::ttBEARER;
	OAuth2Authenticator1->ResponseType = TOAuth2ResponseType::rtTOKEN;
	OAuth2Authenticator1->AccessToken = Edit2->Text;

	RESTClient1->BaseURL = "https://api.dropboxapi.com/2/";
	RESTClient1->Authenticator = OAuth2Authenticator1;

	RESTRequest1->Method = rmPOST;
	RESTRequest1->Resource = "files/list_folder";
	RESTRequest1->Params->Clear();

	//上傳參數要JSON格式
	TJSONObject *o = new TJSONObject;
	o->AddPair("path","//");
	o->AddPair("recursive",new TJSONFalse);
	o->AddPair("include_media_info",new TJSONFalse);
	o->AddPair("include_deleted",new TJSONFalse);
	o->AddPair("include_has_explicit_shared_members",new TJSONFalse);

	RESTRequest1->AddBody(o);

	RESTRequest1->Execute();

		o->Free();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	RESTClient1->ResetToDefaults();
	RESTRequest1->ResetToDefaults();
	RESTResponse1->ResetToDefaults();
	RESTResponseDataSetAdapter1->ResetToDefaults();
	is_get_session_id_flag = 1;
    data_cnt = 0;

    //Get Session Id
	AnsiString LURL = "https://content.dropboxapi.com/2/files/upload_session/start";
	RESTClient1->BaseURL = LURL;
	RESTClient1->Authenticator = SimpleAuthenticator1;

	RESTRequest1->Method = rmPOST;
	AnsiString Auth = "Bearer " + Edit2->Text;
	RESTRequest1->AddAuthParameter("Authorization", Auth, TRESTRequestParameterKind::pkHTTPHEADER, TRESTRequestParameterOptions() << TRESTRequestParameterOption::poDoNotEncode);
	RESTRequest1->AddAuthParameter("Dropbox-API-Arg", "{\"close\": false}", TRESTRequestParameterKind::pkHTTPHEADER, TRESTRequestParameterOptions() << TRESTRequestParameterOption::poDoNotEncode);
	RESTRequest1->Client = RESTClient1;

	RESTRequest1->ClearBody();
	RESTRequest1->AddBody("" ,TRESTContentType::ctAPPLICATION_OCTET_STREAM);

	Memo1->Lines->Add(RESTClient1->BaseURL);
	RESTRequest1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	RESTClient1->ResetToDefaults();
	RESTRequest1->ResetToDefaults();
	RESTResponse1->ResetToDefaults();
	RESTResponseDataSetAdapter1->ResetToDefaults();

    //Append Content
	AnsiString LURL = "https://content.dropboxapi.com/2/files/upload_session/append_v2";
	RESTClient1->BaseURL = LURL;
	RESTClient1->Authenticator = SimpleAuthenticator1;

	RESTRequest1->Method = rmPOST;
	AnsiString Auth = "Bearer " + Edit2->Text;
	RESTRequest1->AddAuthParameter("Authorization", Auth, TRESTRequestParameterKind::pkHTTPHEADER, TRESTRequestParameterOptions() << TRESTRequestParameterOption::poDoNotEncode);
	//offset 從0開始累加
	AnsiString str = Memo2->Lines->GetText();
	Memo1->Lines->Add(IntToStr(data_cnt));
	AnsiString arg = "{\"cursor\": {\"session_id\": \""+Edit3->Text+"\",\"offset\": "+IntToStr(data_cnt)+"},\"close\": false}";
	data_cnt += str.Length();
	RESTRequest1->AddAuthParameter("Dropbox-API-Arg", arg, TRESTRequestParameterKind::pkHTTPHEADER, TRESTRequestParameterOptions() << TRESTRequestParameterOption::poDoNotEncode);
	RESTRequest1->Client = RESTClient1;

	RESTRequest1->ClearBody();

	RESTRequest1->AddBody(str ,TRESTContentType::ctAPPLICATION_OCTET_STREAM);

	Memo1->Lines->Add(RESTClient1->BaseURL);
	Memo1->Lines->Add(arg);
	RESTRequest1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	RESTClient1->ResetToDefaults();
	RESTRequest1->ResetToDefaults();
	RESTResponse1->ResetToDefaults();
	RESTResponseDataSetAdapter1->ResetToDefaults();

	time_t now = time(0);
	tm *ltm = localtime(&now);
	AnsiString time = String(ltm->tm_hour)+":"+String(ltm->tm_min)+":"+String(ltm->tm_sec);
	AnsiString date = Date();

	AnsiString file_datetime = date+"_"+String(ltm->tm_hour)+String(ltm->tm_min)+String(ltm->tm_sec);
	AnsiString result;
	result =  StringReplace(file_datetime, "/", "", TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);

    //Append Content
	AnsiString LURL = "https://content.dropboxapi.com/2/files/upload_session/finish";
	RESTClient1->BaseURL = LURL;
	RESTClient1->Authenticator = SimpleAuthenticator1;

	RESTRequest1->Method = rmPOST;
	AnsiString Auth = "Bearer " + Edit2->Text;
	RESTRequest1->AddAuthParameter("Authorization", Auth, TRESTRequestParameterKind::pkHTTPHEADER, TRESTRequestParameterOptions() << TRESTRequestParameterOption::poDoNotEncode);

	AnsiString arg = "{\"cursor\": {\"session_id\": \""+Edit3->Text+"\",\"offset\": "+IntToStr(data_cnt)+"},\"commit\": {\"path\": \"/john_yeh/"+Edit4->Text+"_"+result+".csv"+"\",\"mode\": \"overwrite\",\"autorename\": true,\"mute\": false}}";
	RESTRequest1->AddAuthParameter("Dropbox-API-Arg", arg, TRESTRequestParameterKind::pkHTTPHEADER, TRESTRequestParameterOptions() << TRESTRequestParameterOption::poDoNotEncode);
	RESTRequest1->Client = RESTClient1;

	RESTRequest1->ClearBody();

	RESTRequest1->AddBody("" ,TRESTContentType::ctAPPLICATION_OCTET_STREAM);

	Memo1->Lines->Add(RESTClient1->BaseURL);
	Memo1->Lines->Add(arg);

	RESTRequest1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	RESTClient1->ResetToDefaults();
	RESTRequest1->ResetToDefaults();
	RESTResponse1->ResetToDefaults();
	RESTResponseDataSetAdapter1->ResetToDefaults();

	OAuth2Authenticator1->TokenType = TOAuth2TokenType::ttBEARER;
	OAuth2Authenticator1->ResponseType = TOAuth2ResponseType::rtTOKEN;
	OAuth2Authenticator1->AccessToken = Edit2->Text;

	RESTClient1->BaseURL = "https://content.dropboxapi.com/2/";
	//RESTClient1->BaseURL = "http://192.168.1.36/2/";
	RESTClient1->Authenticator = OAuth2Authenticator1;

	//上傳參數要JSON格式
	TJSONObject *o = new TJSONObject;
	o->AddPair("path","/test/test.txt");
	o->AddPair("mode","overwrite");
	o->AddPair("autorename",new TJSONTrue);
	o->AddPair("mute",new TJSONFalse);
	//TJSONFalse
    //TJSONTrue

	RESTRequest1->Method = rmPOST;
	RESTRequest1->Resource = "files/upload?arg=" + o->ToString();
	RESTRequest1->Params->Clear();

	RESTRequest1->ClearBody();

	RESTRequest1->AddBody(Memo2->Lines->GetText() ,TRESTContentType::ctAPPLICATION_OCTET_STREAM);

	Memo1->Lines->Add("Append content Click");
	Memo1->Lines->Add(RESTRequest1->Resource);
	RESTRequest1->Execute();

	o->Free();
}

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	if(start_file_header_flag){
		Memo1->Lines->Clear();
		RESTClient1->ResetToDefaults();
		RESTRequest1->ResetToDefaults();
		RESTResponse1->ResetToDefaults();
		RESTResponseDataSetAdapter1->ResetToDefaults();

		//Append Content
		AnsiString LURL = "https://content.dropboxapi.com/2/files/upload_session/append_v2";
		RESTClient1->BaseURL = LURL;
		RESTClient1->Authenticator = SimpleAuthenticator1;

		RESTRequest1->Method = rmPOST;
		AnsiString Auth = "Bearer " + Edit2->Text;
		RESTRequest1->AddAuthParameter("Authorization", Auth, TRESTRequestParameterKind::pkHTTPHEADER, TRESTRequestParameterOptions() << TRESTRequestParameterOption::poDoNotEncode);
		//offset 從0開始累加
		AnsiString str = "Date,Time,Event Message\r\n";
		Memo1->Lines->Add(IntToStr(data_cnt));
		AnsiString arg = "{\"cursor\": {\"session_id\": \""+Edit3->Text+"\",\"offset\": "+IntToStr(data_cnt)+"},\"close\": false}";
		data_cnt += str.Length();
		RESTRequest1->AddAuthParameter("Dropbox-API-Arg", arg, TRESTRequestParameterKind::pkHTTPHEADER, TRESTRequestParameterOptions() << TRESTRequestParameterOption::poDoNotEncode);
		RESTRequest1->Client = RESTClient1;

		RESTRequest1->ClearBody();

		RESTRequest1->AddBody(str ,TRESTContentType::ctAPPLICATION_OCTET_STREAM);

		Memo1->Lines->Add(RESTClient1->BaseURL);
		Memo1->Lines->Add(arg);
		RESTRequest1->Execute();
        start_file_header_flag = 0;
	}

	if(Edit2->Text==""){
		Button5->Enabled = False;
		Button6->Enabled = False;
		Button7->Enabled = False;
	}
	else{
		if(Edit3->Text==""){
			Button5->Enabled = False;
            Button6->Enabled = True;
			Button7->Enabled = False;
		}
		else{
			Button5->Enabled = True;
			Button6->Enabled = True;
			Button7->Enabled = True;
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	AnsiString time = String(ltm->tm_hour)+":"+String(ltm->tm_min)+":"+String(ltm->tm_sec);
	AnsiString date = Date();
    Memo2->Lines->Clear();
	Memo2->Lines->Add(date+","+time+",Test Message\r\n");
}
//---------------------------------------------------------------------------
