# FixedPoints
A portable fixed point arithmetic library.

Some knowledge of how fixed point types are formatted is required to used this library to full effect.
No knowledge of how these operations are implemented is required to use them.

This library was written with Arduino in mind, as well as CPUs with limited floating point support.
However, given the templated nature of the library, it should still function on a wide variety of CPUs.

## Requirements:

- The Compiler must be C++11 compliant.
- The user should ideally be familar with the [Q number format](https://en.wikipedia.org/wiki/Q_(number_format)) for fixed points.

## Licence

This code uses the Apache 2.0 Licence.
This means:

- This code comes with no warranty.
- The licensor and any contributors cannot be held liable for damages.
- If you use this code, edited or unedited, you must:
  - Package a copy of LICENCE with your code.
  - Package a copy of NOTICE with your code.
- You may modify the source code.
  - If you modify a file, you must state this prominently in the file (i.e. in a comment at the top).
  - Any modified code may use a different licence.
  - Any unmodified code must carry the same Apache 2.0 licence.
- You may not use any trademarks owned by the licensor.

## The Future

At the moment there are no additional features planned.
For now, future changes will consist solely of:
- Fixing Bugs
- Eradicating Warnings
- Adding Better Documentation

However, better support for pre-C++11 compilers may be investigated if there is found to be sufficient demand for it.

## Contents
This library supplies two core types and sixteen type aliases.

### Core Types:
The core types are provided by `FixedPoints.h`.

- `UFixedPoint<I, F>`: An unsigned fixed point type where I is the number of bits used for the integer part of the number and F is the number of bits used for the fractional part of the number.  
- `FixedPoint<I, F>`: An signed fixed point type where I is the number of bits used for the integer part of the number (excluding the implicit sign bit) and F is the number of bits used for the fractional part of the number.

### Aliases:
The common aliases are provided by `FixedPointsCommon.h`.

- `Q4x4`: An alias for `UFixedPoint<4, 4>`, an 8-bit unsigned fixed point in the Q4.4 format.
- `Q8x8`: An alias for `UFixedPoint<8, 8>`, a 16-bit unsigned fixed point in the Q8.8 format.
- `Q16x16`: An alias for `UFixedPoint<16, 16>`, a 32-bit unsigned fixed point in the Q16.16 format.
- `Q32x32`: An alias for `UFixedPoint<32, 32>`, a 64-bit unsigned fixed point in the Q32.32 format.
- `Q1x7`: An alias for `UFixedPoint<1, 7>`, an 8-bit unsigned fixed point in the Q1.7 format.
- `Q1x15`: An alias for `UFixedPoint<1, 15>`, a 16-bit unsigned fixed point in the Q1.15 format.
- `Q1x31`: An alias for `UFixedPoint<1, 31>`, a 32-bit unsigned fixed point in the Q1.31 format.
- `Q1x63`: An alias for `UFixedPoint<1, 63>`, a 64-bit unsigned fixed point in the Q1.63 format.
- `SQ3x4`: An alias for `FixedPoint<3, 4>`, an 8-bit signed fixed point in the Q3.4 format with implicit sign bit.
- `SQ7x8`: An alias for `FixedPoint<7, 8>`, a 16-bit signed fixed point in the Q7.8 format with implicit sign bit.
- `SQ15x16`: An alias for `FixedPoint<15, 16>`, a 32-bit signed fixed point in the Q15.16 format with implicit sign bit.
- `SQ31x32`: An alias for `FixedPoint<31, 32>`, a 64-bit signed fixed point in the Q31.32 format with implicit sign bit.
- `SQ1x6`: An alias for `FixedPoint<1, 6>`, an 8-bit signed fixed point in the Q1.6 format with implicit sign bit.
- `SQ1x14`: An alias for `FixedPoint<1, 14>`, a 16-bit signed fixed point in the Q1.14 format with implicit sign bit.
- `SQ1x30`: An alias for `FixedPoint<1, 30>`, a 32-bit signed fixed point in the Q1.30 format with implicit sign bit.
- `SQ1x62`: An alias for `FixedPoint<1, 62>`, a 64-bit signed fixed point in the Q1.62 format with implicit sign bit.

([About Q Format](https://en.wikipedia.org/wiki/Q_(number_format)).)

### Operators:

- `+`: Adds two `UFixedPoint`s or two `FixedPoint`s
- `-`: Subtracts two `UFixedPoint`s or two `FixedPoint`s
- `*`: Multiplies two `UFixedPoint`s or two `FixedPoint`s
- `/`: Divides two `UFixedPoint`s or two `FixedPoint`s
- `==`: Compares two `UFixedPoint`s or two `FixedPoint`s
- `!=`: Compares two `UFixedPoint`s or two `FixedPoint`s
- `<`: Compares two `UFixedPoint`s or two `FixedPoint`s
- `<=`: Compares two `UFixedPoint`s or two `FixedPoint`s
- `>`: Compares two `UFixedPoint`s or two `FixedPoint`s
- `>=`: Compares two `UFixedPoint`s or two `FixedPoint`s

### Free Functions:

- `Floor`: The floor operation.
- `Ceil`: The Ceiling operation
- `Round`: Rounding operation.
- `Signbit`: Returns `true` for signed numbers and `false` for unsigned numbers.
- `Multiply`: Multiplies two `UFixedPoint`s or two `FixedPoint`s, returns a result that is twice the resolution of the input.

### Member Functions:

- `UFixedPoint<I, F>::GetInteger`: Gets the integer part of an unsigned fixed point.
- `UFixedPoint<I, F>::GetFraction`: Gets the fractional part of an unsigned fixed point.
- `UFixedPoint<I, F>::GetInternal`: Gets the internal representation of an unsigned fixed point.

- `FixedPoint<I, F>::GetInteger`: Gets the integer part of a signed fixed point.
- `FixedPoint<I, F>::GetFraction`: Gets the fractional part of a signed fixed point.
- `FixedPoint<I, F>::GetInternal`: Gets the internal representation of a signed fixed point.

### Static Functions:

- `UFixedPoint<I, F>::FromInternal`: Produces an unsigned fixed point number from its internal representation.
- `FixedPoint<I, F>::FromInternal`: Produces a signed fixed point number from its internal representation.

## Construction:

Note that both `UFixedPoint<I, F>` and `FixedPoint<I, F>` are implicitly compile-time constructable from all integer and decimal literals. This means that you may write code such as `UFixedPoint<8, 8> value = 0.5;` without incurring a runtime cost for converting from `double` to `UFixedPoint<8, 8>` because the constructor is `constexpr`.

`UFixedPoint<I, F>` is constructable from:
- Any integer litral type, regardless of sign.
-- This constructs the fixed point as an integer with no fractional part.
-- A value that does not fit shall be truncated without warning. 
-- If a constant value is used, the fixed point shall be constructed at compile time.
- An unsigned integer part and an unsigned fractional part.
-- The integer part is of the smallest type capable of representing `I` bits.
-- The fractional part is of the smallest type capable of representing `F` bits.
-- If constant values are used, the fixed point shall be constructed at compile time.
- Any decimal literal type, regardless of sign.
-- This constructs the fixed point as a best approximation of the provided value.
-- A value that does not fit shall be truncated without warning. 
-- If a constant value is used, the fixed point shall be constructed at compile time.

`FixedPoint<I, F>` is constructable from:
- Any integer litral type, regardless of sign.
-- This constructs the fixed point as an integer with no fractional part.
-- A value that does not fit shall be truncated without warning. 
-- If a constant value is used, the fixed point shall be constructed at compile time.
- A signed integer part and an unsigned fractional part.
-- The integer part is of the smallest type capable of representing `I + 1` bits.
-- The fractional part is of the smallest type capable of representing `F` bits.
-- If constant values are used, the fixed point shall be constructed at compile time.
- Any decimal literal type, regardless of sign.
-- This constructs the fixed point as a best approximation of the provided value.
-- A value that does not fit shall be truncated without warning. 
-- If a constant value is used, the fixed point shall be constructed at compile time.

### Casts:

`UFixedPoint<I, F>` is explicitly convertible to:
- `float`.
- `double`.
- The smallest unsigned type capable of holding its integer part. I.e. a type of at least `I` bits.
- Another `UFixedPoint` type of a different scale. E.g. `UFixedPoint<4, 4>` may be converted to `UFixedPoint<8, 8>` and vice versa.

`FixedPoint<I, F>` is explicitly convertible to:
- `float`.
- `double`.
- The smallest signed type capable of holding its integer part. I.e. a type of at least `I + 1` bits.
- Another `FixedPoint` type of a different scale. E.g. `FixedPoint<3, 4>` may be converted to `FixedPoint<7, 8>` and vice versa.


