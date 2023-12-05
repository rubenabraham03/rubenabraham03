//Ruben Abraham

#include "App.h"
#include "MainFrame.h"

// Entry point for the application
wxIMPLEMENT_APP(App);

// Initialization function called when the application starts
bool App::OnInit()
{
    // Create the main application window
    MainFrame* mainFrame = new MainFrame("To-Do Application");

    // Set the initial size of the main window
    mainFrame->SetClientSize(800, 600);

    // Center the main window on the screen
    mainFrame->Center();

    // Display the main window
    mainFrame->Show();

    // Indicate successful initialization
    return true;
}
