#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QClipboard>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    getColor = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *)
{
    getColor = true;
}

void MainWindow::mouseMoveEvent(QMouseEvent *)
{
    if(getColor) {
        QScreen *screen = QGuiApplication::primaryScreen();
        QPixmap pixmap = screen->grabWindow(0, QCursor::pos().x(), QCursor::pos().y(), 1, 1);
        // convert pixmap to QImage so we can access pixel data crossplatform
        QImage img = pixmap.toImage();
        // image has only one pixel at coords (0,0), get its color
        QColor col = QColor(img.pixel(0,0));
        ui->color_label->setStyleSheet(QString("background-color:%1;border: 1px solid grey;").arg(col.name()));
        ui->hex_color->setText(col.name().toUpper());
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    getColor = false;
}

void MainWindow::on_copy_hex_clicked()
{
    // copy color to clipboard
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->hex_color->text());
}
