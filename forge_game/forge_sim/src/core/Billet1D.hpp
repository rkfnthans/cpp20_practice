#pragma once

#include <cstddef>
#include <vector>
#include <Cell.hpp>

class Billet1D{
private:
    std::vector<Cell> cells_;
public:
    Billet1D(
        std::size_t cellCount,
        double initalMassPerCell
    );

    Cell& at(std::size_t index);
    const Cell& at(std::size_t index) const;

    std::size_t size() const;

};