#include "../interface/BlockStore.h"
#include "BlockStoreUtils.h"
#include <messmer/cpp-utils/data/Data.h>
#include <memory>
#include <cassert>

using std::unique_ptr;
using cpputils::Data;

namespace blockstore {
namespace utils {

unique_ptr<Block> copyToNewBlock(BlockStore *blockStore, const Block &block) {
  Data data(block.size());
  std::memcpy(data.data(), block.data(), block.size());
  return blockStore->create(data);
}

void copyTo(Block *target, const Block &source) {
  assert(target->size() == source.size());
  target->write(source.data(), 0, source.size());
}

void fillWithZeroes(Block *target) {
  Data zeroes(target->size());
  zeroes.FillWithZeroes();
  target->write(zeroes.data(), 0, target->size());
}

}
}