#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QtGui/QMainWindow>
#include <QDir>
#include <QHash>
#include "SQLParser.h"
#include "yaml.h"

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
    SqlParser::Parser parser;
    SqlParser::SqlQuery query;
    QDir dir;

    void processQuery();
    void readTable(QList< QHash<QString, QString> >&, std::string&);
    void createTable();

public slots:
    void setWorkingDir();
    void clear();
    void clearAll();
    void parseQuery();
};

#endif // PRINCIPAL_H
