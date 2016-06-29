/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "gamewidget.h"
#include "player.h"
#include "widget.h"
#include "window.h"

#include <QGridLayout>
#include <QLabel>
#include <QTimer>
#include <stdio.h>
#include <QKeyEvent>

//! [0]
Window::Window()
{
    setWindowTitle(tr("Polandball Game"));
    Player * player = new Player(0, 0, 50, 1);
    GameWidget *openGL = new GameWidget(player, this);
    connect(this, SIGNAL(keyPress(int)), player, SLOT(handleInput(int)));
    connect(this, SIGNAL(keyRelease(int)), player, (SLOT(handleRelease(int))));
    printf("WE Started");
}

void Window::keyPressEvent(QKeyEvent * event){
    printf("KEY PRESSED\n");
    int key = event->key();
    emit keyPress(key);
    /*switch(key){
        case Qt::Key_Left:
            printf("LEFT PRESS\n");
            emit movement(-5, 0);
            break;
        case Qt::Key_Right:
            emit movement(5, 0);
            break;
        case Qt::Key_Up:
            emit movement(0, -5);
            break;
        case Qt::Key_Down:
            emit movement(0, 5);
            break;
    }*/
}

void Window::keyReleaseEvent(QKeyEvent *event){
    int key = event->key();
    emit keyRelease(key);
}

//! [0]