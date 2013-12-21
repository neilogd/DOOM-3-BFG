/*
===========================================================================

Doom 3 BFG Edition GPL Source Code - Raspberry Pi Port.
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company. 

This file is part of the Doom 3 BFG Edition Raspberry Pi Port GPL Source Code ("Doom 3 BFG Edition Raspberry Pi Port Source Code").  

Doom 3 BFG Edition Raspberry Pi Port Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/
#ifndef __SNDDUMMY_H__
#define __SNDDUMMY_H__

#include "SoundVoice.h"


class idSoundSample_Dummy {
public:
	// Loads and initializes the resource based on the name.
	virtual void	 LoadResource() {}

	void			SetName( const char * n ) { (void)n; }
	const char *	GetName() const { return "idSoundSample_Dummy"; }
	ID_TIME_T		GetTimestamp() const { return 0; }

	// turns it into a beep
	void			MakeDefault() {}

	// frees all data
	void			FreeData() {}

	int				LengthInMsec() const { return 0; }
	int				SampleRate() const { return 44100; }
	int				NumSamples() const { return 0; }
	int				NumChannels() const { return 1; }
	int				BufferSize() const { return 0; }

	bool			IsCompressed() const { return false; }

	bool			IsDefault() const { return false; }
	bool			IsLoaded() const { return true; }

	void			SetNeverPurge() { }
	bool			GetNeverPurge() const { return false; }

	void			SetLevelLoadReferenced() { }
	void			ResetLevelLoadReferenced() { }
	bool			GetLevelLoadReferenced() const { return false; }

	int				GetLastPlayedTime() const { return 0; }
	void			SetLastPlayedTime( int t ) { (void)t; }

	float			GetAmplitude( int timeMS ) const{ return 1.0f; }
};

class idSoundSample : public idSoundSample_Dummy {
public:
};






class idSoundVoice_Dummy : public idSoundVoice_Base {
public:
	void					Create( const idSoundSample * leadinSample, const idSoundSample * loopingSample ){}

	// Start playing at a particular point in the buffer.  Does an Update() too
	void					Start( int offsetMS, int ssFlags ){}

	// Stop playing.
	void					Stop(){}

	// Stop consuming buffers
	void					Pause(){}
	// Start consuming buffers again
	void					UnPause(){}

	// Sends new position/volume/pitch information to the hardware
	bool					Update(){ return true; }

	// returns the RMS levels of the most recently processed block of audio, SSF_FLICKER must have been passed to Start
	float					GetAmplitude(){ return 1.0f; }

	// returns true if we can re-use this voice
	bool					CompatibleFormat( idSoundSample * s ){ return false; }

	uint32					GetSampleRate() const { return 44100; }

	// callback function
	void					OnBufferStart( idSoundSample * sample, int bufferNumber ){}
};


class idSoundVoice : public idSoundVoice_Dummy {
};





class idSoundHardware_Dummy {
public:
	void			Init(){}
	void			Shutdown(){}

	void 			Update(){}

	idSoundVoice *	AllocateVoice( const idSoundSample * leadinSample, const idSoundSample * loopingSample ){ return NULL; }
	void			FreeVoice( idSoundVoice * voice ){}

	int				GetNumZombieVoices() const { return 0; }
	int				GetNumFreeVoices() const { return 0; }
};

class idSoundHardware : public idSoundHardware_Dummy {
};

#endif // __NGDBUILD_H__
