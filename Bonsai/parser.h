#ifndef PARSER_H
#define PARSER_H

#include "sqlquery.h"
#include <QString>
#include <QStringList>

/*
  Namespace: SqlParser
    Namespace that contains the classes needed to parse SQL sentences.
 */
namespace SqlParser
{
    /*
      Class: Parser
        This class provides the public interface for parsing SQL statements.
     */
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

        /*
          Constructor: Parser
            Initialize the parser.
         */
        Parser();

        /*
          Constructor: Parser
            Initialize the parser by providing a QString as the query to parse.
         */
        Parser(const QString&);

        /*
          Method: parse
            Returns a SqlQuery object that contains all the tables, fields, values and conditions
            of the parsed query.
         */
        SqlQuery parse();

        //Getters
        QString query();

        //Setters
        void setQuery(const QString&);
    };
}

#endif // PARSER_H
