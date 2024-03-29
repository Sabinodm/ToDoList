//
// Created by sabinodm on 30/09/23.
//

#include "gtest/gtest.h"
#include "../Category.h"

class CategoryFixture : public ::testing::Test {

protected:

    void SetUp() override {
        category.addActivity("bbbb", "cccc", 1, 1, 2000, true);
        category.addActivity("dddd", "eeee", false);
    }


    virtual void TearDown() {
        category.clearList();

    }

    std::string name = "aaaa";
    Category category = Category(name);
};

TEST_F(CategoryFixture, AddActivity) {
    category.addActivity("ffff", "gggg", 7, 8, 2003, true);
    EXPECT_EQ(category.getSize(), 3) << "The size of the list is not correct";
    EXPECT_EQ(category.getActivityName(2), "ffff") << "The name of the activity is not correct";
    EXPECT_EQ(category.getActivityDescription(2), "gggg") << "The description of the activity is not correct";
    EXPECT_EQ(category.getActivityDate(2).getDay(), 7) << "The day of the activity is not correct";
    EXPECT_EQ(category.getActivityDate(2).getMonth(), 8) << "The month of the activity is not correct";
    EXPECT_EQ(category.getActivityDate(2).getYear(), 2003) << "The year of the activity is not correct";
    EXPECT_EQ(category.getActivityYesNOdata(2), true) << "The yesNOdata of the activity is not correct";
}

TEST_F(CategoryFixture, RemoveActivity) {
    category.removeActivity(1);
    EXPECT_EQ(category.getSize(), 1);
}

TEST_F(CategoryFixture, ClearList) {
    category.clearList();
    EXPECT_EQ(category.getSize(), 0);
}


TEST_F(CategoryFixture, SearchActivity) {
    EXPECT_EQ(category.searchActivity("bbbb"), 1);
    EXPECT_EQ(category.searchActivity("dddd"), 1);
    EXPECT_EQ(category.searchActivity("llll"), 0);
}