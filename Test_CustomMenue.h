#pragma once

#include <windows.h>
#include "MQBasePlugin.h"
#include "MQSetting.h"

class Test_CustomMenue :
	public MQCommandPlugin
{
	//Window プロシージャー
	friend LRESULT CALLBACK MainDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	
private:
	static Test_CustomMenue *singleton;
	MQDocument document;
	HWND hMainDialog;

public:
	static Test_CustomMenue* GetInstance();

	// プラグインIDを返す。
	virtual void GetPlugInID(DWORD *Product, DWORD *ID);
	// プラグイン名を返す。
	virtual const char *GetPlugInName();
	// ポップアップメニューに表示される文字列を返す。
	virtual const char *EnumString();
	// アプリケーションの初期化
	virtual BOOL Initialize();
	// アプリケーションの終了
	virtual void Exit();
	// 表示・非表示切り替え要求
	virtual BOOL Activate(MQDocument doc, BOOL flag);
	//ドキュメント初期化
	virtual void OnNewDocument(MQDocument doc, const char *filename, NEW_DOCUMENT_PARAM& param);


private:
	Test_CustomMenue();
	Test_CustomMenue( const Test_CustomMenue& p );
	~Test_CustomMenue();
};

