project (blockstore)

set(SOURCES
  utils/BlockId.cpp
  utils/IdWrapper.cpp
  utils/BlockStoreUtils.cpp
  utils/FileDoesntExistException.cpp
  implementations/testfake/FakeBlockStore.cpp
  implementations/testfake/FakeBlock.cpp
  implementations/inmemory/InMemoryBlockStore2.cpp
  implementations/parallelaccess/ParallelAccessBlockStore.cpp
  implementations/parallelaccess/BlockRef.cpp
  implementations/parallelaccess/ParallelAccessBlockStoreAdapter.cpp
  implementations/compressing/CompressingBlockStore.cpp
  implementations/compressing/CompressedBlock.cpp
  implementations/compressing/compressors/RunLengthEncoding.cpp
  implementations/compressing/compressors/Gzip.cpp
  implementations/encrypted/EncryptedBlockStore2.cpp
  implementations/ondisk/OnDiskBlockStore2.cpp
  implementations/caching/CachingBlockStore2.cpp
  implementations/caching/cache/PeriodicTask.cpp
  implementations/caching/cache/CacheEntry.cpp
  implementations/caching/cache/Cache.cpp
  implementations/caching/cache/QueueMap.cpp
  implementations/low2highlevel/LowToHighLevelBlock.cpp
  implementations/low2highlevel/LowToHighLevelBlockStore.cpp
  implementations/integrity/IntegrityBlockStore2.cpp
  implementations/integrity/KnownBlockVersions.cpp
  implementations/integrity/ClientIdAndBlockId.cpp
  implementations/integrity/IntegrityViolationError.cpp
  implementations/mock/MockBlockStore.cpp
  implementations/mock/MockBlock.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC cpp-utils)

target_add_boost(${PROJECT_NAME} filesystem system thread)
target_enable_style_warnings(${PROJECT_NAME})
target_activate_cpp14(${PROJECT_NAME})
