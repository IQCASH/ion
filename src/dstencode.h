#ifndef BITCOIN_DSTENCODE_H
#define BITCOIN_DSTENCODE_H

// key.h and pubkey.h are not used here, but gcc doesn't want to instantiate
// CTxDestination if types are unknown
#include "key.h"
#include "pubkey.h"
#include "script/standard.h"
#include <string>

class CChainParams;

std::string EncodeDestination(const CTxDestination &, const CChainParams &);
CTxDestination DecodeDestination(const std::string &addr, const CChainParams &);
bool IsValidDestinationString(const std::string &addr, const CChainParams &params);

// Temporary workaround. Don't rely on global state, pass all parameters in new
// code.
std::string EncodeDestination(const CTxDestination &);
CTxDestination DecodeDestination(const std::string &addr);
bool IsValidDestinationString(const std::string &addr);

/// Encode an old-style bitcoin address
std::string EncodeLegacyAddr(const CTxDestination &dest, const CChainParams &);

/// Decode an old-style bitcoin address
CTxDestination DecodeLegacyAddr(const std::string &str, const CChainParams &);

#endif // BITCOIN_DSTENCODE_H
