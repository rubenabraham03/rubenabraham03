//Ruben Abraham
#pragma once

#include <wx/wx.h>
using namespace std;

// MainFrame class represents the main window of the To-Do application
class MainFrame : public wxFrame
{
public:
    // Constructor for the MainFrame
    MainFrame(const wxString& title);

private:
    // Function to create and set up UI controls
    void CreateControls();

    // Function to bind event handlers for UI components
    void BindEventHandlers();

    // Function to load saved tasks from a file
    void AddSavedtasks();

    // Event handlers for UI component interactions
    void OnAddButtonClicked(wxCommandEvent& evt);
    void OnInputEnter(wxCommandEvent& evt);
    void OnListKeyDown(wxKeyEvent& evt);
    void OnClearButtonClicked(wxCommandEvent& evt);
    void OnWindowClosed(wxCloseEvent& evt);

    // Helper functions for task management
    void AddTaskFromInput();
    void DeleteSelectedTask();

    // UI components
    wxPanel* panel;               // Main panel
    wxStaticText* headlineText;   // Headline text for the application
    wxTextCtrl* inputField;       // Text input field for task descriptions
    wxButton* addButton;          // Button to add tasks
    wxCheckListBox* checkListBox;  // Check list box to display tasks
    wxButton* clearButton;         // Button to clear tasks
};

