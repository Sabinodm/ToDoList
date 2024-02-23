//
// Created by sabinodm on 30/09/23.
//

#include "gtest/gtest.h"
#include "../TxtFile.h"

class TxtFileFixture : public ::testing::Test {

protected:

    void SetUp() override {
        std::string aaaa = "aaaa";
        Category aaaaCategory = Category(aaaa);
        aaaaCategory.addActivity("bbbb", "cccc", false);
        aaaaCategory.addActivity("dddd", "eeee", 12, 10, 2009, true);
        testIndex.push_back(aaaaCategory);
        std::string ffff = "ffff";
        Category ffffCategory = Category(ffff);
        ffffCategory.addActivity("gggg", "hhhh", false);
        ffffCategory.addActivity("iiii", "llll", 13, 2, 2000, true);
        testIndex.push_back(ffffCategory);
    }
    std::vector<Category> testIndex;

    void TearDown() override {
        testIndex.clear();
    }
};

TEST_F(TxtFileFixture, saveFileTest) {
    //saveFile usa TxtFile::writeLabel, Category::collectCategory ; quindi non serve testarli
    //collectCategory usa TxtFile::writeCategory, Activity::collectActivity; quindi non serve testarli
    //collectActivity usa TxtFile::writeActivity; quindi non serve testarlo
    saveFile(testIndex, "file.txt");
    std::ifstream testFin;
    testFin.open("file.txt", std::ios_base::app);
    std::string firstLine;
    getline(testFin, firstLine);
    ASSERT_EQ(firstLine, "Il file è in caricamento");
    std::string line;
    getline(testFin, line);
    ASSERT_EQ(line, "newCategoryLabel");
        // Category aaaa
        getline(testFin, line);
        ASSERT_EQ(line, "aaaa");
            // Activity bbbb
            getline(testFin, line);
            ASSERT_EQ(line, "bbbb");
            getline(testFin, line);
            ASSERT_EQ(line, "cccc");
            getline(testFin, line);
            ASSERT_EQ(line, "1");
            getline(testFin, line);
            ASSERT_EQ(line, "1");
            getline(testFin, line);
            ASSERT_EQ(line, "1900");
            getline(testFin, line);
            ASSERT_EQ(line, "0");
            // Activity dddd
            getline(testFin, line);
            ASSERT_EQ(line, "dddd");
            getline(testFin, line);
            ASSERT_EQ(line, "eeee");
            getline(testFin, line);
            ASSERT_EQ(line, "12");
            getline(testFin, line);
            ASSERT_EQ(line, "10");
            getline(testFin, line);
            ASSERT_EQ(line, "2009");
            getline(testFin, line);
            ASSERT_EQ(line, "1");
    //new Category label
    getline(testFin, line);
    ASSERT_EQ(line, "newCategoryLabel");
        // Category ffff
        getline(testFin, line);
        ASSERT_EQ(line, "ffff");
            // Activity gggg
            getline(testFin, line);
            ASSERT_EQ(line, "gggg");
            getline(testFin, line);
            ASSERT_EQ(line, "hhhh");
            getline(testFin, line);
            ASSERT_EQ(line, "1");
            getline(testFin, line);
            ASSERT_EQ(line, "1");
            getline(testFin, line);
            ASSERT_EQ(line, "1900");
            getline(testFin, line);
            ASSERT_EQ(line, "0");
            // Activity iiii
            getline(testFin, line);
            ASSERT_EQ(line, "iiii");
            getline(testFin, line);
            ASSERT_EQ(line, "llll");
            getline(testFin, line);
            ASSERT_EQ(line, "13");
            getline(testFin, line);
            ASSERT_EQ(line, "2");
            getline(testFin, line);
            ASSERT_EQ(line, "2000");
            getline(testFin, line);
            ASSERT_EQ(line, "1");
}


TEST_F(TxtFileFixture, chechFileTest){
    //checkFile usa TxtFile::readFile; quindi non serve testarlo
    //readFile usa TxtFile::readLabel, Category::readCategory; quindi non serve testarli
    //readCategory usa Activity::readActivity; quindi non serve testarlo
    std::vector<Category> testReadIndex;
    checkFile("readTestFile.txt", testReadIndex);
    ASSERT_EQ(testReadIndex.size(), 2);
    ASSERT_EQ(testReadIndex[0].getName(), "aaaa");
    ASSERT_EQ(testReadIndex[0].getSize(), 2);
    ASSERT_EQ(testReadIndex[0].getActivityName(0), "bbbb");
    ASSERT_EQ(testReadIndex[0].getActivityDescription(0), "cccc");
    ASSERT_EQ(testReadIndex[0].getActivityDate(0).getDay(), 1);
    ASSERT_EQ(testReadIndex[0].getActivityDate(0).getMonth(), 1);
    ASSERT_EQ(testReadIndex[0].getActivityDate(0).getYear(), 1900);
    ASSERT_EQ(testReadIndex[0].getActivityYesNOdata(0), false);
    ASSERT_EQ(testReadIndex[0].getActivityName(1), "dddd");
    ASSERT_EQ(testReadIndex[0].getActivityDescription(1), "eeee");
    ASSERT_EQ(testReadIndex[0].getActivityDate(1).getDay(), 12);
    ASSERT_EQ(testReadIndex[0].getActivityDate(1).getMonth(), 10);
    ASSERT_EQ(testReadIndex[0].getActivityDate(1).getYear(), 2009);
    ASSERT_EQ(testReadIndex[0].getActivityYesNOdata(1), true);
    ASSERT_EQ(testReadIndex[1].getName(), "ffff");
    ASSERT_EQ(testReadIndex[1].getSize(), 2);
    ASSERT_EQ(testReadIndex[1].getActivityName(0), "gggg");
    ASSERT_EQ(testReadIndex[1].getActivityDescription(0), "hhhh");
    ASSERT_EQ(testReadIndex[1].getActivityDate(0).getDay(), 1);
    ASSERT_EQ(testReadIndex[1].getActivityDate(0).getMonth(), 1);
    ASSERT_EQ(testReadIndex[1].getActivityDate(0).getYear(), 1900);
    ASSERT_EQ(testReadIndex[1].getActivityYesNOdata(0), false);
    ASSERT_EQ(testReadIndex[1].getActivityName(1), "iiii");
    ASSERT_EQ(testReadIndex[1].getActivityDescription(1), "llll");
    ASSERT_EQ(testReadIndex[1].getActivityDate(1).getDay(), 13);
    ASSERT_EQ(testReadIndex[1].getActivityDate(1).getMonth(), 2);
    ASSERT_EQ(testReadIndex[1].getActivityDate(1).getYear(), 2000);
    ASSERT_EQ(testReadIndex[1].getActivityYesNOdata(1), true);
}
