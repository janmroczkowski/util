#pragma once
#include <cstdint>
#include <cstring>
#include <utility>

template<class Index = std::uint_least32_t>
class DynamicBitSet
{
public:
  DynamicBitSet(Index const n) : z([=]
    {
      QR const d = d8(n);
      return d.q + (d.r ? 1 : 0);
    }()), s(new std::uint8_t[z])
  {
    std::memset(s, 0, z);
  }
  DynamicBitSet(DynamicBitSet const& n) : z(n.z),
    s(new std::uint8_t[z])
  {
    std::memcpy(s, n.s, z);
  }
  DynamicBitSet(DynamicBitSet&& n) noexcept :
    z(n.z), s(n.s)
  {
    n.s = nullptr;
  }
  DynamicBitSet& operator=(DynamicBitSet const&) = delete;
  DynamicBitSet& operator=(DynamicBitSet &&) = delete;
  DynamicBitSet& operator|=(DynamicBitSet const& o)
  {
    std::uint8_t const* const b = o.s;
    Index const a = (o.z < z) ? o.z : z;
    for (Index i = 0; i < a; ++i)
    {
      s[i] |= b[i];
    }
    return *this;
  }
  bool test(Index const i) const
  {
    QR const d = d8(i);
    return s[d.q] & 1 << d.r;
  }
  void set(Index const i)
  {
    QR const d = d8(i);
    s[d.q] |= 1 << d.r;
  }
  ~DynamicBitSet()
  {
    delete[] s;
  }
private:
  struct QR
  {
    Index q, r;
  };
  QR d8(Index const i) const
  {
    Index const q = i >> 3;
    return QR{q, static_cast<Index>(i & 7)};
  }
  Index z;
  std::uint8_t* s;
};

template<class Index = std::uint_least32_t>
class DynamicBitMap : DynamicBitSet<Index>
{
public:
  DynamicBitMap(Index const w_, Index const h_) :
    DynamicBitSet<Index>(w_ * h_),  w(w_), h(h_)
  {
  }
  DynamicBitMap& operator=(DynamicBitMap const&) = delete;
  DynamicBitMap& operator=(DynamicBitMap &&) = delete;
  DynamicBitMap(DynamicBitMap const& m_) :
    DynamicBitSet<Index>(m_), w(m_.w), h(m_.h)
  {
  }
  DynamicBitMap(DynamicBitMap&& m_) noexcept :
    DynamicBitSet<Index>(std::move(m_)),
    w(m_.w), h(m_.h)
  {
  }
  void set(Index const x, Index const y)
  {
    DynamicBitSet<Index>::set(c(x, y));
  }
  bool test(Index const x, Index const y) const
  {
    return DynamicBitSet<Index>::test(c(x, y));
  }
  Index width() const
  {
    return w;
  }
  Index height() const
  {
    return h;
  }
private:
  Index c(Index const x, Index const y) const
  {
    return x + h * y;
  }
  Index w;
  Index h;
};

