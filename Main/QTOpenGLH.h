#pragma once


#include "Includes.h"
class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    GLWidget(QWidget* parent = nullptr) : QOpenGLWidget(parent) {}



protected:
    void initializeGL() override
    {
        initializeOpenGLFunctions();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    //void paintGL()
    //{
    //    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //    // Create a QPainter to draw the character
    //    QPainter painter(glWidget);
    //    painter.drawPixmap(character->character->xPos, character->character->yPos, QPixmap(character->image_file.c_str()));

    //    // Update the character's position
    //    character->character->update(0.1f);

    //}

    void resizeGL(int w, int h) override
    {
        glViewport(0, 0, w, h);
    }
};


