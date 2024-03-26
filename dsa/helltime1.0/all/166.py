class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return '0'

        result = []

        is_negative = (numerator > 0) ^ (denominator > 0)
        if is_negative:
            result.append('-')

        numerator_abs = abs(numerator)
        denominator_abs = abs(denominator)

        result.append(str(numerator_abs // denominator_abs))

        remainder = numerator_abs % denominator_abs

        if remainder == 0:
            return ''.join(result)

        result.append('.')

        seen_remainders = {}

        while remainder != 0:
            if remainder in seen_remainders:
                idx = seen_remainders[remainder]
                result.insert(idx, '(')
                result.append(')')
                break

            seen_remainders[remainder] = len(result)

            remainder *= 10

            result.append(str(remainder // denominator_abs))

            remainder %= denominator_abs

        return ''.join(result)
