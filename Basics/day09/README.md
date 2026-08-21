# Day 09 — User-Defined Literals and Object Creation

## Topic

User-defined literals and object creation with a `Distance` class.

## What I Studied

- User-defined literals can create objects from values with custom suffixes.
- `_km` converts kilometers to meters.
- `_m` stores the value directly as meters.
- `Distance` stores all values internally in meters.
- `auto` deduces the returned object type automatically.
- `operator+` defines how two `Distance` objects are added.
- The result of the addition is a new `Distance` object.
- `static_cast<double>(value)` explicitly converts `long double` to `double`.

## Examples

```cpp
auto d1{1.5_km};
auto d2{500.0_m};
```

Both expressions create `Distance` objects.

```text
1.5_km   -> 1500 m internally
500.0_m  -> 500 m internally
```

## Practice Code

```cpp
#include <iostream>

class Distance
{
private:
    double meter;

public:
    explicit Distance(double m)
        : meter{m}
    {
    }

    double get_meter() const
    {
        return meter;
    }

    double get_km() const
    {
        return meter / 1000.0;
    }

    Distance operator+(const Distance& other) const
    {
        return Distance{
            meter + other.meter
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
        static_cast<double>(value * 1000.0L)
    };
}

int main()
{
    auto d1{1.5_km};
    auto d2{500.0_m};

    auto total{d1 + d2};

    std::cout << total.get_km() << " km\n";

    return 0;
}
```

## How It Works

```text
1.5_km
-> operator""_km()
-> convert km to m
-> Distance object

500.0_m
-> operator""_m()
-> Distance object

d1 + d2
-> Distance::operator+()
-> add the internally stored meter values
-> return a new Distance object

total.get_km()
-> convert the internal meter value to kilometers
-> output
```

## Key Notes

```text
literal
-> literal operator
-> Distance object
-> calculation in meters
-> output in kilometers
```

`auto` does not perform the unit conversion itself. The `_m` and `_km` literal operators perform the conversion and return a `Distance` object, and `auto` deduces that returned type.

`static_cast<double>(value)` makes the conversion from the literal operator's `long double` parameter to the `double` value used by the `Distance` constructor explicit.
