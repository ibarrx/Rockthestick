#include "Includes.h"

#pragma comment(lib, "winmm.lib")
bool menuSoundPlaying = false;
bool fullBattleSoundPlaying = false;

void soundPlay()
{
    fullBattleSoundPlaying = true;
    bool played = PlaySound(_T("sounds/fullBattleTheme.wav"), NULL, SND_LOOP | SND_ASYNC);
    std::cout << played << std::endl;
}

void menuSoundPlay()
{
    menuSoundPlaying = true;
    bool played = PlaySound(_T("sounds/MenuLoopable.wav"), NULL, SND_LOOP | SND_ASYNC);
    std::cout << played << std::endl;
}

void stopMenuSound()
{
    if (menuSoundPlaying)
    {
        PlaySound(NULL, NULL, 0);
        menuSoundPlaying = false;
    }
}

void stopFullBattleSound()
{
    if (fullBattleSoundPlaying)
    {
        PlaySound(NULL, NULL, 0);
        fullBattleSoundPlaying = false;
    }
}

int main(int argc, char* argv[])
{
    // Initialize Qt application
    QApplication app(argc, argv);
    QIcon icon("Rock.ico");

    QUiLoader loader;
    QFile file("menu.ui");
    file.open(QIODevice::ReadOnly);
    QWidget* menu = loader.load(&file);
    file.close();
    if (!menu) {
        qDebug() << "Failed to load UI file";
        return 1;
    }

    menu->setWindowIcon(icon);
    menu->setWindowTitle("RockTheStick");

    QCheckBox* isAudio = menu->findChild<QCheckBox*>("checkAudio");
    QPushButton* btnStartGame = menu->findChild<QPushButton*>("btnStartGame");

    if (isAudio && isAudio->isChecked()) {
        menuSoundPlay();
    }

    QPixmap menuBkgnd("back.png");
    if (menuBkgnd.isNull()) {
        qDebug() << "Error loading image file";
    }
    QSize menuSize = menu->size();
    menuBkgnd = menuBkgnd.scaled(menuSize, Qt::IgnoreAspectRatio);

    // Create a QLabel for displaying the background image
    QLabel* backgroundLabel1 = new QLabel(menu);
    backgroundLabel1->setPixmap(menuBkgnd);
    backgroundLabel1->setGeometry(0, 0, menu->width(), menu->height());
    backgroundLabel1->setScaledContents(true); // Set to stretch the background image
    backgroundLabel1->lower(); // Lower the background image to the bottom of the widget

    QRect screen1 = QGuiApplication::primaryScreen()->geometry();
    int x = (screen1.width() - menu->width()) / 2;
    int y = (screen1.height() - menu->height()) / 2;
    menu->move(x, y);

    QObject::connect(isAudio, &QCheckBox::clicked, [menu, isAudio]() {
        if (isAudio && isAudio->isChecked()) {
            menuSoundPlay();
        }
        else if (isAudio && !isAudio->isChecked()) {
            stopMenuSound();
        }
        });



    QObject::connect(btnStartGame, &QPushButton::clicked, [menu, isAudio, &app, btnStartGame, icon]() {

    if (btnStartGame)
    {
        menu->close();
        stopMenuSound();
    }

    // Load the UI file
    QUiLoader loader1;
    QFile file1("Widget.ui");
    file1.open(QIODevice::ReadOnly);
    QWidget* widget = loader1.load(&file1);
    file1.close();
    if (!widget) {
        qDebug() << "Failed to load UI file";
        return;
    }
    widget->setWindowIcon(icon);
    widget->setWindowTitle("RockTheStick");

    // Find the isTraining checkbox and btnGo button by name
    QCheckBox* checkbox = widget->findChild<QCheckBox*>("isTraining");
    QPushButton* button = widget->findChild<QPushButton*>("btnGo");

    // Connect button click event to slot
    QObject::connect(button, &QPushButton::clicked, [widget, checkbox, isAudio, &app, icon]() {
        if (checkbox && checkbox->isChecked()) {
            qDebug() << "Is Training checkbox is checked";
        }
        else {
            qDebug() << "Is Training checkbox is not checked";
        }

    if (isAudio && isAudio->isChecked()) {
        soundPlay();
    }

    // Close the widget
    widget->close();

    // Create main window
    QMainWindow* mainWindow = new QMainWindow();
    mainWindow->setWindowTitle("RockTheStick");
    mainWindow->setGeometry(100, 100, 816, 489); // Set window geometry

    // Set window icon
    mainWindow->setWindowIcon(icon);

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
    mainWindow->setMaximumHeight(mainWindow->height());
    mainWindow->setMaximumWidth(mainWindow->width());
    // Show the main window
    mainWindow->show();
        });

    // Show the widget
    widget->show();
        });

    // Show the menu
    menu->show();
    // Run the event loop
    return app.exec();
}