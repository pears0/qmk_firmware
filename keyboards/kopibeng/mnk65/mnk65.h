/* Copyright 2021 Samuel Lu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

#define ___ KC_NO

/*
 * 
 *             ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐  ┌───────┐
 *             │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0A │0B │0C │1D │0D │0E │  │0D     │ Full Backspace
 *             ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤  └─┬─────┤
 *             │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1A │1B │2C │1C   │1E │    │2D   │
 *  2.25u      ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤  ┌─┴─┐   │ ISO
 *  LShift     │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2A │2B │2D      │2E │  │1C │   │
 * ┌────────┐  ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤  └───┴───┘
 * │30      │  │30  │31 │32 │33 │34 │35 │36 │37 │38 │39 │3A │3B │3C    │3D │3E │
 * └────────┘  ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 *             │40  │41  │42  │46                      │4A  │4B  │ │4C │4D │4E │
 *             └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 *             ┌─────┬───┬─────┬───────────────────────────┬─────┐
 *             │40   │41 │42   │46                         │4B   │ 7u Tsangan
 *             └─────┴───┴─────┴───────────────────────────┴─────┘
 *
 */

// LAYOUT_all:
#define LAYOUT_all( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K1D, K0D, K0E, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K2C, K1C,      K1E, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D,      K2E, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C,      K3D, K3E, \
    K40, K41, K42,                K46,                K4A, K4B,      K4C, K4D, K4E  \
) { \
    {K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E}, \
    {K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E}, \
    {K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E}, \
    {K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E}, \
    {K40, K41, K42, ___, ___, ___, K46, ___, ___, ___, K4A, K4B, K4C, K4D, K4E}  \
}
