#pragma once

#include <concepts>
#include <iostream>
template<typename I> requires std::integral<I>
class rational {
    I num_;
    I den_;
    
    I euclide_mcd(I a, I b) const {
        if (a < I{0}) {
            a = -a;
        }
        if (b < I{0}) {
            b = -b;
        }
        while (b > 0) {
            I r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    
    void semplifica_frazioni() {
        if (den_ == I{0}) {
            return;
        }
        I mcd = euclide_mcd(num_, den_);
        num_ = num_ / mcd;
        den_ = den_ / mcd;
        if (den_ < I{0}) {
            num_ = -num_;
            den_ = -den_;
        }
    }

public:
    rational()
        : num_(I{0}), den_(I{1})
    {}
    
    rational(const I& num, const I& den) {
        if (den == I{0}) {
            if (num == I{0}) {
                num_ = I{0};
                den_ = I{0};
            } else {
                if (num > I{0}) {
                    num_ = I{1};
                } else {
                    num_ = I{-1};
                }
                den_ = I{0};
            }
        } else {
            num_ = num;
            den_ = den;
            semplifica_frazioni();
        }
    }
    
    I num() const { return num_; }
    I den() const { return den_; }
    
    bool is_nan() const {
        return (den_ == I{0} && num_ == I{0});
    }
    bool is_inf() const {
        return (den_ == I{0} && num_ != I{0});
    }

    rational& operator+=(const rational& other) {
        if (is_nan() || other.is_nan()) {
            num_ = I{0};
            den_ = I{0};
            return *this;
        }
        if (is_inf() && other.is_inf()) {
            if (num_ != other.num_) {
                num_ = I{0};
                den_ = I{0};
            } 
            return *this;
        }
        if (is_inf()) {
            return *this;
        }
        if (other.is_inf()) {
            num_ = other.num_;
            den_ = other.den_;
            return *this;
        }
        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        semplifica_frazioni();
        return *this;
    }
    
    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }

    rational& operator-=(const rational& other) {
        if (is_nan() || other.is_nan()) {
            num_ = I{0};
            den_ = I{0};
            return *this;
        }
        if (is_inf() && other.is_inf()) {
            if (num_ == other.num_) {
                num_ = I{0};
                den_ = I{0};
            } 
            return *this;
        }
        if (is_inf()) {
            return *this;
        }
        if (other.is_inf()) {
            num_ = -other.num_;
            den_ = other.den_;
            return *this;
        }
        num_ = num_ * other.den_ - other.num_ * den_;
        den_ = den_ * other.den_;
        semplifica_frazioni();
        return *this;
    }
    
    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }

    rational& operator*=(const rational& other) {
        if (is_nan() || other.is_nan()) {
            num_ = I{0};
            den_ = I{0};
            return *this;
        }
        if (is_inf() || other.is_inf()) {
            if (num_ == I{0} || other.num_ == I{0}) {
                num_ = I{0};
                den_ = I{0};
                return *this;
            }
            if ((num_ > I{0} && other.num_ > I{0}) || (num_ < I{0} && other.num_ < I{0})) {
                num_ = I{1};
            } else {
                num_ = I{-1};
            }
            den_ = I{0};
            return *this;
        }
        num_ = num_ * other.num_;
        den_ = den_ * other.den_;
        semplifica_frazioni();
        return *this;
    }

    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }

    rational& operator/=(const rational& other) {
        if (is_nan() || other.is_nan()) {
            num_ = I{0};
            den_ = I{0};
            return *this;
        }
        if (other.num_ == I{0}) {
            if (num_ == I{0}) {
                den_ = I{0};
                return *this;
            }
            if (num_ > I{0}) {
                num_ = I{1};
            } else {
                num_ = I{-1};
            }
            den_ = I{0};
            return *this;
        }
        if (other.is_inf()) {
            if (is_inf()) {
                num_ = I{0};
                den_ = I{0};
                return *this;
            }
            num_ = I{0};
            den_ = I{1};
            return *this;
        }
        if (is_inf()) {
            if (other.num_ < I{0}) {
                num_ = -num_;
            }
            return *this;
        }
        num_ = num_ * other.den_;
        den_ = den_ * other.num_;
        semplifica_frazioni();
        return *this;
    }

    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }

};

template<typename I> requires std::integral<I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
    if (r.is_nan()) {
        os << "NaN";
    } else if (r.is_inf()) {
        if (r.num() == I{1}) {
            os << "+Inf";
        } else {
            os << "-Inf";
        }
    } else {
        if (r.den() == I{1}) {
            os << r.num();
        } else {
            os << r.num() << "/" << r.den();
        } 
    }
    return os;
}