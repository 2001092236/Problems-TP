
#pragma once

#include <gtest/gtest.h>
#include "WeatherMock.h"
#include <cpr/cpr.h>

class WeatherTestCase : public ::testing::Test {
public:
    void SetUp();
    WeatherMock weather;
    cpr::Response Kazan;
    cpr::Response Moscow;
};