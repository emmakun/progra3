#include "sqlquery.h"

using namespace SqlParser;

SqlQuery::SqlQuery()
{
}

QueryType SqlQuery::type()
{
    return _type;
}

QStringList SqlQuery::fields()
{
    return _fields;
}

QStringList SqlQuery::tables()
{
    return _tables;
}

QStringList SqlQuery::values()
{
    return _values;
}

QString SqlQuery::conditions()
{
    return _conditions;
}

bool SqlQuery::isValid()
{
    bool valid = true;

    if(
            _type == UNKNOWN ||
            _tables.empty()
      )
        valid = false;

    return valid;
}

void SqlQuery::setType(const QueryType& type)
{
    _type = type;
}
void SqlQuery::setFields(const QStringList& fields)
{
    _fields = fields;
}
void SqlQuery::setTables(const QStringList& tables)
{
    _tables = tables;
}

void SqlQuery::setValues(const QStringList& values)
{
    _values = values;
}

void SqlQuery::setConditions(const QString& conditions)
{
    _conditions = conditions;
}
