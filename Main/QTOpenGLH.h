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

    void paintGL()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    }

    void resizeGL(int w, int h) override
    {
        glViewport(0, 0, w, h);
    }
};