#pragma once

#include <windows.h>
#include "MQBasePlugin.h"
#include "MQSetting.h"

class Test_CustomMenue :
	public MQCommandPlugin
{
	//Window �v���V�[�W���[
	friend LRESULT CALLBACK MainDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	
private:
	static Test_CustomMenue *singleton;
	MQDocument document;
	HWND hMainDialog;

public:
	static Test_CustomMenue* GetInstance();

	// �v���O�C��ID��Ԃ��B
	virtual void GetPlugInID(DWORD *Product, DWORD *ID);
	// �v���O�C������Ԃ��B
	virtual const char *GetPlugInName();
	// �|�b�v�A�b�v���j���[�ɕ\������镶�����Ԃ��B
	virtual const char *EnumString();
	// �A�v���P�[�V�����̏�����
	virtual BOOL Initialize();
	// �A�v���P�[�V�����̏I��
	virtual void Exit();
	// �\���E��\���؂�ւ��v��
	virtual BOOL Activate(MQDocument doc, BOOL flag);
	//�h�L�������g������
	virtual void OnNewDocument(MQDocument doc, const char *filename, NEW_DOCUMENT_PARAM& param);


private:
	Test_CustomMenue();
	Test_CustomMenue( const Test_CustomMenue& p );
	~Test_CustomMenue();
};

