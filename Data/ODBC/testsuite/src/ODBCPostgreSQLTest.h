//
// ODBCPostgreSQLTest.h
//
// $Id: //poco/Main/Data/ODBC/testsuite/src/ODBCPostgreSQLTest.h#2 $
//
// Definition of the ODBCPostgreSQLTest class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef ODBCPostgreSQLTest_INCLUDED
#define ODBCPostgreSQLTest_INCLUDED


#include "Poco/Data/ODBC/ODBC.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/ODBC/Utility.h"
#include "Poco/SharedPtr.h"
#include "CppUnit/TestCase.h"
#include "SQLExecutor.h"


class ODBCPostgreSQLTest: public CppUnit::TestCase
	/// PostgreSQL ODBC test class
	/// Tested:
	/// 
	/// Driver		|	DB				| OS										| Notes
	/// ------------+-------------------+-------------------------------------------+--------------------------------
	///	07.03.02.60	| PostgreSQL 7.4.6	| MS Windows XP Professional x64 v.2003/SP1	| BLOB fails (missing 'lo' module)
	/// 08.01.02.00 | PostgreSQL 8.1.5-1| MS Windows XP Professional x64 v.2003/SP1 |
	/// 
{
public:
	ODBCPostgreSQLTest(const std::string& name);
	~ODBCPostgreSQLTest();

	void testBareboneODBC();

	void testSimpleAccess();
	void testComplexType();
	void testSimpleAccessVector();
	void testComplexTypeVector();
	void testInsertVector();
	void testInsertEmptyVector();

	void testInsertSingleBulk();
	void testInsertSingleBulkVec();

	void testLimit();
	void testLimitOnce();
	void testLimitPrepare();
	void testLimitZero();
	void testPrepare();

	void testSetSimple();
	void testSetComplex();
	void testSetComplexUnique();
	void testMultiSetSimple();
	void testMultiSetComplex();
	void testMapComplex();
	void testMapComplexUnique();
	void testMultiMapComplex();
	void testSelectIntoSingle();
	void testSelectIntoSingleStep();
	void testSelectIntoSingleFail();
	void testLowerLimitOk();
	void testLowerLimitFail();
	void testCombinedLimits();
	void testCombinedIllegalLimits();
	void testRange();
	void testIllegalRange();
	void testSingleSelect();
	void testEmptyDB();

	void testBLOB();
	void testBLOBStmt();

	void testFloat();
	void testDouble();

	void testTuple();
	void testTupleVector();

	void testInternalExtraction();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
	void checkODBCSetup();
	void dropTable(const std::string& tableName);
	void recreatePersonTable();
	void recreatePersonBLOBTable();
	void recreateStringsTable();
	void recreateIntsTable();
	void recreateFloatsTable();
	void recreateTuplesTable();
	void recreateVectorsTable();

	static Poco::Data::ODBC::Utility::DriverMap _drivers;
	static Poco::Data::ODBC::Utility::DSNMap _dataSources;
	static std::string _dsn;
	static std::string _dbConnString;
	static Poco::SharedPtr<Poco::Data::Session> _pSession;
	static Poco::SharedPtr<SQLExecutor> _pExecutor;
	static const bool bindValues[8];
};


#endif // ODBCPostgreSQLTest_INCLUDED
