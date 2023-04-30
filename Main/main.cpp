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
    // Initialize game objects

    // Create a QLabel for displaying the background image
    QLabel* backgroundLabel = new QLabel(game);
    // Load and scale background image

    QPixmap bkgnd(":/new/prefix1/Scenes/Background_normal.png");
    if (bkgnd.isNull()) {
        qDebug() << "Error loading image file";
        return;
    }


    backgroundLabel->setPixmap(bkgnd);
    backgroundLabel->setGeometry(0, 0, game->width(), game->height());
    backgroundLabel->setScaledContents(true); // Set to stretch the background image
    backgroundLabel->lower(); // Lower the background image to the bottom of the widget 

    game->setParent(centralWidget);
    game->setGeometry(0, 0, 816, 489); // Set widget geometry

    // Set the central widget of the main window
    mainWindow->setCentralWidget(centralWidget);

    // Set window properties
    mainWindow->setWindowTitle("RockTheStick");
    mainWindow->setGeometry(100, 100, 816, 489); // Set window geometry
    mainWindow->setWindowIcon(icon);


    QSize mainWindowSize = game->size(); // Access size of mainWindow
    bkgnd = bkgnd.scaled(mainWindowSize, Qt::IgnoreAspectRatio); // Scale background image to mainWindow size


    // Center the main window on the screen
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    int x = (screenGeometry.width() - mainWindow->width()) / 2;
    int y = (screenGeometry.height() - mainWindow->height()) / 2;
    mainWindow->move(x, y);
    mainWindow->setMaximumHeight(mainWindow->height());
    mainWindow->setMaximumWidth(mainWindow->width());

    enum class GameState { PlayerTurn, EnemyTurn, GameOver };
    GameState currentState = GameState::PlayerTurn;
    QTimer gameLoopTimer;
    gameLoopTimer.setInterval(1000 / 60); // Set the interval to 60 times per second (approx. 16ms per frame)
        // Game loop
        QTimer animationTimer;
        animationTimer.setSingleShot(true);
        QObject::connect(&animationTimer, &QTimer::timeout, [&backgroundLabel]() {
            // Set the background to the default image after the animation duration has elapsed
            backgroundLabel->setPixmap(QPixmap(":/new/prefix1/Scenes/Background_normal.png"));
            });
        bool playerTurn = true;
            QPushButton* btnPunch = game->findChild<QPushButton*>("btnPunch");
            QPushButton* btnKick = game->findChild<QPushButton*>("btnKick");
            QPushButton* btnSpecial = game->findChild<QPushButton*>("btnSpecial");
            QProgressBar* playerHealth = game->findChild<QProgressBar*>("playerHealth");
            QProgressBar* enemyHealth = game->findChild<QProgressBar*>("enemyHealth");
            Enemy enemy;
            Character lose;
            Player player;

            player.hp = 100;
            enemy.hp = 100;

            // Handle events (e.g., button clicks, key presses)
            if (playerTurn) {
                QObject::connect(btnPunch, &QPushButton::clicked, [&player, &enemy, backgroundLabel,&animationTimer, enemyHealth]() {
                // Deal damage to the enemy
                int damage = player.punch();
                enemy.hp = enemy.hp - damage;
                enemyHealth->setValue(enemy.hp);
                // Show the punch animation for 3 seconds
                delete[] backgroundLabel;
                QPixmap bkgnd(":/new/prefix1/Scenes/Background_punch.png");
                backgroundLabel->setPixmap(bkgnd);
                //animationTimer.start(3000);
                    });

                QObject::connect(btnKick, &QPushButton::clicked, [&player, &enemy, &backgroundLabel, &animationTimer, playerHealth]() {
                    // Show the kick animation for 3 seconds
                    int damage = player.kick();
                    playerHealth->setValue(player.hp);

                if (damage == 0)
                {
                    backgroundLabel->setPixmap(QPixmap(":/new/prefix1/Scenes/Background_kick_block.png"));
                    animationTimer.start(3000);
                }
                else
                {
                    backgroundLabel->setPixmap(QPixmap(":/new/prefix1/Scenes/Background_kick.png"));
                    animationTimer.start(3000);
                }
                    });

                QObject::connect(btnSpecial, &QPushButton::clicked, [&player, &enemy, &backgroundLabel, &animationTimer, playerHealth]() {
                    // Deal damage to the enemy
                    int damage = player.special_attack();
                    playerHealth->setValue(player.hp);

                if (damage == 0)
                {
                    backgroundLabel->setPixmap(QPixmap(":/new/prefix1/Scenes/Background_super_block.png"));
                    animationTimer.start(3000);
                }
                else
                {
                    backgroundLabel->setPixmap(QPixmap(":/new/prefix1/Scenes/Background_super.png"));
                    animationTimer.start(3000);
                }
                    });

                // Check if the game is over
                if (player.isDead()) {
                    isLose(game, backgroundLabel);
                }

                playerTurn = false;
            }
            else {
                // Enemy's turn
                // Disable the buttons for the player's moves

                // Enemy makes a move
                enemy.randmove();
                int damage = 0; // Placeholder for the damage dealt by the enemy's move
                int moveType = rand() % 3; // Randomly choose the type of move (0 = punch, 1 = kick, 2 = special attack)
                switch (moveType) {
                case 0:
                    damage = enemy.punch();
                    player.hp = player.hp - damage;
                    backgroundLabel->setPixmap(QPixmap(":/images/punch_animation.png"));
                    animationTimer.start(3000);
                    break;
                case 1:
                    damage = enemy.kick();
                    player.hp = player.hp - damage;
                    if (damage == 0)
                    {
                        backgroundLabel->setPixmap(QPixmap(":/new/prefix1/Scenes/Background_e_kick_block.png"));
                        animationTimer.start(3000);
                    }
                    else
                    {
                        backgroundLabel->setPixmap(QPixmap(":/new/prefix1/Scenes/Background_e_kick.png"));
                        animationTimer.start(3000);
                    }
                    break;
                case 2:
                    damage = enemy.special_attack();
                    player.hp = player.hp - damage;
                    if (damage == 0)
                    {
                        backgroundLabel->setPixmap(QPixmap(":/new/prefix1/Scenes/Background_e_super.png"));
                        animationTimer.start(3000);
                    }
                    else
                    {
                        backgroundLabel->setPixmap(QPixmap(":/new/prefix1/Scenes/Background_e_super.png"));
                        animationTimer.start(3000);
                    }
                    break;
                default:
                    break;
                }
                // do something with damage, like subtract it from player health

                // Check if the game is over
                if (enemy.isDead()) {
                    isWin(game, backgroundLabel);
                }
                playerTurn = true;
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