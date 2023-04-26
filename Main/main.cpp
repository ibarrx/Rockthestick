#include "Includes.h"



#pragma comment(lib, "winmm.lib")

void soundPlay()
{
    bool played = PlaySound(_T("sounds/fullBattleTheme.wav"), NULL, SND_LOOP | SND_ASYNC);
    std::cout << played << std::endl;
}

void menuSoundPlay()
{
    bool played = PlaySound(_T("sounds/MenuLoopable.wav"), NULL, SND_LOOP | SND_ASYNC);
    std::cout << played << std::endl;
}

int main(int argc, char* argv[])
{

    // Initialize Qt application
    QApplication app(argc, argv);
    bool playAudio = true;
    if (argc > 1)
    {
        std::string audioArg(argv[1]);
        if (audioArg == "False" || audioArg == "false")
        {
            playAudio = false;
        }
    }

    QUiLoader loader;
    QFile file("menu.ui");
    file.open(QIODevice::ReadOnly);
    QWidget* menu = loader.load(&file);
    file.close();
    if (!menu) {
        qDebug() << "Failed to load UI file";
        return 1;
    }
    QIcon icon("Rock.ico"); // Replace with your icon file path
    
    menu->setWindowIcon(icon);
    menu->setWindowTitle("RockTheStick");

    QCheckBox* isAudio = menu->findChild<QCheckBox*>("checkAudio");
    QPushButton* btnStartGame = menu->findChild<QPushButton*>("btnStartGame");

    QPixmap menuBkgnd("back.png");
    if (menuBkgnd.isNull()) {
        qDebug() << "Error loading image file";
        return;
    }

    QObject::connect(btnStartGame, &QPushButton::clicked, [menu, isAudio, &app]() {
        // Check if checkbox is checked
        if (isAudio && isAudio->isChecked()) {
            menuSoundPlay();
        }

    if (btnStartGame)
    {

    }

    // Close the widget
    menu->close();
        });

    // Load the UI file
    QUiLoader loader1;
    QFile file1("Widget.ui");
    file1.open(QIODevice::ReadOnly);
    QWidget* widget = loader.load(&file1);
    file1.close();
    if (!widget) {
        qDebug() << "Failed to load UI file";
        return 1;
    }
    widget->setWindowIcon(icon);
    widget->setWindowTitle("RockTheStick");

    // Find the isTraining checkbox and btnGo button by name
    QCheckBox* checkbox = widget->findChild<QCheckBox*>("isTraining");
    QPushButton* button = widget->findChild<QPushButton*>("btnGo");

    // Connect button click event to slot
    QObject::connect(button, &QPushButton::clicked, [widget, checkbox, &app]() {
        // Check if checkbox is checked
        if (checkbox && checkbox->isChecked()) {
            qDebug() << "Is Training checkbox is checked";
        }
        else {
            qDebug() << "Is Training checkbox is not checked";
        }

    // Close the widget
    widget->close();



    // Create main window
    QMainWindow* mainWindow = new QMainWindow();
    mainWindow->setWindowTitle("RockTheStick");
    mainWindow->setGeometry(100, 100, 816, 489); // Set window geometry

    // Set window icon
    QIcon icon2("Rock.ico");
    mainWindow->setWindowIcon(icon2);

    // Load and scale background image
    QPixmap bkgnd("bg.png");
    if (bkgnd.isNull()) {
        qDebug() << "Error loading image file";
        return;
    }
    QSize mainWindowSize = mainWindow->size(); // Access size of mainWindow
    bkgnd = bkgnd.scaled(mainWindowSize, Qt::IgnoreAspectRatio); // Scale background image to mainWindow size

    // Create a QLabel for displaying the background image
    QLabel* backgroundLabel = new QLabel(mainWindow);
    backgroundLabel->setPixmap(bkgnd);
    backgroundLabel->setGeometry(0, 0, mainWindow->width(), mainWindow->height());
    backgroundLabel->setScaledContents(true); // Set to stretch the background image
    backgroundLabel->lower(); // Lower the background image to the bottom of the widget

    // Center the main window on the screen
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    int x = (screenGeometry.width() - mainWindow->width()) / 2;
    int y = (screenGeometry.height() - mainWindow->height()) / 2;
    mainWindow->move(x, y);

    // Show the main window

    mainWindow->show();
        });


    // Show the widget
    widget->show();
    if (playAudio)
    {
        soundPlay();
    }
    // Run the event loop
    return app.exec();
}