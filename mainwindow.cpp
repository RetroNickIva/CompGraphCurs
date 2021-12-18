#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    objproc = new OBJ_Processor(ui->l_drawspace,ui->l_drawspace);

    vertex prisma1[8] = {
        {   2.000000,  1.000000, -1.000000  },
        {   2.000000, -1.000000, -1.000000  },
        {   2.000000,  1.000000,  1.000000  },
        {   2.000000, -1.000000,  1.000000  },
        {  -2.000000,  1.000000, -1.000000  },
        {  -2.000000, -1.000000, -1.000000  },
        {  -2.000000,  1.000000,  1.000000  },
        {  -2.000000, -1.000000,  1.000000  }
    };

    int prisma1_indicies[36] = {
        5, 3, 1,
        3, 8, 4,
        7, 6, 8,
        2, 8, 6,
        1, 4, 2,
        5, 2, 6,
        5, 7, 3,
        3, 7, 8,
        7, 5, 6,
        2, 4, 8,
        1, 3, 4,
        5, 1, 2
    };

    for (int i = 0; i < 36; ++i) {
        prisma1_indicies[i]--;
    }

    vertex prisma2[8] = {
        {  -5.386903,  1.000000, -1.000000  },
        {  -5.386903, -1.000000, -1.000000  },
        {  -5.386903,  1.000000,  1.000000  },
        {  -5.386903, -1.000000,  1.000000  },
        {  -9.386903,  1.000000, -1.000000  },
        {  -9.386903, -1.000000, -1.000000  },
        {  -9.386903,  1.000000,  1.000000  },
        {  -9.386903, -1.000000,  1.000000  }
    };

    int prisma2_indicies[72] = {
        5, 3, 1,
        3, 8, 4,
        7, 6, 8,
        2, 8, 6,
        1, 4, 2,
        5, 2, 6,
        5, 7, 3,
        3, 7, 8,
        7, 5, 6,
        2, 4, 8,
        1, 3, 4,
        5, 1, 2
    };

    for (int i = 0; i < 36; ++i) {
        prisma2_indicies[i]--;
    }

    objproc->set_light({-4,-4,-4});
    objproc->add_object(prisma1,prisma1_indicies,8,36,qRgb(70,130,180),{2,0,0});
    objproc->add_object(prisma2,prisma2_indicies,8,36,qRgb(138,43,226),{0,-0.9,0},{0.14,-0.5,0});
}

MainWindow::~MainWindow() {
    delete objproc;
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if( event->key() == Qt::Key_Space ) {
        objproc->draw = !objproc->draw;
    }

    if( event->key() == Qt::Key_W ) {
        objproc->w_state = true;
    }
    if( event->key() == Qt::Key_S ) {
        objproc->s_state = true;
    }
    if( event->key() == Qt::Key_A ) {
        objproc->a_state = true;
    }
    if( event->key() == Qt::Key_D ) {
        objproc->d_state = true;
    }
    if ( event->key() == Qt::Key_E) {
        objproc->ctrl_state = true;
    }
    if ( event->key() == Qt::Key_Q) {
        objproc->space_state = true;
    }

    // вращение призма + -
    if( event->key() == Qt::Key_P ) {
        objproc->rotate(0,0.05,0,0);
    }
    if( event->key() == Qt::Key_BracketLeft ) {
        objproc->rotate(0,0,0.05,0);
    }
    if( event->key() == Qt::Key_BracketRight ) {
        objproc->rotate(0,0,0,0.05);
    }

    if( event->key() == Qt::Key_L ) {
        objproc->rotate(0,-0.05,0,0);
    }
    if( event->key() == Qt::Key_Semicolon) {
        objproc->rotate(0,0,-0.05,0);
    }
    if( event->key() == Qt::Key_Apostrophe ) {
        objproc->rotate(0,0,0,-0.05);
    }

    // вращение призма + -
    if( event->key() == Qt::Key_U ) {
        objproc->rotate(1,0.05,0,0);
    }
    if( event->key() == Qt::Key_I) {
        objproc->rotate(1,0,0.05,0);
    }
    if( event->key() == Qt::Key_O ) {
        objproc->rotate(1,0,0,0.05);
    }

    if( event->key() == Qt::Key_H ) {
        objproc->rotate(1,-0.05,0,0);
    }
    if( event->key() == Qt::Key_J) {
        objproc->rotate(1,0,-0.05,0);
    }
    if( event->key() == Qt::Key_K ) {
        objproc->rotate(1,0,0,-0.05);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if( event->key() == Qt::Key_W ) {
        objproc->w_state = false;
    }
    if( event->key() == Qt::Key_S ) {
        objproc->s_state = false;
    }
    if( event->key() == Qt::Key_A ) {
        objproc->a_state = false;
    }
    if( event->key() == Qt::Key_D ) {
        objproc->d_state = false;
    }
    if ( event->key() == Qt::Key_E) {
        objproc->ctrl_state = false;
    }
    if ( event->key() == Qt::Key_Q) {
        objproc->space_state = false;
    }
}
