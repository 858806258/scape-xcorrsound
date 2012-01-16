#ifndef MY_UTILS_GUARD
#define MY_UTILS_GUARD
#include "stdint.h"
#include <string>
#include <vector>

int getFilesize(std::string filename);
short convertTwoBytesToShort(char a, char b);
uint32_t convertFourBytesToInt(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
void convertCharArrayToShort(char* arr, short* arr2, int arraySize);
int16_t getIntFromChars(uint8_t a, uint8_t b);
int32_t getIntFromChars(uint8_t a, uint8_t b, uint8_t c, uint8_t d);

template<typename T1, typename T2> 
inline
void prefixSquareSum(std::vector<T1> &a, std::vector<T2> &res) {
    res.resize(a.size());
    res[0] = a[0] * a[0];
    for (size_t i = 1; i < res.size(); ++i) {
	res[i] = res[i-1] + a[i] * a[i];
    }
}

template<typename T1> inline
double computeNormFactor(std::vector<T1> &prefixSquareSmall, std::vector<T1> &prefixSquareLarge, 
		     typename std::vector<T1>::iterator smallBegin, typename std::vector<T1>::iterator smallEnd,
		     typename std::vector<T1>::iterator largeBegin, typename std::vector<T1>::iterator largeEnd) {
    
    if (smallEnd != prefixSquareSmall.begin()) --smallEnd;

    int64_t smallVal = *smallEnd;

    if (smallBegin != prefixSquareSmall.begin()) {
	--smallBegin;
	smallVal -= *smallBegin;
    }

    if (largeEnd != prefixSquareLarge.begin()) --largeEnd;

    int64_t largeVal = *largeEnd;    

    if (largeBegin != prefixSquareLarge.begin()) {
	--largeBegin;
	largeVal -= *largeBegin;
    }
    double val = ((smallVal+0.0) + (largeVal+0.0));
    if (val < 1) return 1;
    return 0.5 * val;

}

#endif
