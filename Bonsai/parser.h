#ifndef PARSER_H
#define PARSER_H

#include "sqlquery.h"
#include <QString>
#include <QStringList>
namespace SqlParser
{
    class Parser
    {
        QString _query;

        QueryType getType();
        QStringList getFields(QueryType);
        QStringList getTables(QueryType);
        QStringList getValues(QueryType);
        QString getConditions(QueryType);

        void parseFieldsSelect(QStringList&);
        void parseFieldsInsert(QStringList&);
        void parseFieldsUpdate(QStringList&);
        void parseFieldsCreate(QStringList&);

        void parseTablesSelect(QStringList&);
        void parseTablesInsert(QStringList&);
        void parseTablesUpdate(QStringList&);
        void parseTablesDelete(QStringList&);
        void parseTablesCreate(QStringList&);

        void parseValuesInsert(QStringList&);
        void parseValuesUpdate(QStringList&);

    public:
        Parser();
        Parser(const QString&);
        SqlQuery parse();

        //Getters
        QString query();

        //Setters
        void setQuery(const QString&);
    };
}

#endif // PARSER_H
