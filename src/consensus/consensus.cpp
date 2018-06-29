#include "consensus.h"
#include "primitives/transaction.h"
#include "policy/policy.h"

/** The maximum allowed size for a serialized block, in bytes (only for buffer size limits) */
unsigned int dgpMaxBlockSerSize = 16000000;
/** The maximum allowed weight for a block, see BIP 141 (network rule) */
unsigned int dgpMaxBlockWeight = 16000000;
/** The maximum allowed size for a block excluding witness data, in bytes (network rule) */
unsigned int dgpMaxBlockBaseSize = 4000000;

unsigned int dgpMaxBlockSize = 4000000; // runebase

/** The maximum allowed number of signature check operations in a block (network rule) */
int64_t dgpMaxBlockSigOps = 160000;

unsigned int dgpMaxProtoMsgLength = 16000000;

unsigned int dgpMaxTxSigOps = 32000;

void updateBlockSizeParams(unsigned int newBlockSize){
    unsigned int newSizeForParams=WITNESS_SCALE_FACTOR*newBlockSize;
    dgpMaxBlockSerSize=newSizeForParams;
    dgpMaxBlockWeight=newSizeForParams;
    dgpMaxBlockBaseSize=newBlockSize;
    dgpMaxBlockSigOps=(int64_t)(newSizeForParams/100);
    dgpMaxTxSigOps = (unsigned int)(dgpMaxBlockSigOps/5);
    dgpMaxProtoMsgLength=newSizeForParams;
}
