#ifndef SQLQUERY_H
#define SQLQUERY_H

#include <QStringList>
#include <QString>

namespace SqlParser
{
    enum QueryType
    {
        SELECT,
        INSERT,
        UPDATE,
        CREATE,
        DELETE,
        UNKNOWN
    };

    class SqlQuery
    {
        QueryType _type;
        QStringList _fields;
        QStringList _tables;
        QStringList _values;
        QString _conditions;

    public:
        SqlQuery(); //constructor

        //Getters...
        QueryType type();
        QStringList fields();
        QStringList tables();
        QStringList values();
        QString conditions();
        bool isValid();

        //Setters
        void setType(const QueryType&);
        void setFields(const QStringList&);
        void setTables(const QStringList&);
        void setValues(const QStringList&);
        void setConditions(const QString&);
    };
}

#endif // SQLQUERY_H
