//
// Created by sabinodm on 05/10/23.
//

#include "gtest/gtest.h"
#include "../TimeDate.h"

class TimeDateFixture : public ::testing::Test {


protected:

    Date date;

};

TEST_F(TimeDateFixture, checkDateTest){
    //checkDate usa TimeDate::checkDate; quindi non serve testarlo
    //checkDate usa TimeDate::isLeap; quindi non serve testarlo
    ASSERT_THROW(date.setDate(0,1,2020), TimeDateException); //Giorno sia maggiore di 0
    ASSERT_THROW(date.setDate(32,1,2020), TimeDateException); //Giorno sia minore di 32
    ASSERT_THROW(date.setDate(1,0,2020), TimeDateException); //Mese sia maggiore di 0
    ASSERT_THROW(date.setDate(1,13,2020), TimeDateException); //Mese sia minore di 13
    ASSERT_THROW(date.setDate(1,1,0), TimeDateException); //Anno sia maggiore di 0
    //controllo giorni se mesi = 4,6,9,11
    ASSERT_THROW(date.setDate(31,4,2020), TimeDateException);
    ASSERT_THROW(date.setDate(31,6,2020), TimeDateException);
    ASSERT_THROW(date.setDate(31,9,2020), TimeDateException);
    ASSERT_THROW(date.setDate(31,11,2020), TimeDateException);
    //controllo giorni se anno bisestile
    ASSERT_THROW(date.setDate(30,2,2020), TimeDateException);
    //controllo giorni se anno non bisestile
    ASSERT_THROW(date.setDate(29,2,2021), TimeDateException);

}