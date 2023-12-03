#pragma once
#include <wx/wx.h>
using namespace std;

class MainFrame: public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	void CreateControls();
	void BindEventHandlers();
	void AddSavedtasks();
	
	void OnAddButtonClicked(wxCommandEvent& evt);
	void OnInputEnter(wxCommandEvent& evt);
	void OnListKeyDown(wxKeyEvent& evt);
	void OnClearButtonClicked(wxCommandEvent& evt);
	void OnWindowClosed(wxCloseEvent& evt);

	void AddTaskFromInput();
	void DeleteSelectedTask();

	wxPanel* panel;
	wxStaticText* headlineText;
	wxTextCtrl* inputField;
	wxButton* addButton;
	wxCheckListBox* checkListBox;
	wxButton* clearButton;

};

