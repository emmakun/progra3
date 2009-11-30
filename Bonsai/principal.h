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

public slots:
    void setWorkingDir();
    void clear();
    void clearAll();
};

#endif // PRINCIPAL_H
