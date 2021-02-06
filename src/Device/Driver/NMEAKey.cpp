/*
Copyright_License {
  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2016 The XCSoar Project
  A detailed list of copyright holders can be found in the file "AUTHORS".
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#include "Device/Driver/NMEAKey.hpp"
#include "Device/Driver.hpp"
#include "NMEA/Checksum.hpp"
#include "NMEA/Info.hpp"
#include "NMEA/InputLine.hpp"
#include "Units/System.hpp"

extern bool nmea_keys[20];

class NMEAKeyDevice : public AbstractDevice {
public:
  /* virtual methods from class Device */
  bool ParseNMEA(const char *line, struct NMEAInfo &info) override;
};

/**
 * Parse a "$PDKEY" sentence.
 *
 * Example: "$PDKEY,1" NMEA_KEY1 Set
 */
// PDKEY
static bool
PDKEY(NMEAInputLine &line, gcc_unused NMEAInfo &info)
{
  int keynum;
  if (line.ReadChecked(keynum)) {
    if (keynum>=0 && keynum<20) {
      nmea_keys[keynum]=1;
    }
  }
  return true;
}

bool
NMEAKeyDevice::ParseNMEA(const char *String, NMEAInfo &info)
{
  NMEAInputLine line(String);
  char type[16];
  line.Read(type, 16);

  if (StringIsEqual(type, "$PDKEY"))
    return PDKEY(line, info);
  else
    return false;
}

static Device *
NMEAKeyCreateOnPort(const DeviceConfig &config, Port &com_port)
{
  return new NMEAKeyDevice();
}

const struct DeviceRegister nmeakey_driver = {
  _T("NMEA Key"),
  _T("NMEA Key"),
  0,
  NMEAKeyCreateOnPort,
};