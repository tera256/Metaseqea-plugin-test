//������ƕς��Ă݂�

#include "Test_CustomMenue.h"
#include "resource.h"

extern HINSTANCE hInstance;

//Window�v���V�[�W��
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
//    �v���O�C��ID��Ԃ��B
//---------------------------------------------------------------------------
void Test_CustomMenue::GetPlugInID(DWORD *Product, DWORD *ID)
{
	// �v���_�N�g��(����Җ�)��ID���A�S����64bit�̒l�Ƃ��ĕԂ�
	// �l�͑��Əd�����Ȃ��悤�ȃ����_���Ȃ��̂ŗǂ�
	*Product = 0x00000000;
	*ID      = 0x00000000;
}


//---------------------------------------------------------------------------
//  ScissorPlugin::GetPlugInName
//    �v���O�C������Ԃ��B
//---------------------------------------------------------------------------
const char *Test_CustomMenue::GetPlugInName(void)
{
	return "CustomMenue";

}
	
//---------------------------------------------------------------------------
//  ScissorPlugin::EnumString
//    �{�^���ɕ\������镶�����Ԃ��B
//---------------------------------------------------------------------------
const char *Test_CustomMenue::EnumString(void)
{
	return "CustomMenue";
}

//---------------------------------------------------------------------------
//  ScissorPlugin::Initialize
//    �A�v���P�[�V�����̏�����
//---------------------------------------------------------------------------
BOOL Test_CustomMenue::Initialize()
{	
	/*
	// �J�[�\�������[�h
	if(hFace3Cursor == NULL)
	{
		hFace3Cursor = (HCURSOR)LoadImage(hInstance, MAKEINTRESOURCE(IDC_CURSOR_FACE3), IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	}

	if(hFace4Cursor == NULL)
	{
		hFace4Cursor = (HCURSOR)LoadImage(hInstance, MAKEINTRESOURCE(IDC_CURSOR_FACE4), IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	}
	*/
	// ���ɉ������Ȃ��̂ŁA���̂܂�TRUE��Ԃ�
	return TRUE;
}

//---------------------------------------------------------------------------
//  ScissorPlugin::Exit
//    �A�v���P�[�V�����̏I��
//---------------------------------------------------------------------------
void Test_CustomMenue::Exit()
{
	//DestroyWindow(hMainDialog);
	//hMainDialog = NULL;
	//document = NULL;
}


//---------------------------------------------------------------------------
//  ScissorPlugin::Activate
//    �\���E��\���؂�ւ��v��
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
	// ���̂܂�flag��Ԃ�
	return flag;
}

//---------------------------------------------------------------------------
//  GetPluginClass
//    �v���O�C���̃x�[�X�N���X��Ԃ�
//---------------------------------------------------------------------------
MQBasePlugin *GetPluginClass()
{
	return Test_CustomMenue::GetInstance();
}



//---------------------------------------------------------------------------
//  OnNewDocument
//    Windows �_�C�A���O�{�b�N�X���쐬����
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



//�E�B���h�E�v���V�[�W���𗘗p�����ꍇ�̏���������
LRESULT CALLBACK MainDlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){

	switch (message)
	{
	case WM_LBUTTONDOWN:
		MessageBox(hwnd , TEXT("�I���ɂ��") ,
			 TEXT("Kitty") , MB_ICONINFORMATION);
		break;
	default:
		break;
	}
	return FALSE;
}