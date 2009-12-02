#include "parser.h"

using namespace SqlParser;

Parser::Parser()
{
}

Parser::Parser(const QString& query)
{
    _query = query.simplified();
}

QueryType Parser::getType()
{
    if(_query.startsWith("select ", Qt::CaseInsensitive))
        return SELECT;
    else if(_query.startsWith("insert into ", Qt::CaseInsensitive))
        return INSERT;
    else if(_query.startsWith("update ", Qt::CaseInsensitive))
        return UPDATE;
    else if(_query.startsWith("delete from ", Qt::CaseInsensitive))
        return DELETE;
    else if(_query.startsWith("create table ", Qt::CaseInsensitive))
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
            parseTablesInsert(result);
        break;
        case UPDATE:
            parseTablesUpdate(result);
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
        int end = _query.indexOf(" from ", 7, Qt::CaseInsensitive) - 1;
        QString substring = _query.mid(7, end - 7).trimmed();

        fields = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

        foreach(QString field, fields)
        {
            field = field.trimmed();
            if(field.contains(' ', Qt::CaseInsensitive) || field.contains(QRegExp("[[:punct:]]", Qt::CaseInsensitive)) ||
               field.isEmpty() || field.isNull())
            {
                fields.clear();
                break;
            }
            else
                fields.append(field);
        }
    }
    else
        fields.clear();
}

void Parser::parseFieldsInsert(QStringList& fields)
{
    int start = _query.indexOf('(', 11, Qt::CaseInsensitive) + 1;
    int end = _query.indexOf(')', start, Qt::CaseInsensitive) - 1;

    QString substring = _query.mid(start, end - start).trimmed();

    fields = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

    foreach(QString field, fields)
    {
        field = field.trimmed();
        if(field.contains(' ', Qt::CaseInsensitive) || field.contains(QRegExp("[[:punct:]]", Qt::CaseInsensitive)) ||
           field.isEmpty() || field.isNull())
        {
            fields.clear();
            break;
        }
        else
            fields.append(field);
    }
}

void Parser::parseFieldsUpdate(QStringList& fields)
{
    if(_query.contains(" set ", Qt::CaseInsensitive))
    {
        int start = _query.indexOf(" set ", 6, Qt::CaseInsensitive) + 5;
        int end;

        if(_query.contains(" where ", Qt::CaseInsensitive))
            end = _query.indexOf(" where ", start, Qt::CaseInsensitive) - 1;
        else
            end = _query.length();

        QString substring = _query.mid(start, end - start).trimmed();

        QStringList sets = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

        foreach(QString set, sets)
        {
            set = set.trimmed();
            QStringList pair = set.split('=', QString::KeepEmptyParts, Qt::CaseInsensitive);

            if(pair.count() != 2)
            {
                fields.clear();
                break;
            }

            pair[0] = pair[0].trimmed();
            if(pair[0].contains(' ', Qt::CaseInsensitive) || pair[0].contains(QRegExp("[[:punct:]]", Qt::CaseInsensitive)) ||
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
    int start = _query.indexOf('(', 12, Qt::CaseInsensitive) + 1;
    int end = _query.indexOf(')', start, Qt::CaseInsensitive) -1;

    QString substring = _query.mid(start, end - start).trimmed();

    fields = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

    foreach(QString field, fields)
    {
        field = field.trimmed();
        if(field.contains(' ', Qt::CaseInsensitive) || field.contains(QRegExp("[[:punct:]]", Qt::CaseInsensitive)) ||
           field.isEmpty() || field.isNull())
        {
            fields.clear();
            break;
        }
        else
            fields.append(field);
    }
}

void Parser::parseTablesSelect(QStringList& tables)
{    
    if(_query.contains(" from "))
    {
        QString substring;

        int start = _query.indexOf(" from ", 0, Qt::CaseInsensitive) + 6;
        if(_query.contains(" where "))
        {
            int end = _query.indexOf(" where ", 0, Qt::CaseInsensitive) - 1;
            substring = _query.mid(start, end - start).trimmed();
        }
        else
        {
            substring = _query.mid(start).trimmed();
        }

        tables = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

        foreach(QString table, tables)
        {
            table = table.trimmed();
            if(table.contains(' ', Qt::CaseInsensitive) || table.contains(QRegExp("[[:punct:]]", Qt::CaseInsensitive)) ||
               table.isEmpty() || table.isNull())
            {
                tables.clear();
                break;
            }
            else
                tables.append(table);
        }
    }
    else
        tables.clear();
}

void Parser::parseTablesInsert(QStringList& tables)
{
    int start = _query.indexOf("into ", 0, Qt::CaseInsensitive) + 5;
    int end = _query.indexOf('(', 0, Qt::CaseInsensitive) - 1;

    QString substring = _query.mid(start, end - start).trimmed();

    if(substring.contains(' ', Qt::CaseInsensitive) || substring.contains(QRegExp("[[:punct:]]", Qt::CaseInsensitive)) ||
       substring.isEmpty() || substring.isNull())
        tables.clear();
    else
        tables.append(substring);
}

void Parser::parseTablesUpdate(QStringList& tables)
{
    int end = _query.indexOf(" set ", 0, Qt::CaseInsensitive) - 1;
    QString substring = _query.mid(7, end - 7).trimmed();

    if(substring.contains(' ', Qt::CaseInsensitive) || substring.contains(QRegExp("[[:punct:]]", Qt::CaseInsensitive)) ||
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
        end = _query.indexOf(" where ", start, Qt::CaseInsensitive) - 1;
    else
        end = _query.length();

    QString substring = _query.mid(start, end - start).trimmed();

    if(substring.contains(' ', Qt::CaseInsensitive) || substring.contains(QRegExp("[[:punct:]]", Qt::CaseInsensitive)) ||
       substring.isEmpty() || substring.isNull())
        tables.clear();
    else
        tables.append(substring);
}

void Parser::parseTablesCreate(QStringList& tables)
{
    int start = _query.indexOf("table ", 0, Qt::CaseInsensitive) + 6;
    int end = _query.indexOf('(', 0, Qt::CaseInsensitive) - 1;

    QString substring = _query.mid(start, end - start).trimmed();

    if(substring.contains(' ', Qt::CaseInsensitive) || substring.contains(QRegExp("[[:punct:]]", Qt::CaseInsensitive)) ||
       substring.isEmpty() || substring.isNull())
        tables.clear();
    else
        tables.append(substring);
}

void Parser::parseValuesInsert(QStringList& values)
{
}
void Parser::parseValuesUpdate(QStringList& values)
{
    if(_query.contains(" set ", Qt::CaseInsensitive))
    {
        int start = _query.indexOf(" set ", 6, Qt::CaseInsensitive) + 5;
        int end;

        if(_query.contains(" where ", Qt::CaseInsensitive))
            end = _query.indexOf(" where ", start, Qt::CaseInsensitive) - 1;
        else
            end = _query.length();

        QString substring = _query.mid(start, end - start).trimmed();

        QStringList sets = substring.split(',', QString::KeepEmptyParts, Qt::CaseInsensitive);

        foreach(QString set, sets)
        {
            set = set.trimmed();
            QStringList pair = set.split('=', QString::KeepEmptyParts, Qt::CaseInsensitive);

            if(pair.count() != 2)
            {
                values.clear();
                break;
            }

//            pair[1] = pair[1].trimmed();
//            if(pair[1].contains(' ', Qt::CaseInsensitive) || pair[0].contains(QRegExp("[[:punct:]]", Qt::CaseInsensitive)) ||
//            pair[0].isEmpty() || pair[0].isNull())
//            {
//                fields.clear();
//                break;
//            }
//            else
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

        result.setTables(getTables(result.type()));

        if(result.tables().isEmpty())
            return result;
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
