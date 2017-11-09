#ifndef TRANSACTIONSREQUESTBUILDERTEST_H
#define TRANSACTIONSREQUESTBUILDERTEST_H
#include <QObject>

#include <QtTest>
#include "../testcollector.h"
#include "../../src/server.h"
#include "../../src/keypair.h"

class TransactionsRequestBuilderTest: public QObject
{
    Q_OBJECT
public:


private slots:

    void initTestCase(){

    }
    void cleanupTestCase()
    {

    }

    void testTransactions() {
      Server *server = new Server("https://horizon-testnet.stellar.org");
      QUrl uri = server->transactions()
              .limit(200)
              .order(RequestBuilder::Order::DESC)
              .buildUri();
      QCOMPARE(QString("https://horizon-testnet.stellar.org/transactions?limit=200&order=desc"), uri.toString());
    }

    void testForAccount() {
      Server* server = new Server("https://horizon-testnet.stellar.org");
      QUrl uri = server->transactions()
              .forAccount(KeyPair::fromAccountId(QString("GBRPYHIL2CI3FNQ4BXLFMNDLFJUNPU2HY3ZMFSHONUCEOASW7QC7OX2H")))
              .limit(200)
              .order(RequestBuilder::Order::DESC)
              .buildUri();
      QCOMPARE(QString("https://horizon-testnet.stellar.org/accounts/GBRPYHIL2CI3FNQ4BXLFMNDLFJUNPU2HY3ZMFSHONUCEOASW7QC7OX2H/transactions?limit=200&order=desc"), uri.toString());
    }

    void testForLedger() {
      Server* server = new Server("https://horizon-testnet.stellar.org");
      QUrl uri = server->transactions()
              .forLedger(200000000000L)
              .limit(50)
              .order(RequestBuilder::Order::ASC)
              .buildUri();
      QCOMPARE(QString("https://horizon-testnet.stellar.org/ledgers/200000000000/transactions?limit=50&order=asc"), uri.toString());
    }
};

ADD_TEST(TransactionsRequestBuilderTest)
#endif // TRANSACTIONSREQUESTBUILDERTEST_H