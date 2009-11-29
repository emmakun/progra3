#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = 0);
    ~Principal();

private:
    Ui::Principal *ui;
};

#endif // PRINCIPAL_H
