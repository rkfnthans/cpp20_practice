#pragma once

struct Cell
{
    double feMassKg{0.0};           //해당 cell에 존재하는 질량
    double thermalEnergyJ{0.0};     //기준 온도보다 추가로 가지고 있는 열에너지
};
