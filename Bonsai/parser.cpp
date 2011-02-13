#include "parser.h"

using namespace SqlParser;

Parser::Parser()
{
}

/*
  Parameters:
    query - The QString containing the sql statement.
 */
Parser::Parser(const QString& query)
{
    _query = query.simplified();
}

bool Parser::hasPunct(const QString& str)
{
    for(int i=0;i<str.length();i++)
        if(str[i].isPunct())
            return true;

    return false;
}

QueryType Parser::getType()
{
    if(_query.toLower().startsWith("select ", Qt::CaseInsensitive))
        return SELECT;
    else if(_query.toLower().startsWith("insert into ", Qt::CaseInsensitive))
        return INSERT;
    else if(_query.toLower().startsWith("update ", Qt::CaseInsensitive))
        return UPDATE;
    else if(_query.toLower().startsWith("delete from ", Qt::CaseInsensitive))
        return DELETE;
    else if(_query.toLower().startsWith("create table ", Qt::CaseInsensitive))
        return CREATE;
    else
        return UNKNOWN;
}

QStringList Parser::getFields(QueryType type)
{
    QStringList result;

    switch(type)
    {
        case SELECT:
            parseFieldsSelect(result);
        break;
        case INSERT:
            parseFieldsInsert(result);
        break;
        case UPDATE:
            parseFieldsUpdate(result);
        break;
        case CREATE:
            parseFieldsCreate(result);
        break;
        default:
            result.clear();
        break;
    }

    return result;
}

QStringList Parser::getTables(QueryType type)
{
    QStringList result;

    switch(type)
    {
        case SELECT:
            parseTablesSelect(result);
        break;
        case INSERT:
            parseTablesInsert(result);
        break;
        case UPDATE:
            parseTablesUpdate(result);
        break;
        case DELETE:
            parseTablesDelete(result);
        break;
        case CREATE:
            parseTablesCreate(result);
        break;
        default:
            result.clear();
        break;
    }

    return result;
}

QStringList Parser::getValues(QueryType type)
{
    QStringList result;

    switch(type)
    {
        case INSERT:
            parseValuesInsert(result);
        break;
        case UPDATE:
            parseValuesUpdate(result);
        break;
        default:
            result.clear();
        break;
    }

    return result;
}

QString Parser::getConditions(QueryType type)
{
}

void Parser::parseFieldsSelect(QStringList& fields)
{
    if(_query.contains(" from ", Qt::CaseInsensitive))
    {
        int end = _query.indexOf(" from ", 6, Qt::CaseInsensitive);
        QString substring = _query.mid(6, end - 6).trimmed();

        fields = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

        foreach(QString field, fields)
        {
            fields.removeOne(field);
            field = field.trimmed();

            if(field.contains(' ', Qt::CaseInsensitive) || hasPunct(field) ||
               field.isEmpty() || field.isNull())
            {
                if(field != "*")
                {
                    fields.clear();
                    break;
                }
            }

            fields.append(field);
        }
    }
    else
        fields.clear();
}

void Parser::parseFieldsInsert(QStringList& fields)
{
    int start = _query.indexOf('(', 11, Qt::CaseInsensitive) + 1;
    int end = _query.indexOf(')', start, Qt::CaseInsensitive);

    QString substring = _query.mid(start, end - start).trimmed();

    fields = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

    foreach(QString field, fields)
    {
        fields.removeOne(field);

        field = field.trimmed();
        if(field.contains(' ', Qt::CaseInsensitive) || hasPunct(field) ||
           field.isEmpty() || field.isNull())
        {
            fields.clear();
            break;
        }

        fields.append(field);
    }
}

void Parser::parseFieldsUpdate(QStringList& fields)
{
    if(_query.contains(" set ", Qt::CaseInsensitive))
    {
        int start = _query.indexOf(" set ", 7, Qt::CaseInsensitive) + 5;
        int end;

        if(_query.contains(" where ", Qt::CaseInsensitive))
            end = _query.indexOf(" where ", start, Qt::CaseInsensitive);
        else
            end = _query.length();

        QString substring = _query.mid(start, end - start).trimmed();

        QStringList sets = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

        foreach(QString set, sets)
        {
            sets.removeOne(set);

            set = set.trimmed();
            QStringList pair = set.split('=', QString::KeepEmptyParts, Qt::CaseInsensitive);

            if(pair.count() != 2)
            {
                fields.clear();
                break;
            }

            pair[0] = pair[0].trimmed();
            if(pair[0].contains(' ', Qt::CaseInsensitive) || hasPunct(pair[0]) ||
            pair[0].isEmpty() || pair[0].isNull())
            {
                fields.clear();
                break;
            }
            else
                fields.append(pair[0]);
        }
    }
    else
        fields.clear();
}

void Parser::parseFieldsCreate(QStringList& fields)
{
    int start = _query.indexOf('(', 13, Qt::CaseInsensitive) + 1;
    int end = _query.indexOf(')', start, Qt::CaseInsensitive);

    QString substring = _query.mid(start, end - start).trimmed();

    fields = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

    foreach(QString field, fields)
    {
        fields.removeOne(field);

        field = field.trimmed();
        if(field.contains(' ', Qt::CaseInsensitive) || hasPunct(field) ||
           field.isEmpty() || field.isNull())
        {
            fields.clear();
            break;
        }

        fields.append(field);
    }
}

void Parser::parseTablesSelect(QStringList& tables)
{    
    if(_query.contains(" from ", Qt::CaseInsensitive))
    {
        QString substring;

        int start = _query.indexOf(" from ", 0, Qt::CaseInsensitive) + 6;
        if(_query.contains(" where ", Qt::CaseInsensitive))
        {
            int end = _query.indexOf(" where ", 0, Qt::CaseInsensitive);
            substring = _query.mid(start, end - start).trimmed();
        }
        else
        {
            substring = _query.mid(start).trimmed();
        }

        tables = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

        foreach(QString table, tables)
        {
            tables.removeOne(table);

            table = table.trimmed();
            if(table.contains(' ', Qt::CaseInsensitive) || hasPunct(table) ||
               table.isEmpty() || table.isNull())
            {
                tables.clear();
                break;
            }

            tables.append(table);
        }
    }
    else
        tables.clear();
}

void Parser::parseTablesInsert(QStringList& tables)
{
    int start = _query.indexOf("into ", 0, Qt::CaseInsensitive) + 5;
    int end = _query.indexOf('(', 0, Qt::CaseInsensitive);

    QString substring = _query.mid(start, end - start).trimmed();

    if(substring.contains(' ', Qt::CaseInsensitive) || hasPunct(substring) ||
       substring.isEmpty() || substring.isNull())
        tables.clear();
    else
        tables.append(substring);
}

void Parser::parseTablesUpdate(QStringList& tables)
{
    int end = _query.indexOf(" set ", 0, Qt::CaseInsensitive);
    QString substring = _query.mid(7, end - 7).trimmed();

    if(substring.contains(' ', Qt::CaseInsensitive) || hasPunct(substring) ||
       substring.isEmpty() || substring.isNull())
        tables.clear();
    else
        tables.append(substring);
}

void Parser::parseTablesDelete(QStringList& tables)
{
    int start = _query.indexOf("from ", 0, Qt::CaseInsensitive) + 5;
    int end;

    if(_query.contains(" where ", Qt::CaseInsensitive))
        end = _query.indexOf(" where ", start, Qt::CaseInsensitive);
    else
        end = _query.length();

    QString substring = _query.mid(start, end - start).trimmed();

    if(substring.contains(' ', Qt::CaseInsensitive) || hasPunct(substring) ||
       substring.isEmpty() || substring.isNull())
        tables.clear();
    else
        tables.append(substring);
}

void Parser::parseTablesCreate(QStringList& tables)
{
    int start = _query.indexOf("table ", 0, Qt::CaseInsensitive) + 6;
    int end = _query.indexOf('(', 0, Qt::CaseInsensitive);

    QString substring = _query.mid(start, end - start).trimmed();

    if(substring.contains(' ', Qt::CaseInsensitive) || hasPunct(substring) ||
       substring.isEmpty() || substring.isNull())
        tables.clear();
    else
        tables.append(substring);
}

void Parser::parseValuesInsert(QStringList& values)
{
    if(_query.contains(" values", Qt::CaseInsensitive))
    {
        int start = _query.indexOf('(', _query.indexOf(" values", 0, Qt::CaseInsensitive), Qt::CaseInsensitive) + 1;
        int end = _query.indexOf(')', start, Qt::CaseInsensitive);

        QString substring = _query.mid(start, end - start).trimmed();

        values = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

        foreach(QString value, values)
        {
            values.removeOne(value);

            value = value.trimmed();
            if(value.isNull())
            {
                values.clear();
                break;
            }
            if(value.isEmpty())
                value = "NULL";

            values.append(value);
        }
    }
    else
        values.clear();
}

void Parser::parseValuesUpdate(QStringList& values)
{
    if(_query.contains(" set ", Qt::CaseInsensitive))
    {
        int start = _query.indexOf(" set ", 7, Qt::CaseInsensitive) + 5;
        int end;

        if(_query.contains(" where ", Qt::CaseInsensitive))
            end = _query.indexOf(" where ", start, Qt::CaseInsensitive);
        else
            end = _query.length();

        QString substring = _query.mid(start, end - start).trimmed();

        QStringList sets = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

        foreach(QString set, sets)
        {
            sets.removeOne(set);

            set = set.trimmed();
            QStringList pair = set.split('=', QString::KeepEmptyParts, Qt::CaseInsensitive);

            if(pair.count() != 2)
            {
                values.clear();
                break;
            }

            pair[1] = pair[1].trimmed();
            if(pair[0].isNull())
            {
                values.clear();
                break;
            }

            if(pair[1].isEmpty())
                pair[1] = "NULL";

            values.append(pair[1]);
        }
    }
    else
        values.clear();
}

SqlQuery Parser::parse()
{
    SqlQuery result;

    if(!(_query.isNull() || _query.isEmpty()))
    {
        result.setType(getType());

        if(result.type() == UNKNOWN)
            return result;

        result.setFields(getFields(result.type()));

        if(result.type() != DELETE && result.fields().isEmpty())
            return result;

        result.setTables(getTables(result.type()));

        if(result.tables().isEmpty())
            return result;

        result.setValues(getValues(result.type()));
    }

    return result;
}

QString Parser::query()
{
    return _query;
}

void Parser::setQuery(const QString& query)
{
    _query = query.simplified();
}
