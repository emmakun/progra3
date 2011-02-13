#include "principal.h"
#include "ui_principal.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <fstream>
//#include "yaml.h"

void operator >> (const YAML::Node& node, QHash<QString, QString> row)
{
    using namespace std;
    for(YAML::Iterator it = node.begin();it!=node.end();++it)
    {
        string field, value;
        it.first() >> field;
        it.second() >> value;

        row.insert(QString::fromStdString(field), QString::fromStdString(value));
    }
}

Principal::Principal(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Principal)
{
    ui->setupUi(this);

    connect(ui->browseButton,SIGNAL(clicked()),this,SLOT(setWorkingDir()));
    connect(ui->actionClear,SIGNAL(triggered()),this,SLOT(clear()));
    connect(ui->actionClear_All,SIGNAL(triggered()),this,SLOT(clearAll()));
    connect(ui->runButton, SIGNAL(clicked()),this,SLOT(parseQuery()));
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
    ui->textQuery->clear();
}

void Principal::clearAll()
{
    ui->lineDir->clear();
    ui->textQuery->clear();
}

void Principal::parseQuery()
{
    QString path = ui->lineDir->text();
    if(!path.isEmpty() && !path.isNull())
    {
        dir.setPath(path);
        if(dir.exists())
        {
            parser.setQuery(ui->textQuery->toPlainText());

            query = parser.parse();

            if(query.isValid())
            {
                ui->textQuery->setPlainText("Es una consulta válida...");
            }
            else
                QMessageBox::information(this, tr("Bonsai"), tr("The query format is not valid."));
        }
        else
            QMessageBox::information(this, tr("Bonsai"), tr("The directory doesn't exists.\nPlease select a valid directory."));
    }
    else
        QMessageBox::information(this, tr("Bonsai"), tr("The working directory can't be empty."));
}

void Principal::processQuery()
{
    using namespace SqlParser;
    switch(query.type())
    {
        case SELECT:
        break;
        case INSERT:
        break;
        case DELETE:
        break;
        case UPDATE:
        break;
        case CREATE:
        break;
    }
}

void readTable(QList< QHash<QString, QString> >& fields, std::string& file)
{
    using namespace std;
    
    ifstream fin(file.c_str());
    
    YAML::Parser yparser(fin);
    YAML::Node doc;
    
    yparser.GetNextDocument(doc);
    
    for(unsigned i=0;i<doc.size();i++)
    {
        QHash<QString, QString> row;
        doc[i] >> row;
        fields.append(row);
    }
}

void Principal::createTable()
{
    QString file = dir.path() + query.tables()[0] + ".yml";
    if(!QFile::exists(file))
    {
        
    }
    else
        QMessageBox::information(this, tr("Bonsai"), tr("The table already exists."));
}
