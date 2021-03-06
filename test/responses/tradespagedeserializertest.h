#ifndef TRADESPAGEDESERIALIZERTEST_H
#define TRADESPAGEDESERIALIZERTEST_H
#include <QObject>


#include <QtTest>
#include "../testcollector.h"
#include "../../src/responses/page.h"
#include "../../src/responses/traderesponse.h"
#include "../../src/keypair.h"
#include "../../src/assettypenative.h"

class TradesPageDeserializerTest: public QObject
{
    Q_OBJECT

public:


private slots:

    void initTestCase(){

    }
    void cleanupTestCase()
    {

    }
    void testDeserialize() {
        Page<TradeResponse> tradesPage;
        tradesPage.loadFromJson(json);
        QCOMPARE(tradesPage.getLinks().getNext().getHref(), QString("https://horizon.stellar.org/trades?order=asc&limit=10&cursor=3748308153536513-0"));
        QCOMPARE(tradesPage.getLinks().getPrev().getHref(), QString("https://horizon.stellar.org/trades?order=desc&limit=10&cursor=3697472920621057-0"));
        QCOMPARE(tradesPage.getLinks().getSelf().getHref(), QString("https://horizon.stellar.org/trades?order=asc&limit=10&cursor="));

        QCOMPARE(tradesPage.get(0).getId(), QString("3697472920621057-0"));
        QCOMPARE(tradesPage.get(0).getPagingToken(), QString("3697472920621057-0"));
        QCOMPARE(tradesPage.get(0).getLedgerCloseTime(), QString("2015-11-18T03:47:47Z"));
        QCOMPARE(tradesPage.get(0).getOfferId(),QString("9"));
        QCOMPARE(tradesPage.get(0).isBaseSeller(),true);
        QVERIFY(tradesPage.get(0).getBaseAsset()->equals(new AssetTypeNative()));
        QVERIFY(tradesPage.get(0).getCounterAsset()->equals( Asset::createNonNativeAsset("JPY", KeyPair::fromAccountId(QString("GBVAOIACNSB7OVUXJYC5UE2D4YK2F7A24T7EE5YOMN4CE6GCHUTOUQXM")))));
        QCOMPARE(tradesPage.get(1).getBaseAccount().getAccountId(), QString("GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G"));
    }
private:
      const QByteArray json = "{\n"
              "  \"_links\": {\n"
              "    \"self\": {\n"
              "      \"href\": \"https://horizon.stellar.org/trades?order=asc\\u0026limit=10\\u0026cursor=\"\n"
              "    },\n"
              "    \"next\": {\n"
              "      \"href\": \"https://horizon.stellar.org/trades?order=asc\\u0026limit=10\\u0026cursor=3748308153536513-0\"\n"
              "    },\n"
              "    \"prev\": {\n"
              "      \"href\": \"https://horizon.stellar.org/trades?order=desc\\u0026limit=10\\u0026cursor=3697472920621057-0\"\n"
              "    }\n"
              "  },\n"
              "  \"_embedded\": {\n"
              "    \"records\": [\n"
              "      {\n"
              "        \"_links\": {\n"
              "          \"self\": {\n"
              "            \"href\": \"\"\n"
              "          },\n"
              "          \"base\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\"\n"
              "          },\n"
              "          \"counter\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\"\n"
              "          },\n"
              "          \"operation\": {\n"
              "            \"href\": \"https://horizon.stellar.org/operations/3697472920621057\"\n"
              "          }\n"
              "        },\n"
              "        \"id\": \"3697472920621057-0\",\n"
              "        \"paging_token\": \"3697472920621057-0\",\n"
              "        \"ledger_close_time\": \"2015-11-18T03:47:47Z\",\n"
              "        \"offer_id\": \"9\",\n"
              "        \"base_account\": \"GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\",\n"
              "        \"base_amount\": \"10.0000000\",\n"
              "        \"base_asset_type\": \"native\",\n"
              "        \"counter_account\": \"GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\",\n"
              "        \"counter_amount\": \"2.6700000\",\n"
              "        \"counter_asset_type\": \"credit_alphanum4\",\n"
              "        \"counter_asset_code\": \"JPY\",\n"
              "        \"counter_asset_issuer\": \"GBVAOIACNSB7OVUXJYC5UE2D4YK2F7A24T7EE5YOMN4CE6GCHUTOUQXM\",\n"
              "        \"base_is_seller\": true\n"
              "      },\n"
              "      {\n"
              "        \"_links\": {\n"
              "          \"self\": {\n"
              "            \"href\": \"\"\n"
              "          },\n"
              "          \"base\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\"\n"
              "          },\n"
              "          \"counter\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\"\n"
              "          },\n"
              "          \"operation\": {\n"
              "            \"href\": \"https://horizon.stellar.org/operations/3697472920621057\"\n"
              "          }\n"
              "        },\n"
              "        \"id\": \"3697472920621057-1\",\n"
              "        \"paging_token\": \"3697472920621057-1\",\n"
              "        \"ledger_close_time\": \"2015-11-18T03:47:47Z\",\n"
              "        \"offer_id\": \"4\",\n"
              "        \"base_account\": \"GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\",\n"
              "        \"base_amount\": \"10.0000000\",\n"
              "        \"base_asset_type\": \"native\",\n"
              "        \"counter_account\": \"GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\",\n"
              "        \"counter_amount\": \"2.6800000\",\n"
              "        \"counter_asset_type\": \"credit_alphanum4\",\n"
              "        \"counter_asset_code\": \"JPY\",\n"
              "        \"counter_asset_issuer\": \"GBVAOIACNSB7OVUXJYC5UE2D4YK2F7A24T7EE5YOMN4CE6GCHUTOUQXM\",\n"
              "        \"base_is_seller\": true\n"
              "      },\n"
              "      {\n"
              "        \"_links\": {\n"
              "          \"self\": {\n"
              "            \"href\": \"\"\n"
              "          },\n"
              "          \"base\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\"\n"
              "          },\n"
              "          \"counter\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\"\n"
              "          },\n"
              "          \"operation\": {\n"
              "            \"href\": \"https://horizon.stellar.org/operations/3697472920621057\"\n"
              "          }\n"
              "        },\n"
              "        \"id\": \"3697472920621057-2\",\n"
              "        \"paging_token\": \"3697472920621057-2\",\n"
              "        \"ledger_close_time\": \"2015-11-18T03:47:47Z\",\n"
              "        \"offer_id\": \"8\",\n"
              "        \"base_account\": \"GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\",\n"
              "        \"base_amount\": \"20.0000000\",\n"
              "        \"base_asset_type\": \"native\",\n"
              "        \"counter_account\": \"GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\",\n"
              "        \"counter_amount\": \"5.3600000\",\n"
              "        \"counter_asset_type\": \"credit_alphanum4\",\n"
              "        \"counter_asset_code\": \"JPY\",\n"
              "        \"counter_asset_issuer\": \"GBVAOIACNSB7OVUXJYC5UE2D4YK2F7A24T7EE5YOMN4CE6GCHUTOUQXM\",\n"
              "        \"base_is_seller\": true\n"
              "      },\n"
              "      {\n"
              "        \"_links\": {\n"
              "          \"self\": {\n"
              "            \"href\": \"\"\n"
              "          },\n"
              "          \"base\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\"\n"
              "          },\n"
              "          \"counter\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\"\n"
              "          },\n"
              "          \"operation\": {\n"
              "            \"href\": \"https://horizon.stellar.org/operations/3712329212497921\"\n"
              "          }\n"
              "        },\n"
              "        \"id\": \"3712329212497921-0\",\n"
              "        \"paging_token\": \"3712329212497921-0\",\n"
              "        \"ledger_close_time\": \"2015-11-18T07:26:21Z\",\n"
              "        \"offer_id\": \"36\",\n"
              "        \"base_account\": \"GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\",\n"
              "        \"base_amount\": \"5.0000000\",\n"
              "        \"base_asset_type\": \"native\",\n"
              "        \"counter_account\": \"GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\",\n"
              "        \"counter_amount\": \"1.2000192\",\n"
              "        \"counter_asset_type\": \"credit_alphanum4\",\n"
              "        \"counter_asset_code\": \"JPY\",\n"
              "        \"counter_asset_issuer\": \"GBVAOIACNSB7OVUXJYC5UE2D4YK2F7A24T7EE5YOMN4CE6GCHUTOUQXM\",\n"
              "        \"base_is_seller\": false\n"
              "      },\n"
              "      {\n"
              "        \"_links\": {\n"
              "          \"self\": {\n"
              "            \"href\": \"\"\n"
              "          },\n"
              "          \"base\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\"\n"
              "          },\n"
              "          \"counter\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\"\n"
              "          },\n"
              "          \"operation\": {\n"
              "            \"href\": \"https://horizon.stellar.org/operations/3716237632737281\"\n"
              "          }\n"
              "        },\n"
              "        \"id\": \"3716237632737281-0\",\n"
              "        \"paging_token\": \"3716237632737281-0\",\n"
              "        \"ledger_close_time\": \"2015-11-18T08:27:26Z\",\n"
              "        \"offer_id\": \"37\",\n"
              "        \"base_account\": \"GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\",\n"
              "        \"base_amount\": \"10.0000000\",\n"
              "        \"base_asset_type\": \"native\",\n"
              "        \"counter_account\": \"GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\",\n"
              "        \"counter_amount\": \"2.4500000\",\n"
              "        \"counter_asset_type\": \"credit_alphanum4\",\n"
              "        \"counter_asset_code\": \"JPY\",\n"
              "        \"counter_asset_issuer\": \"GBVAOIACNSB7OVUXJYC5UE2D4YK2F7A24T7EE5YOMN4CE6GCHUTOUQXM\",\n"
              "        \"base_is_seller\": true\n"
              "      },\n"
              "      {\n"
              "        \"_links\": {\n"
              "          \"self\": {\n"
              "            \"href\": \"\"\n"
              "          },\n"
              "          \"base\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\"\n"
              "          },\n"
              "          \"counter\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\"\n"
              "          },\n"
              "          \"operation\": {\n"
              "            \"href\": \"https://horizon.stellar.org/operations/3716302057246721\"\n"
              "          }\n"
              "        },\n"
              "        \"id\": \"3716302057246721-0\",\n"
              "        \"paging_token\": \"3716302057246721-0\",\n"
              "        \"ledger_close_time\": \"2015-11-18T08:28:40Z\",\n"
              "        \"offer_id\": \"35\",\n"
              "        \"base_account\": \"GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\",\n"
              "        \"base_amount\": \"10.0000000\",\n"
              "        \"base_asset_type\": \"native\",\n"
              "        \"counter_account\": \"GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\",\n"
              "        \"counter_amount\": \"2.5000000\",\n"
              "        \"counter_asset_type\": \"credit_alphanum4\",\n"
              "        \"counter_asset_code\": \"JPY\",\n"
              "        \"counter_asset_issuer\": \"GBVAOIACNSB7OVUXJYC5UE2D4YK2F7A24T7EE5YOMN4CE6GCHUTOUQXM\",\n"
              "        \"base_is_seller\": true\n"
              "      },\n"
              "      {\n"
              "        \"_links\": {\n"
              "          \"self\": {\n"
              "            \"href\": \"\"\n"
              "          },\n"
              "          \"base\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\"\n"
              "          },\n"
              "          \"counter\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\"\n"
              "          },\n"
              "          \"operation\": {\n"
              "            \"href\": \"https://horizon.stellar.org/operations/3716302057246721\"\n"
              "          }\n"
              "        },\n"
              "        \"id\": \"3716302057246721-1\",\n"
              "        \"paging_token\": \"3716302057246721-1\",\n"
              "        \"ledger_close_time\": \"2015-11-18T08:28:40Z\",\n"
              "        \"offer_id\": \"34\",\n"
              "        \"base_account\": \"GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\",\n"
              "        \"base_amount\": \"10.0000000\",\n"
              "        \"base_asset_type\": \"native\",\n"
              "        \"counter_account\": \"GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\",\n"
              "        \"counter_amount\": \"3.0000000\",\n"
              "        \"counter_asset_type\": \"credit_alphanum4\",\n"
              "        \"counter_asset_code\": \"JPY\",\n"
              "        \"counter_asset_issuer\": \"GBVAOIACNSB7OVUXJYC5UE2D4YK2F7A24T7EE5YOMN4CE6GCHUTOUQXM\",\n"
              "        \"base_is_seller\": true\n"
              "      },\n"
              "      {\n"
              "        \"_links\": {\n"
              "          \"self\": {\n"
              "            \"href\": \"\"\n"
              "          },\n"
              "          \"base\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\"\n"
              "          },\n"
              "          \"counter\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\"\n"
              "          },\n"
              "          \"operation\": {\n"
              "            \"href\": \"https://horizon.stellar.org/operations/3725961438695425\"\n"
              "          }\n"
              "        },\n"
              "        \"id\": \"3725961438695425-0\",\n"
              "        \"paging_token\": \"3725961438695425-0\",\n"
              "        \"ledger_close_time\": \"2015-11-18T11:09:30Z\",\n"
              "        \"offer_id\": \"47\",\n"
              "        \"base_account\": \"GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\",\n"
              "        \"base_amount\": \"5.0000000\",\n"
              "        \"base_asset_type\": \"native\",\n"
              "        \"counter_account\": \"GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\",\n"
              "        \"counter_amount\": \"1.0000000\",\n"
              "        \"counter_asset_type\": \"credit_alphanum4\",\n"
              "        \"counter_asset_code\": \"JPY\",\n"
              "        \"counter_asset_issuer\": \"GBVAOIACNSB7OVUXJYC5UE2D4YK2F7A24T7EE5YOMN4CE6GCHUTOUQXM\",\n"
              "        \"base_is_seller\": false\n"
              "      },\n"
              "      {\n"
              "        \"_links\": {\n"
              "          \"self\": {\n"
              "            \"href\": \"\"\n"
              "          },\n"
              "          \"base\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\"\n"
              "          },\n"
              "          \"counter\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\"\n"
              "          },\n"
              "          \"operation\": {\n"
              "            \"href\": \"https://horizon.stellar.org/operations/3748080520269825\"\n"
              "          }\n"
              "        },\n"
              "        \"id\": \"3748080520269825-0\",\n"
              "        \"paging_token\": \"3748080520269825-0\",\n"
              "        \"ledger_close_time\": \"2015-11-18T16:56:09Z\",\n"
              "        \"offer_id\": \"53\",\n"
              "        \"base_account\": \"GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\",\n"
              "        \"base_amount\": \"10.0000000\",\n"
              "        \"base_asset_type\": \"native\",\n"
              "        \"counter_account\": \"GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\",\n"
              "        \"counter_amount\": \"3.0000000\",\n"
              "        \"counter_asset_type\": \"credit_alphanum4\",\n"
              "        \"counter_asset_code\": \"JPY\",\n"
              "        \"counter_asset_issuer\": \"GBVAOIACNSB7OVUXJYC5UE2D4YK2F7A24T7EE5YOMN4CE6GCHUTOUQXM\",\n"
              "        \"base_is_seller\": true\n"
              "      },\n"
              "      {\n"
              "        \"_links\": {\n"
              "          \"self\": {\n"
              "            \"href\": \"\"\n"
              "          },\n"
              "          \"base\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\"\n"
              "          },\n"
              "          \"counter\": {\n"
              "            \"href\": \"https://horizon.stellar.org/accounts/GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\"\n"
              "          },\n"
              "          \"operation\": {\n"
              "            \"href\": \"https://horizon.stellar.org/operations/3748308153536513\"\n"
              "          }\n"
              "        },\n"
              "        \"id\": \"3748308153536513-0\",\n"
              "        \"paging_token\": \"3748308153536513-0\",\n"
              "        \"ledger_close_time\": \"2015-11-18T16:59:37Z\",\n"
              "        \"offer_id\": \"59\",\n"
              "        \"base_account\": \"GAVH5JM5OKXGMQDS7YPRJ4MQCPXJUGH26LYQPQJ4SOMOJ4SXY472ZM7G\",\n"
              "        \"base_amount\": \"30.0000000\",\n"
              "        \"base_asset_type\": \"native\",\n"
              "        \"counter_account\": \"GBB4JST32UWKOLGYYSCEYBHBCOFL2TGBHDVOMZP462ET4ZRD4ULA7S2L\",\n"
              "        \"counter_amount\": \"9.0000000\",\n"
              "        \"counter_asset_type\": \"credit_alphanum4\",\n"
              "        \"counter_asset_code\": \"JPY\",\n"
              "        \"counter_asset_issuer\": \"GBVAOIACNSB7OVUXJYC5UE2D4YK2F7A24T7EE5YOMN4CE6GCHUTOUQXM\",\n"
              "        \"base_is_seller\": true\n"
              "      }\n"
              "    ]\n"
              "  }\n"
              "}";
};





ADD_TEST(TradesPageDeserializerTest)
#endif // TRADESPAGEDESERIALIZERTEST_H
