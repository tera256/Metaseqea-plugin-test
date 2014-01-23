//ちょっと変えてみる

#include "Test_CustomMenue.h"
#include "resource.h"

extern HINSTANCE hInstance;

//Windowプロシージャ
LRESULT CALLBACK MainDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

Test_CustomMenue *Test_CustomMenue::singleton = NULL;

Test_CustomMenue::Test_CustomMenue()
{
}

Test_CustomMenue::Test_CustomMenue( const Test_CustomMenue& p )
{
}

Test_CustomMenue::~Test_CustomMenue()
{
}

Test_CustomMenue *Test_CustomMenue::GetInstance()
{
	if (singleton == NULL)
	{
		singleton = new Test_CustomMenue();
	}

	return singleton;
}


//---------------------------------------------------------------------------
//  ScissorPlugin::GetPlugInID
//    プラグインIDを返す。
//---------------------------------------------------------------------------
void Test_CustomMenue::GetPlugInID(DWORD *Product, DWORD *ID)
{
	// プロダクト名(制作者名)とIDを、全部で64bitの値として返す
	// 値は他と重複しないようなランダムなもので良い
	*Product = 0x00000000;
	*ID      = 0x00000000;
}


//---------------------------------------------------------------------------
//  ScissorPlugin::GetPlugInName
//    プラグイン名を返す。
//---------------------------------------------------------------------------
const char *Test_CustomMenue::GetPlugInName(void)
{
	return "CustomMenue";

}
	
//---------------------------------------------------------------------------
//  ScissorPlugin::EnumString
//    ボタンに表示される文字列を返す。
//---------------------------------------------------------------------------
const char *Test_CustomMenue::EnumString(void)
{
	return "CustomMenue";
}

//---------------------------------------------------------------------------
//  ScissorPlugin::Initialize
//    アプリケーションの初期化
//---------------------------------------------------------------------------
BOOL Test_CustomMenue::Initialize()
{	
	/*
	// カーソルをロード
	if(hFace3Cursor == NULL)
	{
		hFace3Cursor = (HCURSOR)LoadImage(hInstance, MAKEINTRESOURCE(IDC_CURSOR_FACE3), IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	}

	if(hFace4Cursor == NULL)
	{
		hFace4Cursor = (HCURSOR)LoadImage(hInstance, MAKEINTRESOURCE(IDC_CURSOR_FACE4), IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	}
	*/
	// 特に何もしないので、そのままTRUEを返す
	return TRUE;
}

//---------------------------------------------------------------------------
//  ScissorPlugin::Exit
//    アプリケーションの終了
//---------------------------------------------------------------------------
void Test_CustomMenue::Exit()
{
	//DestroyWindow(hMainDialog);
	//hMainDialog = NULL;
	//document = NULL;
}


//---------------------------------------------------------------------------
//  ScissorPlugin::Activate
//    表示・非表示切り替え要求
//---------------------------------------------------------------------------
BOOL Test_CustomMenue::Activate(MQDocument doc, BOOL flag)
{
	/*
	bActive = (flag == TRUE);

	if(flag)
	{
		ShowWindow(hMainDialog, SW_SHOW);
		SetActiveWindow(MQ_GetWindowHandle());
		
		SetFaceType(faceType);
	}
	else
	{
		ShowWindow(hMainDialog, SW_HIDE);
		
		creatingVertices.clear();
		creatingVertexIndices.clear();
		highlightVertex.object = -1;
		highlightVertex.vertex = -1;

		SetMouseCursor(GetResourceCursor(MQCURSOR_DEFAULT));
		
		RedrawAllScene();
	}
	*/
	// そのままflagを返す
	return flag;
}

//---------------------------------------------------------------------------
//  GetPluginClass
//    プラグインのベースクラスを返す
//---------------------------------------------------------------------------
MQBasePlugin *GetPluginClass()
{
	return Test_CustomMenue::GetInstance();
}



//---------------------------------------------------------------------------
//  OnNewDocument
//    Windows ダイアログボックスを作成する
//---------------------------------------------------------------------------
void Test_CustomMenue::OnNewDocument(MQDocument doc, const char *filename, NEW_DOCUMENT_PARAM& param)
{
	//HWND hHand = MQ_GetWindowHandle();
	document = doc;
	if(hMainDialog == NULL)
	{
		//hMainDialog = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG_MAIN), hHand, (DLGPROC)MainDlgProc);
		//hMainDialog = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG_MAIN), MQ_GetWindowHandle(), (DLGPROC)MainDlgProc);
	}
}



//ウィンドウプロシージャを利用した場合の処理を書く
LRESULT CALLBACK MainDlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){

	switch (message)
	{
	case WM_LBUTTONDOWN:
		MessageBox(hwnd , TEXT("終わるにゃん") ,
			 TEXT("Kitty") , MB_ICONINFORMATION);
		break;
	default:
		break;
	}
	return FALSE;
}