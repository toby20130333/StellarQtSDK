#include "ledgerresponse.h"

LedgerResponse::LedgerResponse(QNetworkReply *reply)
    :Response(reply)
    ,m_sequence(0)
    ,m_transactionCount(0)
    ,m_operationCount(0)
    ,m_baseFee(0)
    ,m_baseFeeInStroops(0)
    ,m_baseReserveInStroops(0)
    ,m_maxTxSetSize(0)
{

}

qint64 LedgerResponse::getSequence() const{
    return m_sequence;
}

QString LedgerResponse::getHash() const{
    return m_hash;
}

QString LedgerResponse::getPagingToken() const{
    return m_pagingToken;
}

QString LedgerResponse::getPrevHash() const{
    return m_prevHash;
}

qint32 LedgerResponse::getTransactionCount() const{
    return m_transactionCount;
}

qint32 LedgerResponse::getOperationCount() const{
    return m_operationCount;
}

QString LedgerResponse::getClosedAt() const{
    return m_closedAt;
}

QString LedgerResponse::getTotalCoins() const{
    return m_totalCoins;
}

QString LedgerResponse::getFeePool() const{
    return m_feePool;
}

qint64 LedgerResponse::getBaseFee() const{
    return m_baseFee;
}

QString LedgerResponse::getBaseReserve() const{
    return m_baseReserve;
}

QString LedgerResponse::getBaseFeeInStroops() const
{
    return QString::number(m_baseFeeInStroops);
}

QString LedgerResponse::getBaseReserveInStroops() const
{
    return QString::number(m_baseReserveInStroops);
}

qint64 LedgerResponse::baseFeeInStroops() const
{
    return m_baseFeeInStroops;
}

qint64 LedgerResponse::baseReserveInStroops() const
{
    return m_baseReserveInStroops;
}

qint32 LedgerResponse::getMaxTxSetSize() const{
    return m_maxTxSetSize;
}

LedgerResponseAttach::Links& LedgerResponse::getLinks(){
    return m_links;
}

bool LedgerResponseAttach::Links::operator !=(LedgerResponseAttach::Links &links)
{
    Q_UNUSED(links)
    return true;
}
