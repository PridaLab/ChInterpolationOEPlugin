#include "ChInterp.h"
#include "ChInterpEditor.h"
#include <iostream>
using namespace ChInterpSpace;

//Change all names for the relevant ones, including "Processor Name"
ChInterp::ChInterp() : GenericProcessor("Ch-interp")
{
	int og_channelArray[8] = {0,-1,-1,3,-1,-1,-1,7};
	int to_channelArray[8] = {0,1,2,3,4,5,6,7};

}

ChInterp::~ChInterp()
{
}

void ChInterp::process(AudioSampleBuffer& buffer)
{
	/**
	//set -1 channels to 0 manually	and scale the others
	for (int ch = 0; ch < 16 ; ++ch)
	{	
		bool exists = 0;
		int idx_val = -1;
		for (int idx = 0; idx<8; ++idx)
		{
			if (og_channelArray[idx]==ch)
			{	
				idx_val = idx;
				exists = 1;
			}
		}
		if (exists)
		{
			int nSamples = getNumSamples(ch);
			float* ptr = buffer.getWritePointer(ch);
			for (int n = 0; n<nSamples; ++n)
			{
				*(ptr+ n) = idx_val*(*(ptr+n));
			}
	
		}
		else
		{
			int nSamples = getNumSamples(ch);
			float* ptr = buffer.getWritePointer(ch);
			for (int n = 0; n < nSamples; ++n)
			{
				*(ptr +  n) =0*(*(ptr+n));
			}
		}

	}
	*/

	channelBuffer = buffer;

	//Set all to zero
	for (int ch = 0; ch < buffer.getNumChannels() ; ++ch)
	{
		int nSamples = getNumSamples(ch);
		float* ptr = buffer.getWritePointer(ch);
		for (int n = 0; n < nSamples; ++n)
		{
			*(ptr +  n) =0*(*(ptr+n));
		}
	}

	for (int ch=0; ch<8; ++ch)
	{
    	if (og_channelArray[ch]> -1) //if channel provided then just reallocate on new place
    	{
			int nSamples = getNumSamples(og_channelArray[ch]);
			float* toPtr = buffer.getWritePointer(to_channelArray[ch]); //get pointer to new location
			for (int n = 0; n < nSamples; ++n)
			{
                const float sample = *channelBuffer.getReadPointer (og_channelArray[ch], n); //get value from old location
                *(toPtr + n) = sample; //save value to new location
			}
    	}
    	else //if channel not provided then interpolate
    	{
			int nSamples = getNumSamples(to_channelArray[ch]);
			float* toPtr = buffer.getWritePointer(to_channelArray[ch]); //get pointer to memory space to save the interpolated channel

			int left_ch = leftIndex(og_channelArray, ch); //get closest provided channel on the left
			int right_ch = rightIndex(og_channelArray, ch); //get closest provided channel on the right
			float dist_ch = right_ch - left_ch; //get distance to do a weighted linear interpolation

			for (int n=0; n<nSamples; ++n)
			{
                const float leftVal = *channelBuffer.getReadPointer (og_channelArray[left_ch], n); //get value of left channel
                const float rightVal = *channelBuffer.getReadPointer (og_channelArray[right_ch], n); //get value of right channel
				*(toPtr + n) = leftVal + ((ch - left_ch)/dist_ch)*(rightVal - leftVal); //compute weighted linear interpolation
			}			

    	}

	}

}

// Method called when changed value on Editor to update value on process
void ChInterp::setParameter(int parameterIndex, float newValue)
{
	int val = (int) newValue;
	if (parameterIndex < 8)
	{
		og_channelArray[parameterIndex] = val;
	}
	else if (parameterIndex>9)
	{
		to_channelArray[parameterIndex-10] = val;
	}
}

// Method to find the first entry on the left w/o a -1
int ChInterp::leftIndex(int inputChannel[], int currIndex){
	if(currIndex<0){
	    return -1;
	}

	if(inputChannel[currIndex] >-1){
	    return currIndex;
	}

	return leftIndex(inputChannel,currIndex-1);
		    
}

// Method to find the first entry on the right w/o a -1
int ChInterp::rightIndex(int inputChannel[], int currIndex){
    if(currIndex==8){
        return -1;
    }

    if(inputChannel[currIndex] >-1){
        return currIndex;
    }

    return rightIndex(inputChannel,currIndex+1);
		    
}

// Method called at the beggining to create custom Editor
AudioProcessorEditor* ChInterp::createEditor()
{
    editor = new ChInterpEditor (this, true);

    //std::cout << "Creating editor." << std::endl;

    return editor;
}