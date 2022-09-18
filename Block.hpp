// Created by PIN on 2022/9/17.

#ifndef BLOCKCHAIN_BLOCK_HPP
#define BLOCKCHAIN_BLOCK_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "sha256.h"

using namespace std;

class Block{
public:
    string sPrevHash;
    Block(uint32_t nIndexIn, const string &sDataIn);
    string GetHash() const;
    void MineBlock(uint32_t nDifficulty);

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;
    string _CalculateHash() const;
};

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
}

void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
    string str(cstr);
    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);
    cout << "Block mined: " << _sHash << endl;
}

inline string Block::_CalculateHash() const {
    stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;
    return sha256(ss.str());
}

string Block::GetHash() const {
    return _sHash;
}

#endif //BLOCKCHAIN_BLOCK_HPP
