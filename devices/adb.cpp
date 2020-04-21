/*
DingusPPC - The Experimental PowerPC Macintosh emulator
Copyright (C) 2018-20 divingkatae and maximum
                      (theweirdo)     spatium

(Contact divingkatae#1017 or powermax#2286 on Discord for more info)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/** ADB input device definitions

    Simulates Apple Desktop Bus (ADB) keyboard and mice

 */

#include <cinttypes>
#include <cstring>
#include "adb.h"
#include <thirdparty/SDL2/include/SDL.h>
#include <thirdparty/SDL2/include/SDL_events.h>
#include <thirdparty/SDL2/include/SDL_keycode.h>
#include <thirdparty/SDL2/include/SDL_mouse.h>
#include <thirdparty/SDL2/include/SDL_stdinc.h>

using namespace std;

ADB_Input::ADB_Input() {
    this->adb_mousereg0 = 0x8080;

    this->ask_register0 = 0xFFFF;
    this->ask_register2 = 0xFFFF;

	while (SDL_PollEvent(&adb_keybd_evt)) {
		this->adb_input_keybd();
		SDL_Delay(20);
	}

	while (SDL_PollEvent(&adb_mouse_evt)) {
		this->adb_input_mouse();
	}

}

ADB_Input::~ADB_Input() {

}

void ADB_Input::adb_input_keybd() {
	//Poll our SDL key event for any keystrokes.
		switch (adb_keybd_evt.type) {
		case SDL_KEYDOWN:
			switch (adb_keybd_evt.key.keysym.sym) {
			case SDLK_a:
				ask_key_pressed = 0x00;
				break;
			case SDLK_s:
				ask_key_pressed = 0x01;
				break;
			case SDLK_d:
				ask_key_pressed = 0x02;
				break;
			case SDLK_f:
				ask_key_pressed = 0x03;
				break;
			case SDLK_h:
				ask_key_pressed = 0x04;
				break;
			case SDLK_g:
				ask_key_pressed = 0x05;
				break;
			case SDLK_z:
				ask_key_pressed = 0x06;
				break;
			case SDLK_x:
				ask_key_pressed = 0x07;
				break;
			case SDLK_c:
				ask_key_pressed = 0x08;
				break;
			case SDLK_v:
				ask_key_pressed = 0x09;
				break;
			case SDLK_b:
				ask_key_pressed = 0x0B;
				break;
			case SDLK_q:
				ask_key_pressed = 0x0C;
				break;
			case SDLK_w:
				ask_key_pressed = 0x0D;
				break;
			case SDLK_e:
				ask_key_pressed = 0x0E;
				break;
			case SDLK_r:
				ask_key_pressed = 0x0F;
				break;
			case SDLK_y:
				ask_key_pressed = 0x10;
				break;
			case SDLK_t:
				ask_key_pressed = 0x11;
				break;
			case SDLK_1:
				ask_key_pressed = 0x12;
				break;
			case SDLK_2:
				ask_key_pressed = 0x13;
				break;
			case SDLK_3:
				ask_key_pressed = 0x14;
				break;
			case SDLK_4:
				ask_key_pressed = 0x15;
				break;
			case SDLK_6:
				ask_key_pressed = 0x16;
				break;
			case SDLK_5:
				ask_key_pressed = 0x17;
				break;
			case SDLK_EQUALS:
				ask_key_pressed = 0x18;
				break;
			case SDLK_9:
				ask_key_pressed = 0x19;
				break;
			case SDLK_7:
				ask_key_pressed = 0x1A;
				break;
			case SDLK_MINUS:
				ask_key_pressed = 0x1B;
				break;
			case SDLK_8:
				ask_key_pressed = 0x1C;
				break;
			case SDLK_0:
				ask_key_pressed = 0x1D;
				break;
			case SDLK_RIGHTBRACKET:
				ask_key_pressed = 0x1E;
				break;
			case SDLK_o:
				ask_key_pressed = 0x1F;
				break;
			case SDLK_u:
				ask_key_pressed = 0x20;
				break;
			case SDLK_LEFTBRACKET:
				ask_key_pressed = 0x21;
				break;
			case SDLK_i:
				ask_key_pressed = 0x22;
				break;
			case SDLK_p:
				ask_key_pressed = 0x23;
				break;
			case SDLK_RETURN:
				ask_key_pressed = 0x24;
				break;
			case SDLK_l:
				ask_key_pressed = 0x25;
				break;
			case SDLK_j:
				ask_key_pressed = 0x26;
				break;
			case SDLK_QUOTE:
				ask_key_pressed = 0x27;
				break;
			case SDLK_k:
				ask_key_pressed = 0x28;
				break;
			case SDLK_SEMICOLON:
				ask_key_pressed = 0x29;
				break;
			case SDLK_BACKSLASH:
				ask_key_pressed = 0x2A;
				break;
			case SDLK_COMMA:
				ask_key_pressed = 0x2B;
				break;
			case SDLK_SLASH:
				ask_key_pressed = 0x2C;
				break;
			case SDLK_n:
				ask_key_pressed = 0x2D;
				break;
			case SDLK_m:
				ask_key_pressed = 0x2E;
				break;
			case SDLK_PERIOD:
				ask_key_pressed = 0x2F;
				break;
			case SDLK_BACKQUOTE:
				ask_key_pressed = 0x32;
				break;
			case SDLK_ESCAPE:
				ask_key_pressed = 0x35;
				break;
			case SDLK_LEFT:
				ask_key_pressed = 0x3B;
				break;
			case SDLK_RIGHT:
				ask_key_pressed = 0x3C;
				break;
			case SDLK_DOWN:
				ask_key_pressed = 0x3D;
				break;
			case SDLK_UP:
				ask_key_pressed = 0x3E;
				break;
			case SDLK_KP_PERIOD:
				ask_key_pressed = 0x41;
				break;
			case SDLK_KP_MULTIPLY:
				ask_key_pressed = 0x43;
				break;
			case SDLK_KP_PLUS:
				ask_key_pressed = 0x45;
				break;
			case SDLK_DELETE:
				ask_key_pressed = 0x47;
				break;
			case SDLK_KP_DIVIDE:
				ask_key_pressed = 0x4B;
				break;
			case SDLK_KP_ENTER:
				ask_key_pressed = 0x4C;
				break;
			case SDLK_KP_MINUS:
				ask_key_pressed = 0x4E;
				break;
			case SDLK_KP_0:
				ask_key_pressed = 0x52;
				break;
			case SDLK_KP_1:
				ask_key_pressed = 0x53;
				break;
			case SDLK_KP_2:
				ask_key_pressed = 0x54;
				break;
			case SDLK_KP_3:
				ask_key_pressed = 0x55;
				break;
			case SDLK_KP_4:
				ask_key_pressed = 0x56;
				break;
			case SDLK_KP_5:
				ask_key_pressed = 0x57;
				break;
			case SDLK_KP_6:
				ask_key_pressed = 0x58;
				break;
			case SDLK_KP_7:
				ask_key_pressed = 0x59;
				break;
			case SDLK_KP_8:
				ask_key_pressed = 0x5B;
				break;
			case SDLK_KP_9:
				ask_key_pressed = 0x5C;
				break;
			case SDLK_BACKSPACE:
				//ask_key_pressed = 0x33;
				this->confirm_ask_reg_2 = true;
				mod_key_pressed = 0x40;
			case SDLK_CAPSLOCK:
				//ask_key_pressed = 0x39;
				this->confirm_ask_reg_2 = true;
				mod_key_pressed = 0x20;
			case SDLK_LCTRL:
			case SDLK_RCTRL:
				//ask_key_pressed = 0x36;
				this->confirm_ask_reg_2 = true;
				mod_key_pressed = 0x8;
			case SDLK_LSHIFT:
			case SDLK_RSHIFT:
				//ask_key_pressed = 0x38;
				this->confirm_ask_reg_2 = true;
				mod_key_pressed = 0x4;
			case SDLK_LALT:
			case SDLK_RALT:
				//ask_key_pressed = 0x3A;
				this->confirm_ask_reg_2 = true;
				mod_key_pressed = 0x2;
			case SDLK_HOME: //Temp key for the Command/Apple key
				//ask_key_pressed = 0x37;
				this->confirm_ask_reg_2 = true;
				mod_key_pressed = 0x1;
			default:
				break;
			}

			if (ask_register0 & 0x8000) {
				ask_register0 &= 0x7FFF;
				ask_register0 &= (ask_key_pressed << 8);
			}
			else if (ask_register0 & 0x80) {
				ask_register0 &= 0xFF7F;
				ask_register0 &= (ask_key_pressed);
			}

			if (confirm_ask_reg_2) {
				ask_register2 |= (mod_key_pressed << 8);
			}

			break;

		case SDL_KEYUP:
			if (!(ask_register0 & 0x8000)) {
				ask_register0 |= 0x8000;
			}
			else if (ask_register0 & 0x80)
				ask_register0 |= 0x0080;

			if (confirm_ask_reg_2) {
				ask_register2 &= (mod_key_pressed << 8);
				confirm_ask_reg_2 = false;
			}
		}
}

void ADB_Input::adb_input_mouse() {
	switch (adb_mouse_evt.motion.x) {
		adb_mousereg0 &= 0x7F;

		if (adb_mouse_evt.motion.xrel < 0) {
			if (adb_mouse_evt.motion.xrel <= -64) {
				adb_mousereg0 |= 0x7F;
			}
			else if (adb_mouse_evt.motion.xrel >= 63) {
				adb_mousereg0 |= 0x3F;
			}
			else {
				adb_mousereg0 |= adb_mouse_evt.motion.xrel;
			}
		}
	}
	switch (adb_mouse_evt.motion.y) {
		adb_mousereg0 &= 0x7F00;

		if (adb_mouse_evt.motion.yrel < 0) {
			if (adb_mouse_evt.motion.yrel <= -64) {
				adb_mousereg0 |= 0x7F00;
			}
			else if (adb_mouse_evt.motion.yrel >= 63) {
				adb_mousereg0 |= 0x3F00;
			}
			else {
				adb_mousereg0 |= (adb_mouse_evt.motion.yrel << 8);
			}
		}

	}
	switch (adb_mouse_evt.type) {
	case SDL_MOUSEBUTTONDOWN:
		adb_mousereg0 &= 0x7FFF;
	case SDL_MOUSEBUTTONUP:
		adb_mousereg0 |= 0x8000;
	}
}
