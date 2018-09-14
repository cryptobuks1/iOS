#include "BREthereumGas.h"
#include <assert.h>

//
// Gas
//
extern BREthereumGas
gasCreate(uint64_t amountOfGas) {
    BREthereumGas gas;
    gas.amountOfGas = amountOfGas;
    return gas;
}

extern BREthereumComparison
gasCompare (BREthereumGas e1, BREthereumGas e2) {
    return (e1.amountOfGas == e2.amountOfGas
            ? ETHEREUM_COMPARISON_EQ
            : (e1.amountOfGas > e2.amountOfGas
               ? ETHEREUM_COMPARISON_GT
               : ETHEREUM_COMPARISON_LT));
}

extern BRRlpItem
gasRlpEncode (BREthereumGas gas, BRRlpCoder coder) {
    return rlpEncodeItemUInt64(coder, gas.amountOfGas, 1);
}

extern BREthereumGas
gasRlpDecode (BRRlpItem item, BRRlpCoder coder) {
    return gasCreate(rlpDecodeItemUInt64(coder, item, 1));
}

//
// Gas Price
//
extern BREthereumGasPrice
gasPriceCreate(BREthereumEther ether) {
    BREthereumGasPrice gasPrice;
    gasPrice.etherPerGas = ether;
    return gasPrice;
}

extern BREthereumComparison
gasPriceCompare (BREthereumGasPrice e1, BREthereumGasPrice e2) {
    return etherCompare(e1.etherPerGas, e2.etherPerGas);
}

extern BREthereumEther
gasPriceGetGasCost(BREthereumGasPrice price, BREthereumGas gas, int *overflow) {
    assert (NULL != overflow);
    
    return etherCreate (mulUInt256_Overflow (createUInt256(gas.amountOfGas), // gas
                                             price.etherPerGas.valueInWEI,   // WEI/gas
                                             overflow));
}

extern BRRlpItem
gasPriceRlpEncode (BREthereumGasPrice price, BRRlpCoder coder) {
    return etherRlpEncode(price.etherPerGas, coder);
}

extern BREthereumGasPrice
gasPriceRlpDecode (BRRlpItem item, BRRlpCoder coder) {
    return gasPriceCreate(etherRlpDecode(item, coder));
}
