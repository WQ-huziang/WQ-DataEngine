SET(HU_FILE hu_gtest)
SET(MAIN_FILE mongodbenginetest)
SET(GTEST_LIB gtest gflags pthread gtest_main)
SET(TEST_LIBS
  WZMongodbEngine
  mongocxx
  bsoncxx
)

# link all .so
LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})
ADD_EXECUTABLE(${MAIN_FILE} ${MAIN_FILE}.cpp)
TARGET_LINK_LIBRARIES(${MAIN_FILE} ${GTEST_LIB} ${TEST_LIBS})

