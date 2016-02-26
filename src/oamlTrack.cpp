//-----------------------------------------------------------------------------
// Copyright (c) 2015-2016 Marcelo Fernandez
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "oamlCommon.h"


oamlTrack::oamlTrack() {
	name = "Track";
	type = 0;

	fadeIn = 0;
	fadeOut = 0;
	xfadeIn = 0;
	xfadeOut = 0;
}

oamlTrack::~oamlTrack() {
}

void oamlTrack::ClearAudios(std::vector<oamlAudio*> *audios) {
	while (audios->empty() == false) {
		oamlAudio *audio = audios->back();
		audios->pop_back();

		delete audio;
	}
}

int oamlTrack::Random(int min, int max) {
	int range = max - min + 1;
	return rand() % range + min;
}

void oamlTrack::ShowPlaying() {
	std::string info;

	info = GetPlayingInfo();
	printf("%s\n", info.c_str());
}
