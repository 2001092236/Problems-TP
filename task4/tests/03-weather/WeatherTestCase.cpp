//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

using ::testing::Return;


TEST_F(WeatherTestCase, GET)
{
    weather.Get("Moscow");
}

TEST_F(WeatherTestCase, GetTemperature)
{
    ASSERT_NO_THROW(weather.GetTemperature("Moscow"));
}

TEST_F(WeatherTestCase, SetApiKey)
{
    weather.SetApiKey("SUMMER");
}