#include <iostream>

class Distance
{
    private:
        double meter;
    public:
        explicit Distance(double m)
            :meter{m}
        {
        }

        double get_meter() const
        {
            return meter;
        }

        double get_km() const
        {
            return meter/1000.0;
        }

        Distance operator+(const Distance& other) const
        {
            return Distance{
                meter+other.meter
            };
        }
};

Distance operator""_m(long double value)
{
    return Distance{
        static_cast<double>(value)
    };
}

Distance operator""_km(long double value)
{
    return Distance{
        static_cast<double>(value*1000.0L)
    };
}

int main()
{
    auto d1{1.5_km};
    auto d2{500.0_m};

    auto total{d1+d2};

    std::cout<<total.get_km()<<"km\n";

    return 0;
}



/*
[DAY 09 NOTES]

- TOPIC: User-defined literals and object creation

- User-defined literals can create objects from values with custom suffixes.

Examples:
- 1.5_km -> Distance object
- 500.0_m -> Distance object

- _km converts kilometers to meters.
- _m stores the value directly as meters.
- Distance stores all values internally in meters.

- auto deduces the returned type automatically.
  auto d1{1.5_km}; -> Distance

- operator+ defines how two Distance objects are added.
- The result is also a new Distance object.

- static_cast<double>(value) explicitly converts
  long double to double.

Flow:
literal -> literal operator -> Distance object
-> calculation in meters -> output in kilometers
*/