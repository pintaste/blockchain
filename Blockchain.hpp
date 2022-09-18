//
// Created by PIN on 2022/9/17.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_HPP
#define BLOCKCHAIN_BLOCKCHAIN_HPP

#include <cstdint>
#include <vector>
#include "Block.hpp"

using namespace std;

class Blockchain{
public:
    Blockchain();
    void AddBlock(Block bNew);
private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;
    Block _GetLastBlock() const;
};

Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 6;
}

void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}

#endif //BLOCKCHAIN_BLOCKCHAIN_HPP
