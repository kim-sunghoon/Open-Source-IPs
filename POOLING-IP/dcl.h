#ifndef __DCL_H
#define __DCL_H

#include <stdio.h>
#include <math.h>
#include <ap_fixed.h>
#include "hls_stream.h"
#include <iostream>
#include <fstream>


//#define CSIM_DEBUG


typedef ap_uint<8> uint8;
//typedef ap_uint<16> uint16;

#define DEPTH 16
#define WIDTH 42
#define HEIGH 22

#ifdef CSIM_DEBUG
	typedef float FIX_32_4;	//fix point
	typedef float FIX_32_25;	//fix point
	typedef float FIX_FM;	//fix point for feature map
	typedef float FIX_WT;	//fix point for weights
	typedef float FIX_32_16;	//fix point
	typedef float FIX_32_12;	//fix point
	typedef float FIX_16_1;
#else
	typedef ap_fixed<16, 6, AP_TRN_ZERO, AP_SAT> FIX_FM;	//fix point for feature map
	typedef ap_fixed<8,  1, AP_TRN_ZERO, AP_SAT> FIX_WT;	//fix point for weights
	typedef ap_fixed<16, 1, AP_TRN_ZERO, AP_SAT> FIX_16_1;	//fix point for weights
	typedef ap_fixed<32,16, AP_TRN_ZERO, AP_SAT> FIX_32_16;	//fix point
	typedef ap_fixed<32,12, AP_TRN_ZERO, AP_SAT> FIX_32_12;
	typedef ap_fixed<32, 4, AP_TRN_ZERO, AP_SAT> FIX_32_4;	//fix point
	typedef ap_fixed<32,25, AP_TRN_ZERO, AP_SAT> FIX_32_25;	//fix point
#endif



void maxpooling2x2(FIX_FM buf_in[DEPTH][HEIGH][WIDTH], FIX_FM buf_out[DEPTH][HEIGH/2][WIDTH/2]);


#endif /* ifndef  */
