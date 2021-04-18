//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

using ::testing::Return;
using::testing::_;


void WeatherTestCase::SetUp()
{
    Kazan.status_code = 200;
    Kazan.text = "{\"cod\":\"200\",\"main\":{\"temp\":23.00}}";
    Moscow.status_code = 200;
    Moscow.text = "{\"cod\":\"200\",\"main\":{\"temp\":46.00}}";
    ON_CALL(weather, Get("Kazan", _)).WillByDefault(Return(Kazan));
    ON_CALL(weather, Get("Moscow", _)).WillByDefault(Return(Moscow));
}

TEST_F(WeatherTestCase, GetTemperature)
{
    EXPECT_CALL(weather, Get("Kazan", _));
    ASSERT_NO_THROW(weather.GetTemperature("Kazan"));
}

TEST_F(WeatherTestCase, GetDifferenceString)
{
    ASSERT_NO_THROW(weather.GetDifferenceString("Kazan", "Moscow"));
    ASSERT_NO_THROW(weather.GetDifferenceString("Kazan", "Moscow"));
}

TEST_F(WeatherTestCase, SetApiKey)
{
    ASSERT_NO_THROW(weather.SetApiKey("mykey"));
}