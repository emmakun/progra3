#include "principal.h"
#include "ui_principal.h"
#include <QDir>
#include <QFileDialog>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Principal)
{
    ui->setupUi(this);

    connect(ui->browseButton,SIGNAL(clicked()),this,SLOT(setWorkingDir()));
    connect(ui->actionClear,SIGNAL(triggered()),this,SLOT(clear()));
    connect(ui->actionClear_All,SIGNAL(triggered()),this,SLOT(clearAll()));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::setWorkingDir()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select a Directory"), QDir::currentPath());
    ui->lineDir->setText(dir);
}

void Principal::clear()
{
    ui->lineQuery->clear();
}

void Principal::clearAll()
{
    ui->lineDir->clear();
    ui->lineQuery->clear();
}
