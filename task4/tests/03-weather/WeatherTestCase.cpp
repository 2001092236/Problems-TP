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
    Omsk.status_code = 200;
    Omsk.text = "{\"cod\":\"200\",\"main\":{\"temp\":22.00},\"list\":[{\"main\""\
                ":{\"temp\":19.00}}, {\"main\":{\"temp\":67.00}}, {\"main\":"\
                "{\"temp\":97.00}}, {\"main\":{\"temp\":11.00}}, {\"main\":{\"temp\":16.00}}, {\"main\":{\"temp\":18.00}}, {\"main\":{\"temp\":13.00}}, {\"main\":{\"temp\":14.00}}]}";
    ON_CALL(weather, Get("Kazan", _)).WillByDefault(Return(Kazan));
    ON_CALL(weather, Get("Omsk", _)).WillByDefault(Return(Omsk));
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

TEST_F(WeatherTestCase, GetTomorrowDiff)
{
    ASSERT_NO_THROW(weather.GetTomorrowDiff("Omsk"));
}