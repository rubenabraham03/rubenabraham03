//Ruben Abraham

#include "MainFrame.h"
#include <wx/wx.h>
#include <vector>
#include <string>
#include "Task.h" // Assuming Task is defined in "Task.h"
using namespace std;

// Constructor for the main application window
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    // Initialize UI components and event handlers
    CreateControls();
    BindEventHandlers();
    AddSavedtasks();
}

// Function to create and set up UI controls
void MainFrame::CreateControls()
{
    // Font styles for text
    wxFont headlineFont(30, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD);
    wxFont mainFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_HEAVY);

    // Colors for UI elements
    wxColour backgroundColor(230, 230, 230); // Light gray background
    wxColour textColor(0, 0, 0); // Black text
    wxColour buttonTextBurgundy(128, 0, 32); // Burgundy text for buttons

    // Create the main panel
    panel = new wxPanel(this);
    panel->SetBackgroundColour(backgroundColor);
    panel->SetFont(mainFont);

    // Headline Text
    headlineText = new wxStaticText(panel, wxID_ANY, "To-Do List", wxPoint(0, 22), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL);
    headlineText->SetFont(headlineFont);
    headlineText->SetForegroundColour(textColor);

    // Input Field
    inputField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 80), wxSize(495, 35), wxTE_PROCESS_ENTER);

    // Add Button
    addButton = new wxButton(panel, wxID_ANY, "ADD", wxPoint(600, 80), wxSize(100, 35));
    addButton->SetForegroundColour(buttonTextBurgundy);

    // Check List Box
    checkListBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(100, 120), wxSize(600, 400));

    // Clear Button
    clearButton = new wxButton(panel, wxID_ANY, "CLEAR", wxPoint(100, 525), wxSize(100, 35));
    clearButton->SetForegroundColour(buttonTextBurgundy);
}

// Function to bind event handlers for UI components
void MainFrame::BindEventHandlers()
{
    addButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClicked, this);
    inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnInputEnter, this);
    checkListBox->Bind(wxEVT_KEY_DOWN, &MainFrame::OnListKeyDown, this);
    clearButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearButtonClicked, this);
    this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnWindowClosed, this);
}

// Function to load saved tasks from a file
void MainFrame::AddSavedtasks()
{
    vector<Task> tasks = loadTasksFromFile("tasks.txt");

    // Add loaded tasks to the checklist
    for (const Task& task : tasks) {
        int index = checkListBox->GetCount();
        checkListBox->Insert(task.description, index);
        checkListBox->Check(index, task.done);
    }
}

// Event handler for the "ADD" button clicked
void MainFrame::OnAddButtonClicked(wxCommandEvent& evt)
{
    AddTaskFromInput();
}

// Event handler for the Enter key in the input field
void MainFrame::OnInputEnter(wxCommandEvent& evt)
{
    AddTaskFromInput();
}

// Function to add a task from the input field
void MainFrame::AddTaskFromInput()
{
    wxString description = inputField->GetValue();

    // Add a task if the description is not empty
    if (!description.IsEmpty()) {
        checkListBox->Insert(description, checkListBox->GetCount());
        inputField->Clear();
    }

    // Set focus back to the input field for convenience
    inputField->SetFocus();
}

// Event handler for key down in the checklist
void MainFrame::OnListKeyDown(wxKeyEvent& evt)
{
    // Handle specific key events
    switch (evt.GetKeyCode()) {
    case WXK_DELETE:
        DeleteSelectedTask();
        break;
    }
}

// Event handler for the "CLEAR" button clicked
void MainFrame::OnClearButtonClicked(wxCommandEvent& evt)
{
    // Ask for confirmation before clearing all tasks
    if (checkListBox->IsEmpty()) {
        return;
    }

    wxMessageDialog dialog(this, "Are you sure you want to clear all tasks?", "Clear", wxYES_NO | wxCANCEL);
    int result = dialog.ShowModal();

    if (result == wxID_YES) {
        checkListBox->Clear();
    }
}

// Event handler for the window being closed
void MainFrame::OnWindowClosed(wxCloseEvent& evt)
{
    // Save the tasks to a file before closing
    vector<Task> tasks;
    for (int i = 0; i < checkListBox->GetCount(); i++) {
        Task task;
        task.description = checkListBox->GetString(i);
        task.done = checkListBox->IsChecked(i);
        tasks.push_back(task);
    }
    saveTasksToFile(tasks, "tasks.txt");
    evt.Skip();
}

// Function to delete the selected task
void MainFrame::DeleteSelectedTask()
{
    int selectedIndex = checkListBox->GetSelection();
    if (selectedIndex == wxNOT_FOUND) {
        return;
    }

    // Delete the selected task
    checkListBox->Delete(selectedIndex);
}
