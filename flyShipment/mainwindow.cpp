#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"

#include <QDialog>
#include <QDebug>
#include <QColorDialog>
#include <QGraphicsPixmapItem>

#include "dialogmodel.h"
#include "dialogship.h"

#include "camera.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(900, 600);
    ui->model->toggle();
    ui->graphicsView->setFixedSize(screen_size_x, screen_size_y);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene.setSceneRect(-screen_size_x / 2, -screen_size_y / 2, screen_size_x, screen_size_y);

    pixmap = new QPixmap(screen_size_x, screen_size_y);
    painter = new QPainter(pixmap);

    connect(ui->about, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->InfoButtons, SIGNAL(triggered()), this, SLOT(info_buttons()));
    connect(ui->create_model, SIGNAL(triggered()), this, SLOT(create_model()));
    connect(ui->create_ship, SIGNAL(triggered()), this, SLOT(create_ship()));
    connect(ui->download_model, SIGNAL(triggered()), this, SLOT(load_model()));
    connect(ui->download_ship, SIGNAL(triggered()), this, SLOT(load_ship()));
    connect(ui->exit, SIGNAL(triggered()), this, SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete painter;
    delete pixmap;
    delete ui;
}

void MainWindow::info_buttons() {
    QMessageBox::information(this, "Help", "Some text");
}

void MainWindow::about() {
    QMessageBox::information(this, "Help", "Some text");
}

void MainWindow::create_model() {
    DialogModel dmodel;
    dmodel.exec();

    if ((dmodel.Lvalue() != 0) && (dmodel.Wvalue() != 0) && (dmodel.Hvalue() != 0) ) {
        model_s.L = dmodel.Lvalue();
        model_s.H = dmodel.Hvalue();
        model_s.W = dmodel.Wvalue();
    }

    manager.model.createModel(model_s.L, model_s.H, model_s.W);
    manager.active_object = &(manager.model);

    visualize_model();
}

void MainWindow::create_ship() {
    DialogShip dship;
    dship.exec();

    if ((dship.Lvalue() != 0) && (dship.Wbvalue() != 0) && (dship.Hvalue() != 0) && (dship.Wtvalue() != 0)) {
        ship_s.H = dship.Hvalue();
        ship_s.L = dship.Lvalue();
        ship_s.Wb = dship.Wbvalue();
        ship_s.Wt = dship.Wtvalue();
    }

    manager.ship.createShip(ship_s.L, ship_s.H, ship_s.Wt, ship_s.Wb);
    manager.active_object = &(manager.ship);

    visualize_ship();
}

void MainWindow::load_model() {
    QString file_path = QFileDialog::getOpenFileName(this, tr("Выберите файл"), tr(""), tr("*.txt"));
    if (file_path.isEmpty()) {
        return;
    }

    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Невозможно открыть файл"), file.errorString());
        return;
    }

    QTextStream in(&file);

    while (in.status() == QTextStream::Ok) {

        float l, w, h;
        in >> l >> h >> w;

        model_s.H = h;
        model_s.L = l;
        model_s.W = w;
    }

    file.close();
}

void MainWindow::load_ship() {
    QString file_path = QFileDialog::getOpenFileName(this, tr("Выберите файл"), tr(""), tr("*.txt"));
    if (file_path.isEmpty()) {
        return;
    }

    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Невозможно открыть файл"), file.errorString());
        return;
    }

    QTextStream in(&file);

    while (in.status() == QTextStream::Ok) {

        float l, wb, h, wt;
        in >> l >> h >> wt >> wb;

        ship_s.L = l;
        ship_s.H = h;
        ship_s.Wt = wt;
        ship_s.Wb = wb;

    }

    file.close();
}

void MainWindow::visualize_model() {
    scene.clear();

    for (ModelPolygon& pol : manager.model.model) {
        if (manager.check_visible_m()) {

            QVector<QPoint> polyvector;
            for (Edge& edge : pol.mpolygon) {

                polyvector.push_back(manager.camera.to_screen(edge.begin));
                polyvector.push_back(manager.camera.to_screen(edge.end));

            }

            QPolygon polygon(polyvector);
            scene.addPolygon(polygon,QPen());

        }

    }

}

void MainWindow::visualize_ship() {

    for (ShipPolygon& pol : manager.ship.ship) {
        if (manager.check_visible_s()) {

            QVector<QPoint> polyvector;
            for (Edge& edge : pol.spolygon) {

                polyvector.push_back(manager.camera.to_screen(edge.begin));
                polyvector.push_back(manager.camera.to_screen(edge.end));

            }

            QPolygon polygon(polyvector);
            scene.addPolygon(polygon, QPen());

        }

    }

}


void MainWindow::on_clearScr_clicked()
{
    scene.clear();
}

void MainWindow::on_model_toggled(bool checked)
{
    if (checked) {
        visualize_model();
    }
}

void MainWindow::on_ship_toggled(bool checked)
{
    if (checked) {
        visualize_ship();
    }
}

void MainWindow::on_camera_toggled(bool checked)
{

}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    if (manager.active_object != nullptr) {
        Point zero(0, 0, 0);
        switch(e->key()) {
//			move
            case Qt::Key_Q :
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(0, 0, -move_speed);
                } else {
                    manager.active_object->move(0, 0, -move_speed);
                }
                break;

            case Qt::Key_E:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(0, 0, move_speed);
                } else {
                    manager.active_object->move(0, 0, move_speed);
                }
                break;
            case Qt::Key_W:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(0, move_speed, 0);
                } else {
                    manager.active_object->move(0, -move_speed, 0);
                }
                break;
            case Qt::Key_S:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(0, -move_speed, 0);
                } else {
                    manager.active_object->move(0, move_speed, 0);
                }
                break;

            case Qt::Key_A :
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(move_speed, 0, 0);
                } else {
                    manager.active_object->move(-move_speed, 0, 0);
                }
                break;

            case Qt::Key_D:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.move(-move_speed, 0, 0);
                } else {
                    manager.active_object->move(move_speed, 0, 0);
                }
                break;
//			rotate
            case Qt::Key_K:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(0, -rotate_speed, 0, zero);
                } else {
                    manager.active_object->rotate(0, rotate_speed, 0);
                }
                break;
            case Qt::Key_I:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(0, rotate_speed, 0, zero);
                } else {
                    manager.active_object->rotate(0, -rotate_speed, 0);
                }
                break;
            case Qt::Key_L:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(0, 0, -rotate_speed, zero);
                } else {
                    manager.active_object->rotate(0, 0, rotate_speed);
                }
                break;
            case Qt::Key_J:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(0, 0, rotate_speed, zero);
                } else {
                    manager.active_object->rotate(0, 0, -rotate_speed);
                }
                break;
            case Qt::Key_O:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(-rotate_speed, 0, 0, zero);
                } else {
                    manager.active_object->rotate(-rotate_speed, 0, 0);
                }
                break;
            case Qt::Key_U:
                if (e->modifiers() & Qt::ShiftModifier) {
                    manager.model.rotate(rotate_speed, 0, 0, zero);
                } else {
                    manager.active_object->rotate(rotate_speed, 0, 0);
                }
                break;
//			resize
            case Qt::Key_T:
                manager.active_object->resize(resize_speed);
                break;
            case Qt::Key_Y:
                manager.active_object->resize(1/resize_speed);
                break;
            default:
                break;
        }
    }
    if (ui->model->isChecked()) {
        visualize_model();
    } else {
        visualize_ship();
    }
}
