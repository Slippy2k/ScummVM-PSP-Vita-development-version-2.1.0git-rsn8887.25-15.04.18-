/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef TITANIC_MUSIC_WAVE_H
#define TITANIC_MUSIC_WAVE_H

#include "common/array.h"
#include "titanic/support/string.h"

namespace Titanic {

enum MusicWaveInstrument { MV_PIANO = 0, MV_BASS = 1, MV_BELLS = 2, MV_SNAKE = 3 };

class CProjectItem;
class CSoundManager;
class CWaveFile;
class CGameObject;

class CMusicWave {
	struct CMusicWaveFile {
		CWaveFile *_waveFile;
		int _value;
		CMusicWaveFile() : _waveFile(nullptr), _value(0) {}
	};
private:
	static bool _pianoToggle;
	static int _pianoCtr;
	static int _bassCtr;
	static byte *_buffer;
private:
	CSoundManager *_soundManager;
	Common::Array<CMusicWaveFile> _items;
	MusicWaveInstrument _instrument;
	CProjectItem *_project;
	CGameObject *_gameObjects[4];
	int _field20;
	int _field24;
	int _field34;
	int _field38;
	int _field3C;
	int _field40;
	int _field44;
	int _field4C;
private:
	/**
	 * Loads the specified wave file, and returns a CWaveFile instance for it
	 */
	CWaveFile *createWaveFile(const CString &name);
public:
	/**
	 * Handles initialization of static fields
	 */
	static void init();

	/**
	 * Deinitialization of static fields
	 */
	static void deinit();
public:
	CMusicWave(CProjectItem *project, CSoundManager *soundManager, MusicWaveInstrument instrument);

	/**
	 * Sets the maximum number of allowed files that be defined
	 */
	void setSize(uint count);

	/**
	 * Loads a new file into the list of available entries
	 */
	void load(int index, const CString &filename, int v3);

	/**
	 * Starts the music and associated animations
	 */
	void start(int val);

	/**
	 * Stops the music and associated animations
	 */
	void stop();

	/**
	 * Called regularly to handle triggering the animation of the
	 * musical instrument associated with the instance
	 */
	void trigger();

	void reset();
	void setState(int val);

	int setData(const byte *data, int count);
};

} // End of namespace Titanic

#endif /* TITANIC_MUSIC_WAVE_H */
