#pragma once
#include <map>

template<typename T, T defval, size_t Dim = 2>
class Matrix
{
public:
    using DataT = std::map<std::pair<size_t, size_t>, T>;

    template<typename U>
    class ValueProxy
    {
    private:
        U &d;
        const T &val;
        size_t col;
        size_t row;
    public:
        ValueProxy(U &data, const T &value, size_t i, size_t j) : d(data), val(value), col(i), row(j){};
        ValueProxy &operator=(const T& rhs)
        {
            d[std::make_pair(col, row)] = rhs;
            return *this;
        }

        ValueProxy &operator=(const T& rhs) const = delete;

        operator T() const
        {
            return val;
        }
    };

    class DataRepr
    {
    private:
        DataT filledData;
    public:
        auto get(size_t i, size_t j) const -> decltype(auto)
        {
            for (const auto &item : filledData)
            {
                if (item.first.first == i && item.first.second == j)
                {
                    return item.second;
                }
            }
            return defval;
        }

        auto get(size_t i, size_t j) -> decltype(auto)
        {
            for (const auto &item : filledData)
            {
                if (item.first.first == i && item.first.second == j)
                {
                    return ValueProxy{filledData, item.second, i, j};
                }
            }
            return ValueProxy{filledData, defval, i, j};
        }

        size_t size() const { return filledData.size();}
    };

private:
    DataRepr data;
    // TODO: replace pair with template type

public:

    template<typename U>
    class MatrixProxy
    {
    private:
        size_t col;
        U &dataPtr;
    public:
        MatrixProxy(size_t i, U &data) : col(i), dataPtr(data){};

        auto operator[](size_t j) -> decltype(auto)
        {
            return dataPtr.get(col, j);
        }
    };

    Matrix() = default;
    size_t size() const {return data.size();};

    auto operator[](size_t i) const -> decltype(auto)
    {
        return MatrixProxy{i, data};
    };

    auto operator[](size_t i) -> decltype(auto)
    {
        return MatrixProxy{i, data};
    };
};