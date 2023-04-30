//Includes
#include "Includes.h"
//Modular Variables
bool menuSoundPlaying = false;
bool fullBattleSoundPlaying = false;

//Functions
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

void isWin(QWidget* game, QLabel* backgroundLabel)
{
    QPixmap bkgnd("victoryroyale.png");
}
void isLose(QWidget* game, QLabel* backgroundLabel)
{
    QPixmap bkgnd("gameover.png");
}

void punchClick(QProgressBar* enemyHealth, QLabel* backgroundLabel)
{
    Player player;
    Enemy enemy;
    // Deal damage to the enemy
    int damage = player.punch();
    enemy.hp = enemy.hp - damage;

    // Show the punch animation for 2 seconds
    QPixmap bkgnd(":/new/prefix1/Scenes/Background_punch.png");
    backgroundLabel->setPixmap(bkgnd);
    enemyHealth->setValue(enemy.hp);
    //sleep for 2 seconds
    std::this_thread::sleep_for(std::chrono::seconds(2));
    //set to normal
    QPixmap bkgnd2(":/new/prefix1/Scenes/Background_normal.png");
    backgroundLabel->setPixmap(bkgnd2);
}

void kickClick(QProgressBar* enemyHealth, QLabel* backgroundLabel)
{
    Player player;
    Enemy enemy;
    // Show the kick animation for 3 seconds
    int damage = player.kick();
    enemyHealth->setValue(player.hp);

    if (damage == 0)
    {
        QPixmap bkgnd(":/new/prefix1/Scenes/Background_kick_block.png");
        backgroundLabel->setPixmap(bkgnd);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    else
    {
        QPixmap bkgnd2(":/new/prefix1/Scenes/Background_kick.png");
        backgroundLabel->setPixmap(bkgnd2);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    
    QPixmap bkgnd2(":/new/prefix1/Scenes/Background_normal.png");
    backgroundLabel->setPixmap(bkgnd2);
}

void specialClick(QProgressBar* enemyHealth, QLabel* backgroundLabel)
{
    Player player;
    Enemy enemy;
    // Deal damage to the enemy
    int damage = player.special_attack();
    enemyHealth->setValue(player.hp);

    if (damage == 0)
    {
        QPixmap bkgnd(":/new/prefix1/Scenes/Background_super_block.png");
        backgroundLabel->setPixmap(bkgnd);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    else
    {
        QPixmap bkgnd(":/new/prefix1/Scenes/Background_super.png");
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    QPixmap bkgnd2(":/new/prefix1/Scenes/Background_normal.png");
    backgroundLabel->setPixmap(bkgnd2);
}



//Main Function
int main(int argc, char* argv[])
{
    srand(time(NULL));

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
    if (isAudio && isAudio->isChecked()) {
        soundPlay();
    }

   // Create main window
    QMainWindow* mainWindow = new QMainWindow();

    // Create a new QWidget to use as the central widget
    QWidget* centralWidget = new QWidget(mainWindow);

    // Add the QOpenGLWidget as a child widget to the central widget
    QUiLoader load;
    QFile file2("Game.ui");
    file2.open(QIODevice::ReadWrite);
    QWidget* game = load.load(&file2);
    file2.close();
    if (!game) {
        qDebug() << "Failed to load UI file";
        return;
    }
    

  
    // Show the main window
    mainWindow->show();
    game->show();
    // ...
    gameLoopTimer.start();
        });

    // Show the menu
    menu->show();

    // Run the event loop
    return app.exec();

    delete menu;
   
}